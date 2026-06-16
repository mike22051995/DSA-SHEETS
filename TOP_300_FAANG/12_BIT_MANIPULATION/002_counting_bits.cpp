/*
================================================================================
PROBLEM: Counting Bits (LeetCode #338)
DIFFICULTY: Easy
PATTERN: Bit Manipulation / Dynamic Programming
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DP with i & (i-1)
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
    
    // DP with i >> 1
    vector<int> countBits2(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

int main() {
    Solution sol;
    auto result = sol.countBits(5);
    cout << "Count bits for 0-5: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of 1 Bits (LeetCode #191)
2. Hamming Distance (LeetCode #461)
3. Binary Watch (LeetCode #401)
4. Power of Two (LeetCode #231)
5. Power of Four (LeetCode #342)
6. Reverse Bits (LeetCode #190)
7. Single Number (LeetCode #136)
8. Find the Difference (LeetCode #389)
9. UTF-8 Validation (LeetCode #393)
10. Integer Replacement (LeetCode #397)
*/
