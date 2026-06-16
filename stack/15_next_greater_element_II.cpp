/*
PROBLEM: Next Greater Element II (LeetCode 503)
DIFFICULTY: Medium
PATTERN: Monotonic Stack with Circular Array

DESCRIPTION:
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] 
is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order 
next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.

INPUT: nums = [1,2,1]
OUTPUT: [2,-1,2]
Explanation: First 1's next greater is 2, 2 has no next greater, second 1's next greater is 2.

TIME COMPLEXITY: O(n) where n is the length of array
SPACE COMPLEXITY: O(n) for the stack and result

EXPLANATION:
To handle circular array, traverse the array twice (or use modulo).
Use monotonic decreasing stack to find next greater elements.
Store indices in stack, and when we find a greater element, pop and record result.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // Store indices
    
    // Traverse array twice to handle circular nature
    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];
        
        // Pop smaller elements and update their next greater
        while (!st.empty() && nums[st.top()] < num) {
            result[st.top()] = num;
            st.pop();
        }
        
        // Only push indices in first iteration
        if (i < n) {
            st.push(i);
        }
    }
    
    return result;
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
        {1, 2, 1},
        {1, 2, 3, 4, 3},
        {5, 4, 3, 2, 1},
        {1, 1, 1, 1},
        {3, 8, 4, 1, 2}
    };
    
    for (auto& nums : testCases) {
        cout << "Input: ";
        printVector(nums);
        cout << endl;
        
        vector<int> result = nextGreaterElements(nums);
        cout << "Next Greater Elements: ";
        printVector(result);
        cout << endl << endl;
    }
    
    return 0;
}
