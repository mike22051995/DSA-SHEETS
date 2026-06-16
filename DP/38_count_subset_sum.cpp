/*
PROBLEM: Count Subset with Given Sum
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack - Counting Variant

DESCRIPTION:
Given an array of non-negative integers and a target sum, count the number 
of subsets whose sum equals the target.

EXAMPLE:
Input: arr[] = {1, 1, 2, 3}, sum = 4
Output: 3
Explanation: {1, 3}, {1, 3}, {1, 1, 2}

Input: arr[] = {1, 2, 3, 3}, sum = 6
Output: 3
Explanation: {1, 2, 3}, {1, 2, 3}, {3, 3}

Input: arr[] = {2, 3, 5, 6, 8, 10}, sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

TIME COMPLEXITY: O(n * sum)
SPACE COMPLEXITY: O(sum)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: 1D DP (Space Optimized)
    int countSubsets(vector<int>& arr, int targetSum) {
        int n = arr.size();
        
        // dp[sum] = number of subsets with this sum
        vector<int> dp(targetSum + 1, 0);
        dp[0] = 1;  // Empty subset
        
        // For each element
        for (int i = 0; i < n; i++) {
            // Traverse right to left (0/1 knapsack)
            for (int sum = targetSum; sum >= arr[i]; sum--) {
                dp[sum] += dp[sum - arr[i]];
            }
        }
        
        return dp[targetSum];
    }
    
    // Approach 2: 2D DP (More intuitive)
    int countSubsets2D(vector<int>& arr, int targetSum) {
        int n = arr.size();
        
        // dp[i][j] = count of subsets using first i elements with sum j
        vector<vector<int>> dp(n+1, vector<int>(targetSum+1, 0));
        
        // Base case: empty subset has sum 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= targetSum; sum++) {
                // Don't include current element
                dp[i][sum] = dp[i-1][sum];
                
                // Include current element
                if (arr[i-1] <= sum) {
                    dp[i][sum] += dp[i-1][sum - arr[i-1]];
                }
            }
        }
        
        return dp[n][targetSum];
    }
    
    // Approach 3: Recursion with Memoization
    int countSubsetsHelper(vector<int>& arr, int n, int sum, 
                          vector<vector<int>>& dp) {
        // Base cases
        if (sum == 0) return 1;  // Found a subset
        if (n == 0) return 0;     // No elements left
        
        if (dp[n][sum] != -1) return dp[n][sum];
        
        // Don't include current element
        int exclude = countSubsetsHelper(arr, n-1, sum, dp);
        
        // Include current element
        int include = 0;
        if (arr[n-1] <= sum) {
            include = countSubsetsHelper(arr, n-1, sum - arr[n-1], dp);
        }
        
        return dp[n][sum] = include + exclude;
    }
    
    int countSubsetsMemo(vector<int>& arr, int targetSum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(targetSum+1, -1));
        return countSubsetsHelper(arr, n, targetSum, dp);
    }
    
    // Bonus: Print all subsets
    void printSubsetsHelper(vector<int>& arr, int index, int sum, 
                           vector<int>& current, vector<vector<int>>& result) {
        if (sum == 0) {
            result.push_back(current);
            return;
        }
        
        if (index >= arr.size() || sum < 0) return;
        
        // Include current element
        current.push_back(arr[index]);
        printSubsetsHelper(arr, index+1, sum - arr[index], current, result);
        current.pop_back();
        
        // Exclude current element
        printSubsetsHelper(arr, index+1, sum, current, result);
    }
    
    vector<vector<int>> getAllSubsets(vector<int>& arr, int targetSum) {
        vector<vector<int>> result;
        vector<int> current;
        printSubsetsHelper(arr, 0, targetSum, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {1, 1, 2, 3};
    int sum1 = 4;
    cout << "Array: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    cout << "Target sum: " << sum1 << endl;
    cout << "Count (1D DP): " << sol.countSubsets(arr1, sum1) << endl;
    cout << "Count (2D DP): " << sol.countSubsets2D(arr1, sum1) << endl;
    cout << "Count (Memo): " << sol.countSubsetsMemo(arr1, sum1) << endl;
    
    cout << "All subsets:" << endl;
    vector<vector<int>> subsets1 = sol.getAllSubsets(arr1, sum1);
    for (const auto& subset : subsets1) {
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size()-1) cout << ", ";
        }
        cout << "}" << endl;
    }
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {1, 2, 3, 3};
    int sum2 = 6;
    cout << "Array: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    cout << "Target sum: " << sum2 << endl;
    cout << "Count: " << sol.countSubsets(arr2, sum2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {2, 3, 5, 6, 8, 10};
    int sum3 = 10;
    cout << "Array: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    cout << "Target sum: " << sum3 << endl;
    cout << "Count: " << sol.countSubsets(arr3, sum3) << endl;
    
    cout << "All subsets:" << endl;
    vector<vector<int>> subsets3 = sol.getAllSubsets(arr3, sum3);
    for (const auto& subset : subsets3) {
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size()-1) cout << ", ";
        }
        cout << "}" << endl;
    }
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    vector<int> arr4 = {1, 1, 1, 1};
    int sum4 = 2;
    cout << "Array: ";
    for (int x : arr4) cout << x << " ";
    cout << endl;
    cout << "Target sum: " << sum4 << endl;
    cout << "Count: " << sol.countSubsets(arr4, sum4) << endl;
    
    return 0;
}

/*
EXPLANATION:

COUNT SUBSET WITH GIVEN SUM - Classic Counting DP

PROBLEM:
Count how many subsets have sum equal to target.

KEY DIFFERENCE FROM SUBSET SUM:
- Subset sum: Can we make sum? (Boolean)
- Count subsets: How many ways? (Integer)

RECURRENCE:
dp[sum] = number of ways to make this sum

For each element:
    dp[sum] += dp[sum - element]

Why +=? Because we're COUNTING, not just checking existence!

EXAMPLE TRACE:
arr = [1, 2, 3], target = 4

Initial: dp = [1, 0, 0, 0, 0]
         (one way to make 0: empty subset)

After 1: dp = [1, 1, 0, 0, 0]
         (0: {}, 1: {1})

After 2: dp = [1, 1, 1, 1, 0]
         (0: {}
          1: {1}
          2: {2}
          3: {1,2})

After 3: dp = [1, 1, 1, 2, 1]
         (0: {}
          1: {1}
          2: {2}
          3: {3}, {1,2}
          4: {1,3})

Answer: dp[4] = 1

ANOTHER EXAMPLE:
arr = [1, 1, 2, 3], target = 4

Initial: dp = [1, 0, 0, 0, 0]

After 1st '1': dp = [1, 1, 0, 0, 0]
After 2nd '1': dp = [1, 2, 1, 0, 0]
               (two 1's give 2 ways to make sum=2)

After 2: dp = [1, 2, 2, 2, 1]
After 3: dp = [1, 2, 2, 3, 3]

Wait, let me retrace more carefully:

arr = [1, 1, 2, 3], target = 4

Initial: dp[0]=1, others=0

After arr[0]=1:
  dp[1] += dp[0] = 0+1 = 1
  Result: [1, 1, 0, 0, 0]

After arr[1]=1:
  dp[2] += dp[1] = 0+1 = 1
  dp[1] += dp[0] = 1+1 = 2
  Result: [1, 2, 1, 0, 0]

After arr[2]=2:
  dp[4] += dp[2] = 0+1 = 1
  dp[3] += dp[1] = 0+2 = 2
  dp[2] += dp[0] = 1+1 = 2
  Result: [1, 2, 2, 2, 1]

After arr[3]=3:
  dp[4] += dp[1] = 1+2 = 3
  dp[3] += dp[0] = 2+1 = 3
  Result: [1, 2, 2, 3, 3]

Answer: 3 subsets with sum 4:
1. {1, 3} (first 1)
2. {1, 3} (second 1)
3. {1, 1, 2}

WHY RIGHT TO LEFT?
To avoid using same element multiple times!

If we go left to right:
  dp[2] = dp[1] = 1
  dp[3] = dp[2] = 1  (but dp[2] was just updated!)
  
This would count {1, 1, 1} when we only have one 1!

Right to left ensures we use old values only.

2D DP VERSION:
dp[i][j] = count using first i elements with sum j

dp[i][j] = dp[i-1][j]              (don't use element i)
         + dp[i-1][j-arr[i-1]]     (use element i)

PATTERN RECOGNITION:
- Count ways → Add counts
- 0/1 Knapsack → Traverse right to left
- DP counting → Initialize dp[0] = 1

SIMILAR PROBLEMS:
- Target Sum (assign +/-)
- Coin Change II (count ways)
- Combination Sum IV (permutations)

INTERVIEW TIP:
"This is counting variant of subset sum. Instead of OR,
I use addition to count all ways. Base case: one way to
make sum 0 (empty subset)."

COMPLEXITY:
Time: O(n * sum)
Space: O(sum) with 1D, O(n*sum) with 2D

EDGE CASES:
1. Target sum = 0: return 1 (empty subset)
2. Target > total sum: return 0
3. Duplicate elements: count separately

OUTPUT:
Test Case 1:
Array: 1 1 2 3
Target sum: 4
Count (1D DP): 3
Count (2D DP): 3
Count (Memo): 3
All subsets:
{1, 3}
{1, 3}
{1, 1, 2}

Test Case 2:
Array: 1 2 3 3
Target sum: 6
Count: 3

Test Case 3:
Array: 2 3 5 6 8 10
Target sum: 10
Count: 3
All subsets:
{2, 3, 5}
{2, 8}
{10}

Test Case 4:
Array: 1 1 1 1
Target sum: 2
Count: 6
*/
