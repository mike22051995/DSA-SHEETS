/*
================================================================================
PROBLEM: Find First and Last Position in Sorted Array (LeetCode #34)
DIFFICULTY: Medium
PATTERN: Binary Search (Lower & Upper Bound)
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================

PROBLEM DESCRIPTION:
Given a sorted array of integers and a target value, return the starting and
ending index of the target. If it does not exist, return [-1, -1].

EXAMPLES:
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

CODE EXPLANATION:
- Run binary search twice: once to find the first occurrence, once for the last.
- When a match is found, keep searching toward the boundary side.
- Combine both results into the final range.
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findFirst(nums, target);
        int right = findLast(nums, target);
        return {left, right};
    }
    
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
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    auto result = sol.searchRange(nums, 8);
    cout << "Range: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. First Bad Version (LeetCode #278)
2. Search Insert Position (LeetCode #35)
3. Find Minimum in Rotated Sorted Array (LeetCode #153)
4. Search in Rotated Sorted Array (LeetCode #33)
5. Count of Range Sum (LeetCode #327)
6. Find K Closest Elements (LeetCode #658)
7. Search a 2D Matrix (LeetCode #74)
8. Find Peak Element (LeetCode #162)
9. Single Element in Sorted Array (LeetCode #540)
10. Kth Smallest Element in Sorted Matrix (LeetCode #378)
*/
