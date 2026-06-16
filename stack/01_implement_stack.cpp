/*
PROBLEM: Implement Stack using Array
DIFFICULTY: Easy
PATTERN: Basic Stack Operations

DESCRIPTION:
Implement a stack data structure with the following operations:
- push(x): Add element x to the stack
- pop(): Remove and return the top element
- top(): Return the top element without removing it
- isEmpty(): Check if stack is empty
- size(): Return the number of elements in the stack

INPUT:
Operations: push(5), push(10), top(), pop(), isEmpty()

OUTPUT:
top() returns 10
pop() returns 10
isEmpty() returns false

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(n) where n is the number of elements

EXPLANATION:
Stack follows LIFO (Last In First Out) principle. The last element pushed is the first one to be popped.
We use an array and a top pointer to track the last inserted element.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private: 
    int* arr;
    int topIndex;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (topIndex >= capacity - 1) {
            throw overflow_error("Stack Overflow");
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack Underflow");
        }
        return arr[topIndex--];
    }

    int top() {
        if (isEmpty()) {
            throw underflow_error("Stack is Empty");
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack s(100);
    
    cout << "Pushing elements: 5, 10, 15, 20" << endl;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    
    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;
    
    cout << "Current top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    cout << "Is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
