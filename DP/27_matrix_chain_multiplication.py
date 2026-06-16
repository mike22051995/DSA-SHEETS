"""
PROBLEM: Matrix Chain Multiplication
DIFFICULTY: Hard
PATTERN: Interval/Partition DP

DESCRIPTION:
Given a sequence of matrices, find the most efficient way to multiply these matrices.
The problem is not to perform the multiplications, but to decide the sequence of 
matrix multiplications that minimizes the number of scalar multiplications.

Given array arr[] representing the dimensions of n-1 matrices such that 
dimension of ith matrix is arr[i-1] x arr[i].

EXAMPLE:
Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation: 4 matrices with dimensions:
M1: 40x20, M2: 20x30, M3: 30x10, M4: 10x30

Optimal: ((M1(M2M3))M4) = 26000 operations

Input: arr[] = {10, 20, 30}
Output: 6000
Explanation: Only one way to multiply: (M1*M2) = 10*20*30 = 6000

TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(n²)
"""

from typing import List, Optional

class Solution:
    def matrixChainRecursive(self, arr, i, j):
        # Base case: single matrix
        if i >= j:
            return 0
        min_ops = float('inf')
        # Try all possible split points
        for k in range(i, j):
            left_cost = self.matrixChainRecursive(arr, i, k)
            right_cost = self.matrixChainRecursive(arr, k+1, j)
            merge_cost = arr[i-1] * arr[k] * arr[j]
            total_cost = left_cost + right_cost + merge_cost
            min_ops = min(min_ops, total_cost)
        return min_ops

    def matrixChainMultiplication(self, arr):
        n = len(arr) - 1  # number of matrices
        # dp[i][j] = min cost to multiply matrices from i to j
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for length in range(2, n + 1):
            for i in range(1, n - length + 2):
                j = i + length - 1
                dp[i][j] = float('inf')
                for k in range(i, j):
                    cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]
                    dp[i][j] = min(dp[i][j], cost)
        return dp[1][n]

    def matrixChainOrder(self, arr):
        n = len(arr) - 1
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        split = [[0] * (n + 1) for _ in range(n + 1)]
        for length in range(2, n + 1):
            for i in range(1, n - length + 2):
                j = i + length - 1
                dp[i][j] = float('inf')
                for k in range(i, j):
                    cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]
                    if cost < dp[i][j]:
                        dp[i][j] = cost
                        split[i][j] = k

        def build_string(i, j):
            if i == j:
                return f"M{i}"
            k = split[i][j]
            return f"({build_string(i, k)} x {build_string(k+1, j)})"

        return build_string(1, n)


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    arr1 = [40, 20, 30, 10, 30]
    print(f"Matrix dimensions: {arr1}")
    print(f"Minimum operations: {sol.matrixChainMultiplication(arr1)}")
    print(f"Parenthesization: {sol.matrixChainOrder(arr1)}")
    print(f"\nTest Case 2:")
    arr2 = [10, 20, 30]
    print(f"Matrix dimensions: {arr2}")
    print(f"Minimum operations: {sol.matrixChainMultiplication(arr2)}")
    print(f"\nTest Case 3:")
    arr3 = [10, 20, 30, 40, 30]
    print(f"Matrix dimensions: {arr3}")
    print(f"Minimum operations: {sol.matrixChainMultiplication(arr3)}")
    print(f"\nTest Case 4:")
    arr4 = [5, 10, 3, 12, 5, 50, 6]
    print(f"Matrix dimensions: {arr4}")
    print(f"Minimum operations: {sol.matrixChainMultiplication(arr4)}")
