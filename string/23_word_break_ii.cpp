/*
    Word Break II - LeetCode #140
    
    Given a string s and a dictionary of strings wordDict, add spaces in s to construct
    a sentence where each word is a valid dictionary word. Return all such possible sentences
    in any order.
    
    Example 1:
    Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    Output: ["cats and dog","cat sand dog"]
    
    Example 2:
    Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
    Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    Explanation: "pineapplepenapple" can be segmented as "pine apple pen apple".
    
    Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: []
    
    Constraints:
    - 1 <= s.length <= 20
    - 1 <= wordDict.length <= 1000
    - 1 <= wordDict[i].length <= 10
    - s and wordDict[i] consist of only lowercase English letters
    
    Time Complexity: O(n * 2^n) worst case
    Space Complexity: O(n * 2^n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return backtrack(s, 0, wordSet, memo);
    }
    
private:
    vector<string> backtrack(const string& s, int start, 
                            unordered_set<string>& wordSet,
                            unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) {
            return memo[start];
        }
        
        vector<string> result;
        
        // Base case: reached end of string
        if (start == s.length()) {
            result.push_back("");
            return result;
        }
        
        // Try all possible words starting from current position
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            
            if (wordSet.count(word)) {
                vector<string> sublist = backtrack(s, end, wordSet, memo);
                
                for (const string& sub : sublist) {
                    if (sub.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + sub);
                    }
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<string> dict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = sol.wordBreak("catsanddog", dict1);
    cout << "Test 1:" << endl;
    for (const string& s : result1) {
        cout << "  \"" << s << "\"" << endl;
    }
    
    // Test 2
    vector<string> dict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = sol.wordBreak("pineapplepenapple", dict2);
    cout << "Test 2:" << endl;
    for (const string& s : result2) {
        cout << "  \"" << s << "\"" << endl;
    }
    
    return 0;
}
