/*
================================================================================
PROBLEM: Maximum Subarray (Kadane's Algorithm) (LeetCode #53)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / Kadane's Algorithm
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple, LinkedIn
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums, find the subarray with the largest sum, and 
return its sum.

A subarray is a contiguous non-empty sequence of elements within an array.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Finding maximum/minimum in contiguous subarray
2. Problem involves "consecutive elements"
3. Can decide locally: extend current or start new
4. Need to track running sum/product

Key Indicators:
- "Maximum/minimum subarray"
- "Contiguous elements"
- Can solve with DP in O(n) time
- Local decisions lead to global optimum

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

================================================================================
EXPLANATION:

Kadane's Algorithm:
- Key Insight: At each position, decide whether to:
  1. Extend the previous subarray (add current element)
  2. Start a new subarray (from current element)
  
- Choose the option that gives larger sum
- Track the maximum sum seen so far

Algorithm:
1. Initialize: currentSum = nums[0], maxSum = nums[0]
2. For each element from index 1:
   - currentSum = max(nums[i], currentSum + nums[i])
   - maxSum = max(maxSum, currentSum)
3. Return maxSum

Why it works:
- If currentSum becomes negative, starting fresh is better
- We always keep track of the best sum found
- Greedy locally, optimal globally

Time Complexity: O(n) - single pass
Space Complexity: O(1) - only two variables

================================================================================
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Kadane's Algorithm - Most Optimal
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Either extend existing subarray or start new one
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update global maximum
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
    
    // Alternative: More explicit version
    int maxSubArrayExplicit(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;
        
        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            
            // If current sum becomes negative, reset
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
    
    // With subarray indices tracking
    vector<int> maxSubArrayWithIndices(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        int start = 0, end = 0, tempStart = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > currentSum + nums[i]) {
                currentSum = nums[i];
                tempStart = i;
            } else {
                currentSum = currentSum + nums[i];
            }
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }
        
        return {maxSum, start, end};
    }
    
    // Divide and Conquer Approach - O(n log n)
    int maxSubArrayDivideConquer(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
    
    int maxSubArrayHelper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        
        int mid = left + (right - left) / 2;
        
        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);
        
        return max({leftMax, rightMax, crossMax});
    }
    
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        
        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        
        return leftSum + rightSum;
    }
};

void runTest(vector<int> nums, string testName) {
    Solution sol;
    int result = sol.maxSubArray(nums);
    
    cout << testName << ": ";
    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Maximum Subarray Sum: " << result << endl;
    
    // Show subarray indices
    vector<int> withIndices = sol.maxSubArrayWithIndices(nums);
    cout << "Subarray: [";
    for (int i = withIndices[1]; i <= withIndices[2]; i++) {
        cout << nums[i];
        if (i < withIndices[2]) cout << ",";
    }
    cout << "]" << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    runTest(nums1, "Test 1");
    
    vector<int> nums2 = {1};
    runTest(nums2, "Test 2");
    
    vector<int> nums3 = {5, 4, -1, 7, 8};
    runTest(nums3, "Test 3");
    
    vector<int> nums4 = {-1, -2, -3, -4};
    runTest(nums4, "Test 4 (All Negative)");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Maximum Product Subarray (LeetCode #152) - Medium
   - Track both max and min (negative numbers)
   - Similar Kadane's variation

2. Best Time to Buy and Sell Stock (LeetCode #121) - Easy
   - Can be solved with Kadane's approach
   - Find max difference

3. Maximum Sum Circular Subarray (LeetCode #918) - Medium
   - Handle circular array case
   - Find max of (normal max, total - min subarray)

4. Longest Turbulent Subarray (LeetCode #978) - Medium
   - Similar pattern with different condition

5. Maximum Average Subarray I (LeetCode #643) - Easy
   - Fixed size k window

6. Maximum Size Subarray Sum Equals k (LeetCode #325) - Medium
   - Use prefix sum + hash map

7. Minimum Size Subarray Sum (LeetCode #209) - Medium
   - Sliding window variant

8. Range Sum Query - Immutable (LeetCode #303) - Easy
   - Prefix sum preprocessing

9. K Concatenation Maximum Sum (LeetCode #1191) - Medium
   - Array concatenated k times

10. Maximum Absolute Sum of Any Subarray (LeetCode #1749) - Medium
    - Find both max and min subarray sum

================================================================================
KEY CONCEPTS:
================================================================================

1. Kadane's Algorithm Intuition:
   - At each position: extend or start fresh?
   - Negative sum? Better to start over
   - Always track global maximum

2. DP State Definition:
   - dp[i] = maximum sum ending at index i
   - Recurrence: dp[i] = max(nums[i], dp[i-1] + nums[i])

3. Space Optimization:
   - Don't need entire dp array
   - Just previous value (currentSum)

4. Edge Cases:
   - Single element
   - All negative numbers
   - All positive numbers
   - Mix of positive and negative

5. Variations:
   - Find actual subarray (track indices)
   - Count subarrays (not just max)
   - With constraints (k transactions, circular)

================================================================================
*/
