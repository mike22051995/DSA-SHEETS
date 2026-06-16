/*
================================================================================
PROBLEM: Combination Sum II (LeetCode #40)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            
            if (candidates[i] > target) {
                break; // Remaining candidates are too large
            }
            
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    
    cout << "Combination Sum II:" << endl;
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
1. Combination Sum (LeetCode #39)
2. Combination Sum III (LeetCode #216)
3. Combination Sum IV (LeetCode #377)
4. Subsets (LeetCode #78)
5. Subsets II (LeetCode #90)
6. Permutations (LeetCode #46)
7. Permutations II (LeetCode #47)
8. Combinations (LeetCode #77)
9. Factor Combinations (LeetCode #254)
10. Target Sum (LeetCode #494)
*/
