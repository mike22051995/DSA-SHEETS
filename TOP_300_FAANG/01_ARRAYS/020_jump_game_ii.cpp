/*
================================================================================
PROBLEM: Jump Game II (LeetCode #45)
DIFFICULTY: Medium
PATTERN: Greedy / BFS
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Greedy approach
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                if (currentEnd >= n - 1) break;
            }
        }
        
        return jumps;
    }
    
    // BFS approach
    int jumpBFS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int level = 0;
        int currentMax = 0;
        int nextMax = 0;
        int i = 0;
        
        while (currentMax - i + 1 > 0) {
            level++;
            
            while (i <= currentMax) {
                nextMax = max(nextMax, nums[i] + i);
                
                if (nextMax >= n - 1) return level;
                
                i++;
            }
            
            currentMax = nextMax;
        }
        
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {2,3,0,1,4};
    
    cout << "Minimum jumps: " << sol.jump(nums1) << endl;
    cout << "Minimum jumps: " << sol.jump(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Jump Game (LeetCode #55)
2. Jump Game III (LeetCode #1306)
3. Jump Game IV (LeetCode #1345)
4. Jump Game V (LeetCode #1340)
5. Jump Game VI (LeetCode #1696)
6. Jump Game VII (LeetCode #1871)
7. Reach End of Array (LeetCode #2770)
8. Frog Jump (LeetCode #403)
9. Minimum Number of Taps (LeetCode #1326)
10. Video Stitching (LeetCode #1024)
*/
