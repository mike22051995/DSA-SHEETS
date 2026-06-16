/*
================================================================================
PROBLEM: Search Insert Position (LeetCode #35)
DIFFICULTY: Easy
PATTERN: Binary Search
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
Given a sorted array of distinct integers and a target value, return the index
if the target is found. If not, return the index where it would be inserted in
order.

EXAMPLES:
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

CODE EXPLANATION:
- Standard binary search over the array.
- If target is not found, left ends at the insertion index.
- Return left after the loop.
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
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
        
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,6};
    
    cout << "Insert position for 5: " << sol.searchInsert(nums, 5) << endl;
    cout << "Insert position for 2: " << sol.searchInsert(nums, 2) << endl;
    cout << "Insert position for 7: " << sol.searchInsert(nums, 7) << endl;
    cout << "Insert position for 0: " << sol.searchInsert(nums, 0) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Binary Search (LeetCode #704)
2. First Bad Version (LeetCode #278)
3. Find Smallest Letter Greater Than Target (LeetCode #744)
4. Find First and Last Position (LeetCode #34)
5. Search in Rotated Sorted Array (LeetCode #33)
6. Peak Index in Mountain Array (LeetCode #852)
7. Find Peak Element (LeetCode #162)
8. Valid Perfect Square (LeetCode #367)
9. Sqrt(x) (LeetCode #69)
10. Arranging Coins (LeetCode #441)
*/
