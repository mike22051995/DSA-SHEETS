/*
PROBLEM: Merge Two Sorted Arrays
===============================================
DESCRIPTION:
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one 
sorted array. The number of elements in nums1 and nums2 are m and n respectively.
Assume nums1 has enough space to hold additional elements from nums2.

PATTERN: Two Pointer + Merge
DIFFICULTY: Easy
TIME COMPLEXITY: O(m + n)
SPACE COMPLEXITY: O(1)

INPUT:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

OUTPUT:
nums1 = [1,2,2,3,5,6]

EXAMPLE:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end to avoid overwriting elements in nums1
        int i = m - 1;      // Last element in nums1's initial portion
        int j = n - 1;      // Last element in nums2
        int k = m + n - 1;  // Last position in nums1
        
        // Merge from back to front
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If any elements left in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
        // No need to copy remaining elements from nums1 as they're already in place
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    
    cout << "nums1: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nnums2: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    sol.merge(nums1, m, nums2, n);
    
    cout << "Merged array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
1. Key insight: Merge from end to beginning to avoid overwriting
2. Use three pointers: i (last of nums1), j (last of nums2), k (last position)
3. Compare elements from both arrays and place larger one at position k
4. Move corresponding pointers backward
5. If nums2 has remaining elements, copy them (nums1 elements already in place)

WHY MERGE FROM BACK?
- Merging from front would require shifting elements
- Back-to-front utilizes the extra space in nums1 efficiently
- No additional space needed

WHY THIS PATTERN IS IMPORTANT:
- Foundation of merge sort
- Common in merge operations
- Two pointer technique with sorted arrays
- In-place merging technique
- Asked frequently in interviews
*/
