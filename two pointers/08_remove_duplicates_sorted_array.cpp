/*
PROBLEM: Remove Duplicates from Sorted Array
---------------------------------------------------------------------------
Given an integer array nums sorted in non-decreasing order, remove the 
duplicates in-place such that each unique element appears only once. 
Return the number of unique elements in nums.

PATTERN: Fast-Slow Two Pointers (Same Direction)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Function returns 2, with first two elements being 1 and 2.

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Function returns 5, with first five elements being 0,1,2,3,4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int slow = 0; // Position to place next unique element
        
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        
        return slow + 1;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int len1 = sol.removeDuplicates(nums1);
    cout << "Test 1: Length = " << len1 << ", Array = [";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << (i < len1 - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len2 = sol.removeDuplicates(nums2);
    cout << "Test 2: Length = " << len2 << ", Array = [";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << (i < len2 - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
