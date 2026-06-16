"""
PROBLEM: Make The String Great (LeetCode 1544)
DIFFICULTY: Easy
PATTERN: Stack for Character Matching

DESCRIPTION:
A string is "great" if there are no two adjacent characters s[i] and s[i+1] where:
- 0 <= i <= s.length - 2
- s[i] is a lower-case letter and s[i+1] is the same letter but in upper-case or vice-versa

Given a string s, return the string after making it great by removing adjacent pairs.

INPUT: s = "leEeetcode"
OUTPUT: "leetcode"
Explanation: Remove "Ee", then "eE"

INPUT: s = "abBAcC"
OUTPUT: ""

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to track characters. For each character, check if it forms a "bad pair"
with the top of stack (same letter, different case). If yes, pop. Otherwise, push.
"""


def makeGood(s: str) -> str:
    stack = []
    for c in s:
        if stack and abs(ord(stack[-1]) - ord(c)) == 32:
            stack.pop()
        else:
            stack.append(c)
    return ''.join(stack)


def makeGoodOptimized(s: str) -> str:
    result = []
    for c in s:
        if result and abs(ord(result[-1]) - ord(c)) == 32:
            result.pop()
        else:
            result.append(c)
    return ''.join(result)


if __name__ == "__main__":
    test_cases = ["leEeetcode", "abBAcC", "s", "Pp", "AaBbCcDdEe", "mC"]
    for test in test_cases:
        result1 = makeGood(test)
        result2 = makeGoodOptimized(test)
        print(f'Input: "{test}"')
        print(f'Output (stack): "{result1}"')
        print(f'Output (optimized): "{result2}"')
        print()
