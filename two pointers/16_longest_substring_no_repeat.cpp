/*
PROBLEM: Longest Substring Without Repeating Characters
---------------------------------------------------------------------------
Given a string s, find the length of the longest substring without repeating 
characters.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(min(n, m)) where m is character set size

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with length 1.
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Shrink window until no duplicate
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            
            charSet.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }

    // METHOD 2: unordered_map storing last seen index — jump left directly (no inner loop)
    int lengthOfLongestSubstringMap(string s) {
        unordered_map<char, int> lastIndex;  // char -> last seen index
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // If char is inside current window, jump left past the previous occurrence
            if (lastIndex.count(s[right]) && lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "abcabcbb";
    cout << "Test 1 (set): " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "Test 1 (map): " << sol.lengthOfLongestSubstringMap(s1) << endl;
    
    // Test case 2
    string s2 = "bbbbb";
    cout << "Test 2 (set): " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "Test 2 (map): " << sol.lengthOfLongestSubstringMap(s2) << endl;

    // Test case 3 (edge case for map: duplicate outside window)
    string s3 = "abba";
    cout << "Test 3 (set): " << sol.lengthOfLongestSubstring(s3) << endl;
    cout << "Test 3 (map): " << sol.lengthOfLongestSubstringMap(s3) << endl;
    
    return 0;
}
