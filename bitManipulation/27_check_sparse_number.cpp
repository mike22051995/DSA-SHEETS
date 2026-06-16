/*
PROBLEM: Check if Number is Sparse
====================================
A number is Sparse if there are no consecutive 1s in its binary representation.
Check if a given number is sparse.

APPROACH:
- If n is sparse, then n & (n << 1) should be 0
- Left shifting by 1 moves all bits left
- If there were consecutive 1s, AND will produce non-zero

PATTERN: Consecutive Bits Detection

INPUT/OUTPUT:
Input: n = 5
Output: true
Explanation: 5 = 101 (binary), no consecutive 1s

Input: n = 7
Output: false
Explanation: 7 = 111 (binary), has consecutive 1s

Input: n = 2
Output: true
Explanation: 2 = 10 (binary), no consecutive 1s

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSparse(int n) {
        // If there are consecutive 1s, n & (n<<1) will be non-zero
        return (n & (n << 1)) == 0;
    }
    
    // Alternative: Check using n & (n >> 1)
    bool isSparseAlt(int n) {
        return (n & (n >> 1)) == 0;
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
    int n1 = 5;
    cout << "Input: " << n1 << endl;
    cout << "Binary: ";
    printBinary(n1);
    cout << " (" << n1 << ")" << endl;
    cout << "Output: " << (sol.isSparse(n1) ? "true" : "false") << endl;
    cout << "Explanation: 101 has no consecutive 1s" << endl << endl;
    
    // Test Case 2
    int n2 = 7;
    cout << "Input: " << n2 << endl;
    cout << "Binary: ";
    printBinary(n2);
    cout << " (" << n2 << ")" << endl;
    cout << "Output: " << (sol.isSparse(n2) ? "true" : "false") << endl;
    cout << "Explanation: 111 has consecutive 1s" << endl << endl;
    
    // Test Case 3
    int n3 = 2;
    cout << "Input: " << n3 << endl;
    cout << "Binary: ";
    printBinary(n3);
    cout << " (" << n3 << ")" << endl;
    cout << "Output: " << (sol.isSparse(n3) ? "true" : "false") << endl;
    cout << "Explanation: 10 has no consecutive 1s" << endl << endl;
    
    // Test Case 4
    int n4 = 72;
    cout << "Input: " << n4 << endl;
    cout << "Binary: ";
    printBinary(n4);
    cout << " (" << n4 << ")" << endl;
    cout << "Output: " << (sol.isSparse(n4) ? "true" : "false") << endl;
    cout << "Explanation: 1001000 has no consecutive 1s" << endl;
    
    return 0;
}
