/*
PROBLEM: Clear ith Bit
=======================
Given a number n and an index i, clear (set to 0) the ith bit.

APPROACH:
- Create a mask by left shifting 1 by i positions
- Take complement of mask (all bits 1 except ith bit)
- AND with n to clear the bit

PATTERN: Bit Clearing - Single Bit Operations

INPUT/OUTPUT:
Input: n = 7, i = 1
Output: 5
Explanation: 7 in binary is 111, clearing bit at position 1 gives 101 = 5

Input: n = 15, i = 2
Output: 11
Explanation: 15 in binary is 1111, clearing bit at position 2 gives 1011 = 11

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int clearBit(int n, int i) {
        // Create mask with 0 at ith position and 1s elsewhere
        int mask = ~(1 << i);
        // AND with n to clear the bit
        return n & mask;
    }
    
    // Alternative: Single line
    int clearBitOneLine(int n, int i) {
        return n & ~(1 << i);
    }
};

void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 7, i1 = 1;
    cout << "Input: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary before: ";
    printBinary(n1);
    cout << " (" << n1 << ")" << endl;
    int result1 = sol.clearBit(n1, i1);
    cout << "Binary after:  ";
    printBinary(result1);
    cout << " (" << result1 << ")" << endl;
    cout << "Output: " << result1 << endl << endl;
    
    // Test Case 2
    int n2 = 15, i2 = 2;
    cout << "Input: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary before: ";
    printBinary(n2);
    cout << " (" << n2 << ")" << endl;
    int result2 = sol.clearBit(n2, i2);
    cout << "Binary after:  ";
    printBinary(result2);
    cout << " (" << result2 << ")" << endl;
    cout << "Output: " << result2 << endl;
    
    return 0;
}
