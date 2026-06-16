"""
PROBLEM: Implement Queue using Stacks (LeetCode 232)
DIFFICULTY: Easy
PATTERN: Two Stack Technique

DESCRIPTION:
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue:
- push(x): Pushes element x to the back of queue
- pop(): Removes the element from front of queue
- peek(): Returns the element at front of queue
- empty(): Returns True if queue is empty

INPUT:
MyQueue queue = new MyQueue()
queue.push(1)
queue.push(2)
queue.peek();  # returns 1
queue.pop();   # returns 1
queue.empty(); # returns False

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
"""


class MyQueue:
    def __init__(self):
        self.input = []
        self.output = []

    def _transfer(self):
        while self.input:
            self.output.append(self.input.pop())

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> int:
        if not self.output:
            self._transfer()
        return self.output.pop()

    def peek(self) -> int:
        if not self.output:
            self._transfer()
        return self.output[-1]

    def empty(self) -> bool:
        return not self.input and not self.output


if __name__ == "__main__":
    queue = MyQueue()
    print("Pushing: 1, 2, 3, 4, 5")
    queue.push(1)
    queue.push(2)
    queue.push(3)
    queue.push(4)
    queue.push(5)
    print(f"Front element (peek): {queue.peek()}")
    print(f"Pop: {queue.pop()}")
    print(f"Pop: {queue.pop()}")
    print("Pushing: 6")
    queue.push(6)
    print(f"Front element (peek): {queue.peek()}")
    print(f"Is empty: {queue.empty()}")
    print("\nPopping all elements: ", end="")
    while not queue.empty():
        print(queue.pop(), end=" ")
    print()
    print(f"Is empty: {queue.empty()}")
