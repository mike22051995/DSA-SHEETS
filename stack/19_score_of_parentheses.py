"""
PROBLEM: Score of Parentheses (LeetCode 856)
DIFFICULTY: Medium
PATTERN: Stack for Nested Scoring

DESCRIPTION:
Given a balanced parentheses string s, return the score of the string.
Rules:
- "()" has score 1
- "AB" has score A + B, where A and B are balanced parentheses strings
- "(A)" has score 2 * A, where A is a balanced parentheses string

INPUT: s = "()"
OUTPUT: 1

INPUT: s = "(())"
OUTPUT: 2

INPUT: s = "()()"
OUTPUT: 2

INPUT: s = "(()(()))"
OUTPUT: 6

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to track scores at each depth level.
When we see '(', push current score and reset to 0.
When we see ')', the current level is complete - calculate score and add to parent level.
Score is max(2 * current, 1) added to the popped parent score.
"""


def scoreOfParentheses(s: str) -> int:
    stack = [0]  # base score
    for c in s:
        if c == '(':
            stack.append(0)
        else:
            top = stack.pop()
            stack[-1] += max(2 * top, 1)
    return stack[0]


def scoreOfParenthesesOptimized(s: str) -> int:
    score = 0
    depth = 0
    for i, c in enumerate(s):
        if c == '(':
            depth += 1
        else:
            depth -= 1
            if s[i - 1] == '(':
                score += 1 << depth
    return score


if __name__ == "__main__":
    test_cases = ["()", "(())", "()()", "(()(()))", "(((())))", "()((()))"]
    for test in test_cases:
        result1 = scoreOfParentheses(test)
        result2 = scoreOfParenthesesOptimized(test)
        print(f'String: "{test}"')
        print(f"Score (stack): {result1}")
        print(f"Score (optimized): {result2}")
        print()
