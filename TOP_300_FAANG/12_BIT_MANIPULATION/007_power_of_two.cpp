/*
================================================================================
PROBLEM: Power of Two (LeetCode #231)
DIFFICULTY: Easy
PATTERN: Bit Manipulation
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Bit manipulation
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
    
    // Count set bits
    bool isPowerOfTwoCountBits(int n) {
        if (n <= 0) return false;
        
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        
        return count == 1;
    }
    
    // Remove rightmost set bit
    bool isPowerOfTwoRemoveBit(int n) {
        if (n <= 0) return false;
        return (n & (-n)) == n;
    }
};

int main() {
    Solution sol;
    cout << "1 is power of 2: " << (sol.isPowerOfTwo(1) ? "true" : "false") << endl;
    cout << "16 is power of 2: " << (sol.isPowerOfTwo(16) ? "true" : "false") << endl;
    cout << "3 is power of 2: " << (sol.isPowerOfTwo(3) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Power of Three (LeetCode #326)
2. Power of Four (LeetCode #342)
3. Number of 1 Bits (LeetCode #191)
4. Counting Bits (LeetCode #338)
5. Reverse Bits (LeetCode #190)
6. Single Number (LeetCode #136)
7. Single Number II (LeetCode #137)
8. Single Number III (LeetCode #260)
9. Maximum XOR of Two Numbers (LeetCode #421)
10. Bitwise AND of Numbers Range (LeetCode #201)
*/
