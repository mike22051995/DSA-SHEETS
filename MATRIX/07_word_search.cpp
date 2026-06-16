/*
PROBLEM: Word Search (LeetCode 79)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon, Netflix
Pattern: Backtracking on Matrix

DESCRIPTION:
Given an m x n grid of characters and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells (horizontally or vertically).
The same cell cannot be used more than once.

MATRIX DIAGRAM:
  Board:              Search for "ABCCED"
  A  B  C  E          A → B → C → C → E → D ✓
  S  F  C  S          ↓   ↓       ↑   ↑   ↑
  A  D  E  E          Path marked with arrows
  
  Backtracking Process:
  1. Start at 'A' (0,0)
  2. Try all 4 directions (up, down, left, right)
  3. Mark visited cells temporarily
  4. Backtrack if path doesn't match
  5. Unmark when backtracking

APPROACH:
1. For each cell, start DFS if it matches first character
2. Use backtracking to explore all possible paths
3. Mark current cell as visited (modify it or use visited set)
4. Try all 4 directions recursively
5. If word found, return true; otherwise backtrack

TIME COMPLEXITY: O(M * N * 4^L) where L = word length
SPACE COMPLEXITY: O(L) for recursion stack
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        // Base case: found the word
        if (index == word.length()) {
            return true;
        }
        
        // Check boundaries and character match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Try all 4 directions
        bool found = dfs(board, word, index + 1, i + 1, j) ||  // down
                     dfs(board, word, index + 1, i - 1, j) ||  // up
                     dfs(board, word, index + 1, i, j + 1) ||  // right
                     dfs(board, word, index + 1, i, j - 1);    // left
        
        // Backtrack: unmark
        board[i][j] = temp;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    string word1 = "ABCCED";
    cout << "Search for \"" << word1 << "\": " 
         << (sol.exist(board, word1) ? "Found" : "Not Found") << endl;
    
    string word2 = "SEE";
    cout << "Search for \"" << word2 << "\": " 
         << (sol.exist(board, word2) ? "Found" : "Not Found") << endl;
    
    string word3 = "ABCB";
    cout << "Search for \"" << word3 << "\": " 
         << (sol.exist(board, word3) ? "Found" : "Not Found") << endl;
    
    return 0;
}

/*
INPUT:
board = [["A","B","C","E"],
         ["S","F","C","S"],
         ["A","D","E","E"]]
word = "ABCCED"

OUTPUT:
true

EXPLANATION:
Path: A(0,0) → B(0,1) → C(0,2) → C(1,2) → E(2,2) → D(2,1)

For word = "SEE":
OUTPUT: true
Path: S(0,1) → E(0,2) → E(1,2) or S(1,3) → E(2,3) → E(2,2)

For word = "ABCB":
OUTPUT: false
Cannot use the same cell twice
*/
