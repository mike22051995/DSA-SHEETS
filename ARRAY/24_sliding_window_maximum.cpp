/*
PROBLEM: Sliding Window Maximum
Difficulty: Hard
Pattern: Sliding Window, Deque (Monotonic Queue)

DESCRIPTION:
You are given an array of integers nums, there is a sliding window of size k which is moving 
from the very left of the array to the very right. You can only see the k numbers in the 
window. Each time the sliding window moves right by one position.
Return the max sliding window.

EXPLANATION:
Use a deque to maintain indices of useful elements in decreasing order:
- Remove indices outside current window
- Remove indices of smaller elements from back (they won't be max)
- Front of deque always has index of max element in current window

Time Complexity: O(n)
Space Complexity: O(k)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: Window max at each position

Example 2:
Input: nums = [1], k = 1
Output: [1]
Explanation: Single element window

Example 3:
Input: nums = [1,-1], k = 1
Output: [1,-1]
Explanation: Window size 1, each element is max
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove indices of smaller elements
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Add to result if window is formed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result1 = solution.maxSlidingWindow(nums1, 3);
    cout << "Test 1: ";
    printArray(result1);
    
    // Test Case 2
    vector<int> nums2 = {1};
    vector<int> result2 = solution.maxSlidingWindow(nums2, 1);
    cout << "Test 2: ";
    printArray(result2);
    
    // Test Case 3
    vector<int> nums3 = {1, -1};
    vector<int> result3 = solution.maxSlidingWindow(nums3, 1);
    cout << "Test 3: ";
    printArray(result3);
    
    return 0;
}
