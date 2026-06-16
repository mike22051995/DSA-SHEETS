/*
PROBLEM: Count Set Bits (Hamming Weight)
==========================================
Given an integer n, count the number of 1's in its binary representation.

APPROACH:
- Method 1: Use Brian Kernighan's Algorithm
- n & (n-1) clears the rightmost set bit
- Keep doing this until n becomes 0
- Count the number of operations

PATTERN: Brian Kernighan's Algorithm - Count Set Bits

INPUT/OUTPUT:
Input: n = 11
Output: 3
Explanation: 11 in binary is 1011, which has 3 set bits

Input: n = 128
Output: 1
Explanation: 128 in binary is 10000000, which has 1 set bit

TIME COMPLEXITY: O(log n) or O(number of set bits)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        // Brian Kernighan's Algorithm
        while (n > 0) {
            n = n & (n - 1);  // Remove rightmost set bit
            count++;
        }
        return count;
    }
    
    // Alternative approach using __builtin_popcount
    int countSetBitsBuiltin(int n) {
        return __builtin_popcount(n);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 11;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << sol.countSetBits(n1) << endl;
    cout << "Explanation: 11 in binary is 1011 (3 set bits)" << endl << endl;
    
    // Test Case 2
    int n2 = 128;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << sol.countSetBits(n2) << endl;
    cout << "Explanation: 128 in binary is 10000000 (1 set bit)" << endl << endl;
    
    // Test Case 3
    int n3 = 15;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << sol.countSetBits(n3) << endl;
    cout << "Explanation: 15 in binary is 1111 (4 set bits)" << endl;
    
    return 0;
}
