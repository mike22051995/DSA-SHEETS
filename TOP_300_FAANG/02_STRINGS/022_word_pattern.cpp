/*
================================================================================
PROBLEM: Word Pattern (LeetCode #290)
DIFFICULTY: Easy
PATTERN: Hash Map / Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in s.

EXAMPLES:

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

PATTERN RECOGNITION:
Use this pattern when:
- Need to match pattern elements to string elements
- One-to-one mapping required (bijection)
- Order preservation is important
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (pattern.length() != words.size()) return false;
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } else {
                charToWord[c] = w;
            }
            
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) return false;
            } else {
                wordToChar[w] = c;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    cout << "Pattern 'abba', 'dog cat cat dog': " 
         << (sol.wordPattern("abba", "dog cat cat dog") ? "true" : "false") << endl;
    
    cout << "Pattern 'abba', 'dog cat cat fish': " 
         << (sol.wordPattern("abba", "dog cat cat fish") ? "true" : "false") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n + m) where n is pattern length, m is string length
SPACE COMPLEXITY: O(n + m) for hash maps and word storage

SIMILAR PROBLEMS:
1. Isomorphic Strings (LeetCode #205)
2. Word Pattern II (LeetCode #291)
3. Find and Replace Pattern (LeetCode #890)
4. Valid Anagram (LeetCode #242)
5. Group Anagrams (LeetCode #49)
6. Encode and Decode Strings (LeetCode #271)
7. String Compression (LeetCode #443)
8. Minimum Window Substring (LeetCode #76)
9. Longest Substring Without Repeating Characters (LeetCode #3)
10. Group Shifted Strings (LeetCode #249)
*/
