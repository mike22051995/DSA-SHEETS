/*
    Word Break - LeetCode #139
    
    Given a string s and a dictionary of strings wordDict, return true if s can be
    segmented into a space-separated sequence of one or more dictionary words.
    
    Note: The same word in the dictionary may be reused multiple times in the segmentation.
    
    Example 1:
    Input: s = "leetcode", wordDict = ["leet","code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".
    
    Example 2:
    Input: s = "applepenapple", wordDict = ["apple","pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
    
    Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: false
    
    Constraints:
    - 1 <= s.length <= 300
    - 1 <= wordDict.length <= 1000
    - 1 <= wordDict[i].length <= 20
    - s and wordDict[i] consist of only lowercase English letters
    - All the strings of wordDict are unique
    
    Time Complexity: O(n^2) where n is length of s
    Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Approach: Dynamic Programming
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
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
    
    // Test 1
    vector<string> dict1 = {"leet", "code"};
    cout << "Test 1: " << (sol.wordBreak("leetcode", dict1) ? "true" : "false") << endl;
    
    // Test 2
    vector<string> dict2 = {"apple", "pen"};
    cout << "Test 2: " << (sol.wordBreak("applepenapple", dict2) ? "true" : "false") << endl;
    
    // Test 3
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test 3: " << (sol.wordBreak("catsandog", dict3) ? "true" : "false") << endl;
    
    return 0;
}
