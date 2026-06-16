"""
PROBLEM: Validate Stack Sequences (LeetCode 946)
DIFFICULTY: Medium
PATTERN: Stack Simulation

DESCRIPTION:
Given two integer arrays pushed and popped each with distinct values, 
return True if this could have been the result of a sequence of push and pop 
operations on an initially empty stack, or False otherwise.

INPUT: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
OUTPUT: True
Explanation: push(1), push(2), push(3), push(4), pop() -> 4, push(5), pop() -> 5, 
pop() -> 3, pop() -> 2, pop() -> 1

INPUT: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
OUTPUT: False

TIME COMPLEXITY: O(n) where n is the length of arrays
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Simulate the stack operations. For each element in pushed, push to stack.
After each push, try to pop elements that match the current position in popped array.
If all elements can be popped successfully, return True.
"""



from typing import List


def validateStackSequences(pushed: List[int], popped: List[int]) -> bool:
    stack = []
    j = 0
    for num in pushed:
        stack.append(num)
        while stack and stack[-1] == popped[j]:
            stack.pop()
            j += 1
    return len(stack) == 0


if __name__ == "__main__":
    test_cases = [
        ([1, 2, 3, 4, 5], [4, 5, 3, 2, 1]),
        ([1, 2, 3, 4, 5], [4, 3, 5, 1, 2]),
        ([1, 2, 3], [3, 2, 1]),
        ([1, 2, 3], [1, 2, 3]),
        ([2, 1, 0], [1, 2, 0]),
    ]
    for pushed, popped in test_cases:
        result = validateStackSequences(pushed, popped)
        print(f"Pushed: {pushed}")
        print(f"Popped: {popped}")
        print(f"Valid: {result}")
        print()
