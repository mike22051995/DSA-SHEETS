/*
PROBLEM: Gray Code
===================
Generate n-bit Gray code sequence. Gray code is a binary sequence where 
two successive values differ in only one bit.

APPROACH:
- Gray code formula: gray(i) = i ^ (i >> 1)
- For n bits, generate numbers from 0 to 2^n-1
- Apply Gray code formula to each number

PATTERN: Gray Code Generation - XOR with Right Shift

INPUT/OUTPUT:
Input: n = 2
Output: [0,1,3,2]
Explanation: 
00 (0)
01 (1)
11 (3)
10 (2)

Input: n = 3
Output: [0,1,3,2,6,7,5,4]

TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(2^n) for output
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n; // 2^n
        
        for (int i = 0; i < size; i++) {
            // Gray code formula: i XOR (i >> 1)
            int gray = i ^ (i >> 1);
            result.push_back(gray);
        }
        
        return result;
    }
    
    // Alternative: Reflective method
    vector<int> grayCodeReflective(int n) {
        vector<int> result = {0};
        
        for (int i = 0; i < n; i++) {
            int size = result.size();
            // Add reflected sequence with MSB set
            for (int j = size - 1; j >= 0; j--) {
                result.push_back(result[j] | (1 << i));
            }
        }
        
        return result;
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
    int n1 = 2;
    cout << "Input: " << n1 << endl;
    vector<int> result1 = sol.grayCode(n1);
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Binary representation:" << endl;
    for (int val : result1) {
        printBinary(val, n1);
        cout << " (" << val << ")" << endl;
    }
    cout << endl;
    
    // Test Case 2
    int n2 = 3;
    cout << "Input: " << n2 << endl;
    vector<int> result2 = sol.grayCode(n2);
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Binary representation:" << endl;
    for (int val : result2) {
        printBinary(val, n2);
        cout << " (" << val << ")" << endl;
    }
    
    return 0;
}
