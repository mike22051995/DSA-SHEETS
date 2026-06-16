/*
PROBLEM: Beautiful Arrangement
---------------------------------------------------------------------------
Suppose you have n integers labeled 1 through n. A permutation of those n 
integers is considered beautiful if for every i (1 <= i <= n), either:
- perm[i] is divisible by i, or
- i is divisible by perm[i]
Given an integer n, return the number of beautiful arrangements.

DIFFICULTY: Medium
PATTERN: Backtracking (Constraint-based Permutation)
TIME COMPLEXITY: O(k) where k is number of valid permutations (< n!)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 2
Output: 2
Explanation: [1,2] and [2,1] are both beautiful

Example 2:
Input: n = 3
Output: 3
Explanation: [1,2,3], [2,1,3], [3,2,1] are beautiful
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        return backtrack(n, 1, visited);
    }
    
private:
    int backtrack(int n, int pos, vector<bool>& visited) {
        // Base case: placed all numbers
        if (pos > n) {
            return 1;
        }
        
        int count = 0;
        
        // Try each unvisited number at current position
        for (int num = 1; num <= n; num++) {
            if (!visited[num] && (num % pos == 0 || pos % num == 0)) {
                visited[num] = true;                    // choose
                count += backtrack(n, pos + 1, visited); // explore
                visited[num] = false;                   // unchoose
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 2;
    cout << "Test 1: Beautiful arrangements for n=" << n1 << " = " 
         << sol.countArrangement(n1) << endl;
    
    // Test case 2
    int n2 = 3;
    cout << "Test 2: Beautiful arrangements for n=" << n2 << " = " 
         << sol.countArrangement(n2) << endl;
    
    return 0;
}
