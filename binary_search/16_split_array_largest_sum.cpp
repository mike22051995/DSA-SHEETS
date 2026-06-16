/*
PROBLEM: Split Array Largest Sum
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Given an array nums which consists of non-negative integers and an integer m, you can split 
the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest 
sum among these m subarrays.

EXPLANATION:
Binary search on the largest sum:
- Min sum = max(nums) (each subarray has at least one element)
- Max sum = sum(nums) (all in one subarray)
- For each mid, check if can split into m subarrays with max sum <= mid
- Find minimum such sum

Time Complexity: O(n * log(sum))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation: Split into [7,2,5] and [10,8], max is 18

Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9
Explanation: Split into [1,2,3,4] and [5], max is 9

Example 3:
Input: nums = [1,4,4], m = 3
Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canSplit(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canSplit(vector<int>& nums, int m, int maxSum) {
        int subarrays = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {
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
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {7,2,5,10,8};
    cout << "Test 1: " << solution.splitArray(nums1, 2) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1,2,3,4,5};
    cout << "Test 2: " << solution.splitArray(nums2, 2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1,4,4};
    cout << "Test 3: " << solution.splitArray(nums3, 3) << endl;
    
    return 0;
}
