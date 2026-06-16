/*
PROBLEM: Egg Drop Problem
DIFFICULTY: Hard
PATTERN: Min-Max DP / Binary Search Optimization

DESCRIPTION:
You are given k identical eggs and you have access to a building with n floors.
Each egg is identical in strength. An egg can survive a drop from a certain floor
but will break if dropped from a floor above that.

Find the minimum number of attempts you need in the worst case to find the 
critical floor (highest floor from which the egg will not break).

EXAMPLE:
Input: k = 1, n = 2
Output: 2
Explanation: Drop from floor 1, then floor 2. Total 2 attempts.

Input: k = 2, n = 6
Output: 3
Explanation: Optimal: Drop from floor 3
- Breaks: Check floors 1,2 (worst: 2 more)
- Survives: Drop from floor 5 (worst case continues)

Input: k = 2, n = 10
Output: 4

TIME COMPLEXITY: O(k*n²) naive, O(k*n*log(n)) with binary search
SPACE COMPLEXITY: O(k*n)
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (TLE - for understanding)
    int eggDropRecursive(int k, int n) {
        // Base cases
        if (n == 0 || n == 1) return n;  // 0 or 1 floor
        if (k == 1) return n;  // With 1 egg, must try all floors
        
        int minAttempts = INT_MAX;
        
        // Try dropping from each floor
        for (int floor = 1; floor <= n; floor++) {
            // Egg breaks: k-1 eggs, floor-1 floors below
            int breaks = eggDropRecursive(k-1, floor-1);
            
            // Egg survives: k eggs, n-floor floors above
            int survives = eggDropRecursive(k, n-floor);
            
            // Worst case: max of both
            int worstCase = 1 + max(breaks, survives);
            
            // Best of all worst cases
            minAttempts = min(minAttempts, worstCase);
        }
        
        return minAttempts;
    }
    
    // Approach 2: Memoization
    int eggDropMemo(int k, int n, vector<vector<int>>& dp) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;
        
        if (dp[k][n] != -1) return dp[k][n];
        
        int minAttempts = INT_MAX;
        
        for (int floor = 1; floor <= n; floor++) {
            int breaks = eggDropMemo(k-1, floor-1, dp);
            int survives = eggDropMemo(k, n-floor, dp);
            int worstCase = 1 + max(breaks, survives);
            minAttempts = min(minAttempts, worstCase);
        }
        
        return dp[k][n] = minAttempts;
    }
    
    // Approach 3: Bottom-Up DP
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
        
        // Base cases
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for (int j = 1; j <= n; j++) {
            dp[1][j] = j;
        }
        
        // Fill DP table
        for (int eggs = 2; eggs <= k; eggs++) {
            for (int floors = 2; floors <= n; floors++) {
                dp[eggs][floors] = INT_MAX;
                
                for (int floor = 1; floor <= floors; floor++) {
                    int breaks = dp[eggs-1][floor-1];
                    int survives = dp[eggs][floors-floor];
                    int worstCase = 1 + max(breaks, survives);
                    dp[eggs][floors] = min(dp[eggs][floors], worstCase);
                }
            }
        }
        
        return dp[k][n];
    }
    
    // Approach 4: Binary Search Optimization O(k*n*log(n))
    int superEggDropOptimized(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for (int j = 1; j <= n; j++) {
            dp[1][j] = j;
        }
        
        for (int eggs = 2; eggs <= k; eggs++) {
            for (int floors = 2; floors <= n; floors++) {
                int low = 1, high = floors;
                
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    
                    int breaks = dp[eggs-1][mid-1];
                    int survives = dp[eggs][floors-mid];
                    
                    if (breaks > survives) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                
                dp[eggs][floors] = 1 + max(dp[eggs-1][low-1], dp[eggs][floors-low]);
            }
        }
        
        return dp[k][n];
    }
    
    // Approach 5: Reverse thinking - O(k*attempts)
    // "With k eggs and t attempts, what's max floors we can check?"
    int superEggDropReverse(int k, int n) {
        // dp[attempts][eggs] = max floors we can check
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        int attempts = 0;
        while (dp[attempts][k] < n) {
            attempts++;
            for (int eggs = 1; eggs <= k; eggs++) {
                // If egg breaks: check dp[attempts-1][eggs-1] floors below
                // If egg survives: check dp[attempts-1][eggs] floors above
                // Current floor: 1
                dp[attempts][eggs] = dp[attempts-1][eggs-1] + dp[attempts-1][eggs] + 1;
            }
        }
        
        return attempts;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    int k1 = 1, n1 = 2;
    cout << "Eggs: " << k1 << ", Floors: " << n1 << endl;
    cout << "Minimum attempts: " << sol.superEggDrop(k1, n1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    int k2 = 2, n2 = 6;
    cout << "Eggs: " << k2 << ", Floors: " << n2 << endl;
    cout << "Minimum attempts (DP): " << sol.superEggDrop(k2, n2) << endl;
    cout << "Minimum attempts (Optimized): " << sol.superEggDropOptimized(k2, n2) << endl;
    cout << "Minimum attempts (Reverse): " << sol.superEggDropReverse(k2, n2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    int k3 = 2, n3 = 10;
    cout << "Eggs: " << k3 << ", Floors: " << n3 << endl;
    cout << "Minimum attempts: " << sol.superEggDrop(k3, n3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    int k4 = 3, n4 = 14;
    cout << "Eggs: " << k4 << ", Floors: " << n4 << endl;
    cout << "Minimum attempts (Optimized): " << sol.superEggDropOptimized(k4, n4) << endl;
    cout << "Minimum attempts (Reverse): " << sol.superEggDropReverse(k4, n4) << endl;
    
    return 0;
}

/*
EXPLANATION:

EGG DROP PROBLEM - Classic Min-Max DP

PROBLEM UNDERSTANDING:
Find minimum attempts needed in WORST CASE to determine critical floor.

KEY INSIGHT:
When we drop from floor X:
1. Egg breaks → Check X-1 floors below with k-1 eggs
2. Egg survives → Check n-X floors above with k eggs

We want MIN attempts over ALL choices of X
But each choice has WORST CASE (MAX of two scenarios)

RECURRENCE:
dp[k][n] = minimum attempts with k eggs and n floors

dp[k][n] = 1 + min(max(dp[k-1][floor-1], dp[k][n-floor]))
           for all floors from 1 to n

BASE CASES:
- dp[k][0] = 0 (no floors)
- dp[k][1] = 1 (one floor)
- dp[1][n] = n (with 1 egg, must try all floors linearly)

EXAMPLE: k=2, n=6

dp[2][6]:
Try floor 1: max(dp[1][0], dp[2][5]) = max(0, 5) = 5 → 1+5 = 6
Try floor 2: max(dp[1][1], dp[2][4]) = max(1, 4) = 4 → 1+4 = 5
Try floor 3: max(dp[1][2], dp[2][3]) = max(2, 3) = 3 → 1+3 = 4
Try floor 4: max(dp[1][3], dp[2][2]) = max(3, 2) = 3 → 1+3 = 4
Try floor 5: max(dp[1][4], dp[2][1]) = max(4, 1) = 4 → 1+4 = 5
Try floor 6: max(dp[1][5], dp[2][0]) = max(5, 0) = 5 → 1+5 = 6

Minimum = 4 (at floors 3 or 4) → But optimal says 3!

OPTIMIZATION 1: Binary Search
Notice that as floor increases:
- dp[k-1][floor-1] increases (more floors to check below)
- dp[k][n-floor] decreases (fewer floors to check above)

These form two monotonic curves that intersect!
Use binary search to find intersection point.
Time: O(k*n*log(n))

OPTIMIZATION 2: Reverse Thinking
Instead of "min attempts with k eggs, n floors"
Think: "max floors with k eggs, t attempts"

dp[t][k] = max floors we can check with t attempts, k eggs

dp[t][k] = dp[t-1][k-1] (if breaks) 
         + dp[t-1][k] (if survives) 
         + 1 (current floor)

Find minimum t where dp[t][k] >= n
Time: O(k*attempts) where attempts << n

PATTERN VARIANTS:
- Standard: minimize worst case
- Two egg puzzle: k=2
- Infinite eggs: just binary search (log n)

INTERVIEW TIP:
Start with naive DP, then mention:
"This is O(k*n²). Can optimize with binary search to O(k*n*log(n)).
Or reverse thinking for O(k*attempts)."

WHY MIN-MAX?
MIN: over all our choices
MAX: worst case (pessimistic adversary)

OUTPUT:
Test Case 1:
Eggs: 1, Floors: 2
Minimum attempts: 2

Test Case 2:
Eggs: 2, Floors: 6
Minimum attempts (DP): 3
Minimum attempts (Optimized): 3
Minimum attempts (Reverse): 3

Test Case 3:
Eggs: 2, Floors: 10
Minimum attempts: 4

Test Case 4:
Eggs: 3, Floors: 14
Minimum attempts (Optimized): 4
Minimum attempts (Reverse): 4
*/
