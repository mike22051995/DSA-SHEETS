/*
================================================================================
PROBLEM: Find Minimum in Rotated Sorted Array II (LeetCode #154)
DIFFICULTY: Hard
PATTERN: Binary Search (with duplicates)
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Suppose an array of length n sorted in ascending order is rotated between
1 and n times. Given the sorted rotated array nums that may contain duplicates,
return the minimum element of this array.

EXAMPLES:

Example 1:
Input: nums = [1,3,5]
Output: 1

Example 2:
Input: nums = [2,2,2,0,1]
Output: 0

Example 3:
Input: nums = [3,3,1,3]
Output: 1

PATTERN RECOGNITION:
Use this pattern when:
- Rotated sorted array with duplicates
- Need to find minimum/maximum/target
- Binary search with special handling for duplicates

CODE EXPLANATION:
- Use binary search with left/right pointers.
- When nums[mid] < nums[right], the min is in the left half.
- When nums[mid] > nums[right], the min is in the right half.
- When equal, shrink right by one to handle duplicates.
TIME COMPLEXITY: O(log n) average, O(n) worst case with many duplicates
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // Minimum is in right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // Minimum is in left half including mid
                right = mid;
            } else {
                // nums[mid] == nums[right], can't determine which half
                // Reduce search space by one element
                right--;
            }
        }
        
        return nums[left];
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,3,5};
    vector<int> nums2 = {2,2,2,0,1};
    vector<int> nums3 = {3,3,1,3};
    
    cout << "Minimum in [1,3,5]: " << sol.findMin(nums1) << endl;
    cout << "Minimum in [2,2,2,0,1]: " << sol.findMin(nums2) << endl;
    cout << "Minimum in [3,3,1,3]: " << sol.findMin(nums3) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(log n) average, O(n) worst case with all duplicates
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Find Minimum in Rotated Sorted Array (LeetCode #153)
2. Search in Rotated Sorted Array (LeetCode #33)
3. Search in Rotated Sorted Array II (LeetCode #81)
4. Find Peak Element (LeetCode #162)
5. Find Peak Element II (LeetCode #1901)
6. Peak Index in Mountain Array (LeetCode #852)
7. Single Element in Sorted Array (LeetCode #540)
8. Search a 2D Matrix (LeetCode #74)
9. Search a 2D Matrix II (LeetCode #240)
10. Median of Two Sorted Arrays (LeetCode #4)
*/
