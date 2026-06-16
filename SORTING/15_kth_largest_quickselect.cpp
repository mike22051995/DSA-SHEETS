/*
PROBLEM: Kth Largest Element using QuickSelect (LeetCode 215)
===============================================
DESCRIPTION:
Find the kth largest element in an unsorted array using QuickSelect algorithm.
This is more efficient than sorting the entire array.

PATTERN: QuickSelect / Partition
DIFFICULTY: Medium
TIME COMPLEXITY: O(n) average, O(n²) worst case
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers and k

OUTPUT:
Kth largest element

EXAMPLE:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    // Partition function (similar to QuickSort)
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    
    // Randomized partition for better average case
    int randomPartition(vector<int>& nums, int left, int right) {
        int randomIdx = left + rand() % (right - left + 1);
        swap(nums[randomIdx], nums[right]);
        return partition(nums, left, right);
    }
    
    // QuickSelect algorithm
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        // Partition array and get pivot index
        int pivotIdx = randomPartition(nums, left, right);
        
        // Check if pivot is at kth position
        if (pivotIdx == k) {
            return nums[k];
        } else if (pivotIdx > k) {
            // Search in left part
            return quickSelect(nums, left, pivotIdx - 1, k);
        } else {
            // Search in right part
            return quickSelect(nums, pivotIdx + 1, right, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int n = nums.size();
        // kth largest = (n-k)th smallest in 0-indexed
        return quickSelect(nums, 0, n - 1, n - k);
    }
    
    // Alternative: Using STL nth_element
    int findKthLargestSTL(vector<int>& nums, int k) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n - k, nums.end());
        return nums[n - k];
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Array: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nK = " << k1;
    cout << "\n" << k1 << "th largest: " << sol.findKthLargest(nums1, k1) << endl;
    
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "\nArray: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nK = " << k2;
    cout << "\n" << k2 << "th largest: " << sol.findKthLargest(nums2, k2) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
QUICKSELECT ALGORITHM:
1. Partition array around a pivot
2. If pivot is at kth position, return it
3. If pivot > k, search left part
4. If pivot < k, search right part

KEY INSIGHT:
- We don't need to sort entire array
- Only need to partition until kth element is found
- This reduces average complexity from O(n log n) to O(n)

RANDOMIZED PARTITION:
- Choose random pivot to avoid worst case
- Prevents O(n²) on sorted/nearly sorted input
- Provides O(n) average case guarantee

COMPARISON WITH SORTING:
Sorting:
- Time: O(n log n)
- Sorts entire array

QuickSelect:
- Time: O(n) average
- Only finds kth element
- Partial sorting

KTH LARGEST vs KTH SMALLEST:
- kth largest = (n-k)th smallest
- For kth largest in ascending order: index = n-k

OPTIMIZATION TECHNIQUES:
1. Randomized pivot selection
2. Median-of-three pivot
3. Iterative instead of recursive

WHY THIS PATTERN IS IMPORTANT:
- More efficient than sorting for selection problems
- Foundation for many order statistics problems
- Common in FAANG interviews
- Demonstrates optimization over naive approach
- Used in: Top K problems, median finding, etc.
- Shows trade-off between full sorting and partial sorting
*/
