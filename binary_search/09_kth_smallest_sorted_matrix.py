"""
PROBLEM: Kth Smallest Element in a Sorted Matrix
Difficulty: Medium
Pattern: Binary Search on Value Range

DESCRIPTION:
Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

EXPLANATION:
Binary search on value range:
- Search space: [matrix[0][0], matrix[n-1][n-1]]
- For each mid, count elements <= mid
- If count >= k, answer is <= mid, search left
- Otherwise, search right

Time Complexity: O(n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: Elements are [1,5,9,10,11,12,13,13,15], 8th is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Example 3:
Input: matrix = [[1,2],[1,3]], k = 2
Output: 1
"""

from typing import List, Optional


def count_less_equal(matrix, mid):
    n = len(matrix)
    count = 0
    row, col = n - 1, 0
    while row >= 0 and col < n:
        if matrix[row][col] <= mid:
            count += row + 1
            col += 1
        else:
            row -= 1
    return count


class Solution:
    def kthSmallest(self, matrix, k):
        n = len(matrix)
        left = matrix[0][0]
        right = matrix[n - 1][n - 1]
        while left < right:
            mid = left + (right - left) // 2
            count = count_less_equal(matrix, mid)
            if count < k:
                left = mid + 1
            else:
                right = mid
        return left


if __name__ == "__main__":
    solution = Solution()
    matrix1 = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
    print(f"Test 1: {solution.kthSmallest(matrix1, 8)}")
    matrix2 = [[-5]]
    print(f"Test 2: {solution.kthSmallest(matrix2, 1)}")
    matrix3 = [[1, 2], [1, 3]]
    print(f"Test 3: {solution.kthSmallest(matrix3, 2)}")
