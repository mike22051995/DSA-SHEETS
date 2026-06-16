/*
PROBLEM: Implement Queue using Stacks (LeetCode 232)
DIFFICULTY: Easy
PATTERN: Two Stack Technique

DESCRIPTION:
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue:
- push(x): Pushes element x to the back of queue
- pop(): Removes the element from front of queue
- peek(): Returns the element at front of queue
- empty(): Returns true if queue is empty

INPUT:
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

TIME COMPLEXITY: 
- push(): O(1)
- pop(): Amortized O(1)
- peek(): Amortized O(1)
- empty(): O(1)

SPACE COMPLEXITY: O(n) where n is number of elements

EXPLANATION:
Use two stacks - input and output. Push operations go to input stack.
For pop/peek, if output stack is empty, transfer all elements from input to output.
This reverses the order, making the oldest element accessible at top of output stack.
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    
    // Transfer elements from input to output stack
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
        int front = output.top();
        output.pop();
        return front;
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
    MyQueue queue;
    
    cout << "Pushing: 1, 2, 3, 4, 5" << endl;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    
    cout << "Front element (peek): " << queue.peek() << endl;
    cout << "Pop: " << queue.pop() << endl;
    cout << "Pop: " << queue.pop() << endl;
    
    cout << "Pushing: 6" << endl;
    queue.push(6);
    
    cout << "Front element (peek): " << queue.peek() << endl;
    cout << "Is empty: " << (queue.empty() ? "Yes" : "No") << endl;
    
    cout << "\nPopping all elements: ";
    while (!queue.empty()) {
        cout << queue.pop() << " ";
    }
    cout << endl;
    
    cout << "Is empty: " << (queue.empty() ? "Yes" : "No") << endl;
    
    return 0;
}
