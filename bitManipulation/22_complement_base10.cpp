/*
PROBLEM: Complement of Base 10 Integer
========================================
Given a positive integer n, return its complement (flip all bits).
The complement is obtained by flipping all bits in its binary representation.

APPROACH:
- Find the number of bits in n
- Create a mask with all 1s of same length
- XOR n with mask to flip all bits

PATTERN: Bit Flipping with Mask

INPUT/OUTPUT:
Input: n = 5
Output: 2
Explanation: 5 is 101, complement is 010 = 2

Input: n = 1
Output: 0
Explanation: 1 is 1, complement is 0

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // Find number of bits
        int bitCount = 0;
        int temp = num;
        
        while (temp > 0) {
            bitCount++;
            temp >>= 1;
        }
        
        // Create mask with all 1s
        unsigned int mask = (1U << bitCount) - 1;
        
        // XOR to get complement
        return num ^ mask;
    }
    
    // Alternative: Without counting bits
    int findComplementAlt(int num) {
        unsigned int mask = ~0; // All 1s
        
        // Shift mask left until it's greater than num
        while (num & mask) {
            mask <<= 1;
        }
        
        return ~num & ~mask;
    }
};

void printBinary(int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 5;
    cout << "Input: " << n1 << endl;
    cout << "Binary: ";
    printBinary(n1, 3);
    cout << endl;
    int result1 = sol.findComplement(n1);
    cout << "Complement: ";
    printBinary(result1, 3);
    cout << endl;
    cout << "Output: " << result1 << endl << endl;
    
    // Test Case 2
    int n2 = 1;
    cout << "Input: " << n2 << endl;
    cout << "Binary: ";
    printBinary(n2, 1);
    cout << endl;
    int result2 = sol.findComplement(n2);
    cout << "Complement: ";
    printBinary(result2, 1);
    cout << endl;
    cout << "Output: " << result2 << endl << endl;
    
    // Test Case 3
    int n3 = 10;
    cout << "Input: " << n3 << endl;
    cout << "Binary: ";
    printBinary(n3, 4);
    cout << endl;
    int result3 = sol.findComplement(n3);
    cout << "Complement: ";
    printBinary(result3, 4);
    cout << endl;
    cout << "Output: " << result3 << endl;
    
    return 0;
}
