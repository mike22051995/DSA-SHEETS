"""
PROBLEM: Remove All Adjacent Duplicates In String (LeetCode 1047)
DIFFICULTY: Easy
PATTERN: Stack for Removing Consecutive Elements

DESCRIPTION:
You are given a string s. Remove all adjacent duplicate characters repeatedly 
until no adjacent duplicates remain.

INPUT: s = "abbaca"
OUTPUT: "ca"
Explanation: 
"abbaca" -> "aaca" (remove "bb")
"aaca" -> "ca" (remove "aa")

INPUT: s = "azxxzy"
OUTPUT: "ay"

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to store characters. For each character:
- If stack is empty or top is different, push the character
- If top equals current character, pop (remove the duplicate pair)
This ensures all adjacent duplicates are removed in one pass.
"""


def removeDuplicates(s: str) -> str:
    stack = []
    for c in s:
        if stack and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    return ''.join(stack)


def removeDuplicatesOptimized(s: str) -> str:
    result = []
    for c in s:
        if result and result[-1] == c:
            result.pop()
        else:
            result.append(c)
    return ''.join(result)


if __name__ == "__main__":
    test_cases = ["abbaca", "azxxzy", "aabbcc", "aaa", "abcd", "mississippi"]
    for test in test_cases:
        result1 = removeDuplicates(test)
        result2 = removeDuplicatesOptimized(test)
        print(f'Input: "{test}"')
        print(f'Output (stack): "{result1}"')
        print(f'Output (optimized): "{result2}"')
        print()
