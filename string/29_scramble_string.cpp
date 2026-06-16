/*
    Scramble String - LeetCode #87
    
    We can scramble a string s to get a string t using the following algorithm:
    1. If the length of the string is 1, stop.
    2. If the length of the string is > 1, do the following:
       - Split the string into two non-empty substrings at a random index
       - Randomly decide to swap the two substrings or keep them in order
       - Apply step 1 recursively on each substring
    
    Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1.
    
    Example 1:
    Input: s1 = "great", s2 = "rgeat"
    Output: true
    Explanation: One possible scenario is:
    "great" --> "gr/eat" --> "gr/e/at" --> swap("gr", "e") --> "e/gr/at" --> "rg/e/at"
    --> swap("rg", "e") --> "e/rg/at" --> "gr/e/at" --> "rg/eat" --> "rgeat"
    
    Example 2:
    Input: s1 = "abcde", s2 = "caebd"
    Output: false
    
    Example 3:
    Input: s1 = "a", s2 = "a"
    Output: true
    
    Constraints:
    - s1.length == s2.length
    - 1 <= s1.length <= 30
    - s1 and s2 consist of lowercase English letters
    
    Time Complexity: O(n^4) with memoization
    Space Complexity: O(n^3) for memoization
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        
        unordered_map<string, bool> memo;
        return helper(s1, s2, memo);
    }
    
private:
    bool helper(const string& s1, const string& s2, unordered_map<string, bool>& memo) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];
        
        // Check if both strings have same character frequency
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) {
            memo[key] = false;
            return false;
        }
        
        int n = s1.length();
        
        // Try all possible split points
        for (int i = 1; i < n; i++) {
            // Case 1: No swap
            if (helper(s1.substr(0, i), s2.substr(0, i), memo) &&
                helper(s1.substr(i), s2.substr(i), memo)) {
                memo[key] = true;
                return true;
            }
            
            // Case 2: With swap
            if (helper(s1.substr(0, i), s2.substr(n - i), memo) &&
                helper(s1.substr(i), s2.substr(0, n - i), memo)) {
                memo[key] = true;
                return true;
            }
        }
        
        memo[key] = false;
        return false;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << (sol.isScramble("great", "rgeat") ? "true" : "false") << endl;     // true
    cout << "Test 2: " << (sol.isScramble("abcde", "caebd") ? "true" : "false") << endl;     // false
    cout << "Test 3: " << (sol.isScramble("a", "a") ? "true" : "false") << endl;             // true
    cout << "Test 4: " << (sol.isScramble("abcdbdacbdac", "bdacabcdbdac") ? "true" : "false") << endl;  // true
    
    return 0;
}
