/*
PROBLEM: Jump Game (LeetCode 55)
DIFFICULTY: Medium
PATTERN: Greedy Reachability / Farthest Position Tracking

DESCRIPTION:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

INPUT:
- nums: array where nums[i] is max jump length from position i

OUTPUT:
- true if last index is reachable, false otherwise

APPROACH:
1. Track the farthest position reachable so far
2. At each position, update farthest reachable
3. If current position > farthest, we're stuck
4. If farthest >= last index, return true

WHY GREEDY WORKS:
We don't need to find the actual path, just verify reachability.
Tracking maximum reach is sufficient and optimal.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If current position is beyond our reach, can't proceed
            if (i > farthest) {
                return false;
            }
            
            // Update farthest position we can reach
            farthest = max(farthest, i + nums[i]);
            
            // Early exit: if we can reach the end
            if (farthest >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
    
    // Alternative: backward approach
    bool canJumpBackward(vector<int>& nums) {
        int lastGoodIndex = nums.size() - 1;
        
        // Work backward: find if each position can reach last good position
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= lastGoodIndex) {
                lastGoodIndex = i;
            }
        }
        
        return lastGoodIndex == 0;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1 - Array: [2,3,1,1,4]" << endl;
    cout << "Output: " << (sol.canJump(nums1) ? "true" : "false") << endl;
    cout << "Expected: true (jump 1 to index 1, then 3 to last)" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2 - Array: [3,2,1,0,4]" << endl;
    cout << "Output: " << (sol.canJump(nums2) ? "true" : "false") << endl;
    cout << "Expected: false (stuck at index 3)" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {0};
    cout << "Test 3 - Array: [0]" << endl;
    cout << "Output: " << (sol.canJump(nums3) ? "true" : "false") << endl;
    cout << "Expected: true (already at end)" << endl << endl;
    
    // Test Case 4
    vector<int> nums4 = {2, 0, 0};
    cout << "Test 4 - Array: [2,0,0]" << endl;
    cout << "Output: " << (sol.canJump(nums4) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Greedy reachability: track maximum reach instead of all paths
- Forward and backward approaches both work
- This is simpler than BFS/DFS and more efficient than DP
- Pattern extends to Jump Game II (minimum jumps)
- Common in FAANG interviews
*/
