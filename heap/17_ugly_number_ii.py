"""
PROBLEM: Ugly Number II (LeetCode 264)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap + visited set

DESCRIPTION:
An ugly number has only prime factors 2, 3, 5. Return the n-th ugly number.
1 is conventionally considered ugly.

EXAMPLE:
Input: n=10 -> Output: 12
Input: n=1 -> Output: 1
Input: n=15 -> Output: 24

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        min_heap = [1]
        seen = {1}
        factors = [2, 3, 5]
        val = 1

        for _ in range(n):
            val = heapq.heappop(min_heap)
            for f in factors:
                nxt = val * f
                if nxt not in seen:
                    seen.add(nxt)
                    heapq.heappush(min_heap, nxt)

        return val

    def nthUglyNumberDP(self, n: int) -> int:
        ugly = [0] * (n + 1)
        ugly[1] = 1
        i2 = i3 = i5 = 1
        for i in range(2, n + 1):
            nxt2, nxt3, nxt5 = ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5
            ugly[i] = min(nxt2, nxt3, nxt5)
            if ugly[i] == nxt2:
                i2 += 1
            if ugly[i] == nxt3:
                i3 += 1
            if ugly[i] == nxt5:
                i5 += 1
        return ugly[n]


if __name__ == "__main__":
    sol = Solution()
    for n in [1, 10, 15]:
        print(f"n={n} -> {sol.nthUglyNumber(n)} (DP: {sol.nthUglyNumberDP(n)})")
