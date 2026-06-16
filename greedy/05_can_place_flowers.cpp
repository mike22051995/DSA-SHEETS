/*
PROBLEM: Can Place Flowers (LeetCode 605)
DIFFICULTY: Easy
PATTERN: Greedy Placement with Local Constraints

DESCRIPTION:
You have a long flowerbed in which some plots are planted and some are not. However, 
flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 
0's and 1's (0 means empty, 1 means planted) and an integer n, return true if n new flowers 
can be planted without violating the no-adjacent-flowers rule.

INPUT:
- flowerbed: array of 0s and 1s
- n: number of flowers to plant

OUTPUT:
- true if n flowers can be planted, false otherwise

APPROACH:
1. Iterate through the flowerbed
2. At each position, check if we can plant (current empty, left empty, right empty)
3. Greedily plant as soon as we find a valid spot
4. Check if we planted at least n flowers

WHY GREEDY WORKS:
Planting a flower at the earliest valid position never makes it worse for future placements.
It either has no effect or creates more opportunities.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            // Check if current position is empty
            if (flowerbed[i] == 0) {
                // Check left neighbor (empty or out of bounds)
                bool leftEmpty = (i == 0) || (flowerbed[i-1] == 0);
                
                // Check right neighbor (empty or out of bounds)
                bool rightEmpty = (i == size-1) || (flowerbed[i+1] == 0);
                
                // If both neighbors are empty (or don't exist), plant here
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;  // Plant the flower
                    count++;
                    
                    // Early exit optimization
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        
        return count >= n;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    cout << "Test 1 - Flowerbed: [1,0,0,0,1], n=1" << endl;
    cout << "Output: " << (sol.canPlaceFlowers(flowerbed1, 1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 2
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    cout << "Test 2 - Flowerbed: [1,0,0,0,1], n=2" << endl;
    cout << "Output: " << (sol.canPlaceFlowers(flowerbed2, 2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test Case 3
    vector<int> flowerbed3 = {0, 0, 1, 0, 0};
    cout << "Test 3 - Flowerbed: [0,0,1,0,0], n=1" << endl;
    cout << "Output: " << (sol.canPlaceFlowers(flowerbed3, 1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 4
    vector<int> flowerbed4 = {0, 0, 0, 0, 0};
    cout << "Test 4 - Flowerbed: [0,0,0,0,0], n=3" << endl;
    cout << "Output: " << (sol.canPlaceFlowers(flowerbed4, 3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is the flowerbed length
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Greedy placement: plant as early as possible
- Check local constraints before making greedy choice
- Early exit can optimize when target is reached
- This pattern applies to many interval/spacing problems
*/
