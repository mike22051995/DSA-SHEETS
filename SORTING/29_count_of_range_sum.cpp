/*
PROBLEM: Count of Range Sum (LeetCode 327)
===============================================
DESCRIPTION:
Given an integer array nums and two integers lower and upper, return the number 
of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of elements in nums between indices i 
and j inclusive, where i <= j.

PATTERN: Modified Merge Sort with Prefix Sums
DIFFICULTY: Hard
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
nums = [-2,5,-1], lower = -2, upper = 2

OUTPUT:
3
Explanation: Ranges [0,0], [2,2], [0,2] have sums in [-2,2]

EXAMPLE:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3

Input: nums = [0], lower = 0, upper = 0
Output: 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        // Calculate prefix sums
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // Use modified merge sort to count valid ranges
        return mergeSort(prefixSum, 0, n, lower, upper);
    }
    
private:
    int mergeSort(vector<long long>& sums, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        
        int mid = left + (right - left) / 2;
        
        // Count in left and right halves
        int count = mergeSort(sums, left, mid, lower, upper) + 
                    mergeSort(sums, mid, right, lower, upper);
        
        // Count cross ranges
        count += countCross(sums, left, mid, right, lower, upper);
        
        // Merge
        merge(sums, left, mid, right);
        
        return count;
    }
    
    int countCross(vector<long long>& sums, int left, int mid, int right, 
                   int lower, int upper) {
        int count = 0;
        int j = mid, k = mid;
        
        // For each prefix sum in left half
        for (int i = left; i < mid; i++) {
            // Find range [j, k) where sums[j] - sums[i] >= lower
            // and sums[k] - sums[i] > upper
            
            // Find first j where sums[j] - sums[i] >= lower
            while (j < right && sums[j] - sums[i] < lower) j++;
            
            // Find first k where sums[k] - sums[i] > upper
            while (k < right && sums[k] - sums[i] <= upper) k++;
            
            count += k - j;
        }
        
        return count;
    }
    
    void merge(vector<long long>& sums, int left, int mid, int right) {
        vector<long long> temp;
        int i = left, j = mid;
        
        while (i < mid && j < right) {
            if (sums[i] <= sums[j]) {
                temp.push_back(sums[i++]);
            } else {
                temp.push_back(sums[j++]);
            }
        }
        
        while (i < mid) temp.push_back(sums[i++]);
        while (j < right) temp.push_back(sums[j++]);
        
        for (int k = left; k < right; k++) {
            sums[k] = temp[k - left];
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {-2, 5, -1};
    int lower1 = -2, upper1 = 2;
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nRange: [" << lower1 << ", " << upper1 << "]" << endl;
    cout << "Count: " << sol.countRangeSum(nums1, lower1, upper1) << endl;
    
    vector<int> nums2 = {0};
    int lower2 = 0, upper2 = 0;
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nRange: [" << lower2 << ", " << upper2 << "]" << endl;
    cout << "Count: " << sol.countRangeSum(nums2, lower2, upper2) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
PROBLEM BREAKDOWN:
Range sum S(i,j) = nums[i] + nums[i+1] + ... + nums[j]
Find count where lower <= S(i,j) <= upper

KEY INSIGHT:
Use prefix sums: prefixSum[i] = nums[0] + ... + nums[i-1]
Range sum S(i,j) = prefixSum[j+1] - prefixSum[i]

Need to find pairs (i,j) where:
lower <= prefixSum[j+1] - prefixSum[i] <= upper
i.e., prefixSum[i] + lower <= prefixSum[j+1] <= prefixSum[i] + upper

NAIVE APPROACH: O(n²)
Check all pairs - too slow

OPTIMIZED: Modified Merge Sort
Similar to "Count Smaller After Self" and "Reverse Pairs"

WHY MERGE SORT:
When we have sorted left and right halves:
- For each prefixSum[i] in left half
- Find count of prefixSum[j] in right half satisfying condition
- Both halves sorted → use two pointers efficiently

COUNTING ALGORITHM:
For each prefixSum[i] in left half [left, mid):
1. Find first j where prefixSum[j] - prefixSum[i] >= lower
2. Find first k where prefixSum[j] - prefixSum[i] > upper
3. Count = k - j (all elements in [j, k) satisfy condition)

EXAMPLE WALKTHROUGH:
Input: nums = [-2, 5, -1], lower = -2, upper = 2

Prefix sums: [0, -2, 3, 2]
(Index 0 is dummy 0)

We need pairs (i,j) where i < j and:
lower <= prefixSum[j] - prefixSum[i] <= upper
-2 <= prefixSum[j] - prefixSum[i] <= 2

Valid ranges:
- (0,0): -2 - 0 = -2 ✓ (in range)
- (0,1): 3 - 0 = 3 ✗
- (0,2): 2 - 0 = 2 ✓
- (1,1): 3 - (-2) = 5 ✗
- (1,2): 2 - (-2) = 4 ✗
- (2,2): 2 - 3 = -1 ✓

Count = 3

MERGE SORT PROCESS:
1. Split prefix sums into halves
2. Recursively count in each half
3. Count cross ranges (one index in left, one in right)
4. Merge sorted halves

CROSS COUNTING:
For sorted left half and sorted right half:
- Since both sorted, can use two pointers
- For each left element, find valid range in right
- Increment count by range size

TIME COMPLEXITY:
T(n) = 2T(n/2) + O(n)
- 2T(n/2): recursive calls
- O(n): counting + merging
Result: O(n log n)

WHY THIS PATTERN IS IMPORTANT:
- Combines prefix sums with merge sort
- Shows modification of merge sort for range queries
- Similar patterns in:
  * Range sum queries
  * Inversion counting variants
  * Order statistics problems
- Tests advanced algorithmic thinking
- Asked at top companies (Google, Amazon)
- Demonstrates divide and conquer mastery
*/
