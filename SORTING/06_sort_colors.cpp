 /*
PROBLEM: Sort Colors / Dutch National Flag Problem (LeetCode 75)
===============================================
DESCRIPTION:
Given an array with n objects colored red, white, or blue, sort them in-place so 
that objects of the same color are adjacent, with colors in order red, white, blue.
Use integers 0, 1, and 2 to represent red, white, and blue respectively.

PATTERN: Three Pointer / Dutch National Flag
DIFFICULTY: Easy-Medium
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers (0, 1, 2)

OUTPUT:
Sorted array with all 0s, then 1s, then 2s

EXAMPLE:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;              // Boundary for 0s
        int mid = 0;              // Current element
        int high = nums.size() - 1; // Boundary for 2s
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Found 0, swap with low boundary and move both forward
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Found 1, it's in correct region, just move mid
                mid++;
            } else {
                // Found 2, swap with high boundary and move high backward
                swap(nums[mid], nums[high]);
                high--;
                // Don't increment mid as we need to check swapped element
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    sol.sortColors(nums);
    
    cout << "Sorted array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
Dutch National Flag Algorithm (by Edsger Dijkstra)

THREE REGIONS:
[0...low-1]   -> All 0s
[low...mid-1] -> All 1s
[mid...high]  -> Unknown (to be processed)
[high+1...n]  -> All 2s

ALGORITHM:
1. low pointer: tracks the position where next 0 should go
2. mid pointer: current element being examined
3. high pointer: tracks the position where next 2 should go

4. If nums[mid] == 0: swap with low, increment both low and mid
5. If nums[mid] == 1: just increment mid (1s stay in middle)
6. If nums[mid] == 2: swap with high, decrement high (don't increment mid)

WHY NOT INCREMENT MID AFTER SWAPPING WITH HIGH?
- The element swapped from high position is unknown
- We need to examine it in the next iteration

WHY THIS PATTERN IS IMPORTANT:
- Classic partitioning problem
- Foundation for 3-way quicksort
- Single pass solution
- Used in many partitioning scenarios
- Very common in FAANG interviews
- Demonstrates efficient in-place sorting
*/
