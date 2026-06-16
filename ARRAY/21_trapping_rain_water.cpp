/*
PROBLEM: Trapping Rain Water
Difficulty: Hard
Pattern: Two Pointers, Dynamic Programming

DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

EXPLANATION:
Two Pointer Approach:
- Water trapped at any position = min(maxLeft, maxRight) - height[i]
- Use two pointers from both ends
- Move the pointer with smaller height inward
- Track max heights from both sides

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: Water trapped in valleys between bars

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
Explanation: Multiple valleys trap water

Example 3:
Input: height = [4,2,3]
Output: 1
Explanation: Small valley traps 1 unit
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
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
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: " << solution.trap(height1) << endl;
    
    // Test Case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: " << solution.trap(height2) << endl;
    
    // Test Case 3
    vector<int> height3 = {4, 2, 3};
    cout << "Test 3: " << solution.trap(height3) << endl;
    
    return 0;
}
