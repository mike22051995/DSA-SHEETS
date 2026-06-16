"""
PROBLEM: Partition Array According to Given Pivot (LeetCode 2161)
---------------------------------------------------------------------------
Given a 0-indexed integer array nums and an integer pivot, rearrange nums 
such that:
- All elements less than pivot appear before elements greater than pivot
- All elements equal to pivot appear in between
- Relative order of elements less/greater than pivot is maintained

PATTERN: Three Pointers / Dutch National Flag Variation
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for stable, O(1) for in-place unstable

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: Elements < 10 are [9,5,3], equal are [10,10], greater are [12,14]

Example 2:
Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: Elements < 2 is [-3], equal is [2], greater are [4,3]

KEY INSIGHT:
- If relative order MUST be maintained: Need O(n) space (3-pass or counting)
- If relative order doesn't matter: Can use Dutch National Flag O(1) space
"""

from typing import List


class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        # Approach 1: Three-Pass with Extra Space (Maintains Relative Order)
        # TIME: O(n), SPACE: O(n)
        result = []
        # First pass: add all elements less than pivot
        for num in nums:
            if num < pivot:
                result.append(num)
        # Second pass: add all elements equal to pivot
        for num in nums:
            if num == pivot:
                result.append(num)
        # Third pass: add all elements greater than pivot
        for num in nums:
            if num > pivot:
                result.append(num)
        return result

    def pivotArrayInPlace(self, nums: List[int], pivot: int) -> None:
        # Approach 2: Dutch National Flag - In-Place Three Pointers
        # TIME: O(n), SPACE: O(1)
        # WARNING: Does NOT maintain relative order!
        n = len(nums)
        left = 0       # Pointer for elements < pivot
        mid = 0        # Current pointer scanning array
        right = n - 1  # Pointer for elements > pivot
        while mid <= right:
            if nums[mid] < pivot:
                nums[left], nums[mid] = nums[mid], nums[left]
                left += 1
                mid += 1
            elif nums[mid] > pivot:
                nums[mid], nums[right] = nums[right], nums[mid]
                right -= 1
                # Don't increment mid! Need to check swapped element
            else:
                mid += 1


if __name__ == "__main__":
    sol = Solution()

    print("=== APPROACH 1: Three-Pass (Stable, O(n) space) ===")
    nums1 = [9, 12, 5, 10, 14, 3, 10]
    result1 = sol.pivotArray(nums1, 10)
    print(f"Input:  [9,12,5,10,14,3,10], pivot=10")
    print(f"Output: {result1}")

    nums2 = [-3, 4, 3, 2]
    result2 = sol.pivotArray(nums2, 2)
    print(f"\nInput:  [-3,4,3,2], pivot=2")
    print(f"Output: {result2}")

    print("\n=== APPROACH 2: Dutch National Flag (UNSTABLE, O(1) space) ===")
    nums3 = [9, 12, 5, 10, 14, 3, 10]
    sol.pivotArrayInPlace(nums3, 10)
    print(f"Input:  [9,12,5,10,14,3,10], pivot=10")
    print(f"Output: {nums3} (Relative order NOT maintained!)")

    print("\n=== COMPARISON ===")
    print("Approach 1 (Three-Pass): O(n) time, O(n) space, Stable")
    print("Approach 2 (Dutch Flag): O(n) time, O(1) space, UNSTABLE")
