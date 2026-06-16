/*
================================================================================
PROBLEM: Sum of Two Integers (LeetCode #371)
DIFFICULTY: Medium
PATTERN: Bit Manipulation
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
    
    // Recursive approach
    int getSumRecursive(int a, int b) {
        if (b == 0) return a;
        return getSumRecursive(a ^ b, (unsigned int)(a & b) << 1);
    }
};

int main() {
    Solution sol;
    cout << "Sum (1, 2): " << sol.getSum(1, 2) << endl;
    cout << "Sum (2, 3): " << sol.getSum(2, 3) << endl;
    cout << "Sum (-1, 1): " << sol.getSum(-1, 1) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Subtract Two Integers (Without operator)
2. Product of Two Integers (Bit manipulation)
3. Divide Two Integers (LeetCode #29)
4. Add Binary (LeetCode #67)
5. Add Strings (LeetCode #415)
6. Multiply Strings (LeetCode #43)
7. Plus One (LeetCode #66)
8. Add Two Numbers (LeetCode #2)
9. Bitwise AND of Numbers Range (LeetCode #201)
10. Maximum XOR of Two Numbers (LeetCode #421)
*/
