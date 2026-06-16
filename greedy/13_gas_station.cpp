/*
PROBLEM: Gas Station (LeetCode 134)
DIFFICULTY: Medium
PATTERN: Circular Array Greedy with Running Sum

DESCRIPTION:
There are n gas stations along a circular route. You have a car with unlimited gas tank capacity.
It costs cost[i] to travel from station i to next station (i+1). You begin with an empty tank at 
one of the stations. Given gas and cost arrays, return the starting station's index if you can 
travel around the circuit once, otherwise return -1. Solution is guaranteed to be unique.

INPUT:
- gas: array where gas[i] is gas available at station i
- cost: array where cost[i] is gas needed to reach next station

OUTPUT:
- Starting station index, or -1 if impossible

APPROACH:
1. If total gas < total cost, impossible
2. Track running tank: at each station, tank += gas[i] - cost[i]
3. If tank goes negative, all stations from start to current can't be starting point
4. Reset start to next station and reset tank

WHY GREEDY WORKS:
If we can't reach station j from station i, then any station between i and j 
also can't reach j. So we can safely skip all of them.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            
            tank += gas[i] - cost[i];
            
            // If tank is negative, can't start from any station up to i
            if (tank < 0) {
                start = i + 1;  // Try starting from next station
                tank = 0;       // Reset tank
            }
        }
        
        // If total gas < total cost, impossible to complete circuit
        return (totalGas >= totalCost) ? start : -1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test 1 - Gas: [1,2,3,4,5], Cost: [3,4,5,1,2]" << endl;
    cout << "Output: " << sol.canCompleteCircuit(gas1, cost1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test 2 - Gas: [2,3,4], Cost: [3,4,3]" << endl;
    cout << "Output: " << sol.canCompleteCircuit(gas2, cost2) << endl;
    cout << "Expected: -1" << endl << endl;
    
    // Test Case 3
    vector<int> gas3 = {5, 1, 2, 3, 4};
    vector<int> cost3 = {4, 4, 1, 5, 1};
    cout << "Test 3 - Gas: [5,1,2,3,4], Cost: [4,4,1,5,1]" << endl;
    cout << "Output: " << sol.canCompleteCircuit(gas3, cost3) << endl;
    cout << "Expected: 4" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is number of stations
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Circular array problems: one pass can be enough with right greedy insight
- Key insight: if can't reach j from i, skip all stations between i and j
- Check total feasibility first (total gas vs total cost)
- Running balance + reset strategy is powerful
- Very popular in interviews (Amazon, Google, Microsoft)
*/
