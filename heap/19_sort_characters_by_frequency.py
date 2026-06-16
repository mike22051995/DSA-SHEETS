"""
PROBLEM: Sort Characters By Frequency (LeetCode 451)
DIFFICULTY: Medium
PATTERN: Heap - Max-Heap by character frequency

DESCRIPTION:
Given string s, sort it so characters appear in decreasing order of frequency.

EXAMPLE:
Input: s="tree" -> "eert" or "eetr"
Input: s="cccaaa" -> "cccaaa" or "aaaccc"
Input: s="Aabb" -> "bbAa" or "bbaA"

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        # Max-heap: negate frequency
        max_heap = [(-cnt, ch) for ch, cnt in freq.items()]
        heapq.heapify(max_heap)

        result = []
        while max_heap:
            cnt, ch = heapq.heappop(max_heap)
            result.append(ch * (-cnt))

        return "".join(result)


if __name__ == "__main__":
    sol = Solution()
    for s in ["tree", "cccaaa", "Aabb", "z"]:
        print(f"s={s!r} -> {sol.frequencySort(s)!r}")
