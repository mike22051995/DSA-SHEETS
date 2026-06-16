/*
================================================================================
PROBLEM: Climbing Stairs (LeetCode #70)
DIFFICULTY: Easy
PATTERN: Dynamic Programming / Fibonacci
COMPANIES: Amazon, Google, Microsoft, Adobe, Apple
================================================================================

PROBLEM DESCRIPTION:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways 
can you climb to the top?

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Count number of ways to reach goal
2. Can make decision at each step
3. Current state depends on previous states
4. Fibonacci-like recurrence relation

Key Indicators:
- "How many ways" or "count combinations"
- Limited choices at each step
- Order matters (permutations)
- Can be solved with DP

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: n = 2
Output: 2
Explanation: Two ways:
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: Three ways:
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Example 3:
Input: n = 5
Output: 8
Explanation: Ways = 1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 
             2+1+1+1, 1+2+2, 2+1+2, 2+2+1

================================================================================
EXPLANATION:

Recurrence Relation:
ways(n) = ways(n-1) + ways(n-2)

Why?
- To reach step n, you can come from:
  1. Step n-1 (take 1 step)
  2. Step n-2 (take 2 steps)
- Total ways = sum of both options

Base Cases:
- ways(1) = 1 (only one 1-step)
- ways(2) = 2 (1+1 or 2)

This is actually Fibonacci sequence!

Approaches:
1. Recursion: O(2^n) time, O(n) space
2. Recursion + Memoization: O(n) time, O(n) space
3. DP (bottom-up): O(n) time, O(n) space
4. DP Space Optimized: O(n) time, O(1) space

================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Dynamic Programming (Bottom-up)
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    // Approach 2: Space Optimized DP (Best for interviews)
    int climbStairsOptimized(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1;  // ways to reach step 1
        int prev1 = 2;  // ways to reach step 2
        
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
    
    // Approach 3: Recursion with Memoization (Top-down DP)
    int climbStairsMemo(int n) {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }
    
    int helper(int n, vector<int>& memo) {
        if (n <= 2) return n;
        if (memo[n] != -1) return memo[n];
        
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
    
    // Approach 4: Pure Recursion (Not recommended - too slow)
    int climbStairsRecursive(int n) {
        if (n <= 2) return n;
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }
    
    // Approach 5: Matrix Exponentiation - O(log n)
    int climbStairsMatrix(int n) {
        if (n <= 2) return n;
        
        vector<vector<long long>> base = {{1, 1}, {1, 0}};
        vector<vector<long long>> result = matrixPower(base, n);
        
        return (int)result[0][0];
    }
    
    vector<vector<long long>> matrixPower(vector<vector<long long>>& matrix, int n) {
        if (n == 1) return matrix;
        
        if (n % 2 == 0) {
            auto half = matrixPower(matrix, n / 2);
            return matrixMultiply(half, half);
        } else {
            return matrixMultiply(matrix, matrixPower(matrix, n - 1));
        }
    }
    
    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& a, 
                                              vector<vector<long long>>& b) {
        vector<vector<long long>> result(2, vector<long long>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }
};

void runTest(int n, string testName) {
    Solution sol;
    int result = sol.climbStairsOptimized(n);
    
    cout << testName << ": " << endl;
    cout << "n = " << n << endl;
    cout << "Number of ways: " << result << endl;
    cout << "-------------------" << endl;
}

int main() {
    runTest(2, "Test 1");
    runTest(3, "Test 2");
    runTest(5, "Test 3");
    runTest(10, "Test 4");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Min Cost Climbing Stairs (LeetCode #746) - Easy
   - Each step has a cost
   - Similar DP pattern

2. Fibonacci Number (LeetCode #509) - Easy
   - Direct Fibonacci calculation

3. N-th Tribonacci Number (LeetCode #1137) - Easy
   - Sum of previous three terms

4. House Robber (LeetCode #198) - Medium
   - Can't rob adjacent houses
   - Similar DP decision

5. Decode Ways (LeetCode #91) - Medium
   - Count ways to decode string
   - Similar recurrence

6. Unique Paths (LeetCode #62) - Medium
   - Grid version of same problem

7. Jump Game (LeetCode #55) - Medium
   - Can you reach the end

8. Jump Game II (LeetCode #45) - Medium
   - Minimum jumps to reach end

9. Unique Binary Search Trees (LeetCode #96) - Medium
   - Catalan number DP

10. Counting Bits (LeetCode #338) - Easy
    - DP on bit patterns

================================================================================
KEY INSIGHTS:
================================================================================

1. Why it's Fibonacci:
   - f(n) = f(n-1) + f(n-2)
   - Starting from f(1)=1, f(2)=2
   - Sequence: 1, 2, 3, 5, 8, 13, 21...

2. DP State Definition:
   - dp[i] = number of ways to reach step i
   - Answer: dp[n]

3. Space Optimization:
   - Only need last two values
   - Reduce from O(n) to O(1) space

4. Follow-up Variations:
   - What if you can take 1, 2, or 3 steps?
     → dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
   - What if some steps are broken?
     → Skip those in calculation
   - Minimum cost to reach top?
     → Min instead of sum

5. Interview Tips:
   - Start with recursive relation
   - Show memoization improvement
   - Then bottom-up DP
   - Finally space optimization

================================================================================
COMPLEXITY ANALYSIS:
================================================================================

Approach | Time | Space | Notes
---------|------|-------|-------
Recursion | O(2^n) | O(n) | Too slow
Memoization | O(n) | O(n) | Top-down DP
DP Array | O(n) | O(n) | Bottom-up
Optimized | O(n) | O(1) | Best for interviews
Matrix | O(log n) | O(1) | Advanced

================================================================================
*/
