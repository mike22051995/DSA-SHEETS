/*
PROBLEM: Word Search
---------------------------------------------------------------------------
Given an m x n grid of characters board and a string word, return true if 
word exists in the grid. The word can be constructed from letters of 
sequentially adjacent cells (horizontally or vertically). The same cell 
may not be used more than once.

DIFFICULTY: Medium
PATTERN: Backtracking (2D Grid DFS)
TIME COMPLEXITY: O(m * n * 4^L) where L is word length
SPACE COMPLEXITY: O(L) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base case: found the word
        if (index >= word.length()) {
            return true;
        }
        
        // Check boundaries and character match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }
        
        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||  // down
                     dfs(board, word, i - 1, j, index + 1) ||  // up
                     dfs(board, word, i, j + 1, index + 1) ||  // right
                     dfs(board, word, i, j - 1, index + 1);    // left
        
        // Backtrack: restore cell
        board[i][j] = temp;
        
        return found;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<char>> board1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word1 = "ABCCED";
    cout << "Test 1: Word '" << word1 << "' exists? " 
         << (sol.exist(board1, word1) ? "true" : "false") << endl;
    
    // Test case 2
    vector<vector<char>> board2 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word2 = "SEE";
    cout << "Test 2: Word '" << word2 << "' exists? " 
         << (sol.exist(board2, word2) ? "true" : "false") << endl;
    
    return 0;
}
