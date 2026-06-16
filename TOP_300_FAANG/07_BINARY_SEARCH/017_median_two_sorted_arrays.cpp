/*
================================================================================
PROBLEM: Median of Two Sorted Arrays (LeetCode #4)
DIFFICULTY: Hard
PATTERN: Binary Search
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Adobe
================================================================================

PROBLEM DESCRIPTION:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return
the median of the two sorted arrays. The overall run time complexity should
be O(log (m+n)).

EXAMPLES:

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

PATTERN RECOGNITION:
Use this pattern when:
- Need median of merged sorted arrays
- O(log(m+n)) time complexity required
- Binary search on partition point

CODE EXPLANATION:
- Binary search on the smaller array's partition position.
- Ensure left partitions have the correct number of elements.
- Adjust partitions until max(left) <= min(right), then compute median.
TIME COMPLEXITY: O(log min(m, n))
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        
        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found correct partition
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }
        
        return 0.0;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
    
    vector<int> nums3 = {1,2};
    vector<int> nums4 = {3,4};
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(log(min(m,n)))
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Kth Smallest Element in Sorted Matrix (LeetCode #378)
2. Find K-th Smallest Pair Distance (LeetCode #719)
3. Divide Two Integers (LeetCode #29)
4. Minimum Size Subarray Sum (LeetCode #209)
5. Search in Rotated Sorted Array (LeetCode #33)
6. Find Peak Element (LeetCode #162)
7. Find First and Last Position (LeetCode #34)
8. Search a 2D Matrix II (LeetCode #240)
9. H-Index II (LeetCode #275)
10. Split Array Largest Sum (LeetCode #410)
*/
