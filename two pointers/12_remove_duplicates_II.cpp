/*
PROBLEM: Remove Duplicates from Sorted Array II
---------------------------------------------------------------------------
Given an integer array nums sorted in non-decreasing order, remove some 
duplicates in-place such that each unique element appears at most twice. 
Return the number of elements in nums after removing the extra duplicates.

PATTERN: Fast-Slow Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Function returns 5, with first five elements 1,1,2,2,3.

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Function returns 7, with first seven elements 0,0,1,1,2,3,3.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int slow = 2; // Position to place next valid element
        
        for (int fast = 2; fast < nums.size(); fast++) {
            // Only add if not same as element two positions back
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        
        return slow;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int len1 = sol.removeDuplicates(nums1);
    cout << "Test 1: Length = " << len1 << ", Array = [";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << (i < len1 - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int len2 = sol.removeDuplicates(nums2);
    cout << "Test 2: Length = " << len2 << ", Array = [";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << (i < len2 - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
