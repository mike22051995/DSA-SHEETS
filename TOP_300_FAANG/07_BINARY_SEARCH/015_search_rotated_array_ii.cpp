/*
================================================================================
PROBLEM: Search in Rotated Sorted Array II (LeetCode #81)
DIFFICULTY: Medium
PATTERN: Binary Search (with duplicates)
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================

PROBLEM DESCRIPTION:
There is an integer array nums sorted in non-decreasing order (not necessarily
with distinct values). Given the array nums after the rotation and an integer
target, return true if target is in nums, or false if it is not in nums.

EXAMPLES:

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Example 3:
Input: nums = [1,0,1,1,1], target = 0
Output: true

PATTERN RECOGNITION:
Use this pattern when:
- Rotated sorted array with possible duplicates
- Need to search for a target
- Binary search with duplicate handling

CODE EXPLANATION:
- Use modified binary search with left/right pointers.
- If nums[left], nums[mid], and nums[right] are equal, shrink both ends.
- Otherwise determine which half is sorted and check if target lies within it.
TIME COMPLEXITY: O(log n) average, O(n) worst case with duplicates
SPACE COMPLEXITY: O(1)
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
            }
            // Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
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
    Solution sol;
    
    vector<int> nums1 = {2,5,6,0,0,1,2};
    vector<int> nums2 = {2,5,6,0,0,1,2};
    vector<int> nums3 = {1,0,1,1,1};
    
    cout << "Search 0 in [2,5,6,0,0,1,2]: " << (sol.search(nums1, 0) ? "true" : "false") << endl;
    cout << "Search 3 in [2,5,6,0,0,1,2]: " << (sol.search(nums2, 3) ? "true" : "false") << endl;
    cout << "Search 0 in [1,0,1,1,1]: " << (sol.search(nums3, 0) ? "true" : "false") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(log n) average, O(n) worst case
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Search in Rotated Sorted Array (LeetCode #33)
2. Find Minimum in Rotated Sorted Array II (LeetCode #154)
3. Find Minimum in Rotated Sorted Array (LeetCode #153)
4. Binary Search (LeetCode #704)
5. Find First and Last Position (LeetCode #34)
6. Search Insert Position (LeetCode #35)
7. Single Element in Sorted Array (LeetCode #540)
8. Peak Index in Mountain Array (LeetCode #852)
9. Find Peak Element (LeetCode #162)
10. Search a 2D Matrix II (LeetCode #240)
*/
