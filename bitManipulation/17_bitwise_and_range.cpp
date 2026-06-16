/*
PROBLEM: Bitwise AND of Numbers Range
=======================================
Given two integers left and right representing a range [left, right],
return the bitwise AND of all numbers in this range.

APPROACH:
- Find the common prefix of left and right in binary
- All bits after the common prefix will be 0 in the result
- Keep right shifting both numbers until they're equal
- Then left shift back to get the result

PATTERN: Range Bitwise Operations - Common Prefix

INPUT/OUTPUT:
Input: left = 5, right = 7
Output: 4
Explanation: 5 (101) & 6 (110) & 7 (111) = 4 (100)

Input: left = 1, right = 2147483647
Output: 0
Explanation: Range includes 0 somewhere, result is 0

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        
        // Find common prefix by right shifting until equal
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        
        // Left shift back to get the result
        return left << shift;
    }
    
    // Alternative: Using Brian Kernighan's algorithm
    int rangeBitwiseAndAlt(int left, int right) {
        // Clear rightmost bits of right until it becomes <= left
        while (right > left) {
            right = right & (right - 1);
        }
        return right;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int left1 = 5, right1 = 7;
    cout << "Input: left = " << left1 << ", right = " << right1 << endl;
    cout << "Output: " << sol.rangeBitwiseAnd(left1, right1) << endl;
    cout << "Explanation: 5(101) & 6(110) & 7(111) = 4(100)" << endl << endl;
    
    // Test Case 2
    int left2 = 0, right2 = 0;
    cout << "Input: left = " << left2 << ", right = " << right2 << endl;
    cout << "Output: " << sol.rangeBitwiseAnd(left2, right2) << endl;
    cout << "Explanation: Single number" << endl << endl;
    
    // Test Case 3
    int left3 = 1, right3 = 2147483647;
    cout << "Input: left = " << left3 << ", right = " << right3 << endl;
    cout << "Output: " << sol.rangeBitwiseAnd(left3, right3) << endl;
    cout << "Explanation: Large range, no common prefix" << endl;
    
    return 0;
}
