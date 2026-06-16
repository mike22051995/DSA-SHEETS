/*
================================================================================
PROBLEM: Number of 1 Bits (Hamming Weight) (LeetCode #191)
DIFFICULTY: Easy
PATTERN: Bit Manipulation
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    // Method 1: Count set bits using &
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    // Method 2: Brian Kernighan's Algorithm
    int hammingWeight2(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);  // Removes rightmost 1 bit
            count++;
        }
        return count;
    }
    
    // Method 3: Built-in function
    int hammingWeight3(uint32_t n) {
        return __builtin_popcount(n);
    }
};

int main() {
    Solution sol;
    uint32_t n1 = 0b00000000000000000000000000001011; // 11
    uint32_t n2 = 0b11111111111111111111111111111101; // 4294967293
    
    cout << "Hamming weight of " << n1 << ": " << sol.hammingWeight(n1) << endl;
    cout << "Hamming weight of " << n2 << ": " << sol.hammingWeight(n2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Counting Bits (LeetCode #338)
2. Power of Two (LeetCode #231)
3. Power of Four (LeetCode #342)
4. Reverse Bits (LeetCode #190)
5. Single Number (LeetCode #136)
6. Single Number II (LeetCode #137)
7. Missing Number (LeetCode #268)
8. Hamming Distance (LeetCode #461)
9. Total Hamming Distance (LeetCode #477)
10. Binary Watch (LeetCode #401)
*/
