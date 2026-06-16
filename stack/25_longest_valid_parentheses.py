"""
PROBLEM: Longest Valid Parentheses (LeetCode 32)
DIFFICULTY: Hard
PATTERN: Stack for Parentheses Matching with Length Tracking

DESCRIPTION:
Given a string containing just the characters '(' and ')', find the length of the 
longest valid (well-formed) parentheses substring.

INPUT: s = "(()"
OUTPUT: 2
Explanation: The longest valid parentheses substring is "()".

INPUT: s = ")()())"
OUTPUT: 4
Explanation: The longest valid parentheses substring is "()()".

INPUT: s = ""
OUTPUT: 0

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Stack approach: Store indices of unmatched parentheses. Initialize with -1 as base.
For '(', push index. For ')', pop. If stack becomes empty, push current index.
Otherwise, calculate length as current index - top of stack.
This problem is frequently asked in FAANG interviews!
"""



def longestValidParentheses(s: str) -> int:
    stack = [-1]
    max_len = 0

    for i, c in enumerate(s):
        if c == '(':
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                max_len = max(max_len, i - stack[-1])

    return max_len


def longestValidParenthesesDP(s: str) -> int:
    n = len(s)
    if n == 0:
        return 0
    dp = [0] * n
    max_len = 0

    for i in range(1, n):
        if s[i] == ')':
            if s[i - 1] == '(':
                dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
            elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(':
                dp[i] = dp[i - 1] + 2 + (dp[i - dp[i - 1] - 2] if i - dp[i - 1] >= 2 else 0)
            max_len = max(max_len, dp[i])

    return max_len


if __name__ == "__main__":
    test_cases = ["(()", ")()())", "", "()(()  ", "()(())", "((())))", "()()(()()", "(()())"]
    for test in test_cases:
        result1 = longestValidParentheses(test)
        result2 = longestValidParenthesesDP(test)
        print(f'String: "{test}"')
        print(f"Longest valid (stack): {result1}")
        print(f"Longest valid (DP): {result2}")
        print()
