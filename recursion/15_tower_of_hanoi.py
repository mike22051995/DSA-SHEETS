"""
PROBLEM: Tower of Hanoi
---------------------------------------------------------------------------
The Tower of Hanoi is a mathematical puzzle consisting of three rods and n 
disks of different sizes. The objective is to move the entire stack to 
another rod, following these rules:
1. Only one disk can be moved at a time
2. A disk can only be moved if it is the uppermost disk on a stack
3. No larger disk may be placed on top of a smaller disk

DIFFICULTY: Medium
PATTERN: Divide and Conquer Recursion
TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 3, from = 'A', to = 'C', aux = 'B'
Output: 
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total moves: 7 (2^3 - 1)

Example 2:
Input: n = 2, from = 'A', to = 'C', aux = 'B'
Output:
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Total moves: 3 (2^2 - 1)
"""

from typing import List


class Solution:
    def towerOfHanoi(self, n: int, src: str, dest: str, aux: str) -> int:
        # Base case
        if n == 1:
            print(f"Move disk 1 from {src} to {dest}")
            return 1
        # Move top n-1 disks from src to aux using dest
        moves = self.towerOfHanoi(n - 1, src, aux, dest)
        # Move the largest disk from src to dest
        print(f"Move disk {n} from {src} to {dest}")
        moves += 1
        # Move n-1 disks from aux to dest using src
        moves += self.towerOfHanoi(n - 1, aux, dest, src)
        return moves


if __name__ == "__main__":
    sol = Solution()
    print("Test 1: n = 3")
    moves1 = sol.towerOfHanoi(3, 'A', 'C', 'B')
    print(f"Total moves: {moves1}")
    print("Test 2: n = 2")
    moves2 = sol.towerOfHanoi(2, 'A', 'C', 'B')
    print(f"Total moves: {moves2}")
