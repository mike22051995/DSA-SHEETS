/*
PROBLEM: Sort Colors (Dutch National Flag)
---------------------------------------------------------------------------
Given an array nums with n objects colored red, white, or blue (represented 
by integers 0, 1, and 2), sort them in-place so that objects of the same 
color are adjacent, with colors in order red, white, and blue.

PATTERN: Three Pointers (Dutch National Flag)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;      // Boundary for 0s
        int mid = 0;      // Current element
        int high = nums.size() - 1;  // Boundary for 2s
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Test 1: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << (i < nums1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "Test 2: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << (i < nums2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
