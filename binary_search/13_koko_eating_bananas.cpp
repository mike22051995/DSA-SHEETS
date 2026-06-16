/*
PROBLEM: Koko Eating Bananas
Difficulty: Medium
Pattern: Binary Search on Answer

DESCRIPTION:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of 
bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all 
of them instead and will not eat any more bananas during this hour.
Return the minimum integer k such that she can eat all the bananas within h hours.

EXPLANATION:
Binary search on eating speed:
- Min speed = 1
- Max speed = max(piles)
- For each speed, calculate hours needed
- Find minimum speed that works

Time Complexity: O(n * log(max))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4
Explanation: Koko can eat at speed 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30
Explanation: Must eat one pile per hour

Example 3:
Input: piles = [30,11,23,4,20], h = 6 
Output: 23
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canEatAll(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canEatAll(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed; // Ceiling division
            
            if (hours > h) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> piles1 = {3,6,7,11};
    cout << "Test 1: " << solution.minEatingSpeed(piles1, 8) << endl;
    
    // Test Case 2
    vector<int> piles2 = {30,11,23,4,20};
    cout << "Test 2: " << solution.minEatingSpeed(piles2, 5) << endl;
    
    // Test Case 3
    vector<int> piles3 = {30,11,23,4,20};
    cout << "Test 3: " << solution.minEatingSpeed(piles3, 6) << endl;
    
    return 0;
}
