/*
================================================================================
PROBLEM: Combinations (LeetCode #77)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(n, k, 1, current, result);
        
        return result;
    }
    
    void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(n, k, i + 1, current, result);
            current.pop_back();
        }
    }
    
    // Optimized with pruning
    void backtrackOptimized(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Pruning: no need to continue if remaining numbers are not enough
        int remaining = k - current.size();
        
        for (int i = start; i <= n - remaining + 1; i++) {
            current.push_back(i);
            backtrackOptimized(n, k, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> result = sol.combine(4, 2);
    
    cout << "Combinations of 4 choose 2:" << endl;
    for (auto& combo : result) {
        cout << "[";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Permutations (LeetCode #46)
2. Subsets (LeetCode #78)
3. Combination Sum (LeetCode #39)
4. Combination Sum II (LeetCode #40)
5. Combination Sum III (LeetCode #216)
6. Letter Combinations (LeetCode #17)
7. Generate Parentheses (LeetCode #22)
8. Permutation Sequence (LeetCode #60)
9. Factor Combinations (LeetCode #254)
10. Iterator for Combination (LeetCode #1286)
*/
