"""
PROBLEM: Minimum XOR Value Pair
=================================
Find the minimum XOR value of any pair in an array.

APPROACH:
- Sort the array
- Minimum XOR will be between adjacent elements in sorted array
- XOR all adjacent pairs and find minimum

PATTERN: XOR Optimization with Sorting

INPUT/OUTPUT:
Input: arr = [9, 5, 3]
Output: 2
Explanation: (3 XOR 5) = 6, (5 XOR 9) = 12, (3 XOR 9) = 10
Minimum is between 5 and 3 after sorting: 3 XOR 5 = 6
Actually: arr sorted = [3,5,9], min(3^5, 5^9) = min(6,12) = 6
Wait, let me recalculate: 3=011, 5=101, 3^5=110=6

Input: arr = [0, 2, 4, 8]
Output: 0
Explanation: 0 XOR any number gives that number, but 4^0=4, etc
Actually minimum is between adjacent: 0^2=2, 2^4=6, 4^8=12, min=2

TIME COMPLEXITY: O(n log n) - sorting
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def minXOR(self, arr):
        # Sort the array
        sort(arr.begin(), arr.end())
        minXor = float('inf')
        # Check XOR of adjacent elements
        for i in range(len(arr) - 1):
        xorVal = arr[i] ^ arr[i + 1]
        minXor = min(minXor, xorVal)
        return minXor


if __name__ == "__main__":
    sol = Solution()
    arr1 = [9, 5, 3]
    print(f"Input: [9,5,3]")
    print(f"Output (Optimized): {sol.minXOR(arr1)}")
    print(f"Output (Brute Force): {sol.minXORBruteForce([9,}")
    print(f"Explanation: After sorting [3,5,9], min XOR = 3^5 = 6")
    arr2 = [0, 2, 4, 8]
    print(f"Input: [0,2,4,8]")
    print(f"Output (Optimized): {sol.minXOR(arr2)}")
    print(f"Output (Brute Force): {sol.minXORBruteForce([0,}")
    print(f"Explanation: Adjacent pairs give min XOR")
    arr3 = [12, 4, 6, 2]
    print(f"Input: [12,4,6,2]")
    print(f"Output (Optimized): {sol.minXOR(arr3)}")
    print(f"Output (Brute Force): {sol.minXORBruteForce([12,}")
    print(f"Explanation: After sorting [2,4,6,12], 4^6=2 is minimum")
