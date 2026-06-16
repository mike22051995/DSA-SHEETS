/*
PROBLEM: Vertical Lines to Trap Rain Water (LeetCode 42 - Advanced Greedy)
DIFFICULTY: Hard
PATTERN: Two Pointer Greedy Optimization

DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

INPUT:
- height: array of non-negative integers

OUTPUT:
- Total water trapped

APPROACH:
1. Use two pointers from both ends
2. Track leftMax and rightMax
3. Move pointer with smaller max
4. Water at current position = min(leftMax, rightMax) - height[i]
5. Greedy: process from smaller side

WHY GREEDY WORKS:
Water level at position depends on minimum of max heights on both sides.
By processing from smaller side, we ensure we know the limiting height.
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
                // Process left side
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                // Process right side
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
    
    // Alternative: Using extra space (easier to understand)
    int trapWithExtraSpace(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> leftMax(n), rightMax(n);
        
        // Fill leftMax
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        // Fill rightMax
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        // Calculate water
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return water;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1 - Height: [0,1,0,2,1,0,1,3,2,1,2,1]" << endl;
    cout << "Output: " << sol.trap(height1) << endl;
    cout << "Expected: 6" << endl << endl;
    
    // Test Case 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2 - Height: [4,2,0,3,2,5]" << endl;
    cout << "Output: " << sol.trap(height2) << endl;
    cout << "Expected: 9" << endl << endl;
    
    // Test Case 3
    vector<int> height3 = {4, 2, 3};
    cout << "Test 3 - Height: [4,2,3]" << endl;
    cout << "Output: " << sol.trap(height3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 4
    vector<int> height4 = {5, 4, 1, 2};
    cout << "Test 4 - Height: [5,4,1,2]" << endl;
    cout << "Output: " << sol.trap(height4) << endl;
    cout << "Expected: 1" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(1) for two-pointer approach, O(n) for array approach

KEY LEARNING:
- Two pointer greedy: process from both ends toward center
- Key insight: move pointer with smaller height
- Water level determined by minimum of left and right max
- Can trade space for simpler logic (O(n) space approach)
- Classic hard problem, appears frequently in interviews
- Pattern: bidirectional processing with state tracking
- Must-know for FAANG interviews
*/
