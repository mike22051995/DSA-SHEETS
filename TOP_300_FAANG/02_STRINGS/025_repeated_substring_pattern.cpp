/*
================================================================================
PROBLEM: Repeated Substring Pattern (LeetCode #459)
DIFFICULTY: Easy
PATTERN: String / KMP
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given a string s, check if it can be constructed by taking a substring of it
and appending multiple copies of the substring together.

EXAMPLES:

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or "abcabc" twice.

PATTERN RECOGNITION:
Use this pattern when:
- Need to detect repeating patterns in strings
- String periodicity check
- Can use KMP failure function or string concatenation trick
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: String concatenation trick
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.length() - 2);
        return sub.find(s) != string::npos;
    }
    
    // Approach 2: KMP failure function
    bool repeatedSubstringPatternKMP(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        // Build LPS array
        int len = 0;
        for (int i = 1; i < n; ) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Check if string can be divided into repeating pattern
        int lastLPS = lps[n - 1];
        return lastLPS > 0 && n % (n - lastLPS) == 0;
    }
    
    // Approach 3: Check all divisors
    bool repeatedSubstringPatternDivisor(string s) {
        int n = s.length();
        
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string pattern = s.substr(0, len);
                bool valid = true;
                
                for (int i = len; i < n; i += len) {
                    if (s.substr(i, len) != pattern) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    cout << "abab: " << (sol.repeatedSubstringPattern("abab") ? "true" : "false") << endl;
    cout << "aba: " << (sol.repeatedSubstringPattern("aba") ? "true" : "false") << endl;
    cout << "abcabcabcabc: " << (sol.repeatedSubstringPattern("abcabcabcabc") ? "true" : "false") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) for concatenation, O(n) for KMP, O(n*sqrt(n)) for divisor
SPACE COMPLEXITY: O(n) for concatenation, O(n) for KMP, O(1) for divisor check

SIMILAR PROBLEMS:
1. Implement strStr() (LeetCode #28)
2. Shortest Palindrome (LeetCode #214)
3. Detect Pattern of Length M (LeetCode #1566)
4. Check if String Is Decomposable (LeetCode #1933)
5. Rotate String (LeetCode #796)
6. Longest Happy Prefix (LeetCode #1392)
7. Minimum Number of Flips (LeetCode #1888)
8. Find All Good Strings (LeetCode #1397)
9. Number of Substrings With Only 1s (LeetCode #1513)
10. Count and Say (LeetCode #38)
*/
