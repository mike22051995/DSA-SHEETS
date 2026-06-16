/*
PROBLEM: Minimum Number of Days to Make m Bouquets
Difficulty: Medium
Pattern: Binary Search on Answer

DESCRIPTION:
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be 
used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
If it is impossible to make m bouquets return -1.

EXPLANATION:
Binary search on days:
- Min days = min(bloomDay)
- Max days = max(bloomDay)
- For each day, count bouquets we can make
- Find minimum days that gives us m bouquets

Time Complexity: O(n * log(max))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: After 3 days: [1,_,3,_,2], can make 3 bouquets

Example 2:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: Need 6 flowers but only 5 available

Example 3:
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long needed = (long long)m * k;
        if (needed > bloomDay.size()) return -1;
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                    if (bouquets >= m) return true;
                }
            } else {
                flowers = 0;
            }
        }
        
        return bouquets >= m;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> bloomDay1 = {1,10,3,10,2};
    cout << "Test 1: " << solution.minDays(bloomDay1, 3, 1) << endl;
    
    // Test Case 2
    vector<int> bloomDay2 = {1,10,3,10,2};
    cout << "Test 2: " << solution.minDays(bloomDay2, 3, 2) << endl;
    
    // Test Case 3
    vector<int> bloomDay3 = {7,7,7,7,12,7,7};
    cout << "Test 3: " << solution.minDays(bloomDay3, 2, 3) << endl;
    
    return 0;
}
