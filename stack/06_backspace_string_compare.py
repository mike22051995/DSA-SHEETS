"""
PROBLEM: Backspace String Compare (LeetCode 844)
DIFFICULTY: Easy
PATTERN: Stack for String Processing

DESCRIPTION:
Given two strings s and t, return True if they are equal when both are typed into 
empty text editors. '#' means a backspace character.

INPUT: s = "ab#c", t = "ad#c"
OUTPUT: True
Explanation: Both s and t become "ac"

INPUT: s = "ab##", t = "c#d#"
OUTPUT: True
Explanation: Both s and t become ""

TIME COMPLEXITY: O(n + m) where n and m are lengths of strings
SPACE COMPLEXITY: O(n + m) for stacks

EXPLANATION:
Use a stack to process each string. When encountering a regular character, push it.
When encountering '#', pop from stack (if not empty). After processing both strings,
compare the final stacks.
"""


def processString(s: str) -> str:
    stack = []
    for c in s:
        if c != '#':
            stack.append(c)
        elif stack:
            stack.pop()
    return ''.join(stack)


def backspaceCompare(s: str, t: str) -> bool:
    return processString(s) == processString(t)


def backspaceCompareOptimized(s: str, t: str) -> bool:
    i, j = len(s) - 1, len(t) - 1
    skip_s = skip_t = 0

    while i >= 0 or j >= 0:
        while i >= 0:
            if s[i] == '#':
                skip_s += 1
                i -= 1
            elif skip_s > 0:
                skip_s -= 1
                i -= 1
            else:
                break
        while j >= 0:
            if t[j] == '#':
                skip_t += 1
                j -= 1
            elif skip_t > 0:
                skip_t -= 1
                j -= 1
            else:
                break
        if i >= 0 and j >= 0 and s[i] != t[j]:
            return False
        if (i >= 0) != (j >= 0):
            return False
        i -= 1
        j -= 1

    return True


if __name__ == "__main__":
    test_cases = [
        ("ab#c", "ad#c"),
        ("ab##", "c#d#"),
        ("a##c", "#a#c"),
        ("a#c", "b"),
        ("bxj##tw", "bxo#j##tw"),
    ]
    for s, t in test_cases:
        result1 = backspaceCompare(s, t)
        result2 = backspaceCompareOptimized(s, t)
        print(f's = "{s}", t = "{t}"')
        print(f"Stack approach: {result1}")
        print(f"Optimized approach: {result2}")
        print(f'Final strings: "{processString(s)}" vs "{processString(t)}"')
        print()
