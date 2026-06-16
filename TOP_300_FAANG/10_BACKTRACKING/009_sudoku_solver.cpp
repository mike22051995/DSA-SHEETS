/*
================================================================================
PROBLEM: Sudoku Solver (LeetCode #37)
DIFFICULTY: Hard
PATTERN: Backtracking with Constraints
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return backtrack(board, row + 1, 0);
        if (board[row][col] != '.') return backtrack(board, row, col + 1);
        
        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                
                if (backtrack(board, row, col + 1)) {
                    return true;
                }
                
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c || board[i][col] == c) {
                return false;
            }
        }
        
        // Check 3x3 box
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == c) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    sol.solveSudoku(board);
    
    cout << "Solved Sudoku:" << endl;
    for (auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Sudoku (LeetCode #36)
2. N-Queens (LeetCode #51)
3. N-Queens II (LeetCode #52)
4. Word Search (LeetCode #79)
5. Word Search II (LeetCode #212)
6. Unique Paths III (LeetCode #980)
7. Rat in a Maze (Classic Problem)
8. Cryptarithmetic Puzzles
9. Crossword Puzzle Solver
10. Nonogram Solver
*/
