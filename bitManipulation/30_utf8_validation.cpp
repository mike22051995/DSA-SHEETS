/*
PROBLEM: UTF-8 Validation
===========================
Given an array of integers representing data, determine if it is a 
valid UTF-8 encoding.

APPROACH:
- UTF-8 rules:
  * 1-byte: 0xxxxxxx
  * 2-byte: 110xxxxx 10xxxxxx
  * 3-byte: 1110xxxx 10xxxxxx 10xxxxxx
  * 4-byte: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
- Check first byte to determine character length
- Verify following bytes start with 10xxxxxx

PATTERN: Bit Masking for Format Validation

INPUT/OUTPUT:
Input: data = [197,130,1]
Output: true
Explanation: Valid 2-byte char (197,130) + 1-byte char (1)
197 = 11000101, 130 = 10000010, 1 = 00000001

Input: data = [235,140,4]
Output: false
Explanation: 235 = 11101011 expects 3-byte but 4 = 00000100 is invalid

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numBytesToProcess = 0;
        
        // Masks for checking
        int mask1 = 1 << 7;  // 10000000
        int mask2 = 1 << 6;  // 01000000
        
        for (int byte : data) {
            if (numBytesToProcess == 0) {
                // Determine number of bytes in current UTF-8 character
                int mask = 1 << 7;
                while (mask & byte) {
                    numBytesToProcess++;
                    mask >>= 1;
                }
                
                // 1-byte character
                if (numBytesToProcess == 0) continue;
                
                // Invalid: should be between 2 and 4
                if (numBytesToProcess == 1 || numBytesToProcess > 4) {
                    return false;
                }
            } else {
                // Check if byte starts with 10xxxxxx
                if (!((byte & mask1) && !(byte & mask2))) {
                    return false;
                }
            }
            
            numBytesToProcess--;
        }
        
        return numBytesToProcess == 0;
    }
};

void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> data1 = {197, 130, 1};
    cout << "Input: [197,130,1]" << endl;
    cout << "Binary representation:" << endl;
    for (int byte : data1) {
        cout << byte << " = ";
        printBinary(byte);
        cout << endl;
    }
    cout << "Output: " << (sol.validUtf8(data1) ? "true" : "false") << endl;
    cout << "Explanation: Valid 2-byte + 1-byte character" << endl << endl;
    
    // Test Case 2
    vector<int> data2 = {235, 140, 4};
    cout << "Input: [235,140,4]" << endl;
    cout << "Binary representation:" << endl;
    for (int byte : data2) {
        cout << byte << " = ";
        printBinary(byte);
        cout << endl;
    }
    cout << "Output: " << (sol.validUtf8(data2) ? "true" : "false") << endl;
    cout << "Explanation: Invalid UTF-8 sequence" << endl << endl;
    
    // Test Case 3
    vector<int> data3 = {240, 162, 138, 147};
    cout << "Input: [240,162,138,147]" << endl;
    cout << "Binary representation:" << endl;
    for (int byte : data3) {
        cout << byte << " = ";
        printBinary(byte);
        cout << endl;
    }
    cout << "Output: " << (sol.validUtf8(data3) ? "true" : "false") << endl;
    cout << "Explanation: Valid 4-byte character" << endl;
    
    return 0;
}
