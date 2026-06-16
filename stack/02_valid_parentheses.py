"""
PROBLEM: Valid Parentheses (LeetCode 20)
DIFFICULTY: Easy
PATTERN: Stack for Matching Pairs

DESCRIPTION:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid. An input string is valid if:
1. Open brackets must be closed by the same type of brackets
2. Open brackets must be closed in the correct order

INPUT: s = "()[]{}"
OUTPUT: True

INPUT: s = "(]"
OUTPUT: False

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to keep track of opening brackets. When we encounter a closing bracket,
check if it matches the most recent opening bracket (top of stack). If all brackets
match properly, the stack will be empty at the end.
"""


def isValid(s: str) -> bool:
    stack = []
    pairs = {')': '(', '}': '{', ']': '['}

    for c in s:
        if c in pairs:
            if not stack or stack[-1] != pairs[c]:
                return False
            stack.pop()
        else:
            stack.append(c)

    return len(stack) == 0


if __name__ == "__main__":
    test_cases = ["()", "()[]{}", "(]", "([)]", "{[]}", "((()))", "((())", ""]
    for test in test_cases:
        result = "Valid" if isValid(test) else "Invalid"
        print(f'String: "{test}" -> {result}')
