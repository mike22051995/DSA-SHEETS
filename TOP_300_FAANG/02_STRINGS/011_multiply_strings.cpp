/*
================================================================================
PROBLEM: Multiply Strings (LeetCode #43)
DIFFICULTY: Medium
PATTERN: Math / String Manipulation
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.length();
        int n = num2.length();
        vector<int> result(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                int sum = mul + result[p2];
                
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        string str;
        for (int digit : result) {
            if (!(str.empty() && digit == 0)) {
                str += to_string(digit);
            }
        }
        
        return str.empty() ? "0" : str;
    }
    
    // Alternative approach with string building
    string multiplyAlt(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        string result(num1.length() + num2.length(), '0');
        
        for (int i = num1.length() - 1; i >= 0; i--) {
            int carry = 0;
            
            for (int j = num2.length() - 1; j >= 0; j--) {
                int temp = (result[i + j + 1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            
            result[i] += carry;
        }
        
        size_t startPos = result.find_first_not_of('0');
        return startPos == string::npos ? "0" : result.substr(startPos);
    }
};

int main() {
    Solution sol;
    cout << "2 * 3 = " << sol.multiply("2", "3") << endl;
    cout << "123 * 456 = " << sol.multiply("123", "456") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Add Two Numbers (LeetCode #2)
2. Add Binary (LeetCode #67)
3. Add Strings (LeetCode #415)
4. Plus One (LeetCode #66)
5. Add to Array-Form of Integer (LeetCode #989)
6. Factorial Trailing Zeroes (LeetCode #172)
7. String to Integer (atoi) (LeetCode #8)
8. Divide Two Integers (LeetCode #29)
9. Basic Calculator II (LeetCode #227)
10. Pow(x, n) (LeetCode #50)
*/
