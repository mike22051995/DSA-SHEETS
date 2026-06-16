/*
PROBLEM: Maximum Product Subarray
Difficulty: Medium
Pattern: 1D DP, Product Optimization

DESCRIPTION:
Given an integer array nums, find a contiguous non-empty subarray within the array that has 
the largest product, and return the product.

INPUT:
nums = [2, 3, -2, 4]

OUTPUT:
6
Explanation: [2, 3] has the largest product 6.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // Track both max and min product ending at current position
        // (min can become max when multiplied by negative number)
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            // If current number is negative, swap max and min
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            
            // Calculate max and min product ending at current position
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            
            // Update overall result
            result = max(result, maxProd);
        }
        
        return result;
    }
    
    // Alternative: More explicit approach
    int maxProductAlternate(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            int temp = maxSoFar;
            
            // Max can be: current element, max*current, or min*current (if negative)
            maxSoFar = max({nums[i], maxSoFar * nums[i], minSoFar * nums[i]});
            
            // Min can be: current element, max*current (old), or min*current
            minSoFar = min({nums[i], temp * nums[i], minSoFar * nums[i]});
            
            result = max(result, maxSoFar);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Input: nums = [2, 3, -2, 4]" << endl;
    cout << "Output: " << sol.maxProduct(nums1) << endl;
    cout << "Output (Alternate): " << sol.maxProductAlternate(nums1) << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {-2, 0, -1};
    cout << "Input: nums = [-2, 0, -1]" << endl;
    cout << "Output: " << sol.maxProduct(nums2) << endl;
    cout << "Output (Alternate): " << sol.maxProductAlternate(nums2) << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {-2, 3, -4};
    cout << "Input: nums = [-2, 3, -4]" << endl;
    cout << "Output: " << sol.maxProduct(nums3) << endl;
    cout << "Output (Alternate): " << sol.maxProductAlternate(nums3) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Similar to Maximum Subarray but with product instead of sum
2. Key insight: Need to track BOTH max and min products
   - Negative number * min product can become max product
   - Zero resets the product
3. At each position:
   - maxProd = max(nums[i], maxProd * nums[i], minProd * nums[i])
   - minProd = min(nums[i], maxProd * nums[i], minProd * nums[i])
4. When current number is negative, max and min swap roles
5. Track overall maximum across all positions

Example: nums = [2, 3, -2, 4]
i=0: max=2, min=2, result=2
i=1: max=6, min=3, result=6
i=2: max=-2, min=-12, result=6
i=3: max=4, min=-48, result=6

KEY LEARNING:
- Track both maximum and minimum (negative numbers change sign)
- Product of negative * negative = positive
- Zero breaks the chain, restart from next element
- Variant of Kadane's algorithm for products
*/
