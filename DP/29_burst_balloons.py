"""
PROBLEM: Burst Balloons (LeetCode 312)
DIFFICULTY: Hard
PATTERN: Interval/Partition DP

DESCRIPTION:
You are given n balloons indexed from 0 to n-1. Each balloon is painted with 
a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst balloon i, you will get nums[i-1] * nums[i] * nums[i+1] coins.
After bursting it, the left and right balloons become adjacent.

Return the maximum coins you can collect by bursting the balloons wisely.

EXAMPLE:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8]
Burst 1: coins = 3*1*5 = 15, nums = [3,5,8]
Burst 5: coins = 3*5*8 = 120, nums = [3,8]
Burst 3: coins = 1*3*8 = 24, nums = [8]
Burst 8: coins = 1*8*1 = 8
Total = 15+120+24+8 = 167

Input: nums = [1,5]
Output: 10

TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(n²)
"""

from typing import List, Optional

class Solution:
    def maxCoins(self, nums):
        n = len(nums)
        # Add boundary balloons with value 1
        arr = [1] + nums + [1]
        m = len(arr)
        # dp[i][j] = max coins from bursting balloons in range (i, j)
        # not including i and j
        dp = [[0] * m for _ in range(m)]
        # length is the length of the interval
        for length in range(1, n + 1):
            for left in range(n - length + 1):
                right = left + length + 1
                # Try bursting each balloon as the LAST one
                for k in range(left + 1, right):
                    # If k is burst last in range (left, right)
                    # Its neighbors are left and right
                    coins = arr[left] * arr[k] * arr[right]
                    coins += dp[left][k] + dp[k][right]
                    dp[left][right] = max(dp[left][right], coins)
        return dp[0][n+1]


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    nums1 = [3, 1, 5, 8]
    print(f"Balloons: {nums1}")
    print(f"Maximum coins: {sol.maxCoins(nums1)}")
    print(f"\nTest Case 2:")
    nums2 = [1, 5]
    print(f"Balloons: {nums2}")
    print(f"Maximum coins: {sol.maxCoins(nums2)}")
    print(f"\nTest Case 3:")
    nums3 = [8, 2, 6, 8, 9, 8, 1, 4, 1, 5, 3, 0, 7, 7, 0, 4, 2, 2]
    print(f"Balloons: {nums3}")
    print(f"Maximum coins: {sol.maxCoins(nums3)}")
