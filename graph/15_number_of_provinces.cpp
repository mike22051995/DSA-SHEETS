/*
PROBLEM: Number of Provinces (LeetCode 547)
Difficulty: Medium
Pattern: Connected Components using DFS/Union-Find

DESCRIPTION:
Given an n x n matrix isConnected where isConnected[i][j] = 1 if cities i and j are
directly connected, and 0 otherwise. Return the total number of provinces.
A province is a group of directly or indirectly connected cities.

GRAPH DIAGRAM:
  Matrix:              Graph:
  [1 1 0]              0---1    2
  [1 1 0]        -->   
  [0 0 1]              Province 1: {0, 1}
                       Province 2: {2}
  
  Cities 0 and 1 are connected (directly)
  City 2 is isolated (separate province)
  Number of Provinces: 2

APPROACH:
1. Use DFS to find connected components
2. For each unvisited city, start DFS and mark all connected cities
3. Count represents number of provinces

TIME COMPLEXITY: O(N^2) where N = number of cities
SPACE COMPLEXITY: O(N) for visited array and recursion stack
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        
        // Visit all connected cities
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        
        return provinces;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of provinces: " << sol.findCircleNum(isConnected1) << endl;
    
    // Example 2
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of provinces: " << sol.findCircleNum(isConnected2) << endl;
    
    return 0;
}

/*
INPUT 1:
isConnected = [[1,1,0],
               [1,1,0],
               [0,0,1]]

OUTPUT:
Number of provinces: 2

EXPLANATION:
Cities 0 and 1 are connected (province 1)
City 2 is alone (province 2)

INPUT 2:
isConnected = [[1,0,0],
               [0,1,0],
               [0,0,1]]

OUTPUT:
Number of provinces: 3

EXPLANATION:
Each city is its own province (no connections between cities)
*/
