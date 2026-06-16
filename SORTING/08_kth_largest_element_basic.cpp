/*
PROBLEM: Kth Largest Element in Array (Simple Approach)
===============================================
DESCRIPTION:
Find the kth largest element in an unsorted array. Note that it is the kth 
largest element in sorted order, not the kth distinct element.

PATTERN: Sorting Approach
DIFFICULTY: Easy
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)

INPUT:
nums = [3,2,1,5,6,4], k = 2

OUTPUT:
5

EXAMPLE:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5 (largest is 6, 2nd largest is 5)

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Sort and return
    int findKthLargest(vector<int>& nums, int k) {
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
    
    // Approach 2: Sort ascending and return from end
    int findKthLargestV2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    
    // Approach 3: Partial sort (more efficient)
    int findKthLargestV3(vector<int>& nums, int k) {
        // partial_sort puts k largest elements at the beginning
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
    
    // Approach 4: nth_element (most efficient for this approach)
    int findKthLargestV4(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Array: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nK = " << k1;
    cout << "\n" << k1 << "th largest element: " << sol.findKthLargest(nums1, k1) << endl;
    
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "\nArray: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nK = " << k2;
    cout << "\n" << k2 << "th largest element: " << sol.findKthLargest(nums2, k2) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: Sort Descending
- Sort array in descending order
- Return element at index k-1
- Simple but not most efficient

APPROACH 2: Sort Ascending
- Sort array in ascending order
- Return element at index (n-k)
- Same complexity as approach 1

APPROACH 3: Partial Sort
- Only partially sorts array (k elements)
- More efficient than full sort
- Time: O(n log k)

APPROACH 4: nth_element
- Uses quickselect-like algorithm
- Average O(n), worst O(n²)
- Most efficient STL approach

KEY POINTS:
- Kth largest = (n-k+1)th smallest
- In 0-indexed array: kth largest is at index k-1 when sorted descending
- Multiple approaches with different trade-offs

WHY THIS PATTERN IS IMPORTANT:
- Foundation for understanding QuickSelect (covered in medium section)
- Understanding of STL algorithms
- Trade-off between simplicity and efficiency
- Common interview question with multiple solution approaches
*/
