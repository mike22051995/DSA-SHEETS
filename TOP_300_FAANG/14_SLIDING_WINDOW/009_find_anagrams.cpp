/*
================================================================================
PROBLEM: Find All Anagrams in String (LeetCode #438)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        if (s.length() < p.length()) return result;
        
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            
            if (i >= p.length()) {
                sCount[s[i - p.length()] - 'a']--;
            }
            
            if (pCount == sCount) {
                result.push_back(i - p.length() + 1);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    
    vector<int> result = sol.findAnagrams(s, p);
    
    cout << "Anagram indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Anagram (LeetCode #242)
2. Group Anagrams (LeetCode #49)
3. Permutation in String (LeetCode #567)
4. Minimum Window Substring (LeetCode #76)
5. Substring with Concatenation (LeetCode #30)
6. Longest Substring Without Repeating (LeetCode #3)
7. Longest Repeating Character Replacement (LeetCode #424)
8. Sliding Window Maximum (LeetCode #239)
9. Count Anagrams (LeetCode #2514)
10. Find Resultant Array After Queries (LeetCode #2588)
*/
