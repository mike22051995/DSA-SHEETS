"""
PROBLEM: Divisor Game
Difficulty: Easy
Pattern: Game Theory DP

DESCRIPTION:
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
- Choose any x with 0 < x < n and n % x == 0.
- Replace the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.

INPUT:
n = 3

OUTPUT:
False
Explanation: Alice chooses 1, n becomes 2. Bob chooses 1, n becomes 1. Alice has no moves, Bob wins.

TIME COMPLEXITY: O(n^2) for DP approach, O(1) for optimal
SPACE COMPLEXITY: O(n) for DP approach, O(1) for optimal
"""

from typing import List, Optional

class Solution:
    def divisorGame(self, n):
        # Alice wins if and only if n is even
        # Proof:
        # - If n is even, Alice can always choose x=1, making n odd for Bob
        # - If n is odd, all divisors are odd, so n-x is even for Bob
        # - This pattern continues until someone gets n=1 and loses
        return n % 2 == 0
    def divisorGameDP(self, n):
        # dp[i] = True if current player wins with number i
        dp = [False] * (n + 1)
        for i in range(2, n + 1):
            for x in range(1, i):
                if i % x == 0 and not dp[i - x]:
                    dp[i] = True
                    break
        return dp[n]

if __name__ == "__main__":
    sol = Solution()
    n1 = 2
    print(f"Input: n = {n1}")
    print(f"Output: {sol.divisorGame(n1)}")
    print(f"Output (DP): {sol.divisorGameDP(n1)}")
    n2 = 3
    print(f"Input: n = {n2}")
    print(f"Output: {sol.divisorGame(n2)}")
    print(f"Output (DP): {sol.divisorGameDP(n2)}")
    n3 = 10
    print(f"Input: n = {n3}")
    print(f"Output: {sol.divisorGame(n3)}")
    print(f"Output (DP): {sol.divisorGameDP(n3)}")
