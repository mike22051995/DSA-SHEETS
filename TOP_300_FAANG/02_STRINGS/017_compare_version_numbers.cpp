/*
================================================================================
PROBLEM: Compare Version Numbers (LeetCode #165)
DIFFICULTY: Medium
PATTERN: String Parsing / Two Pointers
COMPANIES: Amazon, Microsoft, Google, Apple
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.length(), n2 = version2.length();
        
        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;
            
            // Extract number from version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Extract number from version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            // Move past the dot
            i++;
            j++;
        }
        
        return 0;
    }
};

int main() {
    Solution sol;
    
    cout << "1.01 vs 1.001: " << sol.compareVersion("1.01", "1.001") << endl;
    cout << "1.0 vs 1.0.0: " << sol.compareVersion("1.0", "1.0.0") << endl;
    cout << "0.1 vs 1.1: " << sol.compareVersion("0.1", "1.1") << endl;
    cout << "1.0.1 vs 1: " << sol.compareVersion("1.0.1", "1") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Number (LeetCode #65)
2. String to Integer (atoi) (LeetCode #8)
3. Minimum Time Difference (LeetCode #539)
4. Next Greater Element III (LeetCode #556)
5. Fraction Addition and Subtraction (LeetCode #592)
6. Valid IP Addresses (LeetCode #93)
7. Decode Ways (LeetCode #91)
8. Restore IP Addresses (LeetCode #93)
9. Integer to English Words (LeetCode #273)
10. Add Binary (LeetCode #67)
*/
