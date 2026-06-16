"""
PROBLEM: Restore IP Addresses
---------------------------------------------------------------------------
Given a string s containing only digits, return all possible valid IP 
addresses that can be formed by inserting dots into s. An IP address 
consists of exactly four integers separated by dots, each integer is 
between 0 and 255 and cannot have leading zeros.

DIFFICULTY: Medium-Hard
PATTERN: Backtracking (String Partitioning with Constraints)
TIME COMPLEXITY: O(3^4) = O(1) - max 3 digits per part, 4 parts
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
"""

from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        self._backtrack(s, 0, [], result)
        return result

    def _backtrack(self, s: str, start: int, parts: List[str],
                   result: List[str]) -> None:
        if len(parts) == 4:
            if start == len(s):
                result.append(".".join(parts))
            return
        if start >= len(s):
            return
        for length in range(1, 4):
            if start + length > len(s):
                break
            part = s[start:start + length]
            if self._is_valid(part):
                parts.append(part)
                self._backtrack(s, start + length, parts, result)
                parts.pop()

    def _is_valid(self, part: str) -> bool:
        if len(part) > 1 and part[0] == '0':
            return False
        return 0 <= int(part) <= 255


if __name__ == "__main__":
    sol = Solution()
    s1 = "25525511135"
    result1 = sol.restoreIpAddresses(s1)
    print(f"Test 1: {result1}")
    s2 = "101023"
    result2 = sol.restoreIpAddresses(s2)
    print(f"Test 2: Total IPs = {len(result2)}")
