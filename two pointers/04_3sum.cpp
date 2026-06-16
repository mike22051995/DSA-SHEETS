/*
PROBLEM: 3Sum
---------------------------------------------------------------------------
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
The solution set must not contain duplicate triplets.

PATTERN: Sorting + Opposite Direction Two Pointers
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1) excluding output

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum to 0.
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

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    cout << "Test 1: ";
    for (auto& triplet : result1) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "] ";
    }
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = sol.threeSum(nums2);
    cout << "Test 2: ";
    if (result2.empty()) cout << "[]";
    cout << endl;
    
    return 0;
}
