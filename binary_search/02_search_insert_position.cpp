/*
PROBLEM: Search Insert Position
Difficulty: Easy
Pattern: Binary Search Variant

DESCRIPTION:
Given a sorted array of distinct integers and a target value, return the index if the target 
is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Modified binary search:
- If target is found, return its index
- If not found, left pointer will be at the position where target should be inserted
- This is because left always moves to positions where element could be >= target

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Explanation: 5 is found at index 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Explanation: 2 should be inserted at index 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
Explanation: 7 should be inserted at the end
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left; // Insert position
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 3, 5, 6};
    cout << "Test 1: " << solution.searchInsert(nums1, 5) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 3, 5, 6};
    cout << "Test 2: " << solution.searchInsert(nums2, 2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 3, 5, 6};
    cout << "Test 3: " << solution.searchInsert(nums3, 7) << endl;
    
    return 0;
}
