"""
PROBLEM: Super Ugly Number (LeetCode 313)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap + visited set with custom primes

DESCRIPTION:
Given n and list of primes, return the n-th super ugly number.
A super ugly number has prime factors only from the given primes list.

EXAMPLE:
Input: n=12, primes=[2,7,13,19] -> Output: 32
Input: n=1, primes=[2,3,5] -> Output: 1
Input: n=5, primes=[3,5,7,11] -> Output: 9

TIME COMPLEXITY: O(n * p * log(n*p)) where p = len(primes)
SPACE COMPLEXITY: O(n * p)
"""

import heapq
from typing import List


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        min_heap: List[int] = [1]
        seen = {1}
        val = 1

        for _ in range(n):
            val = heapq.heappop(min_heap)
            for p in primes:
                nxt = val * p
                if nxt not in seen:
                    seen.add(nxt)
                    heapq.heappush(min_heap, nxt)

        return val


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        (12, [2, 7, 13, 19]),
        (1, [2, 3, 5]),
        (5, [3, 5, 7, 11]),
    ]
    for n, primes in test_cases:
        print(f"n={n}, primes={primes} -> {sol.nthSuperUglyNumber(n, primes)}")
