/*
PROBLEM: Maximum Gap (LeetCode 164)
===============================================
DESCRIPTION:
Given an integer array nums, return the maximum difference between two successive 
elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.

PATTERN: Bucket Sort / Pigeonhole Principle
DIFFICULTY: Hard
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Maximum gap in sorted array

EXAMPLE:
Input: [3,6,9,1]
Output: 3
Explanation: Sorted [1,3,6,9], max gap is 6-3 = 3

Input: [10]
Output: 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        // Find min and max
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        if (minVal == maxVal) return 0; // All elements same
        
        // Calculate bucket size and count
        // Gap must be at least (max - min) / (n - 1)
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;
        
        // Create buckets
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        
        // Place elements in buckets
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
        }
        
        // Calculate maximum gap
        int maxGap = 0;
        int prevMax = minVal;
        
        for (int i = 0; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX) continue; // Empty bucket
            
            // Gap between previous bucket's max and current bucket's min
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        
        return maxGap;
    }
    
    // Alternative: Radix Sort approach (also O(n))
    int maximumGapRadix(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        // Radix sort
        radixSort(nums);
        
        // Find max gap
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        
        return maxGap;
    }
    
private:
    void radixSort(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Sort by each digit
        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            countingSortByDigit(nums, exp);
        }
    }
    
    void countingSortByDigit(vector<int>& nums, int exp) {
        int n = nums.size();
        vector<int> output(n);
        int count[10] = {0};
        
        // Count occurrences
        for (int num : nums) {
            count[(num / exp) % 10]++;
        }
        
        // Cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            output[count[digit] - 1] = nums[i];
            count[digit]--;
        }
        
        // Copy back
        nums = output;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 6, 9, 1};
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    cout << "Maximum gap: " << sol.maximumGap(nums1) << endl;
    
    vector<int> nums2 = {10};
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    cout << "Maximum gap: " << sol.maximumGap(nums2) << endl;
    
    vector<int> nums3 = {1, 10000000};
    cout << "\nInput: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;
    cout << "Maximum gap: " << sol.maximumGap(nums3) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
CHALLENGE:
Must achieve O(n) time - comparison-based sorting is O(n log n)
Need non-comparison sorting: bucket sort or radix sort

APPROACH 1: BUCKET SORT (OPTIMAL)
KEY INSIGHT - Pigeonhole Principle:
- With n numbers in range [min, max]
- Average gap = (max - min) / (n - 1)
- Maximum gap >= average gap
- Maximum gap won't be within a bucket (if bucket size = average gap)
- Maximum gap must be between buckets

ALGORITHM:
1. Find min and max values
2. Calculate bucket size = ceiling((max - min) / (n - 1))
3. Create buckets, track min and max in each bucket
4. Maximum gap = max difference between adjacent buckets

BUCKET PLACEMENT:
For value num: bucket_index = (num - minVal) / bucketSize

WHY MAX GAP IS BETWEEN BUCKETS:
- Bucket size ≈ average gap
- Elements within same bucket have difference < bucket size
- Maximum gap must be > average gap
- Therefore, max gap is between buckets, not within

EXAMPLE WALKTHROUGH:
Input: [3, 6, 9, 1]
n = 4, min = 1, max = 9

Bucket size = (9-1)/(4-1) = 8/3 ≈ 3
Bucket count = (9-1)/3 + 1 = 3

Buckets (range [1,4), [4,7), [7,10)):
- Bucket 0: [1,4) → min=1, max=3
- Bucket 1: [4,7) → min=6, max=6
- Bucket 2: [7,10) → min=9, max=9

Gaps between buckets:
- Bucket 0 max (3) to Bucket 1 min (6): gap = 3
- Bucket 1 max (6) to Bucket 2 min (9): gap = 3

Maximum gap = 3

APPROACH 2: RADIX SORT
- Sort using radix sort: O(d*n) where d = number of digits
- For 32-bit integers, d is constant
- After sorting, scan for max consecutive difference

COMPARISON:
Bucket Sort:
- More clever
- Direct calculation
- One pass after bucketing

Radix Sort:
- More straightforward
- Actual sorting
- Multiple passes

TIME COMPLEXITY:
Both approaches: O(n)
Space: O(n) for buckets/temp arrays

EDGE CASES:
1. n < 2: return 0
2. All same: return 0
3. Two elements: return difference
4. Large range: ensure no overflow in calculations

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates O(n) sorting algorithms
- Shows pigeonhole principle application
- Non-comparison sorting techniques
- Important for:
  * Problems requiring linear time
  * Understanding sorting limitations
  * Advanced algorithmic thinking
- Tests knowledge beyond standard sorting
- Asked at Google, Facebook (hard interviews)
*/
