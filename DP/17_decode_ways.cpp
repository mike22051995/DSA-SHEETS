/*
PROBLEM: Decode Ways
Difficulty: Medium
Pattern: 1D DP, String Decoding

DESCRIPTION:
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1", 'B' -> "2", ..., 'Z' -> "26"
Given a string s containing only digits, return the number of ways to decode it.

INPUT:
s = "226"

OUTPUT:
3
Explanation: "226" could be decoded as:
- "BZ" (2 26)
- "VF" (22 6)
- "BBF" (2 2 6)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n), can be optimized to O(1)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: DP with array
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        
        // dp[i] = number of ways to decode s[0...i-1]
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string has 1 way
        dp[1] = 1; // First character (if not '0')
        
        for (int i = 2; i <= n; i++) {
            // Single digit decode
            int oneDigit = stoi(s.substr(i-1, 1));
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i-1];
            }
            
            // Two digit decode
            int twoDigits = stoi(s.substr(i-2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
    
    // Method 2: Space Optimized
    int numDecodingsOptimized(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        
        int prev2 = 1; // dp[i-2]
        int prev1 = 1; // dp[i-1]
        
        for (int i = 2; i <= n; i++) {
            int curr = 0;
            
            // Single digit
            int oneDigit = s[i-1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                curr += prev1;
            }
            
            // Two digits
            int twoDigits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26) {
                curr += prev2;
            }
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "226";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.numDecodings(s1) << endl;
    cout << "Output (Optimized): " << sol.numDecodingsOptimized(s1) << endl << endl;
    
    // Test Case 2
    string s2 = "12";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.numDecodings(s2) << endl;
    cout << "Output (Optimized): " << sol.numDecodingsOptimized(s2) << endl << endl;
    
    // Test Case 3
    string s3 = "06";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.numDecodings(s3) << endl;
    cout << "Output (Optimized): " << sol.numDecodingsOptimized(s3) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. dp[i] = number of ways to decode first i characters
2. At position i, we can:
   - Decode single digit s[i-1] if it's 1-9
   - Decode two digits s[i-2:i-1] if they form 10-26
3. Recurrence:
   - If single digit valid: dp[i] += dp[i-1]
   - If two digits valid: dp[i] += dp[i-2]
4. Handle edge cases: leading zeros, invalid codes

Example: s = "226"
- dp[0] = 1 (empty)
- dp[1] = 1 ("2")
- dp[2] = 2 ("22" can be "2,2" or "22")
- dp[3] = 3 ("226" can be "2,2,6" or "22,6" or "2,26")

KEY LEARNING:
- Similar to climbing stairs but with conditions
- Need to check validity of 1-digit and 2-digit decodings
- Watch for '0' - can only appear as part of "10" or "20"
- Pattern used in: Fibonacci-like problems with constraints
*/
