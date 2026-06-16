"""
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
isEmpty() returns False

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(n) where n is the number of elements

EXPLANATION:
Stack follows LIFO (Last In First Out) principle. The last element pushed is the first one to be popped.
We use an array and a top pointer to track the last inserted element.
"""


class Stack:
    def __init__(self, capacity=100):
        self.arr = []
        self.capacity = capacity

    def push(self, x):
        if len(self.arr) >= self.capacity:
            raise OverflowError("Stack Overflow")
        self.arr.append(x)

    def pop(self):
        if self.isEmpty():
            raise IndexError("Stack Underflow")
        return self.arr.pop()

    def top(self):
        if self.isEmpty():
            raise IndexError("Stack is Empty")
        return self.arr[-1]

    def isEmpty(self):
        return len(self.arr) == 0

    def size(self):
        return len(self.arr)


if __name__ == "__main__":
    s = Stack(100)
    print("Pushing elements: 5, 10, 15, 20")
    s.push(5)
    s.push(10)
    s.push(15)
    s.push(20)
    print(f"Top element: {s.top()}")
    print(f"Stack size: {s.size()}")
    print(f"Popped element: {s.pop()}")
    print(f"Popped element: {s.pop()}")
    print(f"Current top: {s.top()}")
    print(f"Stack size: {s.size()}")
    print(f"Is empty: {s.isEmpty()}")
