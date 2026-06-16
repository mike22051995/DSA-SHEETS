/*
PROBLEM: Largest Rectangle in Histogram
Difficulty: Hard
Pattern: Stack, Monotonic Stack

DESCRIPTION:
Given an array of integers heights representing the histogram's bar height where the width 
of each bar is 1, return the area of the largest rectangle in the histogram.

EXPLANATION:
Use a monotonic stack to track indices of bars:
1. For each bar, pop bars from stack that are taller (can't extend further)
2. Calculate area for each popped bar
3. Stack maintains increasing heights
4. Process remaining bars in stack at the end

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: Rectangle of height 5, width 2 (between indices 2 and 3)

Example 2:
Input: heights = [2,4]
Output: 4
Explanation: Rectangle of height 2, width 2

Example 3:
Input: heights = [1,1]
Output: 2
Explanation: Rectangle of height 1, width 2
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {
            // Pop bars taller than current
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        // Process remaining bars in stack
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        return maxArea;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test 1: " << solution.largestRectangleArea(heights1) << endl;
    
    // Test Case 2
    vector<int> heights2 = {2, 4};
    cout << "Test 2: " << solution.largestRectangleArea(heights2) << endl;
    
    // Test Case 3
    vector<int> heights3 = {1, 1};
    cout << "Test 3: " << solution.largestRectangleArea(heights3) << endl;
    
    return 0;
}
