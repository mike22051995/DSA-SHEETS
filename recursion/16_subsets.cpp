/*
PROBLEM: Subsets (Power Set)
---------------------------------------------------------------------------
Given an integer array nums of unique elements, return all possible subsets.
The solution set must not contain duplicate subsets.

DIFFICULTY: Medium
PATTERN: Backtracking (Include/Exclude)
TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current,
                   vector<vector<int>>& result) {
        // Base case: add current subset
        if (index >= nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Exclude current element
        backtrack(nums, index + 1, current, result);
        
        // Include current element
        current.push_back(nums[index]);
        backtrack(nums, index + 1, current, result);
        current.pop_back(); // backtrack
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = sol.subsets(nums1);
    cout << "Test 1: [";
    for (auto& subset : result1) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << (i < subset.size() - 1 ? "," : "");
        }
        cout << "]";
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = sol.subsets(nums2);
    cout << "Test 2: Total subsets = " << result2.size() << endl;
    
    return 0;
}
