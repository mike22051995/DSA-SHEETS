/*
PROBLEM: Maximum Units on a Truck (LeetCode 1710)
DIFFICULTY: Easy
PATTERN: Fractional Knapsack (Sort by Value Density)

DESCRIPTION:
You are assigned to put some amount of boxes onto one truck. You are given a 2D array 
boxTypes, where boxTypes[i] = [numberOfBoxes_i, numberOfUnitsPerBox_i]:
- numberOfBoxes_i is the number of boxes of type i
- numberOfUnitsPerBox_i is the number of units in each box of type i
You are also given an integer truckSize (maximum boxes on truck).
Return the maximum total number of units that can be put on the truck.

INPUT:
- boxTypes: 2D array where boxTypes[i] = [number of boxes, units per box]
- truckSize: maximum number of boxes truck can carry

OUTPUT:
- Maximum units that can be loaded

APPROACH:
1. Sort box types by units per box in descending order
2. Greedily take boxes with highest units per box first
3. Continue until truck is full or no more boxes

WHY GREEDY WORKS:
This is fractional knapsack pattern - we can take any number of boxes of each type.
Taking highest value items first maximizes total value.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort by units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];  // Compare by units per box
             });
        
        int totalUnits = 0;
        int boxesLoaded = 0;
        
        for (const auto& box : boxTypes) {
            int numberOfBoxes = box[0];
            int unitsPerBox = box[1];
            
            // Take as many boxes as possible of this type
            int boxesToTake = min(numberOfBoxes, truckSize - boxesLoaded);
            
            totalUnits += boxesToTake * unitsPerBox;
            boxesLoaded += boxesToTake;
            
            // If truck is full, stop
            if (boxesLoaded == truckSize) {
                break;
            }
        }
        
        return totalUnits;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> boxTypes1 = {{1, 3}, {2, 2}, {3, 1}};
    cout << "Test 1 - BoxTypes: [[1,3],[2,2],[3,1]], TruckSize: 4" << endl;
    cout << "Output: " << sol.maximumUnits(boxTypes1, 4) << endl;
    cout << "Expected: 8 (1 box of 3 units + 2 boxes of 2 units + 1 box of 1 unit)" << endl << endl;
    
    // Test Case 2
    vector<vector<int>> boxTypes2 = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << "Test 2 - BoxTypes: [[5,10],[2,5],[4,7],[3,9]], TruckSize: 10" << endl;
    cout << "Output: " << sol.maximumUnits(boxTypes2, 10) << endl;
    cout << "Expected: 91" << endl << endl;
    
    // Test Case 3
    vector<vector<int>> boxTypes3 = {{1, 1}, {1, 2}, {1, 3}};
    cout << "Test 3 - BoxTypes: [[1,1],[1,2],[1,3]], TruckSize: 2" << endl;
    cout << "Output: " << sol.maximumUnits(boxTypes3, 2) << endl;
    cout << "Expected: 5 (3 + 2)" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) where n is number of box types (due to sorting)
SPACE COMPLEXITY: O(1) if we ignore sorting space

KEY LEARNING:
- Fractional knapsack: greedy works when we can take fractions/any amount
- Always sort by value density (value per unit weight/space)
- This differs from 0/1 knapsack where greedy doesn't work (need DP)
- Pattern appears in resource allocation problems
- Sort + greedy is a common combination
*/
