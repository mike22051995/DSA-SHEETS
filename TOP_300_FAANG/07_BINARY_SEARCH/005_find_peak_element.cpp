/*
================================================================================
PROBLEM: Find Peak Element (LeetCode #162)
DIFFICULTY: Medium
PATTERN: Binary Search
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
Given an array of integers, return the index of any peak element. A peak element
is an element that is strictly greater than its neighbors.

EXAMPLES:
Example 1:
Input: nums = [1,2,3,1]
Output: 2

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5

CODE EXPLANATION:
- Compare mid with mid + 1 to determine which side has a peak.
- If nums[mid] > nums[mid + 1], the peak is on the left side.
- Otherwise the peak is on the right side; shrink until left == right.
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak is on left side or mid itself
                right = mid;
            } else {
                // Peak is on right side
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    // Linear scan
    int findPeakElementLinear(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return nums.size() - 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {1,2,1,3,5,6,4};
    
    cout << "Peak index (test 1): " << sol.findPeakElement(nums1) << endl;
    cout << "Peak index (test 2): " << sol.findPeakElement(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Find Peak Element II (LeetCode #1901)
2. Peak Index in Mountain Array (LeetCode #852)
3. Find in Mountain Array (LeetCode #1095)
4. Longest Mountain in Array (LeetCode #845)
5. Valid Mountain Array (LeetCode #941)
6. Find Minimum in Rotated Sorted Array (LeetCode #153)
7. Search in Rotated Sorted Array (LeetCode #33)
8. Single Element in Sorted Array (LeetCode #540)
9. Find K Closest Elements (LeetCode #658)
10. Kth Smallest Element in Sorted Matrix (LeetCode #378)
*/
