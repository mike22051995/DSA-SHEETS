/*
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
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int towerOfHanoi(int n, char from, char to, char aux) {
        return solveHanoi(n, from, to, aux);
    }
    
private:
    int solveHanoi(int n, char from, char to, char aux) {
        // Base case: only one disk
        if (n == 1) {
            cout << "Move disk 1 from " << from << " to " << to << endl;
            return 1;
        }
        
        int moves = 0;
        
        // Step 1: Move n-1 disks from 'from' to 'aux' using 'to'
        moves += solveHanoi(n - 1, from, aux, to);
        
        // Step 2: Move the largest disk from 'from' to 'to'
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        moves++;
        
        // Step 3: Move n-1 disks from 'aux' to 'to' using 'from'
        moves += solveHanoi(n - 1, aux, to, from);
        
        return moves;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test 1: n = 3" << endl;
    int moves1 = sol.towerOfHanoi(3, 'A', 'C', 'B');
    cout << "Total moves: " << moves1 << endl << endl;
    
    // Test case 2
    cout << "Test 2: n = 2" << endl;
    int moves2 = sol.towerOfHanoi(2, 'A', 'C', 'B');
    cout << "Total moves: " << moves2 << endl;
    
    return 0;
}
