/*
================================================================================
PROBLEM: Wiggle Subsequence (LeetCode #376)
DIFFICULTY: Medium
PATTERN: Greedy / Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
A wiggle sequence is a sequence where the differences between successive numbers
strictly alternate between positive and negative. Given an integer array nums,
return the length of the longest wiggle subsequence of nums.

EXAMPLES:

Example 1:
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6,-3,5,-7,3).

Example 2:
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7

Example 3:
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2

PATTERN RECOGNITION:
Use this pattern when:
- Subsequence optimization with alternating pattern
- Need to track direction changes
- Greedy works when we want local optimal at each step
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Greedy approach
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        
        int prevDiff = 0;
        int count = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                count++;
                prevDiff = diff;
            }
        }
        
        return count;
    }
    
    // DP approach
    int wiggleMaxLengthDP(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        vector<int> up(n, 1);    // Length ending with up wiggle
        vector<int> down(n, 1);  // Length ending with down wiggle
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                } else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        
        return max(up[n-1], down[n-1]);
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,7,4,9,2,5};
    vector<int> nums2 = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums3 = {1,2,3,4,5,6,7,8,9};
    
    cout << "Wiggle length [1,7,4,9,2,5]: " << sol.wiggleMaxLength(nums1) << endl;
    cout << "Wiggle length [1,17,5,10,13,15,10,5,16,8]: " << sol.wiggleMaxLength(nums2) << endl;
    cout << "Wiggle length [1,2,3,4,5,6,7,8,9]: " << sol.wiggleMaxLength(nums3) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) for greedy, O(n^2) for DP
SPACE COMPLEXITY: O(1) for greedy, O(n) for DP

SIMILAR PROBLEMS:
1. Longest Increasing Subsequence (LeetCode #300)
2. Wiggle Sort (LeetCode #280)
3. Wiggle Sort II (LeetCode #324)
4. Number of Longest Increasing Subsequence (LeetCode #673)
5. Longest Turbulent Subarray (LeetCode #978)
6. Maximum Alternating Subsequence Sum (LeetCode #1911)
7. Increasing Triplet Subsequence (LeetCode #334)
8. Best Time to Buy and Sell Stock II (LeetCode #122)
9. Jump Game (LeetCode #55)
10. Jump Game II (LeetCode #45)
*/
