/*
    Valid Anagram - LeetCode #242
    
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    typically using all the original letters exactly once.
    
    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true
    
    Example 2:
    Input: s = "rat", t = "car"
    Output: false
    
    Constraints:
    - 1 <= s.length, t.length <= 5 * 10^4
    - s and t consist of lowercase English letters
    
    Time Complexity: O(n)
    Space Complexity: O(1) - fixed size array
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using Hash Map
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> count;
        
        for (char c : s) {
            count[c]++;
        }
        
        for (char c : t) {
            count[c]--;
            if (count[c] < 0) return false;
        }
        
        return true;
    }
    
    // Approach 2: Using Array (Better Space)
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
    
    // Approach 3: Using Sorting
    bool isAnagramSort(string s, string t) {
        if (s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << (sol.isAnagram("anagram", "nagaram") ? "true" : "false") << endl;
    cout << "Test 2: " << (sol.isAnagram("rat", "car") ? "true" : "false") << endl;
    cout << "Test 3: " << (sol.isAnagram("listen", "silent") ? "true" : "false") << endl;
    
    return 0;
}
