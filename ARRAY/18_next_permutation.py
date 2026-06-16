"""
PROBLEM: Next Permutation
Difficulty: Medium
Pattern: Array Manipulation

DESCRIPTION:
A permutation of an array of integers is an arrangement of its members into a sequence or 
linear order. Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers. If such arrangement is not possible, it must rearrange 
it as the lowest possible order (i.e., sorted in ascending order).

EXPLANATION:
Algorithm:
1. Find the largest index i such that nums[i] < nums[i+1] (from right)
2. If no such index exists, reverse the entire array
3. Find the largest index j > i such that nums[j] > nums[i]
4. Swap nums[i] and nums[j]
5. Reverse the subarray from i+1 to end

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
Explanation: Next permutation of 123 is 132

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
Explanation: Already at largest permutation, wrap to smallest

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
Explanation: Next permutation considering duplicates
"""

from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = n - 2
        # Step 1: Find first decreasing element from right
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            # Step 2: Find element just larger than nums[i]
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            # Step 3: Swap
            nums[i], nums[j] = nums[j], nums[i]
        # Step 4: Reverse from i+1 to end
        nums[i + 1:] = nums[i + 1:][::-1]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 3]
    solution.nextPermutation(nums1)
    print(f"Test 1: {nums1}")
    nums2 = [3, 2, 1]
    solution.nextPermutation(nums2)
    print(f"Test 2: {nums2}")
    nums3 = [1, 1, 5]
    solution.nextPermutation(nums3)
    print(f"Test 3: {nums3}")
