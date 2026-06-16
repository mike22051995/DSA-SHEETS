"""
PROBLEM: Longest Mountain in Array
---------------------------------------------------------------------------
You may recall that an array arr is a mountain array if and only if:
- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
  arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Return the length of the longest mountain.

PATTERN: Two Pointers (Expand from Center)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: Longest mountain is [1,4,7,3,2] with length 5.

Example 2:
Input: arr = [2,2,2]
Output: 0
Explanation: No mountain exists.
"""

from typing import List, Optional

class Solution:
    def longestMountain(self, arr):
        n = len(arr)
        maxLen = 0
        for i in range(1, n - 1):
            # Check if i is a peak
            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                left = i - 1
                right = i + 1
                # Expand left (uphill)
                while left > 0 and arr[left] > arr[left - 1]:
                    left -= 1
                # Expand right (downhill)
                while right < n - 1 and arr[right] > arr[right + 1]:
                    right += 1
                maxLen = max(maxLen, right - left + 1)
        return maxLen


if __name__ == "__main__":
    sol = Solution()
    arr1 = [2, 1, 4, 7, 3, 2, 5]
    print(f"Test 1: {sol.longestMountain(arr1)}")
    arr2 = [2, 2, 2]
    print(f"Test 2: {sol.longestMountain(arr2)}")
