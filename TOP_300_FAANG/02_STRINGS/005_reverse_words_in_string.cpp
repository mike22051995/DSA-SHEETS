/*
================================================================================
PROBLEM: Reverse Words in a String (LeetCode #151)
DIFFICULTY: Medium
PATTERN: Two Pointers / String Manipulation
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    // Using stringstream
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result;
        
        while (ss >> word) {
            if (!result.empty()) {
                result = word + " " + result;
            } else {
                result = word;
            }
        }
        
        return result;
    }
    
    // In-place approach
    string reverseWordsInPlace(string s) {
        // Remove leading, trailing and multiple spaces
        int i = 0, j = 0, n = s.length();
        
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i == n) break;
            
            if (j != 0) s[j++] = ' ';
            
            int start = j;
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }
        
        s.resize(j);
        
        // Reverse entire string
        reverse(s.begin(), s.end());
        
        // Reverse each word
        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    cout << "'" << sol.reverseWords("the sky is blue") << "'" << endl;
    cout << "'" << sol.reverseWords("  hello world  ") << "'" << endl;
    cout << "'" << sol.reverseWords("a good   example") << "'" << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse String (LeetCode #344)
2. Reverse String II (LeetCode #541)
3. Reverse Words in String III (LeetCode #557)
4. Reverse Only Letters (LeetCode #917)
5. Valid Palindrome (LeetCode #125)
6. String Compression (LeetCode #443)
7. Remove Duplicates from Sorted Array (LeetCode #26)
8. Remove Element (LeetCode #27)
9. Move Zeroes (LeetCode #283)
10. Rotate Array (LeetCode #189)
*/
