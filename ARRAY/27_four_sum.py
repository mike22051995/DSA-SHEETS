"""
PROBLEM: 4Sum
Difficulty: Medium/Hard
Pattern: Two Pointers, Sorting

DESCRIPTION:
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

EXPLANATION:
Extension of 3Sum:
1. Sort the array
2. Fix two elements using nested loops
3. Use two pointers for remaining two elements
4. Skip duplicates at all levels

Time Complexity: O(n³)
Space Complexity: O(1) excluding output

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation: All unique quadruplets summing to 0

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
Explanation: Only one unique quadruplet

Example 3:
Input: nums = [1,2,3,4], target = 10
Output: [[1,2,3,4]]
"""

from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        n = len(nums)
        if n < 4:
            return result
        nums.sort()
        for i in range(n - 3):
            # Skip duplicates for first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                # Skip duplicates for second element
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                left = j + 1
                right = n - 1
                while left < right:
                    s = nums[i] + nums[j] + nums[left] + nums[right]
                    if s == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        # Skip duplicates for third element
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        # Skip duplicates for fourth element
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
    solution = Solution()
    nums1 = [1, 0, -1, 0, -2, 2]
    print(f"Test 1: {solution.fourSum(nums1, 0)}")
    nums2 = [2, 2, 2, 2, 2]
    print(f"Test 2: {solution.fourSum(nums2, 8)}")
    nums3 = [1, 2, 3, 4]
    print(f"Test 3: {solution.fourSum(nums3, 10)}")
