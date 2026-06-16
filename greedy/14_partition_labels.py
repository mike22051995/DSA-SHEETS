"""
PROBLEM: Partition Labels (LeetCode 763)
DIFFICULTY: Medium
PATTERN: Greedy Interval Merging / Last Occurrence Tracking

DESCRIPTION:
You are given a string s. We want to partition the string into as many parts as possible 
so that each letter appears in at most one part. Return a list of integers representing 
the size of these parts.

INPUT:
- s: string to partition

OUTPUT:
- List of partition sizes

APPROACH:
1. Record last occurrence of each character
2. Use two pointers: start and end of current partition
3. Expand end to include last occurrence of all chars seen so far
4. When current index reaches end, partition is complete

WHY GREEDY WORKS:
Once we see a character, we must extend partition to include its last occurrence.
This greedy extension gives us minimal partitions.
"""

from typing import List, Optional

class Solution:
    def if self, end:
        result.append(end - start + 1)
        start = i + 1;  # Start new partition


if __name__ == "__main__":
    sol = Solution()
    s1 = "ababcbacadefegdehijhklij"
    print(f"Test 1 - String: {s1}")
    print("Output: ")
    result1 = sol.partitionLabels(s1)
    for (int size : result1) print(size, end=" ")
    print(f"\nExpected: 9 7 8")
    s2 = "eccbbbbdec"
    print(f"Test 2 - String: {s2}")
    print("Output: ")
    result2 = sol.partitionLabels(s2)
    for (int size : result2) print(size, end=" ")
    print(f"\nExpected: 10")
    s3 = "abcdef"
    print(f"Test 3 - String: {s3}")
    print("Output: ")
    result3 = sol.partitionLabels(s3)
    for (int size : result3) print(size, end=" ")
    print(f"\nExpected: 1 1 1 1 1 1")
