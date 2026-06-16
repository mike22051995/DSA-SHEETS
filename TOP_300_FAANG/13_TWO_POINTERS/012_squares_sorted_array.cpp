/*
================================================================================
PROBLEM: Squares of a Sorted Array (LeetCode #977)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums sorted in non-decreasing order, return an array of
the squares of each number sorted in non-decreasing order.

EXAMPLES:

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, [16,1,0,9,100]. After sorting, [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

PATTERN RECOGNITION:
Use this pattern when:
- Array is sorted but needs transformation
- Two pointers from both ends
- Negative numbers affect order after transformation
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        int index = n - 1;
        
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[index] = leftSquare;
                left++;
            } else {
                result[index] = rightSquare;
                right--;
            }
            index--;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {-4,-1,0,3,10};
    auto result1 = sol.sortedSquares(nums1);
    cout << "Squared: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> nums2 = {-7,-3,2,3,11};
    auto result2 = sol.sortedSquares(nums2);
    cout << "Squared: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array length
SPACE COMPLEXITY: O(n) for result array

SIMILAR PROBLEMS:
1. Merge Sorted Array (LeetCode #88)
2. Sort Colors (LeetCode #75)
3. Sort Array By Parity (LeetCode #905)
4. Sort Array By Parity II (LeetCode #922)
5. Two Sum II (LeetCode #167)
6. Three Sum (LeetCode #15)
7. Container With Most Water (LeetCode #11)
8. Trapping Rain Water (LeetCode #42)
9. Product of Array Except Self (LeetCode #238)
10. Move Zeroes (LeetCode #283)
*/
