"""
PROBLEM: Sliding Window Maximum
Difficulty: Hard
Pattern: Sliding Window, Deque (Monotonic Queue)

DESCRIPTION:
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the 
window. Each time the sliding window moves right by one position.
Return the max sliding window.

EXPLANATION:
Use a deque to maintain indices of useful elements in decreasing order:
- Remove indices outside current window
- Remove indices of smaller elements from back (they won't be max)
- Front of deque always has index of max element in current window

Time Complexity: O(n)
Space Complexity: O(k)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: Window max at each position

Example 2:
Input: nums = [1], k = 1
Output: [1]
Explanation: Single element window

Example 3:
Input: nums = [1,-1], k = 1
Output: [1,-1]
Explanation: Window size 1, each element is max
"""

from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        dq = deque()  # Stores indices in decreasing order of values
        for i in range(len(nums)):
            # Remove indices outside current window
            while dq and dq[0] < i - k + 1:
                dq.popleft()
            # Remove indices of smaller elements
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()
            dq.append(i)
            # Add to result if window is formed
            if i >= k - 1:
                result.append(nums[dq[0]])
        return result


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 3, -1, -3, 5, 3, 6, 7]
    print(f"Test 1: {solution.maxSlidingWindow(nums1, 3)}")
    nums2 = [1]
    print(f"Test 2: {solution.maxSlidingWindow(nums2, 1)}")
    nums3 = [1, -1]
    print(f"Test 3: {solution.maxSlidingWindow(nums3, 1)}")
