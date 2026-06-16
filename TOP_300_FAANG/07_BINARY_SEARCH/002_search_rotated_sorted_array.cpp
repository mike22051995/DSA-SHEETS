/*
================================================================================
PROBLEM: Search in Rotated Sorted Array (LeetCode #33)
DIFFICULTY: Medium
PATTERN: Modified Binary Search
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, LinkedIn
================================================================================

PROBLEM DESCRIPTION:
Given a rotated sorted array of distinct integers and a target value, return
the index of the target if it exists, otherwise return -1.

EXAMPLES:
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

CODE EXPLANATION:
- One half of the array is always sorted.
- Check which half is sorted and decide if the target lies in it.
- Shrink the search window like standard binary search.
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[right]) {
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
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Search 0: index = " << sol.search(nums, 0) << endl;
    cout << "Search 3: index = " << sol.search(nums, 3) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Search in Rotated Sorted Array II (LeetCode #81) - With duplicates
2. Find Minimum in Rotated Sorted Array (LeetCode #153)
3. Find Minimum in Rotated Sorted Array II (LeetCode #154)
4. Find Peak Element (LeetCode #162)
5. Search a 2D Matrix II (LeetCode #240)
6. Single Element in Sorted Array (LeetCode #540)
7. Time Based Key-Value Store (LeetCode #981)
8. Median of Two Sorted Arrays (LeetCode #4)
9. Kth Smallest Element in Sorted Matrix (LeetCode #378)
10. Count of Range Sum (LeetCode #327)
*/
