/*
================================================================================
PROBLEM: Add Binary (LeetCode #67)
DIFFICULTY: Easy
PATTERN: String Manipulation / Math
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            result += (sum % 2) + '0';
            carry = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "11 + 1 = " << sol.addBinary("11", "1") << endl;
    cout << "1010 + 1011 = " << sol.addBinary("1010", "1011") << endl;
    cout << "0 + 0 = " << sol.addBinary("0", "0") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Add Two Numbers (LeetCode #2)
2. Add Two Numbers II (LeetCode #445)
3. Plus One (LeetCode #66)
4. Add Strings (LeetCode #415)
5. Multiply Strings (LeetCode #43)
6. Add to Array-Form of Integer (LeetCode #989)
7. Sum of Two Integers (LeetCode #371)
8. Binary Number with Alternating Bits (LeetCode #693)
9. Number of 1 Bits (LeetCode #191)
10. Reverse Bits (LeetCode #190)
*/
