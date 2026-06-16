/*
================================================================================
PROBLEM: Integer to Roman (LeetCode #12)
DIFFICULTY: Medium
PATTERN: Greedy
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result;
        
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
    
    // Alternative approach with digit processing
    string intToRomanDigits(int num) {
        string thousands[] = {"", "M", "MM", "MMM"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return thousands[num / 1000] + 
               hundreds[(num % 1000) / 100] + 
               tens[(num % 100) / 10] + 
               ones[num % 10];
    }
};

int main() {
    Solution sol;
    cout << "3: " << sol.intToRoman(3) << endl;
    cout << "58: " << sol.intToRoman(58) << endl;
    cout << "1994: " << sol.intToRoman(1994) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Roman to Integer (LeetCode #13)
2. Integer to English Words (LeetCode #273)
3. Excel Sheet Column Title (LeetCode #168)
4. Excel Sheet Column Number (LeetCode #171)
5. Fraction to Recurring Decimal (LeetCode #166)
6. Convert to Base -2 (LeetCode #1017)
7. Base 7 (LeetCode #504)
8. Encode Number (LeetCode #1256)
9. Count Integers With Even Digit Sum (LeetCode #2180)
10. Sum of Digits in Base K (LeetCode #1837)
*/
