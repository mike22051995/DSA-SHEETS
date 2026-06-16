/*
================================================================================
PROBLEM: Kth Smallest Element in a Sorted Matrix (LeetCode #378)
DIFFICULTY: Medium
PATTERN: Heap / Binary Search
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
DESCRIPTION:
Given an n x n matrix where rows and columns are sorted, return the k-th
smallest element.

INPUT FORMAT:
- matrix: n x n sorted rows and columns
- k: 1-based index

OUTPUT FORMAT:
- integer value of the k-th smallest element

APPROACH:
- Heap: keep a max-heap of size k while scanning all elements.
- Binary search: count numbers <= mid using a staircase walk.

CODE EXPLANATION:
- kthSmallest uses a max-heap to retain the k smallest values seen so far.
- kthSmallestBS binary searches on value range and counts <= mid per row/col.

COMPLEXITY:
- Heap: O(n^2 log k) time, O(k) space
- Binary search: O(n log range) time, O(1) space

SAMPLE INPUT/OUTPUT:
1) matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8 -> 13
2) matrix = [[-5]], k = 1 -> -5
3) matrix = [[1,2],[1,3]], k = 2 -> 1
4) matrix = [[1,3,5],[6,7,12],[11,14,14]], k = 6 -> 11
5) matrix = [[1,2,3],[2,3,4],[3,4,5]], k = 5 -> 3
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Min Heap approach
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> maxHeap;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxHeap.push(matrix[i][j]);
                
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }
        
        return maxHeap.top();
    }
    
    // Binary Search approach
    int kthSmallestBS(vector<vector<int>>& matrix, int k) {
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
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    
    cout << "8th smallest: " << sol.kthSmallest(matrix, 8) << endl;
    cout << "Using BS: " << sol.kthSmallestBS(matrix, 8) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Kth Largest Element in Array (LeetCode #215)
2. Find K Pairs with Smallest Sums (LeetCode #373)
3. Kth Smallest in Multiplication Table (LeetCode #668)
4. Find K-th Smallest Pair Distance (LeetCode #719)
5. Kth Smallest Prime Fraction (LeetCode #786)
6. K-th Smallest Instructions (LeetCode #1643)
7. Kth Largest Element in Stream (LeetCode #703)
8. Find Median from Data Stream (LeetCode #295)
9. Ugly Number II (LeetCode #264)
10. Super Ugly Number (LeetCode #313)
*/
