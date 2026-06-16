"""
PROBLEM: Remove K Digits (LeetCode 402)
DIFFICULTY: Hard
PATTERN: Monotonic Stack Greedy

DESCRIPTION:
Given string num representing a non-negative integer num, and an integer k, return the 
smallest possible integer after removing k digits from num.

INPUT:
- num: string representing a number
- k: number of digits to remove

OUTPUT:
- Smallest possible number as string

APPROACH:
1. Use stack to build result
2. For each digit, pop larger digits from stack (while k > 0)
3. This maintains increasing order (monotonic stack)
4. Remove leading zeros
5. If all removed, return "0"

WHY GREEDY WORKS:
To minimize number, we want smaller digits at front. Removing larger digits 
from left side gives smaller result.
"""

from typing import List, Optional

class Solution:
    def removeKdigits(self, num, k):
        if (k >= len(num)) return "0"
        stack<char> st
        for digit in num:
        # Remove larger digits from stack while we can
        while (!not st and k > 0 and st.top() > digit):
        st.pop()
        k -= 1
        st.push(digit)
        # If k is still > 0, remove from end
        while k > 0:
        st.pop()
        k -= 1
        # Build result result = ""
        while !not st:
        result = st.top() + result
        st.pop()
        # Remove leading zeros
        i = 0
        while (i < len(result) and result[i] == '0'):
        i += 1
        result = result.substr(i)
        return not result ? "0" : result


if __name__ == "__main__":
    sol = Solution()
    print(f"Test 1 - num: \")
    print(f"Output: {sol.removeKdigits("1432219",}")
    print(f"Expected: 1219")
    print(f"Test 2 - num: \")
    print(f"Output: {sol.removeKdigits("10200",}")
    print(f"Expected: 200")
    print(f"Test 3 - num: \")
    print(f"Output: {sol.removeKdigits("10",}")
    print(f"Expected: 0")
    print(f"Test 4 - num: \")
    print(f"Output: {sol.removeKdigits("112",}")
    print(f"Expected: 11")
