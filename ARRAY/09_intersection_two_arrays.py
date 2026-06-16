"""
PROBLEM: Intersection of Two Arrays II
Difficulty: Easy
Pattern: Hash Map, Two Pointers

DESCRIPTION:
Given two integer arrays nums1 and nums2, return an array of their intersection. Each 
element in the result must appear as many times as it shows in both arrays and you may 
return the result in any order.

EXPLANATION:
Method 1 (Hash Map): Count frequency of elements in first array, then check second array.
Method 2 (Two Pointers): Sort both arrays, use two pointers to find common elements.

Time Complexity: O(n + m) for hash map, O(nlogn + mlogm) for two pointers
Space Complexity: O(min(n, m))

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Explanation: 2 appears twice in both arrays

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9] or [9,4]
Explanation: Each element appears once in intersection

Example 3:
Input: nums1 = [1,2,3], nums2 = [4,5,6]
Output: []
Explanation: No common elements
"""

from typing import List

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Method 1: Using Hash Map
        count = {}
        result = []
        # Count frequency of elements in nums1
        for num in nums1:
            count[num] = count.get(num, 0) + 1
        # Check nums2 and add to result if present in nums1
        for num in nums2:
            if count.get(num, 0) > 0:
                result.append(num)
                count[num] -= 1
        return result

    def intersectSorted(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Method 2: Using Two Pointers (if arrays are sorted)
        nums1.sort()
        nums2.sort()
        result = []
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return result


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    print(f"Test 1: {solution.intersect(nums1, nums2)}")
    nums3 = [4, 9, 5]
    nums4 = [9, 4, 9, 8, 4]
    print(f"Test 2: {solution.intersect(nums3, nums4)}")
    nums5 = [1, 2, 3]
    nums6 = [4, 5, 6]
    print(f"Test 3: {solution.intersect(nums5, nums6)}")
