/*
================================================================================
PROBLEM: Implement Queue using Stacks (LeetCode #232)
DIFFICULTY: Easy
PATTERN: Stack Design
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    
    void transfer() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    
public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            transfer();
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            transfer();
        }
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
SIMILAR PROBLEMS:
1. Implement Stack using Queues (LeetCode #225)
2. Min Stack (LeetCode #155)
3. Max Stack (LeetCode #716)
4. Design Circular Queue (LeetCode #622)
5. Design Circular Deque (LeetCode #641)
6. Design Front Middle Back Queue (LeetCode #1670)
7. Design Browser History (LeetCode #1472)
8. Design a Stack With Increment (LeetCode #1381)
9. Flatten Nested List Iterator (LeetCode #341)
10. Design Hit Counter (LeetCode #362)
*/
