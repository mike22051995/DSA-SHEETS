/*
================================================================================
PROBLEM: Subsets II (LeetCode #90)
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current, result);
        
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,2};
    
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    
    cout << "Subsets with duplicates:" << endl;
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
1. Subsets (LeetCode #78)
2. Combination Sum (LeetCode #39)
3. Combination Sum II (LeetCode #40)
4. Permutations (LeetCode #46)
5. Permutations II (LeetCode #47)
6. Increasing Subsequences (LeetCode #491)
7. Find Unique Binary String (LeetCode #1980)
8. Maximum Length of Concatenated String (LeetCode #1239)
9. Find All Good Strings (LeetCode #1397)
10. Count Number of Maximum Bitwise-OR Subsets (LeetCode #2044)
*/
