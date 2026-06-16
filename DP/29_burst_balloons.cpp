/*
PROBLEM: Burst Balloons (LeetCode 312)
DIFFICULTY: Hard
PATTERN: Interval/Partition DP

DESCRIPTION:
You are given n balloons indexed from 0 to n-1. Each balloon is painted with 
a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst balloon i, you will get nums[i-1] * nums[i] * nums[i+1] coins.
After bursting it, the left and right balloons become adjacent.

Return the maximum coins you can collect by bursting the balloons wisely.

EXAMPLE:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8]
Burst 1: coins = 3*1*5 = 15, nums = [3,5,8]
Burst 5: coins = 3*5*8 = 120, nums = [3,8]
Burst 3: coins = 1*3*8 = 24, nums = [8]
Burst 8: coins = 1*8*1 = 8
Total = 15+120+24+8 = 167

Input: nums = [1,5]
Output: 10

TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(n²)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Think backwards - last balloon to burst!
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add boundary balloons with value 1
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n+1] = 1;
        for (int i = 0; i < n; i++) {
            arr[i+1] = nums[i];
        }
        
        // dp[i][j] = max coins from bursting balloons in range (i, j)
        // not including i and j
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        // len is the length of the interval
        for (int len = 1; len <= n; len++) {
            for (int left = 0; left <= n - len; left++) {
                int right = left + len + 1;
                
                // Try bursting each balloon as the LAST one
                for (int k = left + 1; k < right; k++) {
                    // If k is burst last in range (left, right)
                    // Its neighbors are left and right
                    int coins = arr[left] * arr[k] * arr[right];
                    coins += dp[left][k] + dp[k][right];
                    
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        
        return dp[0][n+1];
    }
    
    // Approach 2: Memoization
    int maxCoinsHelper(vector<int>& arr, int left, int right, 
                       vector<vector<int>>& dp) {
        if (left + 1 >= right) return 0;  // No balloons in between
        
        if (dp[left][right] != -1) return dp[left][right];
        
        int maxCoins = 0;
        
        for (int k = left + 1; k < right; k++) {
            int coins = arr[left] * arr[k] * arr[right];
            coins += maxCoinsHelper(arr, left, k, dp);
            coins += maxCoinsHelper(arr, k, right, dp);
            
            maxCoins = max(maxCoins, coins);
        }
        
        return dp[left][right] = maxCoins;
    }
    
    int maxCoinsMemo(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n+1] = 1;
        for (int i = 0; i < n; i++) {
            arr[i+1] = nums[i];
        }
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return maxCoinsHelper(arr, 0, n+1, dp);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {3, 1, 5, 8};
    cout << "Balloons: ";
    for (int n : nums1) cout << n << " ";
    cout << endl;
    cout << "Maximum coins: " << sol.maxCoins(nums1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {1, 5};
    cout << "Balloons: ";
    for (int n : nums2) cout << n << " ";
    cout << endl;
    cout << "Maximum coins: " << sol.maxCoins(nums2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {8, 2, 6, 8, 9, 8, 1, 4, 1, 5, 3, 0, 7, 7, 0, 4, 2, 2};
    cout << "Balloons: ";
    for (int n : nums3) cout << n << " ";
    cout << endl;
    cout << "Maximum coins: " << sol.maxCoins(nums3) << endl;
    
    return 0;
}

/*
EXPLANATION:

BURST BALLOONS - Mind-bending Interval DP!

KEY INSIGHT - Think BACKWARDS!
Instead of thinking "which balloon to burst first?"
Think: "which balloon to burst LAST?"

WHY?
If we burst first: neighbors keep changing (hard to track)
If we burst last: neighbors are fixed (easy to compute)!

EXAMPLE:
[3, 1, 5, 8]

Add boundary balloons: [1, 3, 1, 5, 8, 1]

If balloon 5 (index 3) is burst LAST in range (0, 5):
- Its neighbors at burst time: 1 (left boundary) and 1 (right boundary)
- Coins from bursting 5: 1 * 5 * 1 = 5
- Plus coins from left subproblem: (0, 3)
- Plus coins from right subproblem: (3, 5)

RECURRENCE:
dp[i][j] = max coins from bursting all balloons in open interval (i, j)

dp[i][j] = max(arr[i] * arr[k] * arr[j] + dp[i][k] + dp[k][j])
           for all k from i+1 to j-1

Where k is the LAST balloon to burst in range (i, j)

CRUCIAL POINTS:
1. Add virtual balloons with value 1 at boundaries
2. Open interval (i, j) means balloons between i and j
3. When k is burst last, its neighbors are i and j (not others!)

EXAMPLE TRACE:
nums = [3, 1, 5, 8]
arr = [1, 3, 1, 5, 8, 1] (with boundaries)

Base case: dp[i][i+1] = 0 (no balloons in between)

Length 1: (one balloon in between)
dp[0][2]: k=1 → 1*3*1 = 3
dp[1][3]: k=2 → 3*1*5 = 15
dp[2][4]: k=3 → 1*5*8 = 40
dp[3][5]: k=4 → 5*8*1 = 40

Length 2: (two balloons)
dp[0][3]: 
  k=1: 1*3*5 + dp[0][1] + dp[1][3] = 15 + 0 + 15 = 30
  k=2: 1*1*5 + dp[0][2] + dp[2][3] = 5 + 3 + 0 = 8
  max = 30

And so on...

Final answer: dp[0][n+1]

WHY THIS WORKS:
Because we choose the LAST balloon:
- Its neighbors don't change
- Subproblems are independent
- No need to track changing neighbors

PATTERN RECOGNITION:
- Try all split points → Partition DP
- Order matters → Think backwards
- Similar to: Matrix Chain Multiplication

COMMON MISTAKES:
1. Thinking about which to burst first (wrong!)
2. Forgetting boundary balloons
3. Not understanding open interval (i, j)

INTERVIEW TIP:
"I'll think backwards - which balloon bursts last. This fixes its neighbors
and allows independent subproblems. Time: O(n³), Space: O(n²)."

SIMILAR PROBLEMS:
- Matrix Chain Multiplication
- Minimum Score Triangulation
- Remove Boxes

OUTPUT:
Test Case 1:
Balloons: 3 1 5 8
Maximum coins: 167

Test Case 2:
Balloons: 1 5
Maximum coins: 10

Test Case 3:
Balloons: 8 2 6 8 9 8 1 4 1 5 3 0 7 7 0 4 2 2
Maximum coins: 3630
*/
