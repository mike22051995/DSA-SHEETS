/*
    Longest Substring Without Repeating Characters - LeetCode #3
    
    Given a string s, find the length of the longest substring without repeating characters.
    
    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    
    Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    
    Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    
    Constraints:
    - 0 <= s.length <= 5 * 10^4
    - s consists of English letters, digits, symbols and spaces
    
    Time Complexity: O(n)
    Space Complexity: O(min(n, m)) where m is the charset size
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Sliding Window with Hash Map (Optimized)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // If character already exists in current window
            if (charIndex.find(s[right]) != charIndex.end() && 
                charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            
            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // Approach 2: Sliding Window with Set
    int lengthOfLongestSubstringSet(string s) {
        unordered_set<char> chars;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            while (chars.count(s[right])) {
                chars.erase(s[left]);
                left++;
            }
            chars.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.lengthOfLongestSubstring("abcabcbb") << endl;  // 3
    cout << "Test 2: " << sol.lengthOfLongestSubstring("bbbbb") << endl;     // 1
    cout << "Test 3: " << sol.lengthOfLongestSubstring("pwwkew") << endl;    // 3
    cout << "Test 4: " << sol.lengthOfLongestSubstring("") << endl;          // 0
    cout << "Test 5: " << sol.lengthOfLongestSubstring("dvdf") << endl;      // 3
    
    return 0;
}
