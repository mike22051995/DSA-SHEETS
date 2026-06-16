/*
PROBLEM: Word Search II (LeetCode 212)
Difficulty: Hard
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Trie + Backtracking

DESCRIPTION:
Given an m x n board of characters and a list of strings words, return all words 
on the board. Each word must be constructed from letters of sequentially adjacent 
cells (horizontally or vertically). Same cell may not be used more than once per word.

BOARD DIAGRAM:
  Board:                    Words to find: ["oath","pea","eat","rain"]
  o  a  a  n
  e  t  a  e              Found words:
  i  h  k  r              - "oath": o→a→t→h
  i  f  l  v              - "eat": e→a→t
  
  Use Trie for efficient word lookup
  - Build Trie from words list
  - DFS from each cell, following Trie branches
  - If reach word end in Trie, add to result

APPROACH:
1. Build Trie from all words
2. For each cell in board:
   - Start DFS if cell character is in Trie root
   - Mark cell as visited (temporarily modify)
   - Explore 4 directions following Trie branches
   - If reach end of word, add to result and mark word as found
   - Backtrack: unmark cell
3. Return all found words

Optimizations:
- Remove word from Trie once found (avoid duplicates)
- Prune Trie branches with no words left
- Early termination when all words found

TIME COMPLEXITY: O(M * N * 4^L) where L = max word length
SPACE COMPLEXITY: O(W * L) for Trie, where W = number of words
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
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build Trie
        root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (node->children[idx] == nullptr) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->word = word;
        }
        
        // DFS from each cell
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (root->children[board[i][j] - 'a'] != nullptr) {
                    dfs(board, i, j, root);
                }
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        
        // Check if out of bounds or already visited
        if (c == '#') return;
        
        int idx = c - 'a';
        if (node->children[idx] == nullptr) return;
        
        node = node->children[idx];
        
        // Found a word
        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }
        
        // Mark as visited
        board[i][j] = '#';
        
        // Explore 4 directions
        int m = board.size();
        int n = board[0].size();
        
        if (i > 0) dfs(board, i - 1, j, node);
        if (i < m - 1) dfs(board, i + 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (j < n - 1) dfs(board, i, j + 1, node);
        
        // Backtrack: unmark
        board[i][j] = c;
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    
    vector<string> words = {"oath", "pea", "eat", "rain"};
    
    cout << "Board:" << endl;
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
    
    cout << "\nWords to find: ";
    for (string& word : words) cout << word << " ";
    cout << endl;
    
    vector<string> found = sol.findWords(board, words);
    
    cout << "\nFound words: ";
    for (string& word : found) cout << word << " ";
    cout << endl;
    
    return 0;
}

/*
INPUT:
board = [['o','a','a','n'],
         ['e','t','a','e'],
         ['i','h','k','r'],
         ['i','f','l','v']]
words = ["oath","pea","eat","rain"]

OUTPUT:
["oath","eat"]

EXPLANATION:
"oath": o(0,0)→a(0,1)→t(1,1)→h(2,1) ✓
"pea": p not found ✗
"eat": e(1,0)→a(1,1)→t(1,1) ✗ (can't reuse same cell)
       e(1,0)→a(0,1)→t(1,1) ✓
"rain": r(2,3)→a(1,2)→i(2,1) partial, need 'n' adjacent ✗

Trie structure:
root
├─ o → a → t → h [word: "oath"]
├─ p → e → a [word: "pea"]
├─ e → a → t [word: "eat"]
└─ r → a → i → n [word: "rain"]

Why Trie?
- Without Trie: O(W * M * N * 4^L) - check each word separately
- With Trie: O(M * N * 4^L) - share common prefixes

For large word lists, Trie reduces redundant DFS explorations.

Another example:
INPUT:
board = [['a','b'],['c','d']]
words = ["abcb"]
OUTPUT: []
"abcb" requires revisiting 'b', which is not allowed.
*/
