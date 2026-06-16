/*
================================================================================
PROBLEM: N-Queens (LeetCode #51)
DIFFICULTY: Hard
PATTERN: Backtracking
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
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
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false);
        vector<bool> diag2(2 * n, false);
        
        backtrack(board, 0, cols, diag1, diag2, result);
        return result;
    }
    
    void backtrack(vector<string>& board, int row, 
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& result) {
        int n = board.size();
        
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n;
            int d2 = row + col;
            
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            
            backtrack(board, row + 1, cols, diag1, diag2, result);
            
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};

int main() {
    Solution sol;
    auto result = sol.solveNQueens(4);
    
    cout << "N-Queens solutions for n=4:" << endl;
    for (auto& solution : result) {
        for (string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. N-Queens II (LeetCode #52) - Count solutions
2. Sudoku Solver (LeetCode #37)
3. Valid Sudoku (LeetCode #36)
4. Permutations (LeetCode #46)
5. Combinations (LeetCode #77)
6. Combination Sum (LeetCode #39)
7. Palindrome Partitioning (LeetCode #131)
8. Word Search (LeetCode #79)
9. Beautiful Arrangement (LeetCode #526)
10. Maximum Compatibility Score Sum (LeetCode #1947)
*/
