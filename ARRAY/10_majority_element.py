"""
PROBLEM: Majority Element
Difficulty: Easy
Pattern: Boyer-Moore Voting Algorithm, Hash Map

DESCRIPTION:
Given an array nums of size n, return the majority element. The majority element is the 
element that appears more than ⌊n / 2⌋ times. You may assume that the majority element 
always exists in the array.

EXPLANATION:
Boyer-Moore Voting Algorithm: Maintain a candidate and a count.
- If count is 0, set current element as candidate
- If current element equals candidate, increment count
- Otherwise, decrement count
The candidate at the end will be the majority element.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [3,2,3]
Output: 3
Explanation: 3 appears twice (more than n/2)

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
Explanation: 2 appears 4 times (more than 7/2)

Example 3:
Input: nums = [1]
Output: 1
Explanation: Single element is the majority
"""

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = 0
        count = 0
        # Boyer-Moore Voting Algorithm
        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1
        return candidate


if __name__ == "__main__":
    solution = Solution()
    nums1 = [3, 2, 3]
    print(f"Test 1: {solution.majorityElement(nums1)}")
    nums2 = [2, 2, 1, 1, 1, 2, 2]
    print(f"Test 2: {solution.majorityElement(nums2)}")
    nums3 = [1]
    print(f"Test 3: {solution.majorityElement(nums3)}")
