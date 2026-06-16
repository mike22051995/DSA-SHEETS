/*
    Edit Distance - LeetCode #72
    
    Given two strings word1 and word2, return the minimum number of operations required
    to convert word1 to word2.
    
    You have the following three operations permitted on a word:
    - Insert a character
    - Delete a character
    - Replace a character
    
    Example 1:
    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
    
    Example 2:
    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;  // Delete all characters from word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;  // Insert all characters to word1
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],      // Delete
                        dp[i][j - 1],      // Insert
                        dp[i - 1][j - 1]   // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.minDistance("horse", "ros") << endl;           // 3
    cout << "Test 2: " << sol.minDistance("intention", "execution") << endl; // 5
    cout << "Test 3: " << sol.minDistance("", "abc") << endl;                // 3
    cout << "Test 4: " << sol.minDistance("abc", "abc") << endl;             // 0
    
    return 0;
}
