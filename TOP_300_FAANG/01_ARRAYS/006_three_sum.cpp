/*
================================================================================
PROBLEM: Three Sum (LeetCode #15)
DIFFICULTY: Medium
PATTERN: Two Pointers + Sorting
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Finding triplets/pairs with sum condition
2. Need to avoid duplicates in results
3. Can sort array without losing information
4. Two pointers can optimize inner loop

Key Indicators:
- "Find all triplets" or "find all pairs"
- Sum equals target (often 0)
- Avoid duplicate results
- Array can be modified (sorting allowed)

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0
The distinct triplets are [-1,0,1] and [-1,-1,2]

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

================================================================================
EXPLANATION:

Approach: Sort + Two Pointers
1. Sort the array
2. For each element nums[i]:
   - If nums[i] > 0, break (can't sum to 0)
   - Use two pointers on remaining array
   - Find pairs that sum to -nums[i]
3. Skip duplicates to avoid repeated triplets

Algorithm:
- Sort array: O(n log n)
- Outer loop: fix first element
- Inner two pointers: find complementary pair
- Skip duplicates at all levels

Time Complexity: O(n²)
Space Complexity: O(1) or O(n) for sorting

================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // If smallest number > 0, no solution possible
            if (nums[i] > 0) break;
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

void runTest(vector<int> nums, string testName) {
    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);
    
    cout << testName << ": " << endl;
    cout << "Input: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    runTest(nums1, "Test 1");
    
    vector<int> nums2 = {0, 1, 1};
    runTest(nums2, "Test 2");
    
    vector<int> nums3 = {0, 0, 0};
    runTest(nums3, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Two Sum (LeetCode #1) - Easy
   - Base problem using hash map

2. Four Sum (LeetCode #18) - Medium
   - Add one more outer loop

3. 3Sum Closest (LeetCode #16) - Medium
   - Find triplet closest to target

4. 3Sum Smaller (LeetCode #259) - Medium
   - Count triplets with sum < target

5. 4Sum II (LeetCode #454) - Medium
   - Four arrays, use hash map

6. Combination Sum (LeetCode #39) - Medium
   - Can reuse elements

7. Subarray Sum Equals K (LeetCode #560) - Medium
   - Continuous subarray

8. Two Sum II (LeetCode #167) - Medium
   - Sorted array variant

9. Valid Triangle Number (LeetCode #611) - Medium
   - Similar two-pointer technique

10. Number of Subsequences That Satisfy Sum Condition (LeetCode #1498)
    - Counting variant

================================================================================
*/
