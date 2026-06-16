/*
PROBLEM: Search in Rotated Sorted Array II
Difficulty: Medium
Pattern: Modified Binary Search with Duplicates

DESCRIPTION:
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Given the array nums after rotation and an integer target, return true if target is in nums, 
or false if it is not in nums. You must decrease the overall operation steps as much as possible.

EXPLANATION:
Modified binary search handling duplicates:
- When nums[left] == nums[mid] == nums[right], can't determine which half is sorted
- In this case, increment left and decrement right
- Otherwise, same logic as Search in Rotated Sorted Array

Time Complexity: O(log n) average, O(n) worst case
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES: 

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Example 3:
Input: nums = [1,0,1,1,1], target = 0
Output: true
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
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
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {2,5,6,0,0,1,2};
    cout << "Test 1: " << (solution.search(nums1, 0) ? "true" : "false") << endl;
    
    // Test Case 2
    vector<int> nums2 = {2,5,6,0,0,1,2};
    cout << "Test 2: " << (solution.search(nums2, 3) ? "true" : "false") << endl;
    
    // Test Case 3
    vector<int> nums3 = {1,0,1,1,1};
    cout << "Test 3: " << (solution.search(nums3, 0) ? "true" : "false") << endl;
    
    return 0;
}
