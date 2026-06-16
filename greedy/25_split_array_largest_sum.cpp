/*
PROBLEM: Split Array Largest Sum (LeetCode 410)
DIFFICULTY: Hard
PATTERN: Binary Search + Greedy Validation

DESCRIPTION:
Given an array nums which consists of non-negative integers and an integer m, you can split 
the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest 
sum among these m subarrays.

INPUT:
- nums: array of non-negative integers
- m: number of subarrays

OUTPUT:
- Minimized largest sum

APPROACH:
1. Binary search on answer: range [max(nums), sum(nums)]
2. For each mid value, check if we can split into ≤m subarrays with max sum ≤ mid
3. Greedy validation: accumulate sum, create new subarray when exceeds mid
4. Adjust binary search based on validation result

WHY GREEDY WORKS:
For validation, greedily adding elements to current subarray until limit is optimal.
Binary search finds the minimum feasible maximum sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = *max_element(nums.begin(), nums.end());  // Min possible: largest element
        long right = accumulate(nums.begin(), nums.end(), 0L); // Max possible: sum of all
        
        while (left < right) {
            long mid = left + (right - left) / 2;
            
            if (canSplit(nums, m, mid)) {
                right = mid;  // Can achieve mid, try smaller
            } else {
                left = mid + 1;  // Can't achieve mid, need larger
            }
        }
        
        return left;
    }
    
private:
    // Greedy validation: can we split into ≤m subarrays with max sum ≤ maxSum?
    bool canSplit(vector<int>& nums, int m, long maxSum) {
        int subarrays = 1;
        long currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                // Start new subarray
                subarrays++;
                currentSum = num;
                
                if (subarrays > m) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << "Test 1 - nums: [7,2,5,10,8], m=2" << endl;
    cout << "Output: " << sol.splitArray(nums1, 2) << endl;
    cout << "Expected: 18 (split: [7,2,5] and [10,8])" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Test 2 - nums: [1,2,3,4,5], m=2" << endl;
    cout << "Output: " << sol.splitArray(nums2, 2) << endl;
    cout << "Expected: 9 (split: [1,2,3,4] and [5])" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 4, 4};
    cout << "Test 3 - nums: [1,4,4], m=3" << endl;
    cout << "Output: " << sol.splitArray(nums3, 3) << endl;
    cout << "Expected: 4" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n * log(sum)) where n is array length, sum is array sum
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Binary search on answer: when answer space is continuous
- Greedy validation function for feasibility check
- Pattern: minimize maximum or maximize minimum
- Appears in: book allocation, painter partition, capacity to ship
- Combine binary search + greedy for optimization
- Very popular in competitive programming and interviews
*/
