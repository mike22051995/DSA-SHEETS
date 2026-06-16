/*
================================================================================
PROBLEM: ZigZag Conversion (LeetCode #6)
DIFFICULTY: Medium
PATTERN: String Manipulation
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currentRow] += c;
            
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            currentRow += goingDown ? 1 : -1;
        }
        
        string result;
        for (string& row : rows) {
            result += row;
        }
        
        return result;
    }
    
    // Mathematical approach
    string convertMath(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        string result;
        int cycleLen = 2 * numRows - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < s.length(); j += cycleLen) {
                result += s[j + i];
                
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.length()) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "PAYPALISHIRING";
    
    cout << "ZigZag (3 rows): " << sol.convert(s, 3) << endl;
    cout << "ZigZag (4 rows): " << sol.convert(s, 4) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Diagonal Traverse (LeetCode #498)
2. Diagonal Traverse II (LeetCode #1424)
3. Spiral Matrix (LeetCode #54)
4. Spiral Matrix II (LeetCode #59)
5. Set Matrix Zeroes (LeetCode #73)
6. Rotate Image (LeetCode #48)
7. Valid Word Abbreviation (LeetCode #408)
8. Snake in Matrix (LeetCode #3248)
9. Shifting Letters (LeetCode #848)
10. Shifting Letters II (LeetCode #2381)
*/
