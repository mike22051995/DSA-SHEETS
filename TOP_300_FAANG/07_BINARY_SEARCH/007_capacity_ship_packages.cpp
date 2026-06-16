/*
================================================================================
PROBLEM: Capacity To Ship Packages Within D Days (LeetCode #1011)
DIFFICULTY: Medium
PATTERN: Binary Search
COMPANIES: Amazon, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given weights of packages in order and an integer days, return the minimum ship
capacity so that all packages are shipped within days. Packages must be shipped
in the given order and cannot be split.

EXAMPLES:
Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3

CODE EXPLANATION:
- Binary search capacity between max weight and total weight.
- Simulate shipping to count days needed for a candidate capacity.
- If days needed <= days, try smaller capacity; otherwise increase it.
TIME COMPLEXITY: O(n log S), S = sum of weights
SPACE COMPLEXITY: O(1)
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
            
            if (canShip(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    bool canShip(vector<int>& weights, int capacity, int days) {
        int daysNeeded = 1;
        int currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                daysNeeded++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        
        return daysNeeded <= days;
    }
};

int main() {
    Solution sol;
    vector<int> weights1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> weights2 = {3,2,2,4,1,4};
    
    cout << "Min capacity (5 days): " << sol.shipWithinDays(weights1, 5) << endl;
    cout << "Min capacity (3 days): " << sol.shipWithinDays(weights2, 3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Koko Eating Bananas (LeetCode #875)
2. Split Array Largest Sum (LeetCode #410)
3. Divide Chocolate (LeetCode #1231)
4. Minimum Number of Days to Make Bouquets (LeetCode #1482)
5. Magnetic Force Between Two Balls (LeetCode #1552)
6. Minimized Maximum of Products (LeetCode #2064)
7. Minimum Time to Complete Trips (LeetCode #2187)
8. Maximum Candies Allocated (LeetCode #2226)
9. Minimum Speed to Arrive on Time (LeetCode #1870)
10. Find K-th Smallest Pair Distance (LeetCode #719)
*/
