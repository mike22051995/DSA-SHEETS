/*
PROBLEM: Maximum Product Subarray
Difficulty: Medium/Hard
Pattern: Dynamic Programming

DESCRIPTION:
Given an integer array nums, find a contiguous non-empty subarray within the array that has 
the largest product, and return the product.

EXPLANATION:
Track both maximum and minimum products ending at current position:
- Negative number can make minimum become maximum
- At each position, max product can be: num itself, max*num, or min*num
- Similarly for min product
- Track global maximum

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: Subarray [2,3] has product = 6

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: Result cannot be negative, so 0

Example 3:
Input: nums = [-2,3,-4]
Output: 24
Explanation: Subarray [-2,3,-4] has product = 24
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // If current is negative, swap max and min
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            
            // Update max and min products
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            
            // Update result
            result = max(result, maxProd);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Test 1: " << solution.maxProduct(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {-2, 0, -1};
    cout << "Test 2: " << solution.maxProduct(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {-2, 3, -4};
    cout << "Test 3: " << solution.maxProduct(nums3) << endl;
    
    return 0;
}
