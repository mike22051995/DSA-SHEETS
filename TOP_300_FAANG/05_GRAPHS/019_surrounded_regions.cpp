/*
================================================================================
PROBLEM: Surrounded Regions (LeetCode #130)
DIFFICULTY: Medium
PATTERN: DFS / BFS / Union Find
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // DFS approach
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        // Mark boundary O's and connected O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        
        // Flip all remaining O's to X's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        
        board[i][j] = '#';
        
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    
    cout << "Original board:" << endl;
    for (auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    
    sol.solve(board);
    
    cout << "\nAfter solving:" << endl;
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
1. Number of Islands (LeetCode #200)
2. Pacific Atlantic Water Flow (LeetCode #417)
3. Number of Closed Islands (LeetCode #1254)
4. Number of Enclaves (LeetCode #1020)
5. Walls and Gates (LeetCode #286)
6. Is Graph Bipartite (LeetCode #785)
7. Max Area of Island (LeetCode #695)
8. Flood Fill (LeetCode #733)
9. Coloring A Border (LeetCode #1034)
10. Number of Distinct Islands (LeetCode #694)
*/
