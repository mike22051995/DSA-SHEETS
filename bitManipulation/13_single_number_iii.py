"""
PROBLEM: Single Number III (Two Non-Repeating Elements)
=========================================================
Given an array where every element appears twice except two elements,
find those two elements.

APPROACH:
- XOR all elements to get XOR of two unique numbers
- Find rightmost set bit in XOR result (differentiating bit)
- Partition numbers into two groups based on this bit
- XOR each group separately to get the two unique numbers

PATTERN: XOR with Partitioning - Multiple Unique Elements

INPUT/OUTPUT:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation: 1 and 2 appear twice, 3 and 5 appear once

Input: nums = [-1,0]
Output: [-1,0]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""



if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 1, 3, 2, 5]
    print(f"Input: [1,2,1,3,2,5]")
    result1 = sol.singleNumber(nums1)
    print(f"Output: [{result1[0]}")
    print(f"Explanation: 1,2 appear twice; 3,5 once")
    nums2 = [-1, 0]
    print(f"Input: [-1,0]")
    result2 = sol.singleNumber(nums2)
    print(f"Output: [{result2[0]}")
    print(f"Explanation: Only two elements")
    nums3 = [1, 1, 2, 2, 3, 4]
    print(f"Input: [1,1,2,2,3,4]")
    result3 = sol.singleNumber(nums3)
    print(f"Output: [{result3[0]}")
    print(f"Explanation: 1,2 appear twice; 3,4 once")
