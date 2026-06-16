/*
PROBLEM: Implement Stack using Queues
Difficulty: Easy
Pattern: Queue to Stack Conversion

DESCRIPTION:
Implement a stack using two queues with operations:
- push(x): Push element to stack
- pop(): Remove and return top element
- top(): Get top element
- empty(): Check if stack is empty

INPUT:
Operations: push(1), push(2), top(), pop(), empty()

OUTPUT:
Top: 2
Popped: 2
Empty: false

TIME COMPLEXITY: 
- push(): O(n)
- pop(), top(), empty(): O(1)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element (O(n))
    void push(int x) {
        // Add to q2
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        swap(q1, q2);
        cout << "Pushed: " << x << endl;
    }

    // Remove and return top element (O(1))
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int item = q1.front();
        q1.pop();
        return item;
    }

    // Get top element (O(1))
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    // Check if empty (O(1))
    bool empty() {
        return q1.empty();
    }
};

// Alternative: Making pop() costly instead of push()
class StackV2 {
private:
    queue<int> q1, q2;

public:
    // Push element (O(1))
    void push(int x) {
        q1.push(x);
        cout << "Pushed: " << x << endl;
    }

    // Remove and return top element (O(n))
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        // Move all except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int item = q1.front();
        q1.pop();
        
        // Swap q1 and q2
        swap(q1, q2);
        return item;
    }

    // Get top element (O(n))
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int item = q1.front();
        q2.push(item);
        q1.pop();
        
        swap(q1, q2);
        return item;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    cout << "=== Version 1: Push costly ===" << endl;
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Top: " << s1.top() << endl;
    cout << "Popped: " << s1.pop() << endl;
    cout << "Top: " << s1.top() << endl;

    cout << "\n=== Version 2: Pop costly ===" << endl;
    StackV2 s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    cout << "Top: " << s2.top() << endl;
    cout << "Popped: " << s2.pop() << endl;
    cout << "Top: " << s2.top() << endl;

    return 0;
}

/*
EXPLANATION:
Version 1 (Push costly):
- New element is added to q2
- All elements from q1 are moved to q2
- q1 and q2 are swapped
- This ensures newest element is always at front

Version 2 (Pop costly):
- Elements are added normally to q1
- During pop, all except last are moved to q2
- Last element is removed
- Queues are swapped

KEY LEARNING POINTS:
- Can implement stack using queues (reverse of usual)
- Trade-off between push and pop complexity
- Important FAANG interview question
*/
