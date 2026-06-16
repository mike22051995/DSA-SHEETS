/*
PROBLEM: Matrix Chain Multiplication
DIFFICULTY: Hard
PATTERN: Interval/Partition DP

DESCRIPTION:
Given a sequence of matrices, find the most efficient way to multiply these matrices.
The problem is not to perform the multiplications, but to decide the sequence of 
matrix multiplications that minimizes the number of scalar multiplications.

Given array arr[] representing the dimensions of n-1 matrices such that 
dimension of ith matrix is arr[i-1] x arr[i].

EXAMPLE:
Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation: 4 matrices with dimensions:
M1: 40x20, M2: 20x30, M3: 30x10, M4: 10x30

Optimal: ((M1(M2M3))M4) = 26000 operations

Input: arr[] = {10, 20, 30}
Output: 6000
Explanation: Only one way to multiply: (M1*M2) = 10*20*30 = 6000

TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(n²)
*/

#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (TLE - for understanding)
    int matrixChainRecursive(vector<int>& arr, int i, int j) {
        // Base case: single matrix
        if (i >= j) return 0;
        
        int minOps = INT_MAX;
        
        // Try all possible split points
        for (int k = i; k < j; k++) {
            // Cost of multiplying left part
            int leftCost = matrixChainRecursive(arr, i, k);
            
            // Cost of multiplying right part
            int rightCost = matrixChainRecursive(arr, k+1, j);
            
            // Cost of multiplying the two results
            int mergeCost = arr[i-1] * arr[k] * arr[j];
            
            int totalCost = leftCost + rightCost + mergeCost;
            minOps = min(minOps, totalCost);
        }
        
        return minOps;
    }
    
    // Approach 2: Memoization
    int matrixChainMemo(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int minOps = INT_MAX;
        
        for (int k = i; k < j; k++) {
            int leftCost = matrixChainMemo(arr, i, k, dp);
            int rightCost = matrixChainMemo(arr, k+1, j, dp);
            int mergeCost = arr[i-1] * arr[k] * arr[j];
            
            int totalCost = leftCost + rightCost + mergeCost;
            minOps = min(minOps, totalCost);
        }
        
        return dp[i][j] = minOps;
    }
    
    // Approach 3: Bottom-Up DP (BEST)
    int matrixChainMultiplication(vector<int>& arr) {
        int n = arr.size();
        
        // dp[i][j] = minimum operations to multiply matrices i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // L is chain length
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;
                
                // Try all split points between i and j
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][n-1];
    }
    
    // Approach 4: With parenthesization tracking
    string matrixChainOrder(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n, 0));
        
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;  // Store split point
                    }
                }
            }
        }
        
        return getParenthesis(bracket, 1, n-1);
    }
    
    string getParenthesis(vector<vector<int>>& bracket, int i, int j) {
        if (i == j) {
            return "M" + to_string(i);
        }
        
        int k = bracket[i][j];
        string left = getParenthesis(bracket, i, k);
        string right = getParenthesis(bracket, k+1, j);
        
        return "(" + left + right + ")";
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {40, 20, 30, 10, 30};
    cout << "Matrix dimensions: ";
    for (int i = 0; i < arr1.size()-1; i++) {
        cout << "M" << i+1 << "(" << arr1[i] << "x" << arr1[i+1] << ") ";
    }
    cout << endl;
    cout << "Minimum operations: " << sol.matrixChainMultiplication(arr1) << endl;
    cout << "Parenthesization: " << sol.matrixChainOrder(arr1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {10, 20, 30};
    cout << "Matrix dimensions: ";
    for (int i = 0; i < arr2.size()-1; i++) {
        cout << "M" << i+1 << "(" << arr2[i] << "x" << arr2[i+1] << ") ";
    }
    cout << endl;
    cout << "Minimum operations: " << sol.matrixChainMultiplication(arr2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {10, 20, 30, 40, 30};
    cout << "Matrix dimensions: ";
    for (int i = 0; i < arr3.size()-1; i++) {
        cout << "M" << i+1 << "(" << arr3[i] << "x" << arr3[i+1] << ") ";
    }
    cout << endl;
    cout << "Minimum operations: " << sol.matrixChainMultiplication(arr3) << endl;
    cout << "Parenthesization: " << sol.matrixChainOrder(arr3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    vector<int> arr4 = {5, 10, 3, 12, 5, 50, 6};
    cout << "Matrix dimensions: ";
    for (int i = 0; i < arr4.size()-1; i++) {
        cout << "M" << i+1 << "(" << arr4[i] << "x" << arr4[i+1] << ") ";
    }
    cout << endl;
    cout << "Minimum operations: " << sol.matrixChainMultiplication(arr4) << endl;
    cout << "Parenthesization: " << sol.matrixChainOrder(arr4) << endl;
    
    return 0;
}

/*
EXPLANATION:

MATRIX CHAIN MULTIPLICATION - Classic Partition DP

PROBLEM UNDERSTANDING:
Matrix multiplication is associative: (A*B)*C = A*(B*C)
But the number of operations differs!

Example:
A: 10x20, B: 20x30, C: 30x40

(A*B)*C:
- A*B: 10*20*30 = 6000 ops → Result: 10x30
- Result*C: 10*30*40 = 12000 ops
Total: 18000 ops

A*(B*C):
- B*C: 20*30*40 = 24000 ops → Result: 20x40
- A*Result: 10*20*40 = 8000 ops
Total: 32000 ops

First way is better!

RECURRENCE RELATION:
dp[i][j] = minimum operations to multiply matrices i to j

dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j])
           for all k from i to j-1

Cost to multiply:
- Left chain: dp[i][k]
- Right chain: dp[k+1][j]
- Final multiplication: dimensions are arr[i-1] x arr[k] x arr[j]

EXAMPLE TRACE:
arr = {40, 20, 30, 10, 30}
Matrices: M1(40x20), M2(20x30), M3(30x10), M4(10x30)

Base case: dp[i][i] = 0 (single matrix)

Length 2:
dp[1][2] = 40*20*30 = 24000
dp[2][3] = 20*30*10 = 6000
dp[3][4] = 30*10*30 = 9000

Length 3:
dp[1][3] = min(
    dp[1][1] + dp[2][3] + 40*20*10 = 0 + 6000 + 8000 = 14000 ✓
    dp[1][2] + dp[3][3] + 40*30*10 = 24000 + 0 + 12000 = 36000
) = 14000

dp[2][4] = min(
    dp[2][2] + dp[3][4] + 20*30*30 = 0 + 9000 + 18000 = 27000
    dp[2][3] + dp[4][4] + 20*10*30 = 6000 + 0 + 6000 = 12000 ✓
) = 12000

Length 4:
dp[1][4] = min(
    dp[1][1] + dp[2][4] + 40*20*30 = 0 + 12000 + 24000 = 36000
    dp[1][2] + dp[3][4] + 40*30*30 = 24000 + 9000 + 36000 = 69000
    dp[1][3] + dp[4][4] + 40*10*30 = 14000 + 0 + 12000 = 26000 ✓
) = 26000

PATTERN RECOGNITION:
- Try all ways to split → Partition DP
- Fill diagonal by diagonal (by chain length)
- 3 nested loops: length, start, split point

SIMILAR PROBLEMS:
- Burst Balloons
- Palindrome Partitioning
- Boolean Parenthesization
- Minimum Score Triangulation

INTERVIEW TIP:
"This is interval DP. I'll try all split points and take minimum.
Time: O(n³) because 3 nested loops, Space: O(n²) for DP table."

OUTPUT:
Test Case 1:
Matrix dimensions: M1(40x20) M2(20x30) M3(30x10) M4(10x30)
Minimum operations: 26000
Parenthesization: ((M1(M2M3))M4)

Test Case 2:
Matrix dimensions: M1(10x20) M2(20x30)
Minimum operations: 6000

Test Case 3:
Matrix dimensions: M1(10x20) M2(20x30) M3(30x40) M4(40x30)
Minimum operations: 30000
Parenthesization: ((M1(M2M3))M4)

Test Case 4:
Matrix dimensions: M1(5x10) M2(10x3) M3(3x12) M4(12x5) M5(5x50) M6(50x6)
Minimum operations: 2010
Parenthesization: ((M1M2)((M3M4)(M5M6)))
*/
