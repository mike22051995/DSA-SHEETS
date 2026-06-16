/*
================================================================================
PROBLEM: Implement Queue using Stacks (LeetCode #232)
DIFFICULTY: Easy
PATTERN: Stack / Design
COMPANIES: Amazon, Microsoft, Facebook, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Implement a first in first out (FIFO) queue using only two stacks. The
implemented queue should support all the functions of a normal queue
(push, peek, pop, and empty).

EXAMPLES:

Example 1:
Input:
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output:
[null, null, null, 1, 1, false]

PATTERN RECOGNITION:
Use this pattern when:
- Need to implement one data structure using another
- FIFO behavior using LIFO structures
- Amortized analysis of operations
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    
    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
    
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        transfer();
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    
    cout << "Peek: " << q.peek() << endl;  // 1
    cout << "Pop: " << q.pop() << endl;    // 1
    cout << "Empty: " << (q.empty() ? "true" : "false") << endl;  // false
    
    return 0;
}

/*
TIME COMPLEXITY: 
- push: O(1)
- pop: Amortized O(1)
- peek: Amortized O(1)
- empty: O(1)

SPACE COMPLEXITY: O(n) for storing elements

SIMILAR PROBLEMS:
1. Implement Stack using Queues (LeetCode #225)
2. Min Stack (LeetCode #155)
3. Max Stack (LeetCode #716)
4. Design Circular Queue (LeetCode #622)
5. Design Circular Deque (LeetCode #641)
6. LRU Cache (LeetCode #146)
7. LFU Cache (LeetCode #460)
8. Design Browser History (LeetCode #1472)
9. Design Hit Counter (LeetCode #362)
10. Design Phone Directory (LeetCode #379)
*/
