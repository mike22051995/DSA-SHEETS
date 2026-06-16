/*
================================================================================
PROBLEM: Kth Smallest Element in Sorted Matrix (LeetCode #378)
DIFFICULTY: Medium
PATTERN: Binary Search / Heap
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given an n x n matrix where each of the rows and columns is sorted in
ascending order, return the kth smallest element in the matrix.

EXAMPLES:

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

PATTERN RECOGNITION:
Use this pattern when:
- Matrix with sorted rows and columns
- Binary search on value range
- Count elements less than or equal to mid

CODE EXPLANATION:
- Binary search the value range from min to max in the matrix.
- For a candidate mid, count how many elements are <= mid using row/col scan.
- If count >= k, tighten right; otherwise move left up.
TIME COMPLEXITY: O(n log R), R = value range
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Binary search approach
    int kthSmallest(vector<vector<int>>& matrix, int k) {
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
    
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1;
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        
        return count;
    }
    
    // Min heap approach
    int kthSmallestHeap(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Add first element of each row
        for (int i = 0; i < min(n, k); i++) {
            pq.push({matrix[i][0], i, 0});
        }
        
        int result = 0;
        
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            
            result = top[0];
            int row = top[1];
            int col = top[2];
            
            if (col + 1 < n) {
                pq.push({matrix[row][col+1], row, col+1});
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    
    cout << "8th smallest: " << sol.kthSmallest(matrix, 8) << endl;
    cout << "4th smallest: " << sol.kthSmallest(matrix, 4) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n * log(max-min)) for binary search, O(k log n) for heap
SPACE COMPLEXITY: O(1) for binary search, O(n) for heap

SIMILAR PROBLEMS:
1. Kth Largest Element (LeetCode #215)
2. Find K Pairs with Smallest Sums (LeetCode #373)
3. Kth Smallest in Multiplication Table (LeetCode #668)
4. Find K-th Smallest Pair Distance (LeetCode #719)
5. Kth Smallest Product (LeetCode #2040)
6. Search 2D Matrix II (LeetCode #240)
7. Merge k Sorted Lists (LeetCode #23)
8. Ugly Number II (LeetCode #264)
9. Super Ugly Number (LeetCode #313)
10. Median of Two Sorted Arrays (LeetCode #4)
*/
