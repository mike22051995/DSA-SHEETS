/*
PROBLEM: Toggle ith Bit
========================
Given a number n and an index i, toggle (flip) the ith bit.
If bit is 0, make it 1. If bit is 1, make it 0.

APPROACH:
- Create a mask by left shifting 1 by i positions
- XOR with n to toggle the bit
- XOR with 1 flips the bit, XOR with 0 keeps it same

PATTERN: Bit Toggling - Single Bit Operations

INPUT/OUTPUT:
Input: n = 5, i = 1
Output: 7
Explanation: 5 in binary is 101, toggling bit at position 1 gives 111 = 7

Input: n = 7, i = 1
Output: 5
Explanation: 7 in binary is 111, toggling bit at position 1 gives 101 = 5

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int toggleBit(int n, int i) {
        // Create mask with 1 at ith position
        int mask = 1 << i;
        // XOR with n to toggle the bit
        return n ^ mask;
    }
    
    // Alternative: Single line
    int toggleBitOneLine(int n, int i) {
        return n ^ (1 << i);
    }
};

void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}

int main() {
    Solution sol;
    
    // Test Case 1: Toggle 0 to 1
    int n1 = 5, i1 = 1;
    cout << "Input: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary before: ";
    printBinary(n1);
    cout << " (" << n1 << ")" << endl;
    int result1 = sol.toggleBit(n1, i1);
    cout << "Binary after:  ";
    printBinary(result1);
    cout << " (" << result1 << ")" << endl;
    cout << "Output: " << result1 << " (bit 0->1)" << endl << endl;
    
    // Test Case 2: Toggle 1 to 0
    int n2 = 7, i2 = 1;
    cout << "Input: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary before: ";
    printBinary(n2);
    cout << " (" << n2 << ")" << endl;
    int result2 = sol.toggleBit(n2, i2);
    cout << "Binary after:  ";
    printBinary(result2);
    cout << " (" << result2 << ")" << endl;
    cout << "Output: " << result2 << " (bit 1->0)" << endl;
    
    return 0;
}
