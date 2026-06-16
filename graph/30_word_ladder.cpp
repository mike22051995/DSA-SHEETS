/*
PROBLEM: Word Ladder (LeetCode 127)
Difficulty: Hard
Pattern: BFS on Implicit Graph

DESCRIPTION:
Given two words (beginWord and endWord) and a dictionary's word list,
find the length of shortest transformation sequence from beginWord to endWord.
Rules:
1. Only one letter can be changed at a time
2. Each transformed word must exist in the word list

WORD GRAPH DIAGRAM:
  Example: beginWord="hit", endWord="cog"
  wordList=["hot","dot","dog","lot","log","cog"]
  
  Implicit Graph (1 letter difference = edge):
       hit
        |
       hot
      /   \
    dot   lot
     |     |
    dog   log
      \   /
       cog
  
  Shortest Path: hit → hot → dot → dog → cog
  Length: 5 words
  
  BFS finds shortest transformation sequence

APPROACH:
1. Build implicit graph where each word is a node
2. Two words are connected if they differ by exactly one character
3. Use BFS to find shortest path from beginWord to endWord
4. Return the length of the path (number of words in sequence)

TIME COMPLEXITY: O(M² * N) where M = word length, N = number of words
SPACE COMPLEXITY: O(M * N)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord not in dictionary
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();
            
            // If we reached endWord
            if (word == endWord) {
                return level;
            }
            
            // Try changing each character
            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                
                // Try all 26 letters
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    
                    // If this word is in dictionary
                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push({temp, level + 1});
                        wordSet.erase(temp); // Mark as visited
                    }
                }
            }
        }
        
        return 0; // No transformation sequence found
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    cout << "Shortest transformation sequence length: " 
         << sol.ladderLength(beginWord1, endWord1, wordList1) << endl;
    
    // Example 2
    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    
    cout << "Shortest transformation sequence length: " 
         << sol.ladderLength(beginWord2, endWord2, wordList2) << endl;
    
    return 0;
}

/*
INPUT 1:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

OUTPUT:
Shortest transformation sequence length: 5

EXPLANATION:
Sequence: "hit" -> "hot" -> "dot" -> "dog" -> "cog"
Length: 5 words

INPUT 2:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

OUTPUT:
Shortest transformation sequence length: 0

EXPLANATION:
endWord "cog" is not in wordList, so no transformation possible.

KEY INSIGHTS:
- This is a graph problem where words are nodes
- BFS finds shortest path in unweighted graph
- Each word differs by one character from neighbors
- Common pattern in FAANG interviews
*/
