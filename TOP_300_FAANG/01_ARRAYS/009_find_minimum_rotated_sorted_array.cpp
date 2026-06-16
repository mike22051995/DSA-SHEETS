/*
================================================================================
PROBLEM: Find Minimum in Rotated Sorted Array (LeetCode #153)
DIFFICULTY: Medium
PATTERN: Binary Search / Modified Binary Search
COMPANIES: Amazon, Microsoft, Facebook, Google, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Suppose an array of length n sorted in ascending order is rotated between 
1 and n times. Given the rotated array nums of unique elements, return the 
minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example: [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Sorted array with rotation/modification
2. Need O(log n) solution
3. Binary search can be modified
4. Can determine which half contains answer

Key Indicators:
- "Rotated sorted array"
- O(log n) time requirement
- Finding min/max/target in rotated array
- Array has some ordering property

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: Array was [1,2,3,4,5], rotated 3 times

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: Array was [0,1,2,4,5,6,7], rotated 4 times

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: Array not rotated (or rotated n times)

================================================================================
EXPLANATION:

Modified Binary Search:
- In rotated array, one half is always sorted
- Minimum is at the rotation point
- Compare mid with left and right to decide direction

Key Observations:
1. If nums[mid] > nums[right]: min is in right half
2. Else: min is in left half (including mid)

Algorithm:
1. Use binary search
2. Check if right half is sorted (nums[mid] < nums[right])
3. If yes, minimum in left (including mid)
4. If no, minimum in right (excluding mid)

Time Complexity: O(log n)
Space Complexity: O(1)

================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than rightmost element,
            // minimum must be in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise, minimum is in left half (including mid)
            else {
                right = mid;
            }
        }
        
        return nums[left];
    }
    
    // Alternative: Compare with left
    int findMinAlt(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // If array is not rotated
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid+1 is the minimum
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            
            // Check if mid is the minimum
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            
            // Decide which half to search
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return nums[left];
    }
};

void runTest(vector<int> nums, string testName) {
    Solution sol;
    int result = sol.findMin(nums);
    
    cout << testName << ": " << endl;
    cout << "Input:  [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Minimum: " << result << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    runTest(nums1, "Test 1");
    
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    runTest(nums2, "Test 2");
    
    vector<int> nums3 = {11, 13, 15, 17};
    runTest(nums3, "Test 3");
    
    vector<int> nums4 = {2, 1};
    runTest(nums4, "Test 4");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Search in Rotated Sorted Array (LeetCode #33) - Medium
   - Find target in rotated array

2. Find Minimum in Rotated Sorted Array II (LeetCode #154) - Hard
   - With duplicates (O(n) worst case)

3. Search in Rotated Sorted Array II (LeetCode #81) - Medium
   - Search with duplicates

4. Find Peak Element (LeetCode #162) - Medium
   - Modified binary search

5. Single Element in a Sorted Array (LeetCode #540) - Medium
   - Binary search variation

6. First Bad Version (LeetCode #278) - Easy
   - Basic binary search

7. Median of Two Sorted Arrays (LeetCode #4) - Hard
   - Advanced binary search

8. Kth Smallest Element in a Sorted Matrix (LeetCode #378) - Medium
   - Binary search on value range

9. Split Array Largest Sum (LeetCode #410) - Hard
   - Binary search on answer

10. Capacity To Ship Packages Within D Days (LeetCode #1011) - Medium
    - Binary search on capacity

================================================================================
KEY INSIGHTS:
================================================================================

1. Identifying Rotation Point:
   - Where nums[i] > nums[i+1]
   - This is where minimum lies

2. Binary Search Modification:
   - Can't simply compare mid with target
   - Must identify which half is sorted
   - Then determine which side has minimum

3. Edge Cases:
   - Array not rotated (already sorted)
   - Rotated by n (same as not rotated)
   - Array with 2 elements
   - Single element

4. With Duplicates (Follow-up):
   - Can't always determine which half
   - Worst case becomes O(n)
   - Need to handle nums[mid] == nums[right]

================================================================================
*/
