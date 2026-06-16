/*
================================================================================
PROBLEM: Subsets (LeetCode #78)
DIFFICULTY: Medium
PATTERN: Backtracking / Bit Manipulation
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Backtracking Approach
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
    
    // Bit Manipulation
    vector<vector<int>> subsetsBitMask(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n
        
        for (int mask = 0; mask < totalSubsets; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    auto result = sol.subsets(nums);
    
    cout << "Subsets:" << endl;
    for (auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Subsets II (LeetCode #90) - With duplicates
2. Permutations (LeetCode #46)
3. Combination Sum (LeetCode #39)
4. Combinations (LeetCode #77)
5. Generate Parentheses (LeetCode #22)
6. Letter Combinations (LeetCode #17)
7. Palindrome Partitioning (LeetCode #131)
8. Word Search (LeetCode #79)
9. N-Queens (LeetCode #51)
10. Sudoku Solver (LeetCode #37)
*/
