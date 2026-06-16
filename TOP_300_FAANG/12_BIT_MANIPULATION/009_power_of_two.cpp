/*
================================================================================
PROBLEM: Power of Two (LeetCode #231)
DIFFICULTY: Easy
PATTERN: Bit Manipulation
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Using bit manipulation trick
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
    
    // Method 2: Count bits
    bool isPowerOfTwoBits(int n) {
        if (n <= 0) return false;
        
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        
        return count == 1;
    }
    
    // Method 3: Recursive
    bool isPowerOfTwoRecursive(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 2 != 0) return false;
        
        return isPowerOfTwoRecursive(n / 2);
    }
};

int main() {
    Solution sol;
    
    cout << "1 is power of 2: " << (sol.isPowerOfTwo(1) ? "true" : "false") << endl;
    cout << "16 is power of 2: " << (sol.isPowerOfTwo(16) ? "true" : "false") << endl;
    cout << "3 is power of 2: " << (sol.isPowerOfTwo(3) ? "true" : "false") << endl;
    cout << "4 is power of 2: " << (sol.isPowerOfTwo(4) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Power of Three (LeetCode #326)
2. Power of Four (LeetCode #342)
3. Number of 1 Bits (LeetCode #191)
4. Reverse Bits (LeetCode #190)
5. Single Number (LeetCode #136)
6. Missing Number (LeetCode #268)
7. Sum of Two Integers (LeetCode #371)
8. Counting Bits (LeetCode #338)
9. Hamming Distance (LeetCode #461)
10. Binary Number with Alternating Bits (LeetCode #693)
*/
