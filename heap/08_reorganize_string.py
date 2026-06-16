"""
PROBLEM: Reorganize String (LeetCode 767)
DIFFICULTY: Medium
PATTERN: Heap - Max-Heap by character frequency

DESCRIPTION:
Rearrange characters of s so no two adjacent characters are the same.
If impossible, return empty string "".

EXAMPLE:
Input: s = "aab" -> Output: "aba"
Input: s = "aaab" -> Output: ""
Input: s = "vvvlo" -> Output: "vlvov" (one valid)

TIME COMPLEXITY: O(n log 26) = O(n)
SPACE COMPLEXITY: O(1)
"""

import heapq
from collections import Counter


class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = Counter(s)
        # Max-heap: negate frequency
        max_heap = [(-cnt, ch) for ch, cnt in freq.items()]
        heapq.heapify(max_heap)

        result = []
        while len(max_heap) >= 2:
            cnt1, ch1 = heapq.heappop(max_heap)
            cnt2, ch2 = heapq.heappop(max_heap)
            result.append(ch1)
            result.append(ch2)
            if cnt1 + 1 < 0:
                heapq.heappush(max_heap, (cnt1 + 1, ch1))
            if cnt2 + 1 < 0:
                heapq.heappush(max_heap, (cnt2 + 1, ch2))

        if max_heap:
            cnt, ch = max_heap[0]
            if -cnt > 1:
                return ""
            result.append(ch)

        return "".join(result)


if __name__ == "__main__":
    sol = Solution()
    test_cases = ["aab", "aaab", "vvvlo", "a", "aabb"]
    for s in test_cases:
        print(f"s={s!r} -> {sol.reorganizeString(s)!r}")
