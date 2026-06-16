/*
PROBLEM: Maximum Product of Word Lengths
==========================================
Given a string array, find the maximum product of lengths of two words 
that do not share common letters.

APPROACH:
- Use bitmask to represent which letters each word contains
- For each word, create a 26-bit mask (for a-z)
- Check if two words have no common letters: mask1 & mask2 == 0
- Find maximum product among valid pairs

PATTERN: Bitmask for Character Set Representation

INPUT/OUTPUT:
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: "abcw" and "xtfn" have no common letters, 4*4 = 16

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: "ab" and "cd" have no common letters, 2*2 = 4

TIME COMPLEXITY: O(n^2 + L) where L is total length of all words
SPACE COMPLEXITY: O(n) for storing masks
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);
        
        // Create bitmask for each word
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                masks[i] |= (1 << (c - 'a'));
            }
        }
        
        int maxProd = 0;
        
        // Check all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If no common letters (AND is 0)
                if ((masks[i] & masks[j]) == 0) {
                    int product = words[i].length() * words[j].length();
                    maxProd = max(maxProd, product);
                }
            }
        }
        
        return maxProd;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<string> words1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << "Input: [\"abcw\",\"baz\",\"foo\",\"bar\",\"xtfn\",\"abcdef\"]" << endl;
    cout << "Output: " << sol.maxProduct(words1) << endl;
    cout << "Explanation: \"abcw\"(4) and \"xtfn\"(4) = 16" << endl << endl;
    
    // Test Case 2
    vector<string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    cout << "Input: [\"a\",\"ab\",\"abc\",\"d\",\"cd\",\"bcd\",\"abcd\"]" << endl;
    cout << "Output: " << sol.maxProduct(words2) << endl;
    cout << "Explanation: \"ab\"(2) and \"cd\"(2) = 4" << endl << endl;
    
    // Test Case 3
    vector<string> words3 = {"a", "aa", "aaa", "aaaa"};
    cout << "Input: [\"a\",\"aa\",\"aaa\",\"aaaa\"]" << endl;
    cout << "Output: " << sol.maxProduct(words3) << endl;
    cout << "Explanation: All words share 'a', no valid pair" << endl;
    
    return 0;
}
