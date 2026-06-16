/*
PROBLEM: Set ith Bit
=====================
Given a number n and an index i, set the ith bit to 1.

APPROACH:
- Create a mask by left shifting 1 by i positions
- OR the mask with n to set the bit

PATTERN: Bit Setting - Single Bit Operations

INPUT/OUTPUT:
Input: n = 5, i = 1
Output: 7
Explanation: 5 in binary is 101, setting bit at position 1 gives 111 = 7

Input: n = 10, i = 2
Output: 14
Explanation: 10 in binary is 1010, setting bit at position 2 gives 1110 = 14

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int setBit(int n, int i) {
        // Create mask with 1 at ith position
        int mask = 1 << i;
        // OR with n to set the bit
        return n | mask;
    }
    
    // Alternative: Single line
    int setBitOneLine(int n, int i) {
        return n | (1 << i);
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
    int n1 = 5, i1 = 1;
    cout << "Input: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary before: ";
    printBinary(n1);
    cout << " (" << n1 << ")" << endl;
    int result1 = sol.setBit(n1, i1);
    cout << "Binary after:  ";
    printBinary(result1);
    cout << " (" << result1 << ")" << endl;
    cout << "Output: " << result1 << endl << endl;
    
    // Test Case 2
    int n2 = 10, i2 = 2;
    cout << "Input: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary before: ";
    printBinary(n2);
    cout << " (" << n2 << ")" << endl;
    int result2 = sol.setBit(n2, i2);
    cout << "Binary after:  ";
    printBinary(result2);
    cout << " (" << result2 << ")" << endl;
    cout << "Output: " << result2 << endl;
    
    return 0;
}
