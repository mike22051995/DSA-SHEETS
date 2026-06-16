/*
PROBLEM: Maximum Subarray (Kadane's Algorithm) (LeetCode 53)
DIFFICULTY: Easy
PATTERN: Running Sum with Reset Strategy

DESCRIPTION:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

INPUT:
- nums: array of integers

OUTPUT:
- Maximum sum of contiguous subarray

APPROACH (Kadane's Algorithm):
1. Keep track of current sum and maximum sum
2. At each element, decide: extend current subarray or start fresh from current element
3. Greedy choice: if current sum becomes negative, reset it (start new subarray)

WHY GREEDY WORKS:
If sum of elements up to index i is negative, including them can only decrease 
the sum of any subarray starting after i. So we greedily discard them.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;
        
        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            
            // Greedy reset: if sum becomes negative, start fresh
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
    
    // Alternative formulation (more intuitive)
    int maxSubArrayAlt(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Either extend existing subarray or start new one
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1 - Array: [-2,1,-3,4,-1,2,1,-5,4]" << endl;
    cout << "Output: " << sol.maxSubArray(nums1) << endl;
    cout << "Expected: 6 (subarray [4,-1,2,1])" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1};
    cout << "Test 2 - Array: [1]" << endl;
    cout << "Output: " << sol.maxSubArray(nums2) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test 3 - Array: [5,4,-1,7,8]" << endl;
    cout << "Output: " << sol.maxSubArray(nums3) << endl;
    cout << "Expected: 23 (entire array)" << endl << endl;
    
    // Test Case 4
    vector<int> nums4 = {-1, -2, -3, -4};
    cout << "Test 4 - Array: [-1,-2,-3,-4]" << endl;
    cout << "Output: " << sol.maxSubArray(nums4) << endl;
    cout << "Expected: -1" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is the array size
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Kadane's algorithm is a classic greedy approach for subarray problems
- Key insight: negative prefix sums are useless, discard them
- At each step, we make locally optimal choice (extend or reset)
- This pattern extends to 2D maximum submatrix problems
- Can be modified to track actual subarray indices
*/
