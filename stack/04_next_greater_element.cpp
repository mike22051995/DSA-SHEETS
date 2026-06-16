/*
PROBLEM: Next Greater Element I (LeetCode 496)
DIFFICULTY: Easy
PATTERN: Monotonic Stack

DESCRIPTION:
You are given two arrays (without duplicates) nums1 and nums2 where nums1's elements 
are subset of nums2. Find all the next greater numbers for nums1's elements in nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its 
right in nums2. If it does not exist, output -1 for this number.

INPUT: nums1 = [4,1,2], nums2 = [1,3,4,2]
OUTPUT: [-1,3,-1]
Explanation:
For 4: No next greater element -> -1
For 1: Next greater is 3
For 2: No next greater element -> -1

TIME COMPLEXITY: O(n + m) where n = nums2.size(), m = nums1.size()
SPACE COMPLEXITY: O(n) for hashmap and stack

EXPLANATION:
Use a monotonic decreasing stack to find next greater elements in nums2.
Store the results in a hashmap. Then lookup each element of nums1 in the hashmap.
The stack maintains elements in decreasing order, and when we find a larger element,
we pop and record the next greater element.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;
    
    // Traverse nums2 from right to left
    for (int i = nums2.size() - 1; i >= 0; i--) {
        int num = nums2[i];
        
        // Pop elements smaller than or equal to current
        while (!st.empty() && st.top() <= num) {
            st.pop();
        }
        
        // The top of stack is the next greater element
        nextGreater[num] = st.empty() ? -1 : st.top();
        
        // Push current element
        st.push(num);
    }
    
    // Build result for nums1
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater[num]);
    }
    
    return result;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    cout << "nums1: ";
    printVector(nums1);
    cout << "nums2: ";
    printVector(nums2);
    
    vector<int> result = nextGreaterElement(nums1, nums2);
    cout << "Next Greater Elements: ";
    printVector(result);
    
    // Test case 2
    cout << "\nTest case 2:" << endl;
    vector<int> nums3 = {2, 4};
    vector<int> nums4 = {1, 2, 3, 4};
    cout << "nums1: ";
    printVector(nums3);
    cout << "nums2: ";
    printVector(nums4);
    result = nextGreaterElement(nums3, nums4);
    cout << "Next Greater Elements: ";
    printVector(result);
    
    return 0;
}
