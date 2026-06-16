/*
================================================================================
PROBLEM: Trapping Rain Water (LeetCode #42)
DIFFICULTY: Hard
PATTERN: Two Pointers / Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it can trap after raining.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Need to calculate based on surrounding elements
2. Two pointers from both ends
3. Track max from left and right
4. Process smaller side first

Key Indicators:
- "Trap water" or "container"
- Height array
- Calculate area/volume
- Two pointer optimization

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: 6 units of water trapped

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Two Pointer Approach (Optimal)
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
    
    // DP Approach
    int trapDP(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Water trapped: " << sol.trap(height) << endl;
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Container With Most Water (LeetCode #11)
2. Product of Array Except Self (LeetCode #238)
3. Largest Rectangle in Histogram (LeetCode #84)
4. Maximal Rectangle (LeetCode #85)
5. Max Consecutive Ones III (LeetCode #1004)
6. Pour Water (LeetCode #755)
7. Trapping Rain Water II (LeetCode #407)
8. Volume of Histogram LCCI (LeetCode #面试题 17.21)
9. Maximum Width Ramp (LeetCode #962)
10. Minimum Number of Taps (LeetCode #1326)
================================================================================
*/
