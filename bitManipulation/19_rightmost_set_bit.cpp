/*
PROBLEM: Find Position of Rightmost Set Bit
=============================================
Find the position of the rightmost set bit (1-indexed from right).

APPROACH:
- Use n & -n to isolate the rightmost set bit
- Take log2 of result to get position
- Or use bit manipulation to count position

PATTERN: Rightmost Set Bit Isolation

INPUT/OUTPUT:
Input: n = 18
Output: 2
Explanation: 18 in binary is 10010, rightmost set bit at position 2

Input: n = 12
Output: 3
Explanation: 12 in binary is 1100, rightmost set bit at position 3

TIME COMPLEXITY: O(log n) or O(1) with log2
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Method 1: Using n & -n and log2
    int findRightmostSetBit(int n) {
        if (n == 0) return 0;
        
        // Isolate rightmost set bit
        int rightmostBit = n & -n;
        
        // Find position using log2
        return log2(rightmostBit) + 1;
    }
    
    // Method 2: Using XOR
    int findRightmostSetBitXOR(int n) {
        if (n == 0) return 0;
        
        // n & -n gives rightmost set bit
        int pos = 1;
        int rightmost = n & -n;
        
        // Count position
        while ((rightmost & 1) == 0) {
            rightmost >>= 1;
            pos++;
        }
        
        return pos;
    }
    
    // Method 3: Simple counting
    int findRightmostSetBitSimple(int n) {
        if (n == 0) return 0;
        
        int pos = 1;
        while ((n & 1) == 0) {
            n >>= 1;
            pos++;
        }
        
        return pos;
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
    cout << "Output: " << sol.findRightmostSetBit(n1) << endl;
    cout << "Explanation: Rightmost set bit at position 2" << endl << endl;
    
    // Test Case 2
    int n2 = 12;
    cout << "Input: " << n2 << endl;
    cout << "Binary: ";
    printBinary(n2);
    cout << endl;
    cout << "Output: " << sol.findRightmostSetBit(n2) << endl;
    cout << "Explanation: Rightmost set bit at position 3" << endl << endl;
    
    // Test Case 3
    int n3 = 16;
    cout << "Input: " << n3 << endl;
    cout << "Binary: ";
    printBinary(n3);
    cout << endl;
    cout << "Output: " << sol.findRightmostSetBit(n3) << endl;
    cout << "Explanation: Rightmost set bit at position 5" << endl;
    
    return 0;
}
