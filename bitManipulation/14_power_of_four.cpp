/*
PROBLEM: Power of Four
========================
Given an integer n, return true if it is a power of four.

APPROACH:
- First check if it's a power of 2: n & (n-1) == 0
- Power of 4 has set bit only at even positions (0, 2, 4, 6...)
- Use mask 0xAAAAAAAA to check odd positions are all 0
- Or check if (n-1) is divisible by 3

PATTERN: Power Checking with Bit Positions

INPUT/OUTPUT:
Input: n = 16
Output: true
Explanation: 16 = 4^2

Input: n = 5
Output: false

Input: n = 1
Output: true
Explanation: 1 = 4^0

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Using bit position check
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        // Check if power of 2
        if ((n & (n - 1)) != 0) return false;
        // Check if set bit is at even position
        // 0x55555555 = 01010101010101010101010101010101 (set bits at even positions)
        return (n & 0x55555555) != 0;
    }
    
    // Method 2: Using modulo property
    bool isPowerOfFourMod(int n) {
        if (n <= 0) return false;
        // Power of 4: (1) power of 2, (2) (n-1) divisible by 3
        return (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 16;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << (sol.isPowerOfFour(n1) ? "true" : "false") << endl;
    cout << "Explanation: 16 = 4^2" << endl << endl;
    
    // Test Case 2
    int n2 = 5;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << (sol.isPowerOfFour(n2) ? "true" : "false") << endl;
    cout << "Explanation: 5 is not a power of 4" << endl << endl;
    
    // Test Case 3
    int n3 = 1;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << (sol.isPowerOfFour(n3) ? "true" : "false") << endl;
    cout << "Explanation: 1 = 4^0" << endl << endl;
    
    // Test Case 4
    int n4 = 8;
    cout << "Input: " << n4 << endl;
    cout << "Output: " << (sol.isPowerOfFour(n4) ? "true" : "false") << endl;
    cout << "Explanation: 8 is 2^3, not power of 4" << endl;
    
    return 0;
}
