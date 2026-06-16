/*
================================================================================
PROBLEM: Largest Rectangle in Histogram (LeetCode #84)
DIFFICULTY: Hard
PATTERN: Monotonic Stack
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
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
        heights.push_back(0); // Add sentinel
        
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest rectangle area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximal Rectangle (LeetCode #85)
2. Trapping Rain Water (LeetCode #42)
3. Sum of Subarray Minimums (LeetCode #907)
4. Max Rectangle in Binary Matrix
5. Daily Temperatures (LeetCode #739)
6. Next Greater Element (LeetCode #496)
7. Remove K Digits (LeetCode #402)
8. Online Stock Span (LeetCode #901)
9. Score of Parentheses (LeetCode #856)
10. Minimum Cost Tree From Leaf Values (LeetCode #1130)
*/
