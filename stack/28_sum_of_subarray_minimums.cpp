/*
PROBLEM: Sum of Subarray Minimums (LeetCode 907)
DIFFICULTY: Hard
PATTERN: Monotonic Stack for Contribution Counting

DESCRIPTION:
Given an array of integers arr, find the sum of min(b), where b ranges over every 
(contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.

INPUT: arr = [3,1,2,4]
OUTPUT: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
Minimums are  3,   1,   2,   4,    1,     1,     2,      1,       1,       1
Sum = 17

TIME COMPLEXITY: O(n) where n is the length of array
SPACE COMPLEXITY: O(n) for the stacks

EXPLANATION:
For each element, calculate how many subarrays it is the minimum of.
Use two monotonic stacks to find:
- Previous Less Element (PLE): nearest smaller element to the left
- Next Less Element (NLE): nearest smaller element to the right
For each element, contribution = arr[i] * (i - PLE[i]) * (NLE[i] - i)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;
    
    // Calculate left boundaries (previous less element)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    // Clear stack for right boundaries
    while (!st.empty()) st.pop();
    
    // Calculate right boundaries (next less element)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {  // >= to handle duplicates
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    // Calculate sum of minimums
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long count = (long long)(i - left[i]) * (right[i] - i);
        result = (result + arr[i] * count) % MOD;
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
        {3, 1, 2, 4},
        {11, 81, 94, 43, 3},
        {71, 55, 82, 55},
        {1, 2, 3, 4, 5}
    };
    
    for (auto& arr : testCases) {
        cout << "Array: ";
        printVector(arr);
        cout << endl;
        
        int result = sumSubarrayMins(arr);
        cout << "Sum of subarray minimums: " << result << endl << endl;
    }
    
    return 0;
}
