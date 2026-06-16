/*
PROBLEM: 3Sum (LeetCode 15)
===============================================
DESCRIPTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

PATTERN: Sorting + Two Pointer
DIFFICULTY: Medium
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1) excluding output

INPUT:
Array of integers

OUTPUT:
List of triplets that sum to zero

EXAMPLE:
Input: [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: [0,1,1]
Output: []
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 3) return result;
        
        // Sort array first
        sort(nums.begin(), nums.end());
        
        // Fix first element and find other two using two pointers
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Early termination: if smallest element > 0, no solution
            if (nums[i] > 0) break;
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i]; // We need two numbers that sum to target
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++; // Need larger sum
                } else {
                    right--; // Need smaller sum
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    vector<vector<int>> result1 = sol.threeSum(nums1);
    cout << "Output:" << endl;
    for (auto& triplet : result1) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
    
    vector<int> nums2 = {0, 0, 0};
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    vector<vector<int>> result2 = sol.threeSum(nums2);
    cout << "Output:" << endl;
    for (auto& triplet : result2) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
    
    return 0;
}

/*
EXPLANATION:
============
ALGORITHM:
1. Sort the array
2. Fix first element (i)
3. Use two pointers (left, right) to find two numbers summing to -nums[i]
4. Skip duplicates to avoid duplicate triplets

WHY SORTING HELPS:
- Enables two-pointer approach
- Makes duplicate detection easy
- Allows early termination

TWO POINTER TECHNIQUE:
After fixing nums[i], we need nums[left] + nums[right] = -nums[i]
- If sum < target: move left pointer right (increase sum)
- If sum > target: move right pointer left (decrease sum)
- If sum == target: found triplet, record and move both pointers

AVOIDING DUPLICATES:
1. Skip duplicate first elements: if (i > 0 && nums[i] == nums[i-1]) continue
2. Skip duplicate left elements: while (nums[left] == nums[left+1]) left++
3. Skip duplicate right elements: while (nums[right] == nums[right-1]) right--

EXAMPLE WALKTHROUGH:
Input: [-1, 0, 1, 2, -1, -4]
After sort: [-4, -1, -1, 0, 1, 2]

i=0, nums[i]=-4, target=4:
  left=1(-1), right=5(2): sum=1 < 4, left++
  left=2(-1), right=5(2): sum=1 < 4, left++
  left=3(0), right=5(2): sum=2 < 4, left++
  left=4(1), right=5(2): sum=3 < 4, left++
  left > right, done

i=1, nums[i]=-1, target=1:
  left=2(-1), right=5(2): sum=1 == 1 ✓ → [-1,-1,2]
  left=3(0), right=4(1): sum=1 == 1 ✓ → [-1,0,1]

i=2, nums[i]=-1: skip (duplicate)

Result: [[-1,-1,2], [-1,0,1]]

OPTIMIZATIONS:
1. Early termination: if nums[i] > 0, break (all remaining positive)
2. Skip duplicates immediately
3. Use target = -nums[i] for clearer logic

WHY THIS PATTERN IS IMPORTANT:
- Foundation for 3Sum problems (Closest, Smaller, etc.)
- Demonstrates sorting + two pointer combination
- Important duplicate handling technique
- Common in FAANG interviews
- Extends to 4Sum and kSum problems
- Shows reduction from O(n³) to O(n²)
*/
