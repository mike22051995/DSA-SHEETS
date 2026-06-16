/*
PROBLEM: Capacity To Ship Packages Within D Days
Difficulty: Medium
Pattern: Binary Search on Answer

DESCRIPTION:
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship 
with packages on the conveyor belt (in the order given by weights). We may not load more weight 
than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the 
conveyor belt being shipped within days days.

EXPLANATION:
Binary search on ship capacity:
- Min capacity = max(weights) (must carry heaviest package)
- Max capacity = sum(weights) (carry all in one day)
- For each mid capacity, check if can ship in D days
- Find minimum capacity that works

Time Complexity: O(n * log(sum - max))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: Ship with capacity 15: [1,2,3,4,5],[6,7],[8],[9],[10]

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: Ship with capacity 6: [3,2],[2,4],[1,4]

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                daysNeeded++;
                currentLoad = weight;
                
                if (daysNeeded > days) {
                    return false;
                }
            } else {
                currentLoad += weight;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> weights1 = {1,2,3,4,5,6,7,8,9,10};
    cout << "Test 1: " << solution.shipWithinDays(weights1, 5) << endl;
    
    // Test Case 2
    vector<int> weights2 = {3,2,2,4,1,4};
    cout << "Test 2: " << solution.shipWithinDays(weights2, 3) << endl;
    
    // Test Case 3
    vector<int> weights3 = {1,2,3,1,1};
    cout << "Test 3: " << solution.shipWithinDays(weights3, 4) << endl;
    
    return 0;
}
