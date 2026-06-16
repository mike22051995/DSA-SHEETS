/*
PROBLEM: Jump Game II (LeetCode 45)
DIFFICULTY: Medium
PATTERN: Greedy BFS / Range-based Jumping

DESCRIPTION:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i.
Return the minimum number of jumps to reach nums[n - 1]. Test cases are generated such that 
you can reach nums[n - 1].

INPUT:
- nums: array where nums[i] is max jump length from position i

OUTPUT:
- Minimum number of jumps to reach last index

APPROACH (Greedy BFS):
1. Think of each jump as a "level" in BFS
2. Track current jump's reach and next jump's reach
3. When we exhaust current range, increment jumps
4. Always explore farthest reachable in current jump

WHY GREEDY WORKS:
We always want to maximize reach with each jump. Within current jump range,
we find the position that allows us to reach farthest in next jump.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        int jumps = 0;
        int currentEnd = 0;      // End of current jump range
        int farthest = 0;        // Farthest we can reach
        
        // We don't need to jump from last position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update farthest position reachable
            farthest = max(farthest, i + nums[i]);
            
            // If we've reached end of current jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;  // Next jump can reach up to farthest
                
                // Early exit if we can reach the end
                if (currentEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1 - Array: [2,3,1,1,4]" << endl;
    cout << "Output: " << sol.jump(nums1) << endl;
    cout << "Expected: 2 (jump to index 1, then to last index)" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Test 2 - Array: [2,3,0,1,4]" << endl;
    cout << "Output: " << sol.jump(nums2) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Test 3 - Array: [1,2,3]" << endl;
    cout << "Output: " << sol.jump(nums3) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 4
    vector<int> nums4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
    cout << "Test 4 - Array: [10,9,8,7,6,5,4,3,2,1,1,0]" << endl;
    cout << "Output: " << sol.jump(nums4) << endl;
    cout << "Expected: 2 (jump to index 1, then to last)" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Greedy BFS without queue: use range concept
- Each jump explores all positions in current range
- Track current range end and farthest reachable
- More efficient than actual BFS (no queue needed)
- Critical pattern for jump-related problems
- Very common in Google/Meta interviews
*/
