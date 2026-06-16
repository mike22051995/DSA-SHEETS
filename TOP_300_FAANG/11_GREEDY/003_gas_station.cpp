/*
================================================================================
PROBLEM: Gas Station (LeetCode #134)
DIFFICULTY: Medium
PATTERN: Greedy
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currentGas = 0, startStation = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            // If can't reach next station, reset start
            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }
        
        return totalGas >= totalCost ? startStation : -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    
    cout << "Start station: " << sol.canCompleteCircuit(gas, cost) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Jump Game (LeetCode #55)
2. Jump Game II (LeetCode #45)
3. Best Time to Buy and Sell Stock II (LeetCode #122)
4. Maximum Subarray (LeetCode #53)
5. Minimum Size Subarray Sum (LeetCode #209)
6. Container With Most Water (LeetCode #11)
7. Trapping Rain Water (LeetCode #42)
8. Candy (LeetCode #135)
9. Task Scheduler (LeetCode #621)
10. Partition Labels (LeetCode #763)
*/
