/*
    Decode Ways - LeetCode #91
    
    A message containing letters from A-Z can be encoded into numbers using the following mapping:
    'A' -> "1", 'B' -> "2", ..., 'Z' -> "26"
    
    To decode an encoded message, all the digits must be grouped then mapped back into letters
    using the reverse of the mapping above. Given a string s containing only digits,
    return the number of ways to decode it.
    
    Example 1:
    Input: s = "12"
    Output: 2
    Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
    
    Example 2:
    Input: s = "226"
    Output: 3
    Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
    
    Example 3:
    Input: s = "06"
    Output: 0
    Explanation: "06" cannot be mapped to "F" because of the leading zero.
    
    Constraints:
    - 1 <= s.length <= 100
    - s contains only digits and may contain leading zero(s)
    
    Time Complexity: O(n)
    Space Complexity: O(n) or O(1) if optimized
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Dynamic Programming (Bottom-up)
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Empty string
        dp[1] = 1;  // First character (already checked not '0')
        
        for (int i = 2; i <= n; i++) {
            // One digit decode
            int oneDigit = s[i - 1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            
            // Two digit decode
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
    
    // Approach 2: Space Optimized DP
    int numDecodingsOptimized(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        int prev2 = 1;  // dp[i-2]
        int prev1 = 1;  // dp[i-1]
        
        for (int i = 2; i <= n; i++) {
            int current = 0;
            
            // One digit decode
            int oneDigit = s[i - 1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                current += prev1;
            }
            
            // Two digit decode
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.numDecodings("12") << endl;      // 2
    cout << "Test 2: " << sol.numDecodings("226") << endl;     // 3
    cout << "Test 3: " << sol.numDecodings("06") << endl;      // 0
    cout << "Test 4: " << sol.numDecodings("10") << endl;      // 1
    cout << "Test 5: " << sol.numDecodings("2101") << endl;    // 1
    
    return 0;
}
