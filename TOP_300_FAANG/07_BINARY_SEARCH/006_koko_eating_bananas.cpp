/*
================================================================================
PROBLEM: Koko Eating Bananas (LeetCode #875)
DIFFICULTY: Medium
PATTERN: Binary Search
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================

PROBLEM DESCRIPTION:
Koko loves bananas and wants to eat all banana piles within h hours. Each hour
she chooses a pile and eats up to k bananas from it. Return the minimum integer
k so that she can finish all piles within h hours.

EXAMPLES:
Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

CODE EXPLANATION:
- Binary search the eating speed k between 1 and max(piles).
- For a candidate k, compute total hours using ceiling division.
- If total hours <= h, try smaller k; otherwise increase k.
TIME COMPLEXITY: O(n log M), M = max pile size
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    bool canFinish(vector<int>& piles, int k, int h) {
        long long hours = 0;
        
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Ceiling division
        }
        
        return hours <= h;
    }
};

int main() {
    Solution sol;
    vector<int> piles1 = {3,6,7,11};
    vector<int> piles2 = {30,11,23,4,20};
    
    cout << "Min eating speed (h=8): " << sol.minEatingSpeed(piles1, 8) << endl;
    cout << "Min eating speed (h=5): " << sol.minEatingSpeed(piles2, 5) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Capacity To Ship Packages (LeetCode #1011)
2. Minimum Number of Days to Make Bouquets (LeetCode #1482)
3. Split Array Largest Sum (LeetCode #410)
4. Find K-th Smallest Pair Distance (LeetCode #719)
5. Divide Chocolate (LeetCode #1231)
6. Minimized Maximum of Products (LeetCode #2064)
7. Minimum Time to Complete Trips (LeetCode #2187)
8. Maximum Candies Allocated (LeetCode #2226)
9. Minimum Speed to Arrive on Time (LeetCode #1870)
10. Magnetic Force Between Two Balls (LeetCode #1552)
*/
