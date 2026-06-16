"""
PROBLEM: Remove Duplicate Letters (LeetCode 316) / Smallest Subsequence (LeetCode 1081)
DIFFICULTY: Hard
PATTERN: Greedy + Monotonic Stack

DESCRIPTION:
Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.

INPUT: s = "bcabc"
OUTPUT: "abc"

INPUT: s = "cbacdcbc"
OUTPUT: "acdb"

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(1) - using constant space (26 letters)

EXPLANATION:
Use a greedy approach with monotonic stack. Track:
1. Count of remaining characters
2. Whether character is already in result
For each character, decide whether to remove previous characters to get smaller result.
Remove previous character if: it's larger, appears later, and not already used.
"""



def removeDuplicateLetters(s: str) -> str:
    count = [0] * 26
    in_stack = [False] * 26
    stack = []

    for c in s:
        count[ord(c) - ord('a')] += 1

    for c in s:
        count[ord(c) - ord('a')] -= 1
        if in_stack[ord(c) - ord('a')]:
            continue
        while stack and stack[-1] > c and count[ord(stack[-1]) - ord('a')] > 0:
            in_stack[ord(stack.pop()) - ord('a')] = False
        stack.append(c)
        in_stack[ord(c) - ord('a')] = True

    return ''.join(stack)


if __name__ == "__main__":
    test_cases = [
        "bcabc",
        "cbacdcbc",
        "abacb",
        "ecbacba",
        "bbcaac",
        "rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws",
    ]
    for test in test_cases:
        result = removeDuplicateLetters(test)
        print(f'Input:  "{test}"')
        print(f'Output: "{result}"')
        print()
