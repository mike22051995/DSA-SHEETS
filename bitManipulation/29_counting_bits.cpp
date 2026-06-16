/*
PROBLEM: Counting Bits (DP Approach)
======================================
Given an integer n, return an array ans of length n+1 where ans[i] is 
the number of 1's in binary representation of i.

APPROACH:
- Use DP with bit manipulation
- Observation: bits[i] = bits[i >> 1] + (i & 1)
- Right shift removes last bit, then add back if it was 1

PATTERN: Dynamic Programming with Bit Manipulation

INPUT/OUTPUT:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 -> 0 (0 bits)
1 -> 1 (1 bit)
2 -> 10 (1 bit)
3 -> 11 (2 bits)
4 -> 100 (1 bit)
5 -> 101 (2 bits)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for output array
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // bits[i] = bits[i/2] + (i%2)
            // Using bit manipulation: i>>1 is i/2, i&1 is i%2
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
    
    // Alternative using Brian Kernighan
    vector<int> countBitsAlt(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // Remove rightmost bit: ans[i] = ans[i & (i-1)] + 1
            ans[i] = ans[i & (i - 1)] + 1;
        }
        
        return ans;
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
    vector<int> result1 = sol.countBits(n1);
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Explanation:" << endl;
    for (int i = 0; i <= n1; i++) {
        cout << i << " -> ";
        printBinary(i, 4);
        cout << " (" << result1[i] << " bit" << (result1[i] != 1 ? "s" : "") << ")" << endl;
    }
    cout << endl;
    
    // Test Case 2
    int n2 = 8;
    cout << "Input: " << n2 << endl;
    vector<int> result2 = sol.countBits(n2);
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}
