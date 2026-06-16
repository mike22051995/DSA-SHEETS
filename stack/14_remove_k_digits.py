"""
PROBLEM: Remove K Digits (LeetCode 402)
DIFFICULTY: Medium
PATTERN: Monotonic Stack for Optimization

DESCRIPTION:
Given string num representing a non-negative integer, and an integer k, 
return the smallest possible integer after removing k digits from the number.

INPUT: num = "1432219", k = 3
OUTPUT: "1219"
Explanation: Remove digits 4, 3, and 2 to form 1219 which is the smallest.

INPUT: num = "10200", k = 1
OUTPUT: "200"
Explanation: Remove leading 1, result is 200 (remove leading zeros).

TIME COMPLEXITY: O(n) where n is the length of num
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic increasing stack. For each digit, remove larger digits from stack
if we have remaining removals. This ensures the smallest number is formed.
After processing, remove any remaining digits from end and handle leading zeros.
"""



def removeKdigits(num: str, k: int) -> str:
    if k >= len(num):
        return "0"

    stack = []
    for digit in num:
        while stack and k > 0 and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    # Remove remaining k digits from end
    stack = stack[:-k] if k else stack

    # Remove leading zeros
    result = ''.join(stack).lstrip('0')
    return result if result else "0"


if __name__ == "__main__":
    test_cases = [
        ("1432219", 3),
        ("10200", 1),
        ("10", 2),
        ("112", 1),
        ("9", 1),
        ("1234567890", 9),
        ("10001", 4),
    ]
    for num, k in test_cases:
        result = removeKdigits(num, k)
        print(f'num = "{num}", k = {k}')
        print(f'Result: "{result}"')
        print()
