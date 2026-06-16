/*
PROBLEM: Binary Search
Difficulty: Easy
Pattern: Basic Binary Search

DESCRIPTION:
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. 
Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Classic binary search implementation:
1. Maintain left and right pointers
2. Calculate mid = left + (right - left) / 2
3. If nums[mid] == target, return mid
4. If nums[mid] < target, search right half
5. If nums[mid] > target, search left half
6. Return -1 if not found

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums

Example 3:
Input: nums = [5], target = 5
Output: 0
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
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    cout << "Test 1: " << solution.search(nums1, 9) << endl;
    
    // Test Case 2
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    cout << "Test 2: " << solution.search(nums2, 2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {5};
    cout << "Test 3: " << solution.search(nums3, 5) << endl;
    
    return 0;
}
