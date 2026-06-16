/*
PROBLEM: 3Sum
Difficulty: Medium
Pattern: Two Pointers, Sorting

DESCRIPTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

EXPLANATION:
1. Sort the array first
2. Fix one element and use two pointers for the remaining two elements
3. Skip duplicates to avoid duplicate triplets
4. If sum is 0, add to result and move both pointers

Time Complexity: O(n²)
Space Complexity: O(1) excluding output array

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: nums[0] + nums[1] + nums[2] = -1 + 0 + 1 = 0

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum to 0

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only triplet sums to 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});  
                    
                    // Skip duplicates for second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "," << result[i][2] << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution.threeSum(nums1);
    cout << "Test 1: ";
    printResult(result1);
    
    // Test Case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "Test 2: ";
    printResult(result2);
    
    // Test Case 3
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "Test 3: ";
    printResult(result3);
    
    return 0;
}
