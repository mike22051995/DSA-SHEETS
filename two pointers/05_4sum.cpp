/*
PROBLEM: 4Sum
---------------------------------------------------------------------------
Given an array nums of n integers, return an array of all unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

PATTERN: Sorting + Nested Two Pointers
TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(1) excluding output

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
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
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) left++;
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

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    cout << "Test 1: ";
    for (auto& quad : result1) {
        cout << "[" << quad[0] << "," << quad[1] << "," << quad[2] << "," << quad[3] << "] ";
    }
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    vector<vector<int>> result2 = sol.fourSum(nums2, target2);
    cout << "Test 2: ";
    for (auto& quad : result2) {
        cout << "[" << quad[0] << "," << quad[1] << "," << quad[2] << "," << quad[3] << "] ";
    }
    cout << endl;
    
    return 0;
}
