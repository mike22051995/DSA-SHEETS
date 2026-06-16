/*
PROBLEM: Minimum Cost to Move Chips to The Same Position (LeetCode 1217)
DIFFICULTY: Easy
PATTERN: Parity-Based Greedy

DESCRIPTION:
We have n chips, where the position of the ith chip is position[i]. We need to move all 
the chips to the same position. In one step, we can:
- Move a chip at position[i] to position[i+2] or position[i-2] with cost = 0
- Move a chip at position[i] to position[i+1] or position[i-1] with cost = 1

Return the minimum cost to move all the chips to the same position.

INPUT:
- position: array of chip positions

OUTPUT:
- Minimum cost to gather all chips

APPROACH:
Key insight: Moving by 2 is free, moving by 1 costs 1
- All chips at even positions can be gathered at position 0 with 0 cost
- All chips at odd positions can be gathered at position 1 with 0 cost
- Moving from 0 to 1 (or vice versa) costs 1 per chip
- Greedy: Move the smaller group to the larger group

WHY GREEDY WORKS:
Since we can move even→even and odd→odd for free, we only need to count parity.
Moving the minority to majority minimizes cost.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0;
        int oddCount = 0;
        
        // Count chips at even and odd positions
        for (int pos : position) {
            if (pos % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        // Move the smaller group to the larger group
        return min(evenCount, oddCount);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> position1 = {1, 2, 3};
    cout << "Test 1 - Positions: [1,2,3]" << endl;
    cout << "Output: " << sol.minCostToMoveChips(position1) << endl;
    cout << "Expected: 1 (Move chip at position 1 to 2, cost 1)" << endl << endl;
    
    // Test Case 2
    vector<int> position2 = {2, 2, 2, 3, 3};
    cout << "Test 2 - Positions: [2,2,2,3,3]" << endl;
    cout << "Output: " << sol.minCostToMoveChips(position2) << endl;
    cout << "Expected: 2 (Move 2 chips from odd positions)" << endl << endl;
    
    // Test Case 3
    vector<int> position3 = {1, 1000000000};
    cout << "Test 3 - Positions: [1,1000000000]" << endl;
    cout << "Output: " << sol.minCostToMoveChips(position3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is number of chips
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Look for problem invariants (here: parity doesn't change with +2/-2 moves)
- Sometimes the problem simplifies dramatically when you identify the right property
- Greedy choice: move minority to majority
- This pattern appears in problems with grouped operations
*/
