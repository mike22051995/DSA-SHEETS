/*
PROBLEM: Search in Rotated Sorted Array
Difficulty: Medium
Pattern: Modified Binary Search

DESCRIPTION:
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k.
Given the array nums after the possible rotation and an integer target, return the index of 
target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Modified binary search:
1. Find which half is sorted (left or right)
2. Check if target lies in the sorted half
3. If yes, search in that half, otherwise search the other half
4. One half is always sorted in rotated array

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Explanation: 0 is at index 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Explanation: 3 is not in the array

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check which half is sorted
            if (nums[left] <= nums[mid]) {
                // Left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1: " << solution.search(nums1, 0) << endl;
    
    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: " << solution.search(nums2, 3) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Test 3: " << solution.search(nums3, 0) << endl;
    
    return 0;
}
