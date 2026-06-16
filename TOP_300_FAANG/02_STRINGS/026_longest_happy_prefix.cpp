/*
================================================================================
PROBLEM: Longest Happy Prefix (LeetCode #1392)
DIFFICULTY: Hard
PATTERN: KMP / String Matching
COMPANIES: Google, Amazon, Facebook
================================================================================

PROBLEM DESCRIPTION:
A string is called a happy prefix if is a non-empty prefix which is also a
suffix (excluding itself). Given a string s, return the longest happy prefix
of s. Return an empty string "" if no such prefix exists.

EXAMPLES:

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"),
and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix.

Example 3:
Input: s = "leetcodeleet"
Output: "leet"

PATTERN RECOGNITION:
Use this pattern when:
- Need to find longest prefix that's also suffix
- KMP failure function (LPS array)
- String periodicity problems
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        // Build LPS (Longest Proper Prefix which is also Suffix) array
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
        
        // Last value in LPS array gives length of longest happy prefix
        int prefixLen = lps[n - 1];
        return s.substr(0, prefixLen);
    }
    
    // Rolling hash approach
    string longestPrefixHash(string s) {
        int n = s.length();
        long long mod = 1e9 + 7;
        long long base = 26;
        
        long long prefixHash = 0, suffixHash = 0;
        long long power = 1;
        int maxLen = 0;
        
        for (int i = 0; i < n - 1; i++) {
            prefixHash = (prefixHash * base + (s[i] - 'a')) % mod;
            suffixHash = (suffixHash + (s[n - 1 - i] - 'a') * power) % mod;
            power = (power * base) % mod;
            
            if (prefixHash == suffixHash) {
                maxLen = i + 1;
            }
        }
        
        return s.substr(0, maxLen);
    }
};

int main() {
    Solution sol;
    
    cout << "level -> \"" << sol.longestPrefix("level") << "\"" << endl;
    cout << "ababab -> \"" << sol.longestPrefix("ababab") << "\"" << endl;
    cout << "leetcodeleet -> \"" << sol.longestPrefix("leetcodeleet") << "\"" << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) for KMP approach
SPACE COMPLEXITY: O(n) for LPS array

SIMILAR PROBLEMS:
1. Implement strStr() (LeetCode #28)
2. Shortest Palindrome (LeetCode #214)
3. Repeated Substring Pattern (LeetCode #459)
4. Longest Duplicate Substring (LeetCode #1044)
5. Find All Good Strings (LeetCode #1397)
6. Longest Common Prefix (LeetCode #14)
7. Minimum Number of Flips (LeetCode #1888)
8. Count Palindromic Subsequences (LeetCode #730)
9. Palindrome Pairs (LeetCode #336)
10. Longest Palindromic Substring (LeetCode #5)
*/
