"""
PROBLEM: Maximum Performance of a Team (LeetCode 1383)
DIFFICULTY: Hard
PATTERN: Heap - Sort by efficiency desc, Min-Heap for speed selection

DESCRIPTION:
Choose at most k engineers. Team performance = sum(speeds) * min(efficiency).
Return maximum performance modulo 10^9 + 7.

EXAMPLE:
Input: n=6, speed=[2,10,3,1,5,8], efficiency=[5,4,3,9,7,2], k=2 -> 60
Input: same, k=3 -> 68
Input: n=3, speed=[2,8,2], efficiency=[2,7,1], k=2 -> 56

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        # Sort by efficiency descending
        workers = sorted(zip(efficiency, speed), reverse=True)

        min_speed_heap: List[int] = []
        speed_sum = 0
        best = 0

        for eff, spd in workers:
            heapq.heappush(min_speed_heap, spd)
            speed_sum += spd
            if len(min_speed_heap) > k:
                speed_sum -= heapq.heappop(min_speed_heap)
            best = max(best, speed_sum * eff)

        return best % MOD


if __name__ == "__main__":
    sol = Solution()
    speed = [2, 10, 3, 1, 5, 8]
    efficiency = [5, 4, 3, 9, 7, 2]
    print(f"k=2 -> {sol.maxPerformance(6, speed, efficiency, 2)}")
    print(f"k=3 -> {sol.maxPerformance(6, speed, efficiency, 3)}")
    print(f"n=3, speed=[2,8,2], eff=[2,7,1], k=2 -> {sol.maxPerformance(3, [2,8,2], [2,7,1], 2)}")
