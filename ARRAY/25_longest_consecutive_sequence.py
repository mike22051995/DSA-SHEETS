"""
PROBLEM: Longest Consecutive Sequence
Difficulty: Hard
Pattern: Hash Set

DESCRIPTION:
Given an unsorted array of integers nums, return the length of the longest consecutive 
elements sequence. You must write an algorithm that runs in O(n) time.

EXPLANATION:
Use a hash set:
1. Add all numbers to set for O(1) lookup
2. For each number, check if it's the start of a sequence (num-1 not in set)
3. If yes, count consecutive numbers from there
4. Track maximum length

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: Sequence [1,2,3,4] has length 4

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Explanation: Sequence [0,1,2,3,4,5,6,7,8] has length 9

Example 3:
Input: nums = [1,2,0,1]
Output: 3
Explanation: Sequence [0,1,2] has length 3
"""

from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        numSet = set(nums)
        maxLength = 0
        for num in numSet:
            # Check if it's the start of a sequence
            if num - 1 not in numSet:
                currentNum = num
                currentLength = 1
                # Count consecutive numbers
                while currentNum + 1 in numSet:
                    currentNum += 1
                    currentLength += 1
                maxLength = max(maxLength, currentLength)
        return maxLength


if __name__ == "__main__":
    solution = Solution()
    nums1 = [100, 4, 200, 1, 3, 2]
    print(f"Test 1: {solution.longestConsecutive(nums1)}")
    nums2 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
    print(f"Test 2: {solution.longestConsecutive(nums2)}")
    nums3 = [1, 2, 0, 1]
    print(f"Test 3: {solution.longestConsecutive(nums3)}")
