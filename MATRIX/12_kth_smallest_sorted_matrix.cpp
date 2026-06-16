/*
PROBLEM: Kth Smallest Element in Sorted Matrix (LeetCode 378)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Binary Search / Min Heap

DESCRIPTION:
Given an n x n matrix where each row and column is sorted in ascending order,
find the kth smallest element in the matrix.

MATRIX DIAGRAM:
  Matrix:              Sorted elements:
  1   5   9            1  2  3  5  6  7  9  10  13
  10  11  13    -->    ↑     ↑
  12  13  15           1st   3rd (k=3, answer=3)
  
  Properties:
  - Each row sorted: matrix[i][j] ≤ matrix[i][j+1]
  - Each column sorted: matrix[i][j] ≤ matrix[i+1][j]
  - Top-left smallest, bottom-right largest

APPROACH:
Method 1: Min Heap (Priority Queue)
1. Push all elements from first row into min heap
2. Pop k-1 times
3. For each pop, push element below it (if exists)
4. The kth pop is the answer
Time: O(k * log n), Space: O(n)

Method 2: Binary Search on Value Range
1. Search space: [matrix[0][0], matrix[n-1][n-1]]
2. For each mid value, count elements ≤ mid
3. If count < k, search right half
4. If count ≥ k, search left half
Time: O(n * log(max-min)), Space: O(1)

TIME COMPLEXITY: O(k * log n) or O(n * log(max-min))
SPACE COMPLEXITY: O(n) or O(1)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Method 1: Min Heap
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // Min heap: {value, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Push first element of each row
        for (int r = 0; r < min(n, k); r++) {
            minHeap.push({matrix[r][0], r, 0});
        }
        
        int result = 0;
        
        // Pop k times
        for (int i = 0; i < k; i++) {
            auto curr = minHeap.top();
            minHeap.pop();
            result = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            // Push next element in same row
            if (c + 1 < n) {
                minHeap.push({matrix[r][c + 1], r, c + 1});
            }
        }
        
        return result;
    }
    
    // Method 2: Binary Search on Value
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1;
        int col = 0;
        
        // Start from bottom-left
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;  // All elements in this column up to row
                col++;
            } else {
                row--;
            }
        }
        
        return count;
    }
    
    int kthSmallestBinarySearch(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countLessEqual(matrix, mid);
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    
    int k = 8;
    cout << k << "th smallest element: " << sol.kthSmallest(matrix, k) << endl;
    cout << k << "th smallest element (BS): " << sol.kthSmallestBinarySearch(matrix, k) << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[1,5,9],
          [10,11,13],
          [12,13,15]]
k = 8

OUTPUT:
13

EXPLANATION:
Sorted order: [1,5,9,10,11,12,13,13,15]
Position:      1 2 3  4  5  6  7  8  9
8th smallest element is 13

For k = 1: Answer = 1 (top-left)
For k = 9: Answer = 15 (bottom-right)
For k = 4: Answer = 10

Binary Search Approach:
Range: [1, 15]
Mid = 8: Count(≤8) = 2 → too small, search [9,15]
Mid = 12: Count(≤12) = 6 → too small, search [13,15]
Mid = 13: Count(≤13) = 8 → found!
*/
