/*
PROBLEM: Divisor Game
Difficulty: Easy
Pattern: Game Theory DP

DESCRIPTION:
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
- Choose any x with 0 < x < n and n % x == 0.
- Replace the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.
Return true if and only if Alice wins the game, assuming both players play optimally.

INPUT:
n = 3

OUTPUT:
false
Explanation: Alice chooses 1, n becomes 2. Bob chooses 1, n becomes 1. Alice has no moves, Bob wins.

TIME COMPLEXITY: O(n^2) for DP approach, O(1) for optimal
SPACE COMPLEXITY: O(n) for DP approach, O(1) for optimal
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: Mathematical observation (Optimal)
    bool divisorGame(int n) {
        // Alice wins if and only if n is even
        // Proof: 
        // - If n is even, Alice can always choose x=1, making n odd for Bob
        // - If n is odd, all divisors are odd, so n-x is even for Bob
        // - This pattern continues until someone gets n=1 and loses
        return n % 2 == 0;
    }
    
    // Method 2: DP approach (for understanding the game theory)
    bool divisorGameDP(int n) {
        vector<bool> dp(n + 1, false);
        dp[0] = false; // No number, current player loses
        dp[1] = false; // Can't make a move, current player loses
        
        for (int i = 2; i <= n; i++) {
            // Try all possible moves
            for (int x = 1; x < i; x++) {
                if (i % x == 0) {
                    // If opponent loses after this move, current player wins
                    if (!dp[i - x]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 2;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << (sol.divisorGame(n1) ? "true" : "false") << endl;
    cout << "Output (DP): " << (sol.divisorGameDP(n1) ? "true" : "false") << endl << endl;
    
    // Test Case 2
    int n2 = 3;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << (sol.divisorGame(n2) ? "true" : "false") << endl;
    cout << "Output (DP): " << (sol.divisorGameDP(n2) ? "true" : "false") << endl << endl;
    
    // Test Case 3
    int n3 = 10;
    cout << "Input: n = " << n3 << endl;
    cout << "Output: " << (sol.divisorGame(n3) ? "true" : "false") << endl;
    cout << "Output (DP): " << (sol.divisorGameDP(n3) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:
Mathematical Approach:
1. Alice wins if n is even, loses if n is odd
2. Reasoning:
   - Even number: Alice picks 1, Bob gets odd number
   - Odd number: All divisors are odd, so Bob gets even number
   - Pattern continues until someone gets 1 (and loses)

DP Approach:
1. dp[i] = true if current player wins with number i
2. For each number, try all valid moves (divisors)
3. If any move leads to opponent's losing position, current player wins
4. Base case: dp[1] = false (no valid move)

KEY LEARNING:
- Game theory with DP
- Sometimes pattern recognition is faster than DP
- dp[i] depends on results of smaller subproblems
- Optimal play assumption in game theory problems
*/
