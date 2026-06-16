/*
PROBLEM: 3Sum Closest
---------------------------------------------------------------------------
Given an integer array nums of length n and an integer target, find three 
integers in nums such that the sum is closest to target. Return the sum 
of the three integers.

PATTERN: Sorting + Two Pointers
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum closest to target is 2 (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum closest to 1 is 0 (0 + 0 + 0 = 0).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return sum; // Exact match
                }
            }
        }
        
        return closestSum;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Test 1: " << sol.threeSumClosest(nums1, target1) << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Test 2: " << sol.threeSumClosest(nums2, target2) << endl;
    
    return 0;
}
