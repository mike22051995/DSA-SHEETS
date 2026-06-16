/*
================================================================================
PROBLEM: Search in Rotated Sorted Array (LeetCode #33)
DIFFICULTY: Medium
PATTERN: Modified Binary Search
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown 
pivot index k (1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).

Given the array nums after the possible rotation and an integer target, return 
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Sorted array with rotation
2. Need O(log n) search
3. Can identify sorted half and decide direction
4. Modified binary search applicable

Key Indicators:
- "Rotated sorted array"
- "O(log n)" requirement
- Find target value
- Binary search modification needed

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

================================================================================
EXPLANATION:

Modified Binary Search:
1. Find mid element
2. Determine which half is sorted
3. Check if target is in sorted half
4. Adjust search space accordingly

Time: O(log n)
Space: O(1)

================================================================================
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
            
            if (nums[mid] == target) return mid;
            
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
    cout << "Search 0: " << sol.search(nums, 0) << endl;
    cout << "Search 3: " << sol.search(nums, 3) << endl;
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Find Minimum in Rotated Sorted Array (LeetCode #153)
2. Search in Rotated Sorted Array II (LeetCode #81)
3. Find Peak Element (LeetCode #162)
4. Find First and Last Position (LeetCode #34)
5. Single Element in Sorted Array (LeetCode #540)
6. Search a 2D Matrix (LeetCode #74)
7. Search a 2D Matrix II (LeetCode #240)
8. Koko Eating Bananas (LeetCode #875)
9. Capacity To Ship Packages (LeetCode #1011)
10. Split Array Largest Sum (LeetCode #410)
================================================================================
*/
