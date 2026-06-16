/*
PROBLEM: Kth Smallest Number in Multiplication Table
Difficulty: Hard
Pattern: Binary Search on Value Range

DESCRIPTION:
Nearly everyone has used the Multiplication Table. The multiplication table of size m x n 
is an integer matrix mat where mat[i][j] == i * j (1-indexed).
Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

EXPLANATION:
Binary search on value:
- Min value = 1, Max value = m * n
- For each mid, count how many numbers <= mid in table
- Each row i has min(mid / i, n) numbers <= mid
- Find smallest value with at least k numbers <= it

Time Complexity: O(m * log(m * n))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: Table: [[1,2,3],[2,4,6],[3,6,9]], 5th smallest is 3

Example 2:
Input: m = 2, n = 3, k = 6
Output: 6
Explanation: Table: [[1,2,3],[2,4,6]], 6th smallest is 6

Example 3:
Input: m = 3, n = 3, k = 9
Output: 9
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (countLessEqual(m, n, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    int countLessEqual(int m, int n, int target) {
        int count = 0;
        
        for (int i = 1; i <= m; i++) {
            count += min(target / i, n);
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    cout << "Test 1: " << solution.findKthNumber(3, 3, 5) << endl;
    
    // Test Case 2
    cout << "Test 2: " << solution.findKthNumber(2, 3, 6) << endl;
    
    // Test Case 3
    cout << "Test 3: " << solution.findKthNumber(3, 3, 9) << endl;
    
    return 0;
}
