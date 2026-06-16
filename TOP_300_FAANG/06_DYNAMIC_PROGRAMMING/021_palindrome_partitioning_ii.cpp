/*
================================================================================
PROBLEM: Palindrome Partitioning II (LeetCode #132)
DIFFICULTY: Hard
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        
        // Build palindrome table
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    if (len == 2) {
                        isPalin[i][j] = true;
                    } else {
                        isPalin[i][j] = isPalin[i+1][j-1];
                    }
                }
            }
        }
        
        // DP for minimum cuts
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = INT_MAX;
                
                for (int j = 0; j < i; j++) {
                    if (isPalin[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    cout << "Min cuts for 'aab': " << sol.minCut("aab") << endl;
    cout << "Min cuts for 'ababbbabbababa': " << sol.minCut("ababbbabbababa") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Palindrome Partitioning (LeetCode #131)
2. Palindrome Partitioning III (LeetCode #1278)
3. Palindrome Partitioning IV (LeetCode #1745)
4. Longest Palindromic Substring (LeetCode #5)
5. Longest Palindromic Subsequence (LeetCode #516)
6. Count Different Palindromic Subsequences (LeetCode #730)
7. Palindromic Substrings (LeetCode #647)
8. Valid Palindrome II (LeetCode #680)
9. Split Array Largest Sum (LeetCode #410)
10. Minimum Cost to Cut a Stick (LeetCode #1547)
*/
