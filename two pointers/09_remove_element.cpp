/*
PROBLEM: Remove Element
---------------------------------------------------------------------------
Given an integer array nums and an integer val, remove all occurrences of 
val in nums in-place. Return the number of elements in nums which are not 
equal to val.

PATTERN: Fast-Slow Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Function returns 2, with first two elements being 2.

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,3,0,4,_,_,_]
Explanation: Function returns 5, with first five elements 0,1,3,0,4.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0; // Position to place next non-val element
        
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
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
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int len1 = sol.removeElement(nums1, val1);
    cout << "Test 1: Length = " << len1 << ", Array = [";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << (i < len1 - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int len2 = sol.removeElement(nums2, val2);
    cout << "Test 2: Length = " << len2 << ", Array = [";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << (i < len2 - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
