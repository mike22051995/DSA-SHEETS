/*
================================================================================
PROBLEM: Minimum Window Substring (LeetCode #76)
DIFFICULTY: Hard
PATTERN: Sliding Window with Hash Map
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, LinkedIn
================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> target;
        for (char c : t) {
            target[c]++;
        }
        
        int required = target.size();
        int formed = 0;
        unordered_map<char, int> window;
        
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        
        while (right < s.length()) {
            char c = s[right];
            window[c]++;
            
            if (target.count(c) && window[c] == target[c]) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                char leftChar = s[left];
                window[leftChar]--;
                if (target.count(leftChar) && window[leftChar] < target[leftChar]) {
                    formed--;
                }
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;
    cout << "Min window (ADOBECODEBANC, ABC): " << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << "Min window (a, a): " << sol.minWindow("a", "a") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Substring with Concatenation (LeetCode #30)
2. Minimum Size Subarray Sum (LeetCode #209)
3. Longest Substring At Most Two Distinct (LeetCode #159)
4. Longest Substring K Distinct Characters (LeetCode #340)
5. Permutation in String (LeetCode #567)
6. Find All Anagrams in String (LeetCode #438)
7. Smallest Range K Lists (LeetCode #632)
8. Minimum Window Subsequence (LeetCode #727)
9. Fruit Into Baskets (LeetCode #904)
10. Get Equal Substrings Within Budget (LeetCode #1208)
*/
