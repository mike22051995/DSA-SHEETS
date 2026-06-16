/*
PROBLEM: Sort Array By Parity (LeetCode 905)
===============================================
DESCRIPTION:
Given an array of integers, move all the even integers to the beginning of the 
array followed by all the odd integers. Return any array that satisfies this condition.

PATTERN: Two Pointer / Partition
DIFFICULTY: Easy
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers

OUTPUT:
Array with all even numbers before odd numbers

EXAMPLE:
Input: [3,1,2,4]
Output: [2,4,3,1] (or any valid arrangement)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Two Pointer (In-place)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            // If left is odd and right is even, swap them
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }
            
            // Move left pointer if current element is even
            if (nums[left] % 2 == 0) left++;
            
            // Move right pointer if current element is odd
            if (nums[right] % 2 == 1) right--;
        }
        
        return nums;
    }
    
    // Approach 2: Partition approach (similar to quicksort partition)
    vector<int> sortArrayByParityV2(vector<int>& nums) {
        int j = 0; // Position for next even number
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 1, 2, 4};
    vector<int> nums2 = {3, 1, 2, 4};
    
    cout << "Original array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    sol.sortArrayByParity(nums1);
    cout << "Approach 1 (Two Pointer): ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    sol.sortArrayByParityV2(nums2);
    cout << "Approach 2 (Partition): ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: Two Pointer
1. Use two pointers: left at start, right at end
2. If left is odd and right is even, swap them
3. Move left pointer forward if element is even
4. Move right pointer backward if element is odd
5. Continue until pointers meet

APPROACH 2: Partition (Quicksort-style)
1. Maintain a position 'j' for next even number
2. Iterate through array with pointer 'i'
3. When we find an even number, swap it to position 'j'
4. Increment 'j'
5. This partitions array into even and odd sections

WHY THIS PATTERN IS IMPORTANT:
- Partition technique used in quicksort
- Two pointer technique for array rearrangement
- In-place array manipulation
- Similar to Dutch National Flag problem
- Common pattern in many sorting/partitioning problems
*/
