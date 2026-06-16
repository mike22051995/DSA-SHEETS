/*
PROBLEM: Remove Duplicates from Sorted Array
Difficulty: Easy
Pattern: Two Pointers

DESCRIPTION:
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
such that each unique element appears only once. The relative order of the elements should 
be kept the same. Return the number of unique elements in nums.

EXPLANATION:
Use two pointers: one for the position of unique elements and one to scan the array.
Since the array is sorted, duplicates are adjacent. We only copy elements that are 
different from the previous one.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: First 2 elements should be [1,2]

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: First 5 elements should be [0,1,2,3,4]

Example 3:
Input: nums = [1,2,3]
Output: 3, nums = [1,2,3]
Explanation: All elements are unique
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniquePos = 1; // Position for next unique element
        
        for (int i = 1; i < nums.size(); i++) {
            // If current element is different from previous
            if (nums[i] != nums[i - 1]) {
                nums[uniquePos] = nums[i];
                uniquePos++;
            }
        }
        
        return uniquePos;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 2};
    int len1 = solution.removeDuplicates(nums1);
    cout << "Test 1: Length = " << len1 << ", Array = [";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i];
        if (i < len1 - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len2 = solution.removeDuplicates(nums2);
    cout << "Test 2: Length = " << len2 << ", Array = [";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i];
        if (i < len2 - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    int len3 = solution.removeDuplicates(nums3);
    cout << "Test 3: Length = " << len3 << ", Array = [";
    for (int i = 0; i < len3; i++) {
        cout << nums3[i];
        if (i < len3 - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}
