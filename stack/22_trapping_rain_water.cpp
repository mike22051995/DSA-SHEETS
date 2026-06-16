/*
PROBLEM: Trapping Rain Water (LeetCode 42)
DIFFICULTY: Hard
PATTERN: Stack for Water Trapping

DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of each 
bar is 1, compute how much water it can trap after raining.

INPUT: height = [0,1,0,2,1,0,1,3,2,1,2,1]
OUTPUT: 6
Explanation: 6 units of water can be trapped

INPUT: height = [4,2,0,3,2,5]
OUTPUT: 9

TIME COMPLEXITY: O(n) where n is the length of array
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Stack-based approach: Store indices in stack. When current height > stack top,
we can trap water. Pop and calculate water between current bar and the bar before
popped bar. The trapped water is min(left_height, right_height) - current_height.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Stack approach
int trap(vector<int>& height) {
    stack<int> st;
    int water = 0;
    int n = height.size();
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            
            if (st.empty()) break;
            
            // Calculate trapped water
            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            water += distance * boundedHeight;
        }
        st.push(i);
    }
    
    return water;
}

// Two pointer approach (more intuitive)
int trapTwoPointer(vector<int>& height) {
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
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {4, 2, 0, 3, 2, 5},
        {3, 0, 2, 0, 4},
        {5, 4, 1, 2}
    };
    
    for (auto& height : testCases) {
        cout << "Height: ";
        printVector(height);
        cout << endl;
        
        int result1 = trap(height);
        int result2 = trapTwoPointer(height);
        
        cout << "Water trapped (stack): " << result1 << endl;
        cout << "Water trapped (two pointer): " << result2 << endl << endl;
    }
    
    return 0;
}
