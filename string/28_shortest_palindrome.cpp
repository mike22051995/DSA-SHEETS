/*
    Shortest Palindrome - LeetCode #214
    
    You are given a string s. You can convert s to a palindrome by adding characters in front of it.
    Return the shortest palindrome you can find by performing this transformation.
    
    Example 1:
    Input: s = "aacecaaa"
    Output: "aaacecaaa"
    
    Example 2:
    Input: s = "abcd"
    Output: "dcbabcd"
    
    Constraints:
    - 0 <= s.length <= 5 * 10^4
    - s consists of lowercase English letters only
    
    Time Complexity: O(n^2) brute force, O(n) with KMP
    Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using KMP Algorithm
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;
        
        // Build LPS array
        vector<int> lps = buildLPS(combined);
        
        // Length of longest palindrome starting from beginning
        int longestPalindromeLen = lps.back();
        
        // Add reverse of remaining part to the beginning
        string toAdd = s.substr(longestPalindromeLen);
        reverse(toAdd.begin(), toAdd.end());
        
        return toAdd + s;
    }
    
private:
    vector<int> buildLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
            if (pattern[i] == pattern[len]) {
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
        
        return lps;
    }
    
public:
    // Approach 2: Brute Force
    string shortestPalindromeBruteForce(string s) {
        int n = s.length();
        
        // Find the longest palindrome starting from index 0
        int end = n - 1;
        while (end >= 0) {
            if (isPalindrome(s, 0, end)) {
                break;
            }
            end--;
        }
        
        // Add reverse of remaining part to the beginning
        string toAdd = s.substr(end + 1);
        reverse(toAdd.begin(), toAdd.end());
        
        return toAdd + s;
    }
    
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.shortestPalindrome("aacecaaa") << endl;  // "aaacecaaa"
    cout << "Test 2: " << sol.shortestPalindrome("abcd") << endl;      // "dcbabcd"
    cout << "Test 3: " << sol.shortestPalindrome("") << endl;          // ""
    cout << "Test 4: " << sol.shortestPalindrome("a") << endl;         // "a"
    
    return 0;
}
