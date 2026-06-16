/*
PROBLEM: Container With Most Water
---------------------------------------------------------------------------
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container that contains 
the most water. Return the maximum amount of water a container can store.

PATTERN: Opposite Direction Two Pointers (Greedy)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The vertical lines are at indices 1 and 8 with heights 8 and 7.
Water = min(8,7) * (8-1) = 7 * 7 = 49

Example 2:
Input: height = [1,1]
Output: 1
Explanation: Only two lines, water = min(1,1) * (1-0) = 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            // Calculate current area
            int width = right - left;
            int h = min(height[left], height[right]);
            int currentArea = width * h;
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer with smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << sol.maxArea(height1) << endl;
    
    // Test case 2
    vector<int> height2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(height2) << endl;
    
    return 0;
}
