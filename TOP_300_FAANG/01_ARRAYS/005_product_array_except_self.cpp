/*
================================================================================
PROBLEM: Product of Array Except Self (LeetCode #238)
DIFFICULTY: Medium
PATTERN: Prefix/Suffix Product Array
COMPANIES: Amazon, Microsoft, Facebook, Apple, Google, Adobe
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums, return an array answer such that answer[i] is 
equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Need to calculate value using all elements except current
2. Cannot use division
3. Need O(n) solution for array transformation
4. Prefix/suffix preprocessing helps

Key Indicators:
- "Except self" or "excluding current element"
- Product/sum of all other elements
- Two-pass solutions acceptable
- Space-time trade-off considerations

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation: 
- answer[0] = 2*3*4 = 24
- answer[1] = 1*3*4 = 12
- answer[2] = 1*2*4 = 8
- answer[3] = 1*2*3 = 6

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
Explanation:
- answer[0] = 1*0*(-3)*3 = 0
- answer[1] = (-1)*0*(-3)*3 = 0
- answer[2] = (-1)*1*(-3)*3 = 9
- answer[3] = (-1)*1*0*3 = 0
- answer[4] = (-1)*1*0*(-3) = 0

Example 3:
Input: nums = [2,3,4,5]
Output: [60,40,30,24]

================================================================================
EXPLANATION:

Approach 1 - Prefix and Suffix Products (Optimal O(1) space):
For each index i:
- leftProduct[i] = product of all elements to the left of i
- rightProduct[i] = product of all elements to the right of i
- answer[i] = leftProduct[i] * rightProduct[i]

We can optimize space by using the output array itself.

Algorithm:
1. First pass (left to right):
   - Build prefix products in result array
2. Second pass (right to left):
   - Multiply with suffix products

Time Complexity: O(n)
Space Complexity: O(1) excluding output array

================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Optimal Solution - O(1) extra space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Build prefix products in result array
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        // Multiply with suffix products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
    
    // Using explicit prefix and suffix arrays (for understanding)
    vector<int> productExceptSelfVerbose(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> result(n);
        
        // Build left products
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        // Build right products
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        
        // Combine
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }
        
        return result;
    }
    
    // If division was allowed (not accepted by problem)
    vector<int> productExceptSelfDivision(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // Count zeros and calculate product of non-zero elements
        int zeroCount = 0;
        int product = 1;
        
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                product *= num;
            }
        }
        
        // Handle different cases
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1) {
                result[i] = 0;
            } else if (zeroCount == 1) {
                result[i] = (nums[i] == 0) ? product : 0;
            } else {
                result[i] = product / nums[i];
            }
        }
        
        return result;
    }
};

void runTest(vector<int> nums, string testName) {
    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);
    
    cout << testName << ": " << endl;
    cout << "Input:  [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    runTest(nums1, "Test 1");
    
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    runTest(nums2, "Test 2");
    
    vector<int> nums3 = {2, 3, 4, 5};
    runTest(nums3, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Trapping Rain Water (LeetCode #42) - Hard
   - Use prefix max and suffix max arrays

2. Maximum Product Subarray (LeetCode #152) - Medium
   - Track prefix and suffix products

3. Range Product Queries of Powers (LeetCode #2438) - Medium
   - Prefix product with power calculations

4. Minimum Time to Make Array Sum At Most x (LeetCode #2809) - Hard
   - Prefix/suffix optimization

5. Container With Most Water (LeetCode #11) - Medium
   - Two pointer with prefix/suffix logic

6. Best Time to Buy and Sell Stock III (LeetCode #123) - Hard
   - Forward and backward passes

7. Paint House II (LeetCode #265) - Hard
   - Track min excluding current

8. Candy (LeetCode #135) - Hard
   - Left to right, then right to left passes

9. Daily Temperatures (LeetCode #739) - Medium
   - Monotonic stack (related pattern)

10. Maximum Width Ramp (LeetCode #962) - Medium
    - Use suffix maximum array

================================================================================
KEY INSIGHTS:
================================================================================

1. Why Prefix/Suffix Works:
   - Product at i = (product of left) × (product of right)
   - Avoids nested loops
   - Natural two-pass approach

2. Space Optimization:
   - Don't need separate left/right arrays
   - Use output array to store left products
   - Calculate right products on the fly

3. Edge Cases:
   - Array with zeros (handle carefully)
   - Negative numbers (product stays correct)
   - Single element (return [1])
   - Two elements

4. Why Division Approach Fails:
   - Problem explicitly forbids it
   - Doesn't handle zeros elegantly
   - Less efficient for multiple zeros

5. Interview Tips:
   - Start with brute force O(n²) explanation
   - Move to division approach (mention not allowed)
   - Explain prefix/suffix concept
   - Show space optimization

================================================================================
*/
