/*
PROBLEM: Median of Two Sorted Arrays (LeetCode 4)
===============================================
DESCRIPTION:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
the median of the two sorted arrays. The overall run time complexity should be 
O(log(min(m,n))).

PATTERN: Binary Search on Sorted Arrays
DIFFICULTY: Hard
TIME COMPLEXITY: O(log(min(m,n)))
SPACE COMPLEXITY: O(1)

INPUT:
Two sorted arrays

OUTPUT:
Median of combined sorted array

EXAMPLE:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.0
Explanation: merged [1,2,3], median = 2

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.5
Explanation: merged [1,2,3,4], median = (2+3)/2 = 2.5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is smaller for efficiency
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        // Binary search on smaller array
        while (left <= right) {
            // Partition nums1 at i, nums2 at j
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            
            // Handle edge cases
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found correct partition
                if ((m + n) % 2 == 0) {
                    // Even total length
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // Odd total length
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Too far right in nums1, move left
                right = i - 1;
            } else {
                // Too far left in nums1, move right
                left = i + 1;
            }
        }
        
        return 0.0; // Should never reach here
    }
    
    // Alternative: Simple merge approach O(m+n)
    double findMedianSimple(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        
        // Merge arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        
        while (i < nums1.size()) merged.push_back(nums1[i++]);
        while (j < nums2.size()) merged.push_back(nums2[j++]);
        
        int n = merged.size();
        if (n % 2 == 0) {
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        } else {
            return merged[n/2];
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "nums1: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nnums2: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nMedian: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
    
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "\nnums1: ";
    for (int num : nums3) cout << num << " ";
    cout << "\nnums2: ";
    for (int num : nums4) cout << num << " ";
    cout << "\nMedian: " << sol.findMedianSortedArrays(nums3, nums4) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
MEDIAN DEFINITION:
- Odd length: middle element
- Even length: average of two middle elements

NAIVE APPROACH: O(m+n)
Merge arrays and find median - doesn't meet O(log) requirement

OPTIMAL APPROACH: Binary Search
KEY INSIGHT:
Partition both arrays such that:
1. Left partition has (m+n+1)/2 elements
2. All elements in left <= all elements in right

PARTITION CONCEPT:
nums1: [a1, a2, | a3, a4]  (partition at i)
nums2: [b1, b2, b3, | b4]  (partition at j)

Combined left: [a1, a2, b1, b2, b3]
Combined right: [a3, a4, b4]

CONDITIONS FOR VALID PARTITION:
1. i + j = (m + n + 1) / 2
2. nums1[i-1] <= nums2[j]  (maxLeft1 <= minRight2)
3. nums2[j-1] <= nums1[i]  (maxLeft2 <= minRight1)

BINARY SEARCH:
Search for correct partition point i in nums1
j is automatically determined: j = (m+n+1)/2 - i

ALGORITHM:
1. Binary search on smaller array (efficiency)
2. For each partition i:
   - Calculate j
   - Check if partition is valid
   - If maxLeft1 > minRight2: move left
   - If maxLeft2 > minRight1: move right
   - If valid: calculate median

MEDIAN CALCULATION:
Odd total: max(maxLeft1, maxLeft2)
Even total: (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2

EXAMPLE WALKTHROUGH:
nums1 = [1, 3], nums2 = [2]
m = 2, n = 1, total = 3 (odd)

Binary search on nums1:
left = 0, right = 2

Iteration 1:
i = 1, j = (3+1)/2 - 1 = 1
maxLeft1 = nums1[0] = 1
minRight1 = nums1[1] = 3
maxLeft2 = nums2[0] = 2
minRight2 = INT_MAX

Check: 1 <= INT_MAX ✓ and 2 <= 3 ✓
Valid partition!

Median (odd): max(1, 2) = 2

VISUALIZATION:
nums1: [1 | 3]
nums2: [2 |  ]

Left: [1, 2], Right: [3]
Median = 2

EDGE CASES:
1. Empty array: partition at boundary
2. One array much smaller
3. Duplicate elements
4. All elements in one array smaller/larger

TIME COMPLEXITY:
Binary search on smaller array: O(log(min(m,n)))

SPACE COMPLEXITY:
O(1) - constant extra space

WHY THIS PATTERN IS IMPORTANT:
- Classic binary search on answer
- Demonstrates partition technique
- Important for sorted array problems
- Tests binary search mastery
- Common in interviews (especially Google, Facebook)
- Foundation for kth element in sorted arrays
- Shows optimization from O(m+n) to O(log(min(m,n)))
- One of the hardest LeetCode problems
*/
