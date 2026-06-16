"""
PROBLEM: Kth Largest Element (QuickSelect Partition)
---------------------------------------------------------------------------
Find the kth largest element in an unsorted array. Note that it is the 
kth largest element in sorted order, not the kth distinct element.

PATTERN: Two Pointers (QuickSelect - Partition)
TIME COMPLEXITY: O(n) average, O(n²) worst case
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Explanation: When sorted: [1,2,3,4,5,6]. 2nd largest is 5.

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
Explanation: When sorted: [1,2,2,3,3,4,5,5,6]. 4th largest is 4.
"""

from typing import List
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target = len(nums) - k  # Convert to kth smallest index

        def partition(left: int, right: int) -> int:
            pivot_idx = random.randint(left, right)
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
            pivot = nums[right]
            store = left
            for i in range(left, right):
                if nums[i] <= pivot:
                    nums[store], nums[i] = nums[i], nums[store]
                    store += 1
            nums[store], nums[right] = nums[right], nums[store]
            return store

        left, right = 0, len(nums) - 1
        while left <= right:
            pivot_index = partition(left, right)
            if pivot_index == target:
                return nums[pivot_index]
            elif pivot_index < target:
                left = pivot_index + 1
            else:
                right = pivot_index - 1
        return -1


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 2, 1, 5, 6, 4]
    k1 = 2
    print(f"Test 1: {sol.findKthLargest(nums1, k1)}")
    nums2 = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k2 = 4
    print(f"Test 2: {sol.findKthLargest(nums2, k2)}")
