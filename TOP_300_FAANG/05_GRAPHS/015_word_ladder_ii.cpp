/*
================================================================================
PROBLEM: Word Ladder II (LeetCode #126)
DIFFICULTY: Hard
PATTERN: BFS + Backtracking
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        
        if (dict.find(endWord) == dict.end()) {
            return result;
        }
        
        unordered_map<string, vector<string>> parents;
        unordered_set<string> level, nextLevel;
        level.insert(beginWord);
        
        bool found = false;
        
        while (!level.empty() && !found) {
            for (const string& word : level) {
                dict.erase(word);
            }
            
            for (const string& word : level) {
                string curr = word;
                
                for (int i = 0; i < curr.length(); i++) {
                    char original = curr[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        
                        curr[i] = c;
                        
                        if (dict.find(curr) != dict.end()) {
                            if (curr == endWord) {
                                found = true;
                            }
                            
                            parents[curr].push_back(word);
                            nextLevel.insert(curr);
                        }
                    }
                    
                    curr[i] = original;
                }
            }
            
            level = nextLevel;
            nextLevel.clear();
        }
        
        if (found) {
            vector<string> path = {endWord};
            backtrack(beginWord, endWord, parents, path, result);
        }
        
        return result;
    }
    
    void backtrack(const string& beginWord, const string& word, 
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        
        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(beginWord, parent, parents, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);
    
    cout << "All shortest paths:" << endl;
    for (auto& path : result) {
        for (string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Word Ladder (LeetCode #127)
2. Minimum Genetic Mutation (LeetCode #433)
3. Open the Lock (LeetCode #752)
4. Shortest Path in Binary Matrix (LeetCode #1091)
5. Shortest Path with Alternating Colors (LeetCode #1129)
6. All Paths From Source to Target (LeetCode #797)
7. Find All Possible Recipes (LeetCode #2115)
8. Shortest Bridge (LeetCode #934)
9. Cut Off Trees for Golf Event (LeetCode #675)
10. Snakes and Ladders (LeetCode #909)
*/
