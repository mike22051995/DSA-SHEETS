"""
PROBLEM: Minimum Cost to Hire K Workers (LeetCode 857)
DIFFICULTY: Hard
PATTERN: Greedy with Ratio Sorting + Max Heap

DESCRIPTION:
There are n workers. You are given two integer arrays quality and wage where quality[i] is 
the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
We want to hire exactly k workers to form a paid group. When hiring k workers, we must pay 
them according to these rules:
1. Every worker in the paid group should be paid in ratio to their quality
2. Every worker must be paid at least their minimum wage expectation
Return the least amount of money needed to form a paid group satisfying the above conditions.

INPUT:
- quality: array of worker qualities
- wage: array of minimum wage expectations
- k: number of workers to hire

OUTPUT:
- Minimum cost to hire k workers

APPROACH:
1. Calculate wage/quality ratio for each worker
2. Sort workers by this ratio
3. Use max heap to track k workers with smallest qualities
4. For each ratio, calculate cost if this worker sets the ratio
5. Keep track of minimum cost

WHY GREEDY WORKS:
The worker with highest ratio in selected group determines payment for all.
By processing in sorted order and maintaining minimum quality sum, we find optimal group.
"""

from typing import List, Optional

class Solution:
    def mincostToHireWorkers(self, quality, wage, k):
        n = len(quality)
        vector<pair<double, int>> workers;  # (ratio, quality)
        # Calculate ratio for each worker
        for i in range(n):
        workers.append({(double)wage[i] / quality[i], quality[i]})
        # Sort by ratio
        sort(workers.begin(), workers.end())
        double minCost = 1e9
        qualitySum = 0
        priority_queue<int> maxHeap;  # Max heap to remove highest quality
        for (auto& worker : workers):
        double ratio = worker.first
        qual = worker.second
        qualitySum += qual
        maxHeap.push(qual)
        # If we have more than k workers, remove highest quality
        if (len(maxHeap) > k):
        qualitySum -= maxHeap.top()
        maxHeap.pop()
        # If we have exactly k workers, calculate cost
        if (len(maxHeap) == k):
        minCost = min(minCost, qualitySum * ratio)
        return minCost


if __name__ == "__main__":
    sol = Solution()
    quality1 = [10, 20, 5]
    wage1 = [70, 50, 30]
    print(f"Test 1 - quality=[10,20,5], wage=[70,50,30], k=2")
    print(f"Output: {fixed}")
    print(f"Expected: 105.00000")
    quality2 = [3, 1, 10, 10, 1]
    wage2 = [4, 8, 2, 2, 7]
    print(f"Test 2 - quality=[3,1,10,10,1], wage=[4,8,2,2,7], k=3")
    print(f"Output: {fixed}")
    print(f"Expected: 30.66667")
