/*
PROBLEM: Check if a Number is Power of 2
=============================================
Given a positive integer n, check if it is a power of 2 or not.

APPROACH:
- A power of 2 has exactly one set bit in its binary representation
- Using n & (n-1) clears the rightmost set bit
- If result is 0, then n is a power of 2

PATTERN: Basic Bit Manipulation - Clear Rightmost Set Bit

INPUT/OUTPUT:
Input: n = 16
Output: true
Explanation: 16 = 2^4

Input: n = 18
Output: false
Explanation: 18 is not a power of 2

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Power of 2 must be positive and have only one set bit
        // n & (n-1) removes the rightmost set bit
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 16;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << (sol.isPowerOfTwo(n1) ? "true" : "false") << endl;
    cout << "Explanation: 16 = 2^4" << endl << endl;
    
    // Test Case 2
    int n2 = 18;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << (sol.isPowerOfTwo(n2) ? "true" : "false") << endl;
    cout << "Explanation: 18 is not a power of 2" << endl << endl;
    
    // Test Case 3
    int n3 = 1;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << (sol.isPowerOfTwo(n3) ? "true" : "false") << endl;
    cout << "Explanation: 1 = 2^0" << endl;
    
    return 0;
}
