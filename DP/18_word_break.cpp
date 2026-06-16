/*
PROBLEM: Word Break
Difficulty: Medium
Pattern: 1D DP, String Segmentation

DESCRIPTION:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into 
a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

INPUT:
s = "leetcode", wordDict = ["leet", "code"]

OUTPUT:
true
Explanation: Return true because "leetcode" can be segmented as "leet code".

TIME COMPLEXITY: O(n^2 * m) where n = length of s, m = average word length
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i] = true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If s[0...j-1] can be segmented AND s[j...i-1] is in dictionary
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Found one valid segmentation
                }
            }
        }
        
        return dp[n];
    }
    
    // Alternative: Check all words in dictionary
    bool wordBreakAlternate(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (const string& word : wordDict) {
                int len = word.length();
                if (i >= len && dp[i - len] && s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Input: s = \"" << s1 << "\", wordDict = [\"leet\", \"code\"]" << endl;
    cout << "Output: " << (sol.wordBreak(s1, wordDict1) ? "true" : "false") << endl;
    cout << "Output (Alternate): " << (sol.wordBreakAlternate(s1, wordDict1) ? "true" : "false") << endl << endl;
    
    // Test Case 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "Input: s = \"" << s2 << "\", wordDict = [\"apple\", \"pen\"]" << endl;
    cout << "Output: " << (sol.wordBreak(s2, wordDict2) ? "true" : "false") << endl;
    cout << "Output (Alternate): " << (sol.wordBreakAlternate(s2, wordDict2) ? "true" : "false") << endl << endl;
    
    // Test Case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Input: s = \"" << s3 << "\", wordDict = [\"cats\", \"dog\", \"sand\", \"and\", \"cat\"]" << endl;
    cout << "Output: " << (sol.wordBreak(s3, wordDict3) ? "true" : "false") << endl;
    cout << "Output (Alternate): " << (sol.wordBreakAlternate(s3, wordDict3) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:
1. dp[i] = true if s[0...i-1] can be segmented using dictionary words
2. For each position i, check all positions j < i:
   - If dp[j] is true (s[0...j-1] can be segmented)
   - AND s[j...i-1] is in dictionary
   - Then dp[i] = true
3. Use hash set for O(1) word lookup
4. Return dp[n]

Example: s = "leetcode", dict = ["leet", "code"]
dp[0] = true (empty)
dp[4] = true (s[0:4] = "leet" in dict)
dp[8] = true (dp[4] && s[4:8] = "code" in dict)

KEY LEARNING:
- String segmentation using DP
- Try all possible break points
- Hash set for fast word lookup
- Can be extended to Word Break II (find all segmentations)
- Similar to: Concatenated Words
*/
