/*
PROBLEM: Sudoku Solver
---------------------------------------------------------------------------
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row
2. Each of the digits 1-9 must occur exactly once in each column
3. Each of the digits 1-9 must occur exactly once in each 3x3 sub-box

DIFFICULTY: Hard
PATTERN: Backtracking (Constraint Satisfaction)
TIME COMPLEXITY: O(9^(n*n)) worst case
SPACE COMPLEXITY: O(n*n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]]
Output: Solved board with all cells filled

Example 2:
Input: Any valid partially filled 9x9 board
Output: Complete valid solution
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        // Find empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    // Try digits 1-9
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(board, row, col, digit)) {
                            board[row][col] = digit;        // choose
                            
                            if (solve(board)) {              // explore
                                return true;
                            }
                            
                            board[row][col] = '.';          // unchoose
                        }
                    }
                    return false; // No valid digit found
                }
            }
        }
        return true; // All cells filled
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit) return false;
        }
        
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit) return false;
        }
        
        // Check 3x3 box
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == digit) return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
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
    
    cout << "Test 1: Solving Sudoku..." << endl;
    sol.solveSudoku(board);
    cout << "Solved!" << endl;
    
    return 0;
}
