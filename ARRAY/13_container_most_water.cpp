/*
PROBLEM: Container With Most Water
Difficulty: Medium
Pattern: Two Pointers

DESCRIPTION:
You are given an integer array height of length n. There are n vertical lines drawn such 
that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container 
contains the most water. Return the maximum amount of water a container can store.

EXPLANATION:
Use two pointers at the start and end of the array.
Area = min(height[left], height[right]) * (right - left)
Move the pointer with smaller height inward (to potentially find a taller line).

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: Lines at index 1 and 8 form container with area = 7 * 7 = 49

Example 2:
Input: height = [1,1]
Output: 1
Explanation: Only one container possible with area = 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16
Explanation: Lines at index 0 and 4 form container with area = 4 * 4 = 16
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
            int area = width * h;
            
            maxWater = max(maxWater, area);
            
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
    Solution solution;
    
    // Test Case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << solution.maxArea(height1) << endl;
    
    // Test Case 2
    vector<int> height2 = {1, 1};
    cout << "Test 2: " << solution.maxArea(height2) << endl;
    
    // Test Case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Test 3: " << solution.maxArea(height3) << endl;
    
    return 0;
}
