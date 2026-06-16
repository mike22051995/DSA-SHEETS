/*
PROBLEM: Find Peak Element
Difficulty: Medium
Pattern: Binary Search

DESCRIPTION:
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains 
multiple peaks, return the index to any of the peaks.
You must write an algorithm that runs in O(log n) time.

EXPLANATION:
Binary search approach:
- Compare mid with mid+1
- If nums[mid] > nums[mid+1], peak is on left (including mid)
- Otherwise, peak is on right
- Array boundaries are treated as negative infinity

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: 6 is a peak (or index 1 is also valid)

Example 3:
Input: nums = [1]
Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak is on left (including mid)
                right = mid;
            } else {
                // Peak is on right
                left = mid + 1;
            }
        }
        
        return left;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: " << solution.findPeakElement(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Test 2: " << solution.findPeakElement(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Test 3: " << solution.findPeakElement(nums3) << endl;
    
    return 0;
}
