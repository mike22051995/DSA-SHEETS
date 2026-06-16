/*
================================================================================
PROBLEM: Permutation in String (LeetCode #567)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        for (char c : s1) {
            s1Count[c - 'a']++;
        }
        
        for (int i = 0; i < s2.length(); i++) {
            s2Count[s2[i] - 'a']++;
            
            if (i >= s1.length()) {
                s2Count[s2[i - s1.length()] - 'a']--;
            }
            
            if (s1Count == s2Count) {
                return true;
            }
        }
        
        return false;
    }
    
    // Alternative with matches counter
    bool checkInclusionMatches(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> count(26, 0);
        
        for (char c : s1) {
            count[c - 'a']++;
        }
        
        int matches = 0;
        for (int c : count) {
            if (c == 0) matches++;
        }
        
        for (int i = 0; i < s2.length(); i++) {
            int index = s2[i] - 'a';
            count[index]--;
            
            if (count[index] == 0) matches++;
            else if (count[index] == -1) matches--;
            
            if (i >= s1.length()) {
                int leftIndex = s2[i - s1.length()] - 'a';
                count[leftIndex]++;
                
                if (count[leftIndex] == 0) matches++;
                else if (count[leftIndex] == 1) matches--;
            }
            
            if (matches == 26) return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    cout << "Check inclusion (ab, eidbaooo): " << (sol.checkInclusion("ab", "eidbaooo") ? "true" : "false") << endl;
    cout << "Check inclusion (ab, eidboaoo): " << (sol.checkInclusion("ab", "eidboaoo") ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Find All Anagrams in String (LeetCode #438)
2. Minimum Window Substring (LeetCode #76)
3. Substring with Concatenation (LeetCode #30)
4. Valid Anagram (LeetCode #242)
5. Group Anagrams (LeetCode #49)
6. Longest Repeating Character Replacement (LeetCode #424)
7. Frequency of Most Frequent Element (LeetCode #1838)
8. Maximize Win From Two Segments (LeetCode #2555)
9. Count Anagrams (LeetCode #2514)
10. Number of Subsequences That Satisfy (LeetCode #1498)
*/
