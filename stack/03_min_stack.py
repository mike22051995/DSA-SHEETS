"""
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
MinStack minStack = new MinStack()
minStack.push(-2)
minStack.push(0)
minStack.push(-3)
minStack.getMin(); # return -3
minStack.pop()
minStack.top();    # return 0
minStack.getMin(); # return -2

OUTPUT: As shown above

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(n) for storing elements

EXPLANATION:
We use two stacks - one for actual elements and another for tracking minimum values.
The minStack stores the minimum value at each level. When we pop, we pop from both stacks.
This ensures we always know the current minimum in O(1) time.
"""


class MinStack:
    def __init__(self):
        self.main_stack = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.main_stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if not self.main_stack:
            return
        if self.main_stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.main_stack.pop()

    def top(self) -> int:
        return self.main_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


if __name__ == "__main__":
    minStack = MinStack()
    print("Push: -2, 0, -3")
    minStack.push(-2)
    minStack.push(0)
    minStack.push(-3)
    print(f"Current minimum: {minStack.getMin()}")
    minStack.pop()
    print(f"After pop, top element: {minStack.top()}")
    print(f"Current minimum: {minStack.getMin()}")
    minStack.push(-1)
    print(f"After pushing -1, minimum: {minStack.getMin()}")
