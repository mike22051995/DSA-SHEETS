/*
PROBLEM: 4Sum
Difficulty: Medium/Hard
Pattern: Two Pointers, Sorting

DESCRIPTION:
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

EXPLANATION:
Extension of 3Sum:
1. Sort the array
2. Fix two elements using nested loops
3. Use two pointers for remaining two elements
4. Skip duplicates at all levels

Time Complexity: O(n³)
Space Complexity: O(1) excluding output

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation: All unique quadruplets summing to 0

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
Explanation: Only one unique quadruplet

Example 3:
Input: nums = [1,2,3,4], target = 10
Output: [[1,2,3,4]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for third element
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for fourth element
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
        }
        
        return result;
    }
};

void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result1 = solution.fourSum(nums1, 0);
    cout << "Test 1: ";
    printResult(result1);
    
    // Test Case 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    vector<vector<int>> result2 = solution.fourSum(nums2, 8);
    cout << "Test 2: ";
    printResult(result2);
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4};
    vector<vector<int>> result3 = solution.fourSum(nums3, 10);
    cout << "Test 3: ";
    printResult(result3);
    
    return 0;
}
