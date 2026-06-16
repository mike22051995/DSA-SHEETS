/*
PROBLEM: Next Permutation
Difficulty: Medium
Pattern: Array Manipulation

DESCRIPTION:
A permutation of an array of integers is an arrangement of its members into a sequence or 
linear order. Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers. If such arrangement is not possible, it must rearrange 
it as the lowest possible order (i.e., sorted in ascending order).

EXPLANATION:
Algorithm:
1. Find the largest index i such that nums[i] < nums[i+1] (from right)
2. If no such index exists, reverse the entire array
3. Find the largest index j > i such that nums[j] > nums[i]
4. Swap nums[i] and nums[j]
5. Reverse the subarray from i+1 to end

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
Explanation: Next permutation of 123 is 132

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
Explanation: Already at largest permutation, wrap to smallest

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
Explanation: Next permutation considering duplicates
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Step 2: Find element just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            
            // Step 3: Swap
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse from i+1 to end
        reverse(nums.begin() + i + 1, nums.end());
    }
};

void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    solution.nextPermutation(nums1);
    cout << "Test 1: ";
    printArray(nums1);
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 1};
    solution.nextPermutation(nums2);
    cout << "Test 2: ";
    printArray(nums2);
    
    // Test Case 3
    vector<int> nums3 = {1, 1, 5};
    solution.nextPermutation(nums3);
    cout << "Test 3: ";
    printArray(nums3);
    
    return 0;
}
