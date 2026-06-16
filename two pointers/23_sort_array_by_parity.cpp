/*
PROBLEM: Sort Array By Parity
---------------------------------------------------------------------------
Given an integer array nums, move all the even integers to the beginning 
of the array followed by all the odd integers. Return any array that 
satisfies this condition.

PATTERN: Two Pointers (Partition)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1] (or any array with evens first, then odds)
Explanation: [4,2,3,1], [2,4,1,3], and [4,2,1,3] are also valid.

Example 2:
Input: nums = [0]
Output: [0]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // Find odd number from left
            while (left < right && nums[left] % 2 == 0) {
                left++;
            }
            
            // Find even number from right
            while (left < right && nums[right] % 2 == 1) {
                right--;
            }
            
            // Swap
            if (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        return nums;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {3, 1, 2, 4};
    vector<int> result1 = sol.sortArrayByParity(nums1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0};
    vector<int> result2 = sol.sortArrayByParity(nums2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
