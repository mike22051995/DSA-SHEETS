/*
================================================================================
PROBLEM: Bitwise AND of Numbers Range (LeetCode #201)
DIFFICULTY: Medium
PATTERN: Bit Manipulation
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Right shift approach
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        
        return left << shift;
    }
    
    // Clear rightmost bit approach
    int rangeBitwiseAndClear(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};

int main() {
    Solution sol;
    cout << "AND of range [5,7]: " << sol.rangeBitwiseAnd(5, 7) << endl;
    cout << "AND of range [0,0]: " << sol.rangeBitwiseAnd(0, 0) << endl;
    cout << "AND of range [1,2147483647]: " << sol.rangeBitwiseAnd(1, 2147483647) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of 1 Bits (LeetCode #191)
2. Counting Bits (LeetCode #338)
3. Single Number (LeetCode #136)
4. Single Number II (LeetCode #137)
5. Single Number III (LeetCode #260)
6. Maximum XOR of Two Numbers (LeetCode #421)
7. Sum of Two Integers (LeetCode #371)
8. Reverse Bits (LeetCode #190)
9. Power of Two (LeetCode #231)
10. Gray Code (LeetCode #89)
*/
