/*
================================================================================
PROBLEM: Maximum Product Subarray (LeetCode #152)
DIFFICULTY: Medium
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            
            result = max(result, maxProd);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,-2,4};
    vector<int> nums2 = {-2,0,-1};
    
    cout << "Max product [2,3,-2,4]: " << sol.maxProduct(nums1) << endl;
    cout << "Max product [-2,0,-1]: " << sol.maxProduct(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximum Subarray (LeetCode #53)
2. Maximum Sum Circular Subarray (LeetCode #918)
3. Maximum Product of Three Numbers (LeetCode #628)
4. Subarray Product Less Than K (LeetCode #713)
5. Sign of Product of Array (LeetCode #1822)
6. Count Number of Nice Subarrays (LeetCode #1248)
7. K Concatenation Maximum Sum (LeetCode #1191)
8. Best Time to Buy and Sell Stock (LeetCode #121)
9. House Robber (LeetCode #198)
10. Paint House (LeetCode #256)
*/
