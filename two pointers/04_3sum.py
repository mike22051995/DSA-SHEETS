"""
PROBLEM: 3Sum
---------------------------------------------------------------------------
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
The solution set must not contain duplicate triplets.

PATTERN: Sorting + Opposite Direction Two Pointers
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1) excluding output

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum to 0.
"""

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        if n < 3:
            return result
        nums.sort()
        for i in range(n - 2):
            # Skip duplicates for first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left = i + 1
            right = n - 1
            target = -nums[i]
            while left < right:
                s = nums[left] + nums[right]
                if s == target:
                    result.append([nums[i], nums[left], nums[right]])
                    # Skip duplicates for second element
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicates for third element
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif s < target:
                    left += 1
                else:
                    right -= 1
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [-1, 0, 1, 2, -1, -4]
    result1 = sol.threeSum(nums1)
    print(f"Test 1: {result1}")
    nums2 = [0, 1, 1]
    result2 = sol.threeSum(nums2)
    print(f"Test 2: {result2}")
