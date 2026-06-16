/*
================================================================================
PROBLEM: Word Ladder (LeetCode #127)
DIFFICULTY: Hard
PATTERN: BFS (Shortest Path)
COMPANIES: Amazon, Facebook, Google, Microsoft, LinkedIn
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (!wordSet.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) return level;
                
                // Try all possible one-letter changes
                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        
                        word[j] = c;
                        
                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word); // Mark visited
                        }
                    }
                    
                    word[j] = originalChar;
                }
            }
            
            level++;
        }
        
        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    
    cout << "Ladder length: " << sol.ladderLength(beginWord, endWord, wordList) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Word Ladder II (LeetCode #126) - All shortest paths
2. Minimum Genetic Mutation (LeetCode #433)
3. Open the Lock (LeetCode #752)
4. Shortest Path Visiting All Nodes (LeetCode #847)
5. Shortest Path in Binary Matrix (LeetCode #1091)
6. Snakes and Ladders (LeetCode #909)
7. Jump Game IV (LeetCode #1345)
8. Sliding Puzzle (LeetCode #773)
9. Minimum Knight Moves (LeetCode #1197)
10. Shortest Bridge (LeetCode #934)
*/
