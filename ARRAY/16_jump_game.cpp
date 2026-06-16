/*
PROBLEM: Jump Game
Difficulty: Medium
Pattern: Greedy

DESCRIPTION:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

EXPLANATION:
Greedy approach: Track the farthest index we can reach.
At each position, update the farthest reachable index.
If at any point current index exceeds farthest reachable, we cannot proceed.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to last index

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3, max jump = 0

Example 3:
Input: nums = [0]
Output: true
Explanation: Already at last index
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        
        for (int i = 0; i < n; i++) {
            // If current index is beyond max reachable, cannot proceed
            if (i > maxReach) {
                return false;
            }
            
            // Update max reachable index
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can reach the last index
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: " << (solution.canJump(nums1) ? "true" : "false") << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2: " << (solution.canJump(nums2) ? "true" : "false") << endl;
    
    // Test Case 3
    vector<int> nums3 = {0};
    cout << "Test 3: " << (solution.canJump(nums3) ? "true" : "false") << endl;
    
    return 0;
}
