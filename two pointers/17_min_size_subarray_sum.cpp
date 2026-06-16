/*
PROBLEM: Minimum Size Subarray Sum
---------------------------------------------------------------------------
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal 
to target. If there is no such subarray, return 0.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: Subarray [4,3] has minimal length with sum >= 7.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1
Explanation: Subarray [4] has minimal length with sum >= 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            
            // Shrink window while sum >= target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Test 1: " << sol.minSubArrayLen(target1, nums1) << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    cout << "Test 2: " << sol.minSubArrayLen(target2, nums2) << endl;
    
    return 0;
}
