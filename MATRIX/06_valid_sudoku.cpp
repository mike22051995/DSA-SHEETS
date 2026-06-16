/*
PROBLEM: Valid Sudoku (LeetCode 36)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Hash Set Validation

DESCRIPTION:
Determine if a 9x9 Sudoku board is valid. Only filled cells need to be validated:
1. Each row must contain digits 1-9 without repetition
2. Each column must contain digits 1-9 without repetition
3. Each 3x3 sub-box must contain digits 1-9 without repetition

SUDOKU DIAGRAM:
  Valid Board:              Sub-boxes (0-8):
  5 3 . | . 7 . | . . .     0 1 2
  6 . . | 1 9 5 | . . .     3 4 5
  . 9 8 | . . . | . 6 .     6 7 8
  ------+-------+------
  8 . . | . 6 . | . . 3     Box index = (row/3)*3 + (col/3)
  4 . . | 8 . 3 | . . 1     Example: (5,7) → box = (5/3)*3 + (7/3) = 1*3+2 = 5
  7 . . | . 2 . | . . 6
  ------+-------+------
  . 6 . | . . . | 2 8 .
  . . . | 4 1 9 | . . 5
  . . . | . 8 . | . 7 9

APPROACH:
Use hash sets to track seen numbers:
1. Create sets for each row (9 sets)
2. Create sets for each column (9 sets)
3. Create sets for each 3x3 box (9 sets)
4. For each filled cell, check if number already exists
5. If duplicate found, return false

TIME COMPLEXITY: O(1) - constant 9x9 board
SPACE COMPLEXITY: O(1) - constant space for sets
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                
                if (num == '.') continue;
                
                // Calculate box index
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                // Check row
                if (rows[i].count(num)) return false;
                rows[i].insert(num);
                
                // Check column
                if (cols[j].count(num)) return false;
                cols[j].insert(num);
                
                // Check box
                if (boxes[boxIndex].count(num)) return false;
                boxes[boxIndex].insert(num);
            }
        }
        
        return true;
    }
    
    // Alternative: Using bit manipulation for space optimization
    bool isValidSudokuBit(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> boxes(9, 0);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '0';
                int bit = 1 << num;
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[boxIndex] & bit)) {
                    return false;
                }
                
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[boxIndex] |= bit;
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
    
    cout << "Is valid Sudoku: " << (sol.isValidSudoku(board) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT:
board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

OUTPUT:
true

EXPLANATION:
Each row, column, and 3x3 box contains unique digits (no duplicates).

Invalid Example:
board[0][0] = '8', board[3][0] = '8' (same column) → Invalid
*/
