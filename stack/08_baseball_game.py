"""
PROBLEM: Baseball Game (LeetCode 682)
DIFFICULTY: Easy
PATTERN: Stack for Record Keeping

DESCRIPTION:
You're keeping score for a baseball game with operations:
- Integer x: Record a new score of x
- "+": Record sum of previous two scores
- "D": Record double of previous score
- "C": Invalidate previous score

Return the sum of all scores after all operations.

INPUT: ops = ["5","2","C","D","+"]
OUTPUT: 30
Explanation:
"5" - Add 5, total = [5]
"2" - Add 2, total = [5, 2]
"C" - Remove 2, total = [5]
"D" - Add 10 (2 * 5), total = [5, 10]
"+" - Add 15 (5 + 10), total = [5, 10, 15]
Sum = 5 + 10 + 15 = 30

TIME COMPLEXITY: O(n) where n is number of operations
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to maintain valid scores. Process each operation:
- Number: push to stack
- "C": pop last score
- "D": push double of last score
- "+": push sum of last two scores
Finally, sum all elements in stack.
"""

from typing import List


def calPoints(operations: List[str]) -> int:
    scores = []
    for op in operations:
        if op == '+':
            scores.append(scores[-1] + scores[-2])
        elif op == 'D':
            scores.append(2 * scores[-1])
        elif op == 'C':
            scores.pop()
        else:
            scores.append(int(op))
    return sum(scores)


if __name__ == "__main__":
    test_cases = [
        ["5", "2", "C", "D", "+"],
        ["5", "-2", "4", "C", "D", "9", "+", "+"],
        ["1"],
        ["1", "C"],
        ["1", "2", "+", "D"],
    ]
    for ops in test_cases:
        print(f"Operations: {ops}")
        result = calPoints(ops)
        print(f"Total score: {result}")
        print()
