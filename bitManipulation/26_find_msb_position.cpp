/*
PROBLEM: Find MSB Position (Most Significant Bit)
===================================================
Find the position of the most significant bit (leftmost set bit) in a number.

APPROACH:
- Method 1: Keep right shifting until number becomes 0
- Method 2: Use log2 function
- Method 3: Set all bits after MSB and count

PATTERN: MSB Detection - Bit Position Finding

INPUT/OUTPUT:
Input: n = 18
Output: 5
Explanation: 18 = 10010 (binary), MSB at position 5

Input: n = 10
Output: 4
Explanation: 10 = 1010 (binary), MSB at position 4

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Method 1: Counting with right shift
    int findMSB(int n) {
        if (n == 0) return 0;
        
        int pos = 0;
        while (n > 0) {
            n >>= 1;
            pos++;
        }
        return pos;
    }
    
    // Method 2: Using log2
    int findMSBLog(int n) {
        if (n == 0) return 0;
        return log2(n) + 1;
    }
    
    // Method 3: Set all bits after MSB
    int findMSBSetAll(int n) {
        if (n == 0) return 0;
        
        // Set all bits after MSB
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        
        // Count set bits
        return __builtin_popcount(n);
    }
    
    // Get MSB value (not position)
    int getMSBValue(int n) {
        if (n == 0) return 0;
        
        // Keep setting all lower bits
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        
        // Clear all bits except MSB
        return (n + 1) >> 1;
    }
};

void printBinary(int n) {
    for (int i = 15; i >= 0; i--) {
        cout << ((n >> i) & 1);
        if (i % 4 == 0) cout << " ";
    }
}

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 18;
    cout << "Input: " << n1 << endl;
    cout << "Binary: ";
    printBinary(n1);
    cout << endl;
    cout << "MSB Position: " << sol.findMSB(n1) << endl;
    cout << "MSB Value: " << sol.getMSBValue(n1) << endl << endl;
    
    // Test Case 2
    int n2 = 10;
    cout << "Input: " << n2 << endl;
    cout << "Binary: ";
    printBinary(n2);
    cout << endl;
    cout << "MSB Position: " << sol.findMSB(n2) << endl;
    cout << "MSB Value: " << sol.getMSBValue(n2) << endl << endl;
    
    // Test Case 3
    int n3 = 255;
    cout << "Input: " << n3 << endl;
    cout << "Binary: ";
    printBinary(n3);
    cout << endl;
    cout << "MSB Position: " << sol.findMSB(n3) << endl;
    cout << "MSB Value: " << sol.getMSBValue(n3) << endl;
    
    return 0;
}
