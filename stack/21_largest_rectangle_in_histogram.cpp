/*
PROBLEM: Largest Rectangle in Histogram (LeetCode 84)
DIFFICULTY: Hard
PATTERN: Monotonic Stack for Area Calculation

DESCRIPTION:
Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.

INPUT: heights = [2,1,5,6,2,3]
OUTPUT: 10
Explanation: The largest rectangle has area = 10 (width=2, height=5)

INPUT: heights = [2,4]
OUTPUT: 4

TIME COMPLEXITY: O(n) where n is the number of bars
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic increasing stack to store indices of bars.
For each bar, if it's smaller than stack top, we've found the right boundary.
Pop from stack and calculate area using popped height and width between boundaries.
This is a classic and very important pattern for FAANG interviews!
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;  // Store indices
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        
        // Pop all bars higher than current
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop(); 
            
            // Calculate width
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        st.push(i);
    }
    
    return maxArea;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<vector<int>> testCases = {
        {3, 2},
        {2, 4},
        {1, 1, 1, 1, 1},
        {6, 2, 5, 4, 5, 1, 6},
        {2, 1, 2},
        {4, 2, 0, 3, 2, 5}
    };
    
    for (auto& heights : testCases) {
        cout << "Heights: ";
        printVector(heights);
        cout << endl;
        
        int result = largestRectangleArea(heights);
        cout << "Largest Rectangle Area: " << result << endl << endl;
    }
    
    return 0;
}
