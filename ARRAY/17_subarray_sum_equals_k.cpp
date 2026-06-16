/*
PROBLEM: Subarray Sum Equals K
Difficulty: Medium
Pattern: Prefix Sum, Hash Map

DESCRIPTION:
Given an array of integers nums and an integer k, return the total number of subarrays 
whose sum equals to k. A subarray is a contiguous non-empty sequence of elements within 
an array.

EXPLANATION:
Use prefix sum with hash map:
- Store cumulative sums and their frequencies
- For each position, check if (currentSum - k) exists in map
- If yes, it means there's a subarray ending at current position with sum = k

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Explanation: Subarrays [1,1] at positions (0,1) and (1,2)

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: Subarrays [1,2] and [3]

Example 3:
Input: nums = [1,-1,0], k = 0
Output: 3
Explanation: Subarrays [-1,1], [0], and [1,-1,0]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Empty subarray has sum 0
        
        int currentSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currentSum += num;
            
            // Check if (currentSum - k) exists
            // If yes, there's a subarray with sum = k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
            
            // Add current sum to map
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 1};
    cout << "Test 1: " << solution.subarraySum(nums1, 2) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 3};
    cout << "Test 2: " << solution.subarraySum(nums2, 3) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, -1, 0};
    cout << "Test 3: " << solution.subarraySum(nums3, 0) << endl;
    
    return 0;
}
