"""
PROBLEM: Decode String (LeetCode 394)
DIFFICULTY: Medium
PATTERN: Stack for Nested Structures

DESCRIPTION:
Given an encoded string, return its decoded string.
Encoding rule: k[encoded_string], where encoded_string is repeated exactly k times.
You may assume input is always valid with properly nested brackets.

INPUT: s = "3[a]2[bc]"
OUTPUT: "aaabcbc"

INPUT: s = "3[a2[c]]"
OUTPUT: "accaccacc"

INPUT: s = "2[abc]3[cd]ef"
OUTPUT: "abcabccdcdcdef"

TIME COMPLEXITY: O(n) where n is the length of decoded string
SPACE COMPLEXITY: O(n) for the stacks

EXPLANATION:
Use two stacks - one for numbers (repeat count) and one for strings.
When we encounter '[', push current string and number to stacks.
When we encounter ']', pop from stacks and build the decoded string.
For regular characters, append to current string.
"""



def decodeString(s: str) -> str:
    num_stack = []
    str_stack = []
    current_str = ""
    current_num = 0

    for c in s:
        if c.isdigit():
            current_num = current_num * 10 + int(c)
        elif c == '[':
            num_stack.append(current_num)
            str_stack.append(current_str)
            current_num = 0
            current_str = ""
        elif c == ']':
            repeat = num_stack.pop()
            prev_str = str_stack.pop()
            current_str = prev_str + current_str * repeat
        else:
            current_str += c

    return current_str


if __name__ == "__main__":
    test_cases = [
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
        "abc3[cd]xyz",
        "100[leetcode]",
        "3[z]2[2[y]pq4[2[jk]e1[f]]]ef",
    ]
    for test in test_cases:
        result = decodeString(test)
        print(f'Encoded: "{test}"')
        print(f'Decoded: "{result}"')
        print()
