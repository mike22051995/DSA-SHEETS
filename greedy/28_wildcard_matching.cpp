/*
PROBLEM: Wildcard Matching (LeetCode 44)
DIFFICULTY: Hard
PATTERN: Greedy Backtracking with Two Pointers

DESCRIPTION:
Given an input string (s) and a pattern (p), implement wildcard pattern matching with 
support for '?' and '*' where:
- '?' Matches any single character.
- '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

INPUT:
- s: input string
- p: pattern with wildcards

OUTPUT:
- true if pattern matches string

APPROACH:
1. Use two pointers for string and pattern
2. When '*' found, remember position (greedy backtrack point)
3. Try matching '*' with empty sequence first
4. If mismatch later, backtrack and match '*' with more characters
5. Greedy: try minimal match first, expand if needed

WHY GREEDY WORKS:
Try to match '*' with minimum characters first. If doesn't work, backtrack 
and expand the match. This ensures we find a valid match if it exists.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, matchIdx = 0;
        
        while (sIdx < sLen) {
            // If characters match or pattern has '?'
            if (pIdx < pLen && (s[sIdx] == p[pIdx] || p[pIdx] == '?')) {
                sIdx++;
                pIdx++;
            }
            // If pattern has '*', remember position
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++;  // Try matching '*' with empty sequence first
            }
            // Mismatch: if we saw '*' before, backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                matchIdx++;
                sIdx = matchIdx;  // Try matching '*' with one more character
            }
            // No match possible
            else {
                return false;
            }
        }
        
        // Check remaining pattern characters (should all be '*')
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }
        
        return pIdx == pLen;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    cout << "Test 1 - s=\"aa\", p=\"a\"" << endl;
    cout << "Output: " << (sol.isMatch("aa", "a") ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test Case 2
    cout << "Test 2 - s=\"aa\", p=\"*\"" << endl;
    cout << "Output: " << (sol.isMatch("aa", "*") ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 3
    cout << "Test 3 - s=\"cb\", p=\"?a\"" << endl;
    cout << "Output: " << (sol.isMatch("cb", "?a") ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test Case 4
    cout << "Test 4 - s=\"adceb\", p=\"*a*b\"" << endl;
    cout << "Output: " << (sol.isMatch("adceb", "*a*b") ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 5
    cout << "Test 5 - s=\"acdcb\", p=\"a*c?b\"" << endl;
    cout << "Output: " << (sol.isMatch("acdcb", "a*c?b") ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(min(s, p)) best case, O(s * p) worst case
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Greedy with backtracking: try minimal match, expand if needed
- Remember last '*' position for backtracking
- Two pointers with state tracking
- Can also solve with DP but greedy is more space efficient
- Pattern matching is common in system design interviews
- Similar to Regular Expression Matching but simpler
*/
