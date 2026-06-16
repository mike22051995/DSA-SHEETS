/*
PROBLEM: Reverse Bits
======================
Reverse the bits of a given 32-bit unsigned integer.

APPROACH:
- Process each bit from right to left
- Shift result left and add the current bit
- Shift n right to process next bit

PATTERN: Bit-by-Bit Processing

INPUT/OUTPUT:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)

TIME COMPLEXITY: O(32) = O(1) - Fixed 32 iterations
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            // Shift result left to make room for next bit
            result <<= 1;
            // Add the rightmost bit of n to result
            result |= (n & 1);
            // Shift n right to process next bit
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    uint32_t n1 = 43261596; // Binary: 00000010100101000001111010011100
    cout << "Input: " << n1 << endl;
    cout << "Output: " << sol.reverseBits(n1) << endl;
    cout << "Explanation: Reverse bits of 43261596" << endl << endl;
    
    // Test Case 2
    uint32_t n2 = 4294967293; // Binary: 11111111111111111111111111111101
    cout << "Input: " << n2 << endl;
    cout << "Output: " << sol.reverseBits(n2) << endl;
    cout << "Explanation: Reverse bits of 4294967293" << endl;
    
    return 0;
}
