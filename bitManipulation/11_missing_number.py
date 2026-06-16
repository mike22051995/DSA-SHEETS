"""
PROBLEM: Missing Number
=========================
Given an array containing n distinct numbers from 0 to n, 
find the one that is missing from the array.

APPROACH:
- XOR all numbers from 0 to n
- XOR all numbers in the array
- Missing number = XOR of both results
- Duplicate numbers cancel out, missing one remains

PATTERN: XOR Properties - Finding Missing Element

INPUT/OUTPUT:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3, range is [0,3], missing number is 2

Input: nums = [0,1]
Output: 2
Explanation: n = 2, range is [0,2], missing number is 2

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def missingNumber(self, nums):
        n = len(nums)
        xorAll = 0, xorArray = 0
        # XOR all numbers from 0 to n
        for i in range(= n):
        xorAll ^= i
        # XOR all numbers in array
        for num in nums:
        xorArray ^= num
        # Missing number
        return xorAll ^ xorArray


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 0, 1]
    print(f"Input: [3,0,1]")
    print(f"Output: {sol.missingNumber(nums1)}")
    print(f"Explanation: Range [0,3], missing 2")
    nums2 = [0, 1]
    print(f"Input: [0,1]")
    print(f"Output: {sol.missingNumber(nums2)}")
    print(f"Explanation: Range [0,2], missing 2")
    nums3 = [9,6,4,2,3,5,7,0,1]
    print(f"Input: [9,6,4,2,3,5,7,0,1]")
    print(f"Output: {sol.missingNumber(nums3)}")
    print(f"Explanation: Range [0,9], missing 8")
