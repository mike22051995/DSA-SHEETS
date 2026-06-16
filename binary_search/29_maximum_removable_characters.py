"""
PROBLEM: Maximum Number of Removable Characters
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
You are given two strings s and p where p is a subsequence of s. You are also given a distinct 
0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).
You want to choose an integer k (0 <= k <= removable.length) such that, after removing k 
characters from s using the first k indices in removable, p is still a subsequence of s.
Return the maximum k you can choose.

EXPLANATION:
Binary search on k:
- For each k, remove first k characters and check if p is still subsequence
- Use two-pointer technique to check subsequence
- Find maximum k where p remains subsequence

Time Complexity: O(n * log(removable.length))
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
Explanation: After removing indices 3 and 1, "ab" is still subsequence

Example 2:
Input: s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
Output: 1
Explanation: After removing index 3, "abcd" is still subsequence

Example 3:
Input: s = "abcab", p = "abc", removable = [0,1,2,3,4]
Output: 0
"""

from typing import List, Optional


def is_subsequence(s, p, removable, k):
    removed = set(removable[:k])
    j = 0
    for i in range(len(s)):
        if i not in removed and j < len(p) and s[i] == p[j]:
            j += 1
    return j == len(p)


class Solution:
    def maximumRemovals(self, s, p, removable):
        left = 0
        right = len(removable)
        result = 0
        while left <= right:
            mid = left + (right - left) // 2
            if is_subsequence(s, p, removable, mid):
                result = mid
                left = mid + 1
            else:
                right = mid - 1
        return result


if __name__ == "__main__":
    solution = Solution()
    s1, p1 = "abcacb", "ab"
    removable1 = [3, 1, 0]
    print(f"Test 1: {solution.maximumRemovals(s1, p1, removable1)}")
    s2, p2 = "abcbddddd", "abcd"
    removable2 = [3, 2, 1, 4, 5, 6]
    print(f"Test 2: {solution.maximumRemovals(s2, p2, removable2)}")
    s3, p3 = "abcab", "abc"
    removable3 = [0, 1, 2, 3, 4]
    print(f"Test 3: {solution.maximumRemovals(s3, p3, removable3)}")
