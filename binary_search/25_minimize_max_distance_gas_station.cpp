/*
PROBLEM: Minimize Max Distance to Gas Station
Difficulty: Hard
Pattern: Binary Search on Answer (with Precision)

DESCRIPTION:
You are given an integer array stations that represents the positions of gas stations on the 
x-axis. You are also given an integer k.
You should add k new gas stations. You can add the stations anywhere on the x-axis, and you 
do not need to add them on integer coordinates.
Return the minimum possible value of the maximum distance between adjacent gas stations after 
adding the k new stations.

EXPLANATION:
Binary search on the maximum distance:
- Min distance = 0, Max distance = max gap in original stations
- For each distance, calculate stations needed to achieve it
- Find minimum distance that requires <= k stations

Time Complexity: O(n * log(max_gap / precision))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000
Explanation: Add 1 station between each pair

Example 2:
Input: stations = [23,24,36,39,46,56,57,65,84,98], k = 1
Output: 14.00000
Explanation: Add station between 24 and 36

Example 3:
Input: stations = [1,5,10], k = 1
Output: 4.00000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0;
        double right = 0;
        
        // Find maximum gap
        for (int i = 1; i < stations.size(); i++) {
            right = max(right, (double)(stations[i] - stations[i-1]));
        }
        
        double epsilon = 1e-6;
        
        while (right - left > epsilon) {
            double mid = left + (right - left) / 2.0;
            
            if (canAchieve(stations, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return left;
    }
    
private:
    bool canAchieve(vector<int>& stations, int k, double maxDist) {
        int stationsNeeded = 0;
        
        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i-1];
            stationsNeeded += (int)(gap / maxDist);
            
            if (stationsNeeded > k) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> stations1 = {1,2,3,4,5,6,7,8,9,10};
    cout << "Test 1: " << solution.minmaxGasDist(stations1, 9) << endl;
    
    // Test Case 2
    vector<int> stations2 = {23,24,36,39,46,56,57,65,84,98};
    cout << "Test 2: " << solution.minmaxGasDist(stations2, 1) << endl;
    
    // Test Case 3
    vector<int> stations3 = {1,5,10};
    cout << "Test 3: " << solution.minmaxGasDist(stations3, 1) << endl;
    
    return 0;
}
