/*
PROBLEM: Squares of a Sorted Array (LeetCode 977)
===============================================
DESCRIPTION:
Given an integer array sorted in non-decreasing order, return an array of the 
squares of each number sorted in non-decreasing order.

PATTERN: Two Pointer + Merge
DIFFICULTY: Easy
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for output array

INPUT:
Sorted array (can contain negative numbers)

OUTPUT:
Sorted array of squares

EXAMPLE:
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0;
        int right = n - 1;
        int pos = n - 1; // Fill from the end
        
        // Compare absolute values from both ends
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[pos] = leftSquare;
                left++;
            } else {
                result[pos] = rightSquare;
                right--;
            }
            pos--;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    
    cout << "Test Case 1:\n";
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    vector<int> result1 = sol.sortedSquares(nums1);
    cout << "Output: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    
    cout << "\nTest Case 2:\n";
    cout << "Input: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    vector<int> result2 = sol.sortedSquares(nums2);
    cout << "Output: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
KEY INSIGHT:
- Array is sorted, but squares can be larger at both ends (negative numbers)
- Largest square will be either at leftmost or rightmost position
- Use two pointers to compare from both ends

ALGORITHM:
1. Use two pointers: left at start, right at end
2. Create result array and fill from the end (largest first)
3. Compare squares of elements at both pointers
4. Place larger square at current position in result
5. Move the pointer whose square was used
6. Continue until all elements are processed

WHY FILL FROM END?
- Largest squares are at the extremes
- Filling from end avoids need for reverse operation
- Single pass through the array

ALTERNATIVE APPROACH:
- Square all elements and sort: O(n log n)
- Two pointer approach: O(n) - more efficient!

WHY THIS PATTERN IS IMPORTANT:
- Efficient use of sorted array property
- Two pointer technique variation
- Avoiding unnecessary sorting
- Common in array manipulation problems
*/
