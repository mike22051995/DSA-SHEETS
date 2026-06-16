/*
================================================================================
PROBLEM: Median of Two Sorted Arrays (LeetCode #4)
DIFFICULTY: Hard
PATTERN: Binary Search
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
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
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
    
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Find K-th Smallest Pair Distance (LeetCode #719)
2. Kth Smallest Element in Sorted Matrix (LeetCode #378)
3. Find Median from Data Stream (LeetCode #295)
4. Sliding Window Median (LeetCode #480)
5. Minimum Size Subarray Sum (LeetCode #209)
6. Count of Range Sum (LeetCode #327)
7. K-th Smallest Prime Fraction (LeetCode #786)
8. Ugly Number II (LeetCode #264)
9. Super Ugly Number (LeetCode #313)
10. Split Array Largest Sum (LeetCode #410)
*/
