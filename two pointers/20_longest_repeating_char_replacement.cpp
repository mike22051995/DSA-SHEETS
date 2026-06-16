/*
PROBLEM: Longest Repeating Character Replacement
---------------------------------------------------------------------------
You are given a string s and an integer k. You can choose any character of 
the string and change it to any other uppercase English character. You can 
perform this operation at most k times. Return the length of the longest 
substring containing the same letter you can get after performing the operations.

PATTERN: Sliding Window (With Character Frequency)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(26) = O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace two 'A's with 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace one 'A' in the middle with 'B': "AABBBBA". Substring "BBBB" = 4.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int maxCount = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            count[s[right]]++;
            maxCount = max(maxCount, count[s[right]]);
            
            // Window size - most frequent char count > k means invalid
            while (right - left + 1 - maxCount > k) {
                count[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Test 1: " << sol.characterReplacement(s1, k1) << endl;
    
    // Test case 2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Test 2: " << sol.characterReplacement(s2, k2) << endl;
    
    return 0;
}
