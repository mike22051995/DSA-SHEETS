/*
    Distinct Subsequences - LeetCode #115
    
    Given two strings s and t, return the number of distinct subsequences of s which equals t.
    
    Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    There are 3 ways you can generate "rabbit" from s.
    rabb(b)it
    ra(b)bbit
    rab(b)bit
    
    Example 2:
    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation:
    There are 5 distinct subsequences of "bag" in "babgbag":
    (b)a(b)g(bag)
    (b)a(bgba)g
    (ba)b(g)bag
    ba(b)g(bag)
    babg(bag)
    
    Constraints:
    - 1 <= s.length, t.length <= 1000
    - s and t consist of English letters
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Use long long to prevent overflow
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Empty string is a subsequence of any string
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters don't match, we can only use dp[i-1][j]
                dp[i][j] = dp[i - 1][j];
                
                // If characters match, add dp[i-1][j-1]
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized version
    int numDistinctOptimized(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.numDistinct("rabbbit", "rabbit") << endl;  // 3
    cout << "Test 2: " << sol.numDistinct("babgbag", "bag") << endl;     // 5
    cout << "Test 3: " << sol.numDistinct("", "a") << endl;              // 0
    
    return 0;
}
