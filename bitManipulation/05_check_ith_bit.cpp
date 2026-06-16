/*
PROBLEM: Check if ith Bit is Set
==================================
Given a number n and an index i, check if the ith bit is set (1) or not (0).

APPROACH:
- Method 1: Left shift 1 by i positions and AND with n
- Method 2: Right shift n by i positions and AND with 1

PATTERN: Bit Checking - Single Bit Operations

INPUT/OUTPUT:
Input: n = 5, i = 0
Output: true
Explanation: 5 in binary is 101, 0th bit (rightmost) is 1

Input: n = 5, i = 1
Output: false
Explanation: 5 in binary is 101, 1st bit is 0

Input: n = 5, i = 2
Output: true
Explanation: 5 in binary is 101, 2nd bit is 1

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Left shift approach
    bool isSetMethod1(int n, int i) {
        return (n & (1 << i)) != 0;
    }
    
    // Method 2: Right shift approach
    bool isSetMethod2(int n, int i) {
        return ((n >> i) & 1) == 1;
    }
};

int main() {
    Solution sol;
    
    int n = 5; // Binary: 101
    cout << "Number: " << n << " (Binary: 101)" << endl << endl;
    
    // Test Case 1
    int i1 = 0;
    cout << "Check bit at position " << i1 << endl;
    cout << "Output: " << (sol.isSetMethod1(n, i1) ? "true" : "false") << endl;
    cout << "Explanation: Rightmost bit (position 0) is 1" << endl << endl;
    
    // Test Case 2
    int i2 = 1;
    cout << "Check bit at position " << i2 << endl;
    cout << "Output: " << (sol.isSetMethod1(n, i2) ? "true" : "false") << endl;
    cout << "Explanation: Middle bit (position 1) is 0" << endl << endl;
    
    // Test Case 3
    int i3 = 2;
    cout << "Check bit at position " << i3 << endl;
    cout << "Output: " << (sol.isSetMethod1(n, i3) ? "true" : "false") << endl;
    cout << "Explanation: Leftmost bit (position 2) is 1" << endl;
    
    return 0;
}
