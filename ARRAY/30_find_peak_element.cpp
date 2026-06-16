/*
PROBLEM: Find Peak Element
Difficulty: Medium/Hard
Pattern: Binary Search

DESCRIPTION:
A peak element is an element that is strictly greater than its neighbors. Given an integer 
array nums, find a peak element, and return its index. If the array contains multiple peaks, 
return the index to any of the peaks.
You must write an algorithm that runs in O(log n) time.

EXPLANATION:
Binary Search approach:
- If mid element is greater than next element, peak is on the left (including mid)
- Otherwise, peak is on the right
- Array boundaries are treated as negative infinity
- This guarantees finding a peak

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element at index 2

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: 6 is a peak element at index 5 (or index 1 with value 2)

Example 3:
Input: nums = [1]
Output: 0
Explanation: Single element is a peak
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
            
            // If mid is greater than next element, peak is on left side
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                // Peak is on right side
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
