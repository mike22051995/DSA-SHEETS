/*
PROBLEM: Combination Sum
---------------------------------------------------------------------------
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations where the chosen numbers sum to 
target. The same number may be chosen from candidates an unlimited number 
of times.

DIFFICULTY: Medium
PATTERN: Backtracking (Unbounded Knapsack)
TIME COMPLEXITY: O(n^(target/min))
SPACE COMPLEXITY: O(target/min) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
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
    
private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: found valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: exceeded target
        if (target < 0) {
            return;
        }
        
        // Try each candidate from start
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);                          // choose
            backtrack(candidates, target - candidates[i], i, current, result); // explore (i not i+1 for reuse)
            current.pop_back();                                        // unchoose
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = sol.combinationSum(candidates1, target1);
    cout << "Test 1: [";
    for (auto& comb : result1) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i] << (i < comb.size() - 1 ? "," : "");
        }
        cout << "] ";
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = sol.combinationSum(candidates2, target2);
    cout << "Test 2: Total combinations = " << result2.size() << endl;
    
    return 0;
}
