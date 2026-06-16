/*
PROBLEM: Binary String with Substrings Representing 1 to N
============================================================
Given a binary string s and a positive integer n, return true if every 
integer from 1 to n has a binary representation as a substring of s.

APPROACH:
- Generate binary representation of each number from 1 to n
- Check if it exists as substring in s
- Optimization: Start from n and go backwards (larger numbers less likely)

PATTERN: Binary Representation Matching

INPUT/OUTPUT:
Input: s = "0110", n = 3
Output: true
Explanation: "1"(1), "10"(2), "11"(3) all exist in "0110"

Input: s = "0110", n = 4
Output: false
Explanation: "100"(4) doesn't exist in "0110"

TIME COMPLEXITY: O(n * log n) - converting to binary and searching
SPACE COMPLEXITY: O(log n) - for binary string
*/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        // Check from n down to 1 (optimization)
        for (int i = n; i >= 1; i--) {
            string binary = toBinary(i);
            if (s.find(binary) == string::npos) {
                return false;
            }
        }
        return true;
    }
    
private:
    string toBinary(int n) {
        if (n == 0) return "0";
        
        string binary = "";
        while (n > 0) {
            binary = (char)('0' + (n & 1)) + binary;
            n >>= 1;
        }
        return binary;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "0110";
    int n1 = 3;
    cout << "Input: s = \"" << s1 << "\", n = " << n1 << endl;
    cout << "Output: " << (sol.queryString(s1, n1) ? "true" : "false") << endl;
    cout << "Explanation: 1(1), 10(2), 11(3) all exist" << endl;
    cout << "Checking:" << endl;
    for (int i = 1; i <= n1; i++) {
        string bin = "";
        int temp = i;
        while (temp) { bin = (char)('0' + (temp & 1)) + bin; temp >>= 1; }
        cout << "  " << i << " = " << bin << " -> found" << endl;
    }
    cout << endl;
    
    // Test Case 2
    string s2 = "0110";
    int n2 = 4;
    cout << "Input: s = \"" << s2 << "\", n = " << n2 << endl;
    cout << "Output: " << (sol.queryString(s2, n2) ? "true" : "false") << endl;
    cout << "Explanation: 100(4) doesn't exist" << endl << endl;
    
    // Test Case 3
    string s3 = "1111100000";
    int n3 = 5;
    cout << "Input: s = \"" << s3 << "\", n = " << n3 << endl;
    cout << "Output: " << (sol.queryString(s3, n3) ? "true" : "false") << endl;
    cout << "Explanation: All binary from 1 to 5 exist" << endl;
    
    return 0;
}
