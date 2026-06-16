/*
PROBLEM: Trapping Rain Water
---------------------------------------------------------------------------
Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it can trap after raining.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map traps 6 units of rain water.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
Explanation: Water trapped = 1 + 2 + 3 + 2 + 1 = 9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
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
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: " << sol.trap(height1) << endl;
    
    // Test case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: " << sol.trap(height2) << endl;
    
    return 0;
}
