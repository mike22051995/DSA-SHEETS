/*
PROBLEM: N-Queens
---------------------------------------------------------------------------
The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other. Given an integer n, return all 
distinct solutions to the n-queens puzzle.

DIFFICULTY: Hard
PATTERN: Backtracking (Constraint Satisfaction)
TIME COMPLEXITY: O(n!)
SPACE COMPLEXITY: O(n²) - board + recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Example 2:
Input: n = 1
Output: [["Q"]]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<string>& board, int row, vector<vector<string>>& result) {
        // Base case: placed all queens
        if (row >= board.size()) {
            result.push_back(board);
            return;
        }
        
        // Try placing queen in each column
        for (int col = 0; col < board.size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';              // choose
                backtrack(board, row + 1, result);   // explore
                board[row][col] = '.';              // unchoose
            }
        }
    }
    
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 4;
    vector<vector<string>> result1 = sol.solveNQueens(n1);
    cout << "Test 1: Total solutions for " << n1 << "-Queens = " << result1.size() << endl;
    
    // Test case 2
    int n2 = 1;
    vector<vector<string>> result2 = sol.solveNQueens(n2);
    cout << "Test 2: Total solutions for " << n2 << "-Queens = " << result2.size() << endl;
    
    return 0;
}
