/*
================================================================================
PROBLEM: Roman to Integer (LeetCode #13)
DIFFICULTY: Easy
PATTERN: String / Hash Map
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int current = romanMap[s[i]];
            
            if (i + 1 < s.length() && current < romanMap[s[i + 1]]) {
                result -= current;
            } else {
                result += current;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "III = " << sol.romanToInt("III") << endl;
    cout << "IV = " << sol.romanToInt("IV") << endl;
    cout << "IX = " << sol.romanToInt("IX") << endl;
    cout << "LVIII = " << sol.romanToInt("LVIII") << endl;
    cout << "MCMXCIV = " << sol.romanToInt("MCMXCIV") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Integer to Roman (LeetCode #12)
2. Integer to English Words (LeetCode #273)
3. Excel Sheet Column Number (LeetCode #171)
4. Excel Sheet Column Title (LeetCode #168)
5. Fraction to Recurring Decimal (LeetCode #166)
6. Valid Number (LeetCode #65)
7. String to Integer (atoi) (LeetCode #8)
8. Basic Calculator (LeetCode #224)
9. Evaluate Reverse Polish Notation (LeetCode #150)
10. Number of Valid Words (LeetCode #2047)
*/
