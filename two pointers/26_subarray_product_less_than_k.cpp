/*
PROBLEM: Subarray Product Less Than K
---------------------------------------------------------------------------
Given an array of integers nums and an integer k, return the number of 
contiguous subarrays where the product of all the elements in the subarray 
is strictly less than k.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: [10],[5],[2],[6],[10,5],[5,2],[2,6],[5,2,6]

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
Explanation: No subarray has product < 0.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int left = 0;
        int product = 1;
        int count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            // Shrink window while product >= k
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            
            // All subarrays ending at right with valid products
            count += right - left + 1;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << "Test 1: " << sol.numSubarrayProductLessThanK(nums1, k1) << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << "Test 2: " << sol.numSubarrayProductLessThanK(nums2, k2) << endl;
    
    return 0;
}
