"""
PROBLEM: Maximum 69 Number (LeetCode 1323)
DIFFICULTY: Easy
PATTERN: Greedy Single Change Optimization

DESCRIPTION:
You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, or 9 becomes 6).

INPUT:
- num: positive integer with only 6s and 9s

OUTPUT:
- Maximum number after at most one digit change

APPROACH:
1. To maximize the number, change the leftmost 6 to 9
2. More significant digits have greater impact
3. No benefit in changing 9 to 6 (decreases value)

WHY GREEDY WORKS:
Changing the leftmost 6 to 9 gives maximum increase because it affects 
the most significant position.
"""

from typing import List, Optional

class Solution:
    def maximum69Number(self, num):
        s = to_string(num)
        # Find leftmost '6' and change it to '9'
        for i in range(len(s)):
        if s[i] == '6':
        s[i] = '9'
        break;  # Change only one digit
        return stoi(s)


if __name__ == "__main__":
    sol = Solution()
    print(f"Test 1 - Input: 9669")
    print(f"Output: {sol.maximum69Number(9669)}")
    print(f"Expected: 9969")
    print(f"Test 2 - Input: 9996")
    print(f"Output: {sol.maximum69Number(9996)}")
    print(f"Expected: 9999")
    print(f"Test 3 - Input: 9999")
    print(f"Output: {sol.maximum69Number(9999)}")
    print(f"Expected: 9999")
    print(f"Test 4 - Input: 6666")
    print(f"Output: {sol.maximum69Number(6666)}")
    print(f"Expected: 9666")
