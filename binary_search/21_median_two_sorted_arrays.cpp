/*
PROBLEM: Median of Two Sorted Arrays
Difficulty: Hard
Pattern: Binary Search

DESCRIPTION:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of 
the two sorted arrays. The overall run time complexity should be O(log (m+n)).

EXPLANATION:
Binary search on partition:
- Partition both arrays such that left half has same number of elements as right
- Ensure max(left1, left2) <= min(right1, right2)
- Median depends on whether total length is odd or even

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: Merged = [1,2,3], median = 2

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: Merged = [1,2,3,4], median = (2+3)/2 = 2.5

Example 3:
Input: nums1 = [], nums2 = [1]
Output: 1.00000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
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

    double findMedianSortedArraysMerge(vector<int>& nums1, vector<int>& nums2) {
        int total = static_cast<int>(nums1.size() + nums2.size());
        int mid1 = (total - 1) / 2;
        int mid2 = total / 2;

        int i = 0;
        int j = 0;
        int idx = 0;
        int val1 = 0;
        int val2 = 0;

        while (idx <= mid2) {
            int nextVal;
            if (j >= static_cast<int>(nums2.size()) ||
                (i < static_cast<int>(nums1.size()) && nums1[i] <= nums2[j])) {
                nextVal = nums1[i++];
            } else {
                nextVal = nums2[j++];
            }

            if (idx == mid1) {
                val1 = nextVal;
            }
            if (idx == mid2) {
                val2 = nextVal;
            }
            idx++;
        }

        if (total % 2 == 0) {
            return (val1 + val2) / 2.0;
        }
        return val2;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1: " << solution.findMedianSortedArrays(nums1, nums2) << endl;
    cout << "Test 1 (merge): " << solution.findMedianSortedArraysMerge(nums1, nums2) << endl;
    
    // Test Case 2
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Test 2: " << solution.findMedianSortedArrays(nums3, nums4) << endl;
    cout << "Test 2 (merge): " << solution.findMedianSortedArraysMerge(nums3, nums4) << endl;
    
    // Test Case 3
    vector<int> nums5 = {};
    vector<int> nums6 = {1};
    cout << "Test 3: " << solution.findMedianSortedArrays(nums5, nums6) << endl;
    cout << "Test 3 (merge): " << solution.findMedianSortedArraysMerge(nums5, nums6) << endl;
    
    return 0;
}
