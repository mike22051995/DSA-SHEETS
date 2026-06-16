/*
PROBLEM: Valid Anagram (LeetCode 242)
===============================================
DESCRIPTION:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An anagram is a word formed by rearranging the letters of a different word, using 
all the original letters exactly once.

PATTERN: Sorting for Comparison
DIFFICULTY: Easy
TIME COMPLEXITY: O(n log n) for sorting approach
SPACE COMPLEXITY: O(1) ignoring space used for sorting

INPUT:
Two strings

OUTPUT:
Boolean (true if anagram, false otherwise)

EXAMPLE:
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Sorting (most straightforward)
    bool isAnagram(string s, string t) {
        // Different lengths can't be anagrams
        if (s.length() != t.length()) return false;
        
        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Compare sorted strings
        return s == t;
    }
    
    // Approach 2: Frequency Count (more efficient)
    bool isAnagramV2(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> freq;
        
        // Count characters in s
        for (char c : s) {
            freq[c]++;
        }
        
        // Decrease count for characters in t
        for (char c : t) {
            freq[c]--;
            if (freq[c] < 0) return false;
        }
        
        return true;
    }
    
    // Approach 3: Array frequency (for lowercase English letters)
    bool isAnagramV3(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int count[26] = {0};
        
        // Count characters
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // Check if all counts are zero
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    string s1 = "anagram", t1 = "nagaram";
    cout << "s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Is anagram (Sorting): " << (sol.isAnagram(s1, t1) ? "true" : "false") << endl;
    cout << "Is anagram (HashMap): " << (sol.isAnagramV2(s1, t1) ? "true" : "false") << endl;
    cout << "Is anagram (Array): " << (sol.isAnagramV3(s1, t1) ? "true" : "false") << endl;
    
    string s2 = "rat", t2 = "car";
    cout << "\ns = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Is anagram (Sorting): " << (sol.isAnagram(s2, t2) ? "true" : "false") << endl;
    cout << "Is anagram (HashMap): " << (sol.isAnagramV2(s2, t2) ? "true" : "false") << endl;
    cout << "Is anagram (Array): " << (sol.isAnagramV3(s2, t2) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: Sorting
- Sort both strings
- If anagrams, sorted strings will be identical
- Time: O(n log n), Space: O(1)

APPROACH 2: HashMap Frequency
- Count frequency of each character
- If anagrams, all frequencies match
- Time: O(n), Space: O(k) where k is unique characters

APPROACH 3: Array Frequency (optimized for lowercase letters)
- Use array of size 26 for lowercase letters
- Increment for string s, decrement for string t
- If anagrams, all counts become zero
- Time: O(n), Space: O(1) - constant 26 size

COMPARISON:
- Sorting: Simplest to code, O(n log n)
- HashMap: O(n) but uses extra space
- Array: O(n) and O(1) space (best for lowercase letters)

WHY THIS PATTERN IS IMPORTANT:
- Sorting as a technique for comparison problems
- Trade-offs between time and space complexity
- Foundation for "Group Anagrams" problem
- Common string manipulation pattern
- Multiple valid approaches show problem-solving flexibility
*/
