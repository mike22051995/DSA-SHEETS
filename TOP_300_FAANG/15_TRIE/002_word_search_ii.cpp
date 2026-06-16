/*
================================================================================
PROBLEM: Word Search II (LeetCode #212)
DIFFICULTY: Hard
PATTERN: Trie + Backtracking
COMPANIES: Amazon, Google, Microsoft, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    string word;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;
    
    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->word = word;
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        
        char c = board[i][j];
        if (c == '#' || node->children[c - 'a'] == nullptr) {
            return;
        }
        
        node = node->children[c - 'a'];
        
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }
        
        board[i][j] = '#'; // Mark visited
        
        dfs(board, i + 1, j, node);
        dfs(board, i - 1, j, node);
        dfs(board, i, j + 1, node);
        dfs(board, i, j - 1, node);
        
        board[i][j] = c; // Restore
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        result.clear();
        buildTrie(words);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    
    auto result = sol.findWords(board, words);
    cout << "Found words: ";
    for (string& word : result) {
        cout << word << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Word Search (LeetCode #79)
2. Implement Trie (LeetCode #208)
3. Design Add Search Words (LeetCode #211)
4. Boggle Game (Classic Problem)
5. Design Search Autocomplete (LeetCode #642)
6. Stream of Characters (LeetCode #1032)
7. Word Ladder (LeetCode #127)
8. Word Ladder II (LeetCode #126)
9. Count Items Matching a Rule (LeetCode #1773)
10. Maximum XOR of Two Numbers (LeetCode #421)
*/
