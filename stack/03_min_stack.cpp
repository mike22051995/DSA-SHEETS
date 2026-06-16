/*
PROBLEM: Min Stack (LeetCode 155)
DIFFICULTY: Easy
PATTERN: Auxiliary Stack for Tracking Minimum

DESCRIPTION:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
- push(x): Push element x onto stack
- pop(): Removes the element on top of the stack
- top(): Get the top element
- getMin(): Retrieve the minimum element in the stack

INPUT:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

OUTPUT: As shown above

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(n) for storing elements

EXPLANATION:
We use two stacks - one for actual elements and another for tracking minimum values.
The minStack stores the minimum value at each level. When we pop, we pop from both stacks.
This ensures we always know the current minimum in O(1) time.
*/

#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        mainStack.push(val);
        
        // Push to minStack if it's empty or val is smaller than current min
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (mainStack.empty()) return;
        
        // If popping the minimum element, pop from minStack too
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    
    cout << "Push: -2, 0, -3" << endl;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Current minimum: " << minStack.getMin() << endl;  // -3
    
    minStack.pop();
    cout << "After pop, top element: " << minStack.top() << endl;  // 0
    cout << "Current minimum: " << minStack.getMin() << endl;  // -2
    
    minStack.push(-1);
    cout << "After pushing -1, minimum: " << minStack.getMin() << endl;  // -2
    
    return 0;
}
