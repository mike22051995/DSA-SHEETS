/*
================================================================================
PROBLEM: Valid Anagram (LeetCode #242)
DIFFICULTY: Easy
PATTERN: Hash Table / Sorting
COMPANIES: Amazon, Google, Facebook, Microsoft, Bloomberg
================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Hash Map Approach
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        for (char c : t) {
            if (--freq[c] < 0) return false;
        }
        
        return true;
    }
    
    // Array Counter (Better for ASCII)
    bool isAnagramArray(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        
        return true;
    }
    
    // Sorting Approach
    bool isAnagramSort(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution sol;
    cout << "Is anagram (anagram, nagaram): " << (sol.isAnagram("anagram", "nagaram") ? "true" : "false") << endl;
    cout << "Is anagram (rat, car): " << (sol.isAnagram("rat", "car") ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Group Anagrams (LeetCode #49)
2. Find All Anagrams in String (LeetCode #438)
3. Permutation in String (LeetCode #567)
4. Minimum Window Substring (LeetCode #76)
5. Valid Palindrome (LeetCode #125)
6. Isomorphic Strings (LeetCode #205)
7. Word Pattern (LeetCode #290)
8. Ransom Note (LeetCode #383)
9. Find Common Characters (LeetCode #1002)
10. Maximum Number of Balloons (LeetCode #1189)
*/
