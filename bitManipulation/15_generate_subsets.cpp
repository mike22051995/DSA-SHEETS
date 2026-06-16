/*
PROBLEM: Generate All Subsets (Power Set)
===========================================
Given a set of distinct integers, return all possible subsets (power set).

APPROACH:
- Use bit manipulation to generate all subsets
- For n elements, there are 2^n subsets
- Each subset corresponds to a binary number from 0 to 2^n-1
- If ith bit is set, include ith element in subset

PATTERN: Subset Generation using Binary Representation

INPUT/OUTPUT:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Explanation: All possible subsets

Input: nums = [0]
Output: [[],[0]]

TIME COMPLEXITY: O(n * 2^n) - n for each subset creation
SPACE COMPLEXITY: O(n * 2^n) - for output
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n subsets
        
        // Generate all subsets from 0 to 2^n-1
        for (int mask = 0; mask < totalSubsets; mask++) {
            vector<int> subset;
            // Check each bit
            for (int i = 0; i < n; i++) {
                // If ith bit is set, include nums[i]
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        
        return result;
    }
};

void printSubsets(vector<vector<int>>& subsets) {
    cout << "[";
    for (int i = 0; i < subsets.size(); i++) {
        cout << "[";
        for (int j = 0; j < subsets[i].size(); j++) {
            cout << subsets[i][j];
            if (j < subsets[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < subsets.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Input: [1,2,3]" << endl;
    cout << "Output: ";
    vector<vector<int>> result1 = sol.subsets(nums1);
    printSubsets(result1);
    cout << "Total subsets: " << result1.size() << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0};
    cout << "Input: [0]" << endl;
    cout << "Output: ";
    vector<vector<int>> result2 = sol.subsets(nums2);
    printSubsets(result2);
    cout << "Total subsets: " << result2.size() << endl;
    
    return 0;
}
