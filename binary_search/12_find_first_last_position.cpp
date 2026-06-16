/*
PROBLEM: Find First and Last Position of Element in Sorted Array
Difficulty: Medium
Pattern: Binary Search Variants

DESCRIPTION:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending 
position of a given target value. If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Use two binary searches:
1. First search: Find leftmost occurrence
2. Second search: Find rightmost occurrence
Modify standard binary search to continue searching even after finding target

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        
        if (nums.empty()) return result;
        
        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);
        
        return result;
    }
    
private:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1; // Continue searching left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1; // Continue searching right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {5,7,7,8,8,10};
    vector<int> result1 = solution.searchRange(nums1, 8);
    cout << "Test 1: [" << result1[0] << "," << result1[1] << "]" << endl;
    
    // Test Case 2
    vector<int> nums2 = {5,7,7,8,8,10};
    vector<int> result2 = solution.searchRange(nums2, 6);
    cout << "Test 2: [" << result2[0] << "," << result2[1] << "]" << endl;
    
    // Test Case 3
    vector<int> nums3 = {};
    vector<int> result3 = solution.searchRange(nums3, 0);
    cout << "Test 3: [" << result3[0] << "," << result3[1] << "]" << endl;
    
    return 0;
}
