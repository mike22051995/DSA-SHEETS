/*
PROBLEM: Stone Game (LeetCode 877)
DIFFICULTY: Medium
PATTERN: Game Theory DP / Min-Max

DESCRIPTION:
Alice and Bob play a game with piles of stones. There are an even number of piles
arranged in a row, and each pile has a positive integer number of stones.
The objective is to end with the most stones.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes 
the entire pile of stones from either the beginning or end of the row.
This continues until there are no more piles left.

Assuming Alice and Bob play optimally, return true if Alice wins.

EXAMPLE:
Input: piles = [5,3,4,5]
Output: true
Explanation:
Alice: 5, Bob: 5, Alice: 4, Bob: 3
Alice: 5+4=9, Bob: 5+3=8, Alice wins

Input: piles = [3,7,2,3]
Output: true

Input: piles = [1,2,3,4,5]
Output: true (Alice always wins with even piles)

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²)
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Game Theory DP
    // dp[i][j] = max stones current player can get from piles[i..j]
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single pile
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        // Fill by increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                // Take left pile
                int takeLeft = piles[i] + min(dp[i+2][j], dp[i+1][j-1]);
                
                // Take right pile
                int takeRight = piles[j] + min(dp[i+1][j-1], dp[i][j-2]);
                
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        
        int total = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = dp[0][n-1];
        
        return aliceScore > total - aliceScore;
    }
    
    // Approach 2: Difference DP (More elegant!)
    // dp[i][j] = max score difference (current - opponent) for piles[i..j]
    bool stoneGameDiff(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single pile
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        // Fill by increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                // Take left: gain piles[i], opponent gets dp[i+1][j]
                int takeLeft = piles[i] - dp[i+1][j];
                
                // Take right: gain piles[j], opponent gets dp[i][j-1]
                int takeRight = piles[j] - dp[i][j-1];
                
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        
        return dp[0][n-1] > 0;
    }
    
    // Approach 3: Math trick (specific to this problem!)
    bool stoneGameMath(vector<int>& piles) {
        // Alice always wins when even number of piles!
        // She can always take all even-indexed or all odd-indexed piles
        return true;
    }
    
    // Approach 4: Recursion with Memoization
    int stoneGameHelper(vector<int>& piles, int i, int j, 
                       vector<vector<int>>& dp) {
        if (i == j) return piles[i];
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // Take left
        int scoreAfterLeft = (i+1 <= j) ? stoneGameHelper(piles, i+1, j, dp) : 0;
        int takeLeft = piles[i] + min(
            (i+2 <= j) ? stoneGameHelper(piles, i+2, j, dp) : 0,
            (i+1 <= j-1) ? stoneGameHelper(piles, i+1, j-1, dp) : 0
        );
        
        // Take right
        int takeRight = piles[j] + min(
            (i+1 <= j-1) ? stoneGameHelper(piles, i+1, j-1, dp) : 0,
            (i <= j-2) ? stoneGameHelper(piles, i, j-2, dp) : 0
        );
        
        return dp[i][j] = max(takeLeft, takeRight);
    }
    
    bool stoneGameMemo(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int total = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = stoneGameHelper(piles, 0, n-1, dp);
        return aliceScore > total - aliceScore;
    }
    
    // Get actual moves
    vector<int> getOptimalMoves(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                int takeLeft = piles[i] - dp[i+1][j];
                int takeRight = piles[j] - dp[i][j-1];
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        
        // Backtrack to get moves
        vector<int> moves;
        int i = 0, j = n-1;
        bool aliceTurn = true;
        
        while (i <= j) {
            if (i == j) {
                moves.push_back(piles[i]);
                break;
            }
            
            int takeLeft = piles[i] - (i+1 <= j ? dp[i+1][j] : 0);
            int takeRight = piles[j] - (i <= j-1 ? dp[i][j-1] : 0);
            
            if (takeLeft >= takeRight) {
                moves.push_back(piles[i]);
                i++;
            } else {
                moves.push_back(piles[j]);
                j--;
            }
        }
        
        return moves;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> piles1 = {5, 3, 4, 5};
    cout << "Piles: ";
    for (int p : piles1) cout << p << " ";
    cout << endl;
    cout << "Alice wins (DP): " << (sol.stoneGame(piles1) ? "true" : "false") << endl;
    cout << "Alice wins (Diff): " << (sol.stoneGameDiff(piles1) ? "true" : "false") << endl;
    cout << "Alice wins (Math): " << (sol.stoneGameMath(piles1) ? "true" : "false") << endl;
    
    vector<int> moves1 = sol.getOptimalMoves(piles1);
    cout << "Optimal moves: ";
    for (int m : moves1) cout << m << " ";
    cout << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> piles2 = {3, 7, 2, 3};
    cout << "Piles: ";
    for (int p : piles2) cout << p << " ";
    cout << endl;
    cout << "Alice wins: " << (sol.stoneGame(piles2) ? "true" : "false") << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> piles3 = {1, 2, 3, 4, 5, 6};
    cout << "Piles: ";
    for (int p : piles3) cout << p << " ";
    cout << endl;
    cout << "Alice wins: " << (sol.stoneGame(piles3) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:

STONE GAME - Game Theory DP

PROBLEM TYPE:
Two players, alternating turns, optimal play.
This is a MIN-MAX problem!

APPROACH 1: Maximum Score DP
dp[i][j] = maximum stones current player can get from piles[i..j]

When player picks left (piles[i]):
- Gets piles[i]
- Opponent plays optimally on [i+1, j]
- Opponent will choose best, leaving us with worse option
- We get: piles[i] + min(dp[i+2][j], dp[i+1][j-1])

Why min? Opponent plays optimally, chooses what's best for them!

APPROACH 2: Difference DP (Cleaner!)
dp[i][j] = max score difference (me - opponent) for piles[i..j]

Take left:
  diff = piles[i] - dp[i+1][j]
  (I gain piles[i], opponent's advantage becomes my disadvantage)

Take right:
  diff = piles[j] - dp[i][j-1]

dp[i][j] = max(takeLeft, takeRight)

EXAMPLE TRACE:
piles = [5, 3, 4, 5]

Base case: dp[i][i] = piles[i]
dp[0][0]=5, dp[1][1]=3, dp[2][2]=4, dp[3][3]=5

Length 2:
dp[0][1]: max(5-dp[1][1], 3-dp[0][0]) = max(5-3, 3-5) = max(2, -2) = 2
dp[1][2]: max(3-4, 4-3) = max(-1, 1) = 1
dp[2][3]: max(4-5, 5-4) = max(-1, 1) = 1

Length 3:
dp[0][2]: max(5-dp[1][2], 4-dp[0][1]) = max(5-1, 4-2) = max(4, 2) = 4
dp[1][3]: max(3-dp[2][3], 5-dp[1][2]) = max(3-1, 5-1) = max(2, 4) = 4

Length 4:
dp[0][3]: max(5-dp[1][3], 5-dp[0][2]) = max(5-4, 5-4) = max(1, 1) = 1

Since dp[0][3] > 0, Alice wins!

MATHEMATICAL TRICK (This Problem Only!):
With even number of piles, Alice can force a win!

Strategy:
- Color piles alternately: odd positions vs even positions
- Before game, check sum of odd vs sum of even
- Alice chooses strategy to always get the larger sum!

Example: [5,3,4,5]
Odd positions (0,2): 5+4=9
Even positions (1,3): 3+5=8
Alice can always take from odd positions!

This is why stoneGameMath() returns true!

PATTERN RECOGNITION:
- Two players, optimal play → Game theory DP
- MIN-MAX problem → Opponent chooses worst for us
- Interval DP → Fill by increasing length

SIMILAR PROBLEMS:
- Predict the Winner (LeetCode 486)
- Stone Game II (LeetCode 1140)
- Stone Game III (LeetCode 1406)
- Optimal Strategy for a Game

INTERVIEW TIP:
"This is game theory DP. I'll use difference DP where 
dp[i][j] = max advantage I can get. At each step, opponent 
plays optimally, so my advantage becomes their disadvantage."

COMPLEXITY:
Time: O(n²) - n² states
Space: O(n²) - DP table

OUTPUT:
Test Case 1:
Piles: 5 3 4 5
Alice wins (DP): true
Alice wins (Diff): true
Alice wins (Math): true
Optimal moves: 5 5 4 3

Test Case 2:
Piles: 3 7 2 3
Alice wins: true

Test Case 3:
Piles: 1 2 3 4 5 6
Alice wins: true
*/
