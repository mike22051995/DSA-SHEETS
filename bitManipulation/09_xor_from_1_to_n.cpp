/*
PROBLEM: XOR from 1 to N
==========================
Find the XOR of all numbers from 1 to n.

APPROACH:
- Pattern observation: XOR from 1 to n follows a pattern
- If n % 4 == 1, result = 1
- If n % 4 == 2, result = n + 1
- If n % 4 == 3, result = 0
- If n % 4 == 0, result = n

PATTERN: XOR Pattern Recognition - Mathematical Optimization

INPUT/OUTPUT:
Input: n = 5
Output: 1
Explanation: 1 ^ 2 ^ 3 ^ 4 ^ 5 = 1

Input: n = 6
Output: 7
Explanation: 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 7

Input: n = 7
Output: 0
Explanation: 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0

TIME COMPLEXITY: O(1) - Using pattern
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Optimized O(1) solution using pattern
    int xorFrom1ToN(int n) {
        int remainder = n % 4;
        if (remainder == 1) return 1;
        if (remainder == 2) return n + 1;
        if (remainder == 3) return 0;
        return n; // remainder == 0
    }
    
    // Brute force O(n) solution for verification
    int xorFrom1ToNBruteForce(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result ^= i;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 5;
    cout << "Input: " << n1 << endl;
    cout << "Output (Optimized): " << sol.xorFrom1ToN(n1) << endl;
    cout << "Output (Brute Force): " << sol.xorFrom1ToNBruteForce(n1) << endl;
    cout << "Explanation: 1^2^3^4^5 = 1" << endl << endl;
    
    // Test Case 2
    int n2 = 6;
    cout << "Input: " << n2 << endl;
    cout << "Output (Optimized): " << sol.xorFrom1ToN(n2) << endl;
    cout << "Output (Brute Force): " << sol.xorFrom1ToNBruteForce(n2) << endl;
    cout << "Explanation: 1^2^3^4^5^6 = 7" << endl << endl;
    
    // Test Case 3
    int n3 = 7;
    cout << "Input: " << n3 << endl;
    cout << "Output (Optimized): " << sol.xorFrom1ToN(n3) << endl;
    cout << "Output (Brute Force): " << sol.xorFrom1ToNBruteForce(n3) << endl;
    cout << "Explanation: 1^2^3^4^5^6^7 = 0" << endl;
    
    return 0;
}
