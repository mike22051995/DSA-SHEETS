/*
PROBLEM: Edit Distance (Levenshtein Distance)
Difficulty: Medium
Pattern: 2D DP, String Transformation

DESCRIPTION:
Given two strings word1 and word2, return the minimum number of operations required to convert 
word1 to word2.
You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character

INPUT:
word1 = "horse", word2 = "ros"

OUTPUT:
3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

TIME COMPLEXITY: O(m * n) where m, n are lengths of strings
SPACE COMPLEXITY: O(m * n), can be optimized to O(min(m, n))
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
        
        // dp[i][j] = min operations to convert word1[0...i-1] to word2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // Delete all characters from word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // Insert all characters from word2
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // Characters match, no operation needed
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Take minimum of three operations
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // Delete from word1
                        dp[i][j-1],     // Insert to word1
                        dp[i-1][j-1]    // Replace in word1
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string word1_1 = "horse", word2_1 = "ros";
    cout << "Input: word1 = \"" << word1_1 << "\", word2 = \"" << word2_1 << "\"" << endl;
    cout << "Output: " << sol.minDistance(word1_1, word2_1) << endl << endl;
    
    // Test Case 2
    string word1_2 = "intention", word2_2 = "execution";
    cout << "Input: word1 = \"" << word1_2 << "\", word2 = \"" << word2_2 << "\"" << endl;
    cout << "Output: " << sol.minDistance(word1_2, word2_2) << endl << endl;
    
    // Test Case 3
    string word1_3 = "abc", word2_3 = "abc";
    cout << "Input: word1 = \"" << word1_3 << "\", word2 = \"" << word2_3 << "\"" << endl;
    cout << "Output: " << sol.minDistance(word1_3, word2_3) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. dp[i][j] = minimum operations to convert word1[0..i-1] to word2[0..j-1]
2. Base cases:
   - dp[i][0] = i (delete all i characters)
   - dp[0][j] = j (insert all j characters)
3. If characters match: dp[i][j] = dp[i-1][j-1]
4. If don't match, take minimum of:
   - dp[i-1][j] + 1 (delete from word1)
   - dp[i][j-1] + 1 (insert to word1)
   - dp[i-1][j-1] + 1 (replace)

Example: word1 = "horse", word2 = "ros"
      ""  r  o  s
  ""   0  1  2  3
  h    1  1  2  3
  o    2  2  1  2
  r    3  2  2  2
  s    4  3  3  2
  e    5  4  4  3

KEY LEARNING:
- Classic string transformation problem
- Similar to LCS but with cost for operations
- Three choices at each step (insert, delete, replace)
- Used in spell checkers, DNA analysis, plagiarism detection
- Can be extended to have different costs for operations
*/
