"""
PROBLEM: Maximum Gap (LeetCode 164)
===============================================
DESCRIPTION:
Given an integer array nums, return the maximum difference between two successive 
elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.

PATTERN: Bucket Sort / Pigeonhole Principle
DIFFICULTY: Hard
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Maximum gap in sorted array

EXAMPLE:
Input: [3,6,9,1]
Output: 3
Explanation: Sorted [1,3,6,9], max gap is 6-3 = 3

Input: [10]
Output: 0
"""

from typing import List

class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return 0
        
        # Find min and max
        minVal = min(nums)
        maxVal = max(nums)
        
        if minVal == maxVal:
            return 0
        
        # Calculate bucket size and count
        # Gap must be at least (max - min) / (n - 1)
        bucket_size = max(1, (maxVal - minVal) // (n - 1))
        bucket_count = (maxVal - minVal) // bucket_size + 1
        
        # Create buckets
        bucket_min = [float('inf')] * bucket_count
        bucket_max = [float('-inf')] * bucket_count
        
        # Place elements in buckets
        for num in nums:
            idx = (num - minVal) // bucket_size
            bucket_min[idx] = min(bucket_min[idx], num)
            bucket_max[idx] = max(bucket_max[idx], num)
        
        # Calculate maximum gap
        max_gap = 0
        prev_max = minVal
        
        for i in range(bucket_count):
            if bucket_min[i] == float('inf'):
                continue
            # Gap between previous bucket's max and current bucket's min
            max_gap = max(max_gap, bucket_min[i] - prev_max)
            prev_max = bucket_max[i]
        
        return max_gap


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [3, 6, 9, 1]
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print()
    print(f"Maximum gap: {sol.maximumGap(nums1)}")
    
    nums2 = [10]
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print()
    print(f"Maximum gap: {sol.maximumGap(nums2)}")
    
    nums3 = [1, 10000000]
    print("\nInput: ")
    for num in nums3:
        print(num, end=" ")
    print()
    print(f"Maximum gap: {sol.maximumGap(nums3)}")
