/*
================================================================================
PROBLEM: Longest Substring Without Repeating Characters (LeetCode #3)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Sliding Window with Set
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // Optimized with Map
    int lengthOfLongestSubstringMap(string s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (lastSeen.count(s[right])) {
                left = max(left, lastSeen[s[right]] + 1);
            }
            lastSeen[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << "Length (abcabcbb): " << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "Length (bbbbb): " << sol.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "Length (pwwkew): " << sol.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Substring with At Most K Distinct (LeetCode #340)
2. Longest Substring At Most Two Distinct (LeetCode #159)
3. Longest Repeating Character Replacement (LeetCode #424)
4. Minimum Window Substring (LeetCode #76)
5. Permutation in String (LeetCode #567)
6. Find All Anagrams in String (LeetCode #438)
7. Substring with Concatenation (LeetCode #30)
8. Max Consecutive Ones III (LeetCode #1004)
9. Fruit Into Baskets (LeetCode #904)
10. Subarrays with K Different Integers (LeetCode #992)
*/
