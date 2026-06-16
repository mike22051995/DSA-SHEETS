/*
================================================================================
PROBLEM: Two Sum (LeetCode #1)
DIFFICULTY: Easy
PATTERN: Hash Map / Hash Table
COMPANIES: Amazon, Google, Microsoft, Facebook, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may 
not use the same element twice.
You can return the answer in any order.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. You need to find a pair of elements that satisfy a condition
2. The problem involves finding complement values (target - current)
3. You need O(n) time complexity instead of O(n²) brute force
4. The problem asks "find two elements that..."

Key Indicators:
- Looking for pairs in an array
- Target sum or difference mentioned
- Need to return indices or values
- Each element used at most once

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation: nums[1] + nums[2] == 6, so return [1, 2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
Explanation: nums[0] + nums[1] == 6, return [0, 1]

================================================================================
EXPLANATION:

Approach 1 - Brute Force (Not Optimal):
- Use two nested loops to check every pair
- Time: O(n²), Space: O(1)

Approach 2 - Hash Map (Optimal):
- As we iterate through the array, for each element we:
  1. Calculate complement = target - current_element
  2. Check if complement exists in hash map
  3. If yes, return current index and complement's index
  4. If no, store current element with its index in hash map

Why Hash Map?
- Provides O(1) lookup time
- Stores previously seen elements and their indices
- Avoids nested loops

Time Complexity: O(n) - single pass through array
Space Complexity: O(n) - hash map storage

================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Optimal Solution using Hash Map
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Store current number with its index
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
    
    // Brute Force Solution (for comparison)
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Test function
void runTest(vector<int> nums, int target, string testName) {
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    
    cout << testName << ": ";
    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "], target = " << target << endl;
    
    if (!result.empty()) {
        cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;
        cout << "Sum: " << nums[result[0]] << " + " << nums[result[1]] 
             << " = " << target << endl;
    } else {
        cout << "No solution found" << endl;
    }
    cout << "-------------------" << endl;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    runTest(nums1, 9, "Test 1");
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    runTest(nums2, 6, "Test 2");
    
    // Test Case 3
    vector<int> nums3 = {3, 3};
    runTest(nums3, 6, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Three Sum (LeetCode #15) - Medium
   - Find three numbers that sum to zero
   - Use two pointers after sorting

2. Four Sum (LeetCode #18) - Medium
   - Find four numbers that sum to target
   - Extension of two sum pattern

3. Two Sum II - Input Array Is Sorted (LeetCode #167) - Medium
   - Use two pointers approach (more efficient for sorted array)

4. Two Sum III - Data Structure Design (LeetCode #170) - Easy
   - Design a data structure for two sum operations

5. Two Sum IV - Input is a BST (LeetCode #653) - Easy
   - Apply two sum on binary search tree

6. Subarray Sum Equals K (LeetCode #560) - Medium
   - Use prefix sum with hash map

7. 4Sum II (LeetCode #454) - Medium
   - Four arrays variation using hash map

8. Two Sum Less Than K (LeetCode #1099) - Easy
   - Find maximum sum less than K

9. Count Pairs with Given Sum - Various platforms
   - Count instead of finding indices

10. Maximum Number of K-Sum Pairs (LeetCode #1679) - Medium
    - Remove pairs that sum to K

================================================================================
TIPS FOR INTERVIEWS:
================================================================================
1. Always clarify constraints:
   - Can array have duplicates?
   - Is array sorted?
   - Can we use same element twice?
   - Is solution guaranteed to exist?

2. Start with brute force, then optimize

3. Mention trade-offs:
   - Time vs Space complexity
   - When to use hash map vs two pointers

4. Edge cases to consider:
   - Empty array
   - Array with one element
   - Duplicate values
   - Negative numbers
   - Large numbers

5. Follow-up questions to expect:
   - What if array is sorted? (Use two pointers)
   - What if we need all pairs? (Modify to collect all)
   - What if we can't use extra space? (Two pointers on sorted)
================================================================================
*/
