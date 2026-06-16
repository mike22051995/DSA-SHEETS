/*
PROBLEM: Maximum Frequency Stack (LeetCode 895)
DIFFICULTY: Hard
PATTERN: Stack with Frequency Tracking

DESCRIPTION:
Design a stack-like data structure that pops the most frequent element.
Implement FreqStack class:
- FreqStack() constructs an empty frequency stack
- void push(int val) pushes an integer val onto the top of the stack
- int pop() removes and returns the most frequent element. If tie, return the one closest to top

INPUT:
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
OUTPUT:
[null, null, null, null, null, null, null, 5, 7, 5, 4]

TIME COMPLEXITY: O(1) for both push and pop
SPACE COMPLEXITY: O(n) where n is number of elements

EXPLANATION:
Maintain:
1. freq: map from element to its frequency
2. group: map from frequency to stack of elements with that frequency
3. maxFreq: current maximum frequency
On push, increment frequency and add to appropriate frequency group.
On pop, return from maxFreq group and decrement frequency.
*/

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq;  // element -> frequency
    unordered_map<int, stack<int>> group;  // frequency -> stack of elements
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        // Increment frequency
        freq[val]++;
        int f = freq[val];
        
        // Update max frequency
        maxFreq = max(maxFreq, f);
        
        // Add to frequency group
        group[f].push(val);
    }
    
    int pop() {
        // Get element from max frequency group
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        
        // Decrement frequency
        freq[val]--;
        
        // Update max frequency if needed
        if (group[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};

int main() {
    FreqStack freqStack;
    
    cout << "Operations:" << endl;
    cout << "push(5), push(7), push(5), push(7), push(4), push(5)" << endl;
    
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(4);
    freqStack.push(5);
    
    cout << "\nPopping elements:" << endl;
    cout << "pop() = " << freqStack.pop() << " (expected: 5, freq=3)" << endl;
    cout << "pop() = " << freqStack.pop() << " (expected: 7, freq=2)" << endl;
    cout << "pop() = " << freqStack.pop() << " (expected: 5, freq=2)" << endl;
    cout << "pop() = " << freqStack.pop() << " (expected: 4, freq=1)" << endl;
    
    cout << "\n\nAnother test:" << endl;
    FreqStack fs2;
    
    cout << "push(4), push(0), push(9), push(3), push(4), push(2)" << endl;
    fs2.push(4);
    fs2.push(0);
    fs2.push(9);
    fs2.push(3);
    fs2.push(4);
    fs2.push(2);
    
    cout << "pop() = " << fs2.pop() << " (expected: 4)" << endl;
    
    return 0;
}
