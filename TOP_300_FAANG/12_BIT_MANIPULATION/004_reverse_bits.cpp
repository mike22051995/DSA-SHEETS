/*
================================================================================
PROBLEM: Reverse Bits (LeetCode #190)
DIFFICULTY: Easy
PATTERN: Bit Manipulation
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;           // Shift result left
            result |= (n & 1);      // Add rightmost bit of n
            n >>= 1;                // Shift n right
        }
        
        return result;
    }
    
    // Divide and conquer approach
    uint32_t reverseBitsDivideConquer(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

int main() {
    Solution sol;
    uint32_t n = 0b00000010100101000001111010011100;
    uint32_t reversed = sol.reverseBits(n);
    
    cout << "Original: " << n << endl;
    cout << "Reversed: " << reversed << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse Integer (LeetCode #7)
2. Number of 1 Bits (LeetCode #191)
3. Power of Two (LeetCode #231)
4. Power of Four (LeetCode #342)
5. Missing Number (LeetCode #268)
6. Bitwise AND of Numbers Range (LeetCode #201)
7. UTF-8 Validation (LeetCode #393)
8. Binary Number with Alternating Bits (LeetCode #693)
9. Binary String With Substrings (LeetCode #1461)
10. Minimum Flips to Make OR Equal (LeetCode #1318)
*/
