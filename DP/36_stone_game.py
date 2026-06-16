"""
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

Assuming Alice and Bob play optimally, return True if Alice wins.

EXAMPLE:
Input: piles = [5,3,4,5]
Output: True
Explanation:
Alice: 5, Bob: 5, Alice: 4, Bob: 3
Alice: 5+4=9, Bob: 5+3=8, Alice wins

Input: piles = [3,7,2,3]
Output: True

Input: piles = [1,2,3,4,5]
Output: True (Alice always wins with even piles)

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²)
"""

from typing import List, Optional

class Solution:
    def stoneGame(self, piles):
        n = len(piles)
        # Alice always wins with even number of piles (math proof)
        # But let's do DP for completeness
        dp = [[0] * n for _ in range(n)]
        # Base case: single pile
        for i in range(n):
            dp[i][i] = piles[i]
        # Fill by increasing length
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                # Take left pile: piles[i] + what's left for Alice in [i+1..j]
                # Take right pile: piles[j] + what's left for Alice in [i..j-1]
                # dp[i][j] = best score advantage Alice can achieve
                take_left = piles[i] - dp[i+1][j]
                take_right = piles[j] - dp[i][j-1]
                dp[i][j] = max(take_left, take_right)
        return dp[0][n-1] > 0

    def stoneGameDiff(self, piles):
        n = len(piles)
        dp = list(piles)
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i] = max(piles[i] - dp[i+1], piles[j] - dp[i])
        return dp[0] > 0

    def stoneGameMath(self, piles):
        # Alice always wins when piles count is even
        return True

    def getOptimalMoves(self, piles):
        n = len(piles)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = piles[i]
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
        moves = []
        lo, hi = 0, n - 1
        while lo < hi:
            if piles[lo] - dp[lo+1][hi] >= piles[hi] - dp[lo][hi-1]:
                moves.append(piles[lo])
                lo += 1
            else:
                moves.append(piles[hi])
                hi -= 1
        moves.append(piles[lo])
        return moves


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    piles1 = [5, 3, 4, 5]
    print(f"Piles: {piles1}")
    print(f"Alice wins (DP): {sol.stoneGame(piles1)}")
    print(f"Alice wins (Diff): {sol.stoneGameDiff(piles1)}")
    print(f"Alice wins (Math): {sol.stoneGameMath(piles1)}")
    moves1 = sol.getOptimalMoves(piles1)
    print(f"Optimal moves: {moves1}")
    print(f"\nTest Case 2:")
    piles2 = [3, 7, 2, 3]
    print(f"Piles: {piles2}")
    print(f"Alice wins: {sol.stoneGame(piles2)}")
    print(f"\nTest Case 3:")
    piles3 = [1, 2, 3, 4, 5, 6]
    print(f"Piles: {piles3}")
    print(f"Alice wins: {sol.stoneGame(piles3)}")
