/*
================================================================================
PROBLEM: Combination Sum (LeetCode #39)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        if (target < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    auto result = sol.combinationSum(candidates, 7);
    
    cout << "Combinations for target 7:" << endl;
    for (auto& combo : result) {
        cout << "[";
        for (int i = 0; i < combo.size(); i++) {
            cout << combo[i];
            if (i < combo.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Combination Sum II (LeetCode #40) - No duplicates
2. Combination Sum III (LeetCode #216) - k numbers
3. Combination Sum IV (LeetCode #377) - Count ways (DP)
4. Factor Combinations (LeetCode #254)
5. Subsets (LeetCode #78)
6. Permutations (LeetCode #46)
7. Combinations (LeetCode #77)
8. Letter Combinations (LeetCode #17)
9. Generate Parentheses (LeetCode #22)
10. Partition to K Equal Sum Subsets (LeetCode #698)
*/
