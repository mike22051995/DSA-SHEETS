/*
================================================================================
PROBLEM: Longest Continuous Subarray With Absolute Diff <= Limit (LeetCode #1438)
DIFFICULTY: Medium
PATTERN: Sliding Window / Monotonic Deque
COMPANIES: Amazon, Microsoft, Google
================================================================================

PROBLEM DESCRIPTION:
Given an array of integers nums and an integer limit, return the size of the
longest non-empty subarray such that the absolute difference between any two
elements of this subarray is less than or equal to limit.

EXAMPLES:

Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are: 
[8] with max=8 and min=8, diff=0 <= 4.
[8,2] with max=8 and min=2, diff=6 > 4.
[2,4] with max=4 and min=2, diff=2 <= 4.
[2,4,7] with max=7 and min=2, diff=5 > 4.
[4,7] with max=7 and min=4, diff=3 <= 4.

Example 2:
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4

Example 3:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

PATTERN RECOGNITION:
Use this pattern when:
- Track min and max in sliding window
- Monotonic deques for efficient min/max queries
- Expand window when condition met, shrink otherwise
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque;  // Decreasing order
        deque<int> minDeque;  // Increasing order
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Maintain max deque
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);
            
            // Maintain min deque
            while (!minDeque.empty() && nums[right] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);
            
            // Shrink window if difference exceeds limit
            while (maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[left]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[left]) {
                    minDeque.pop_front();
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {8,2,4,7};
    cout << "Longest subarray (limit=4): " << sol.longestSubarray(nums1, 4) << endl;
    
    vector<int> nums2 = {10,1,2,4,7,2};
    cout << "Longest subarray (limit=5): " << sol.longestSubarray(nums2, 5) << endl;
    
    vector<int> nums3 = {4,2,2,2,4,4,2,2};
    cout << "Longest subarray (limit=0): " << sol.longestSubarray(nums3, 0) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(n) for deques

SIMILAR PROBLEMS:
1. Sliding Window Maximum (LeetCode #239)
2. Longest Repeating Character Replacement (LeetCode #424)
3. Max Consecutive Ones III (LeetCode #1004)
4. Minimum Size Subarray Sum (LeetCode #209)
5. Subarrays with K Different Integers (LeetCode #992)
6. Fruit Into Baskets (LeetCode #904)
7. Longest Substring with At Most K Distinct (LeetCode #340)
8. Grumpy Bookstore Owner (LeetCode #1052)
9. Maximum Points from Cards (LeetCode #1423)
10. Constrained Subsequence Sum (LeetCode #1425)
*/
