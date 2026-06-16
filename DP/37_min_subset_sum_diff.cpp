/*
PROBLEM: Minimum Subset Sum Difference
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack Variant / Partition DP

DESCRIPTION:
Given a set of integers, partition it into two subsets S1 and S2 such that 
the difference of the sum of elements between S1 and S2 is minimized.

Return the minimum possible absolute difference.

EXAMPLE:
Input: arr[] = {1, 6, 11, 5}
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum = 12
Subset2 = {11}, sum = 11
Difference = |12-11| = 1

Input: arr[] = {1, 2, 3, 4}
Output: 0
Explanation:
Subset1 = {1, 4}, sum = 5
Subset2 = {2, 3}, sum = 5
Difference = 0

Input: arr[] = {1, 5, 11, 5}
Output: 0
Explanation:
Subset1 = {1, 5, 5}, sum = 11
Subset2 = {11}, sum = 11

TIME COMPLEXITY: O(n * sum)
SPACE COMPLEXITY: O(sum)
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using Subset Sum DP
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // dp[i] = true if sum i is achievable
        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;  // Empty subset
        
        // Standard subset sum
        for (int num : arr) {
            for (int sum = totalSum; sum >= num; sum--) {
                dp[sum] = dp[sum] || dp[sum - num];
            }
        }
        
        // Find minimum difference
        // If S1 has sum i, then S2 has sum (totalSum - i)
        // Difference = |i - (totalSum - i)| = |2*i - totalSum|
        int minDiff = INT_MAX;
        
        for (int i = 0; i <= totalSum / 2; i++) {
            if (dp[i]) {
                int diff = totalSum - 2 * i;
                minDiff = min(minDiff, diff);
            }
        }
        
        return minDiff;
    }
    
    // Approach 2: 2D DP (More intuitive)
    int minDifference2D(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // dp[i][j] = true if sum j is achievable using first i elements
        vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1, false));
        
        // Base case: sum 0 is always achievable
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= totalSum; sum++) {
                // Don't include current element
                dp[i][sum] = dp[i-1][sum];
                
                // Include current element
                if (arr[i-1] <= sum) {
                    dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i-1]];
                }
            }
        }
        
        // Find minimum difference
        int minDiff = INT_MAX;
        
        for (int i = 0; i <= totalSum / 2; i++) {
            if (dp[n][i]) {
                minDiff = min(minDiff, totalSum - 2 * i);
            }
        }
        
        return minDiff;
    }
    
    // Approach 3: Get actual partitions
    pair<vector<int>, vector<int>> getPartitions(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1, false));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= totalSum; sum++) {
                dp[i][sum] = dp[i-1][sum];
                if (arr[i-1] <= sum) {
                    dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i-1]];
                }
            }
        }
        
        // Find closest sum to totalSum/2
        int target = totalSum / 2;
        while (target >= 0 && !dp[n][target]) {
            target--;
        }
        
        // Backtrack to find elements
        vector<int> subset1, subset2;
        int i = n, sum = target;
        
        while (i > 0 && sum > 0) {
            // Check if current element was included
            if (sum >= arr[i-1] && dp[i-1][sum - arr[i-1]]) {
                subset1.push_back(arr[i-1]);
                sum -= arr[i-1];
            } else {
                subset2.push_back(arr[i-1]);
            }
            i--;
        }
        
        // Add remaining elements to subset2
        while (i > 0) {
            subset2.push_back(arr[i-1]);
            i--;
        }
        
        return {subset1, subset2};
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {1, 6, 11, 5};
    cout << "Array: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    cout << "Minimum difference: " << sol.minDifference(arr1) << endl;
    
    auto [s1_1, s2_1] = sol.getPartitions(arr1);
    cout << "Subset 1: ";
    int sum1_1 = 0;
    for (int x : s1_1) {
        cout << x << " ";
        sum1_1 += x;
    }
    cout << " (sum = " << sum1_1 << ")" << endl;
    
    cout << "Subset 2: ";
    int sum2_1 = 0;
    for (int x : s2_1) {
        cout << x << " ";
        sum2_1 += x;
    }
    cout << " (sum = " << sum2_1 << ")" << endl;
    cout << "Difference: " << abs(sum1_1 - sum2_1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {1, 2, 3, 4};
    cout << "Array: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    cout << "Minimum difference: " << sol.minDifference(arr2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {1, 5, 11, 5};
    cout << "Array: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    cout << "Minimum difference (1D): " << sol.minDifference(arr3) << endl;
    cout << "Minimum difference (2D): " << sol.minDifference2D(arr3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    vector<int> arr4 = {3, 1, 4, 2, 2, 1};
    cout << "Array: ";
    for (int x : arr4) cout << x << " ";
    cout << endl;
    cout << "Minimum difference: " << sol.minDifference(arr4) << endl;
    
    return 0;
}

/*
EXPLANATION:

MINIMUM SUBSET SUM DIFFERENCE - Beautiful Knapsack Application!

KEY INSIGHT:
If we partition array into S1 and S2:
  sum(S1) + sum(S2) = totalSum
  
We want to minimize: |sum(S1) - sum(S2)|

Let sum(S1) = x, then sum(S2) = totalSum - x
Difference = |x - (totalSum - x)| = |2x - totalSum|

To minimize difference:
Choose x closest to totalSum/2

APPROACH:
1. Find all possible subset sums using 0/1 Knapsack
2. Find largest sum ≤ totalSum/2 that's achievable
3. That gives minimum difference

EXAMPLE:
arr = [1, 6, 11, 5], totalSum = 23

Possible sums:
0, 1, 5, 6, 7, 11, 12, 16, 17, 18, 22, 23

Target = 23/2 = 11 (rounded down)
Sums ≤ 11: 0, 1, 5, 6, 7, 11
Closest to 11: 11

If S1 has sum 11:
  S2 has sum 23-11 = 12
  Difference = |11-12| = 1 ✓

SUBSET SUM DP:
dp[sum] = true if sum is achievable

For each number:
  for sum from totalSum down to num:
    dp[sum] = dp[sum] || dp[sum - num]

Why reverse? To ensure each element used only once (0/1 knapsack)

FINDING MINIMUM:
Iterate from totalSum/2 down to 0:
  First achievable sum is the answer
  Difference = totalSum - 2*sum

ALTERNATIVE FORMULA:
Since we know S1 + S2 = totalSum:
If S1 = i, then S2 = totalSum - i
We want: min(|i - (totalSum - i)|) = min(|2i - totalSum|)

For minimum:
Choose largest i ≤ totalSum/2 where dp[i] = true

EXAMPLE TRACE:
arr = [1, 2, 3, 4], totalSum = 10

Initial: dp[0] = true

After 1: dp[0]=T, dp[1]=T
After 2: dp[0]=T, dp[1]=T, dp[2]=T, dp[3]=T
After 3: dp[0..6]=T
After 4: dp[0..10]=T

All sums achievable! Choose i = 5 (half of 10)
Difference = 10 - 2*5 = 0 ✓

PATTERN CONNECTION:
- Partition array → Subset sum
- Minimize difference → Choose closest to half
- 0/1 Knapsack → Each element once

SIMILAR PROBLEMS:
- Equal Sum Partition (difference = 0?)
- Count Subset Sum (count ways)
- Target Sum (assign +/-)

INTERVIEW TIP:
"This reduces to subset sum. Find largest achievable sum 
≤ totalSum/2. That minimizes |2*sum - totalSum|."

COMPLEXITY:
Time: O(n * sum) where sum = total of all elements
Space: O(sum) with 1D array, O(n*sum) with 2D

EDGE CASES:
1. All equal elements: difference = 0 or 1 element
2. One large element: might dominate
3. Odd total sum: minimum difference ≥ 1

OUTPUT:
Test Case 1:
Array: 1 6 11 5
Minimum difference: 1
Subset 1: 11 1 (sum = 12)
Subset 2: 5 6 (sum = 11)
Difference: 1

Test Case 2:
Array: 1 2 3 4
Minimum difference: 0

Test Case 3:
Array: 1 5 11 5
Minimum difference (1D): 0
Minimum difference (2D): 0

Test Case 4:
Array: 3 1 4 2 2 1
Minimum difference: 1
*/
