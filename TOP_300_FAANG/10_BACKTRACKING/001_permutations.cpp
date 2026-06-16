/*
================================================================================
PROBLEM: Permutations (LeetCode #46)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& used, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            current.push_back(nums[i]);
            used[i] = true;
            
            backtrack(nums, used, current, result);
            
            current.pop_back();
            used[i] = false;
        }
    }
    
    // Alternative: Swap approach
    vector<vector<int>> permuteSwap(vector<int>& nums) {
        vector<vector<int>> result;
        backtrackSwap(nums, 0, result);
        return result;
    }
    
    void backtrackSwap(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrackSwap(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    auto result = sol.permute(nums);
    
    cout << "Permutations:" << endl;
    for (auto& perm : result) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Permutations II (LeetCode #47) - With duplicates
2. Next Permutation (LeetCode #31)
3. Permutation Sequence (LeetCode #60)
4. Letter Case Permutation (LeetCode #784)
5. Subsets (LeetCode #78)
6. Subsets II (LeetCode #90)
7. Combination Sum (LeetCode #39)
8. Combinations (LeetCode #77)
9. Generate Parentheses (LeetCode #22)
10. Letter Combinations of Phone Number (LeetCode #17)
*/
