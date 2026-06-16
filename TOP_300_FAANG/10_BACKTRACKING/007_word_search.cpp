/*
================================================================================
PROBLEM: Word Search (LeetCode #79)
DIFFICULTY: Medium
PATTERN: Backtracking / DFS
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#'; // Mark visited
        
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        board[i][j] = temp; // Restore
        
        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    cout << "Exists (ABCCED): " << (sol.exist(board, "ABCCED") ? "true" : "false") << endl;
    cout << "Exists (SEE): " << (sol.exist(board, "SEE") ? "true" : "false") << endl;
    cout << "Exists (ABCB): " << (sol.exist(board, "ABCB") ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Word Search II (LeetCode #212)
2. Number of Islands (LeetCode #200)
3. Surrounded Regions (LeetCode #130)
4. Pacific Atlantic Water Flow (LeetCode #417)
5. Unique Paths III (LeetCode #980)
6. Robot Room Cleaner (LeetCode #489)
7. Matchsticks to Square (LeetCode #473)
8. N-Queens (LeetCode #51)
9. Sudoku Solver (LeetCode #37)
10. Android Unlock Patterns (LeetCode #351)
*/
