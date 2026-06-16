/*
PROBLEM: Two Sum Less Than K
---------------------------------------------------------------------------
Given an array nums of integers and integer k, return the maximum sum such 
that there exists i < j with nums[i] + nums[j] = sum and sum < k. 
If no i, j exist satisfying this equation, return -1.

PATTERN: Sorting + Opposite Direction Two Pointers
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

Example 2:
Input: nums = [10,20,30], k = 15
Output: -1
Explanation: No two elements sum to a value less than 15.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        int maxSum = -1;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum < k) {
                maxSum = max(maxSum, sum);
                left++;
            } else {
                right--;
            }
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {34, 23, 1, 24, 75, 33, 54, 8};
    int k1 = 60;
    cout << "Test 1: " << sol.twoSumLessThanK(nums1, k1) << endl;
    
    // Test case 2
    vector<int> nums2 = {10, 20, 30};
    int k2 = 15;
    cout << "Test 2: " << sol.twoSumLessThanK(nums2, k2) << endl;
    
    return 0;
}
