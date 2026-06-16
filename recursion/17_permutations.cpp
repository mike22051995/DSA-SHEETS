/*
PROBLEM: Permutations
---------------------------------------------------------------------------
Given an array nums of distinct integers, return all possible permutations.

DIFFICULTY: Medium
PATTERN: Backtracking (Swap-based)
TIME COMPLEXITY: O(n * n!)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: reached end
        if (start >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Try each element at current position
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);         // choose
            backtrack(nums, start + 1, result); // explore
            swap(nums[start], nums[i]);         // unchoose (backtrack)
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = sol.permute(nums1);
    cout << "Test 1: Total permutations = " << result1.size() << endl;
    cout << "Permutations: ";
    for (auto& perm : result1) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i] << (i < perm.size() - 1 ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> result2 = sol.permute(nums2);
    cout << "Test 2: Total permutations = " << result2.size() << endl;
    
    return 0;
}
