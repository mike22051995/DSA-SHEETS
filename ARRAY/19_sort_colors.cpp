/*
PROBLEM: Sort Colors (Dutch National Flag)
Difficulty: Medium
Pattern: Three Pointers, Partitioning

DESCRIPTION:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

EXPLANATION:
Dutch National Flag Algorithm (Three-way partitioning):
- Use three pointers: low, mid, high
- low tracks the boundary of 0s, high tracks boundary of 2s
- mid scans the array
- Swap elements to maintain: [0s][1s][2s]

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Explanation: All 0s, then 1s, then 2s

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
Explanation: One of each color

Example 3:
Input: nums = [1,2,0]
Output: [0,1,2]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;           // Boundary for 0s
        int mid = 0;           // Current element
        int high = nums.size() - 1; // Boundary for 2s
        
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
                // Don't increment mid, need to check swapped element
            }
        }
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
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums1);
    cout << "Test 1: ";
    printArray(nums1);
    
    // Test Case 2
    vector<int> nums2 = {2, 0, 1};
    solution.sortColors(nums2);
    cout << "Test 2: ";
    printArray(nums2);
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 0};
    solution.sortColors(nums3);
    cout << "Test 3: ";
    printArray(nums3);
    
    return 0;
}
