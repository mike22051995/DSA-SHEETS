/*
================================================================================
PROBLEM: Word Break (LeetCode #139)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / Trie
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================

PROBLEM DESCRIPTION:
Given a string s and a dictionary of strings wordDict, return true if s can be 
segmented into a space-separated sequence of one or more dictionary words.

Note: The same word in the dictionary may be reused multiple times.

================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << "Can break: " << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Word Break II (LeetCode #140)
2. Concatenated Words (LeetCode #472)
3. Word Squares (LeetCode #425)
4. Decode Ways (LeetCode #91)
5. Sentence Screen Fitting (LeetCode #418)
6. Word Pattern (LeetCode #290)
7. Word Pattern II (LeetCode #291)
8. Remove Invalid Parentheses (LeetCode #301)
9. Partition to K Equal Sum Subsets (LeetCode #698)
10. Partition Equal Subset Sum (LeetCode #416)
*/
