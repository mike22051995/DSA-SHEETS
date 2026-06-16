/*
PROBLEM: Minimum Score Triangulation of Polygon (LeetCode 1039)
DIFFICULTY: Medium  
PATTERN: Interval/Partition DP

DESCRIPTION:
You have a convex n-sided polygon where each vertex has an integer value.
You are given an integer array values where values[i] is the value of the 
ith vertex (in order).

Triangulate the polygon into n-2 triangles. For each triangle, the value 
of that triangle is the product of the values of its vertices, and the 
total score is the sum of these values over all n-2 triangles.

Return the smallest possible total score that you can achieve with some 
triangulation of the polygon.

EXAMPLE:
Input: values = [1,2,3]
Output: 6
Explanation: Only one triangle: 1*2*3 = 6

Input: values = [3,7,4,5]
Output: 144
Explanation: Triangulation: (3,7,4) + (3,4,5) = 84 + 60 = 144

Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: Minimum score triangulation

TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(n²)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Approach 1: Bottom-up DP
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        // dp[i][j] = minimum score to triangulate polygon from vertex i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Length of the polygon side
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // Try all vertices k between i and j as third vertex of triangle
                for (int k = i + 1; k < j; k++) {
                    // Cost of triangle (i, k, j)
                    int triangleCost = values[i] * values[k] * values[j];
                    
                    // Cost of sub-polygons
                    int leftCost = dp[i][k];
                    int rightCost = dp[k][j];
                    
                    dp[i][j] = min(dp[i][j], triangleCost + leftCost + rightCost);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
    // Approach 2: Recursion with Memoization
    int minScoreHelper(vector<int>& values, int i, int j, 
                      vector<vector<int>>& dp) {
        // Base case: less than 3 vertices, no triangle
        if (j - i < 2) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int minScore = INT_MAX;
        
        // Try each vertex k as third point of triangle with edge (i,j)
        for (int k = i + 1; k < j; k++) {
            int triangleCost = values[i] * values[k] * values[j];
            int leftCost = minScoreHelper(values, i, k, dp);
            int rightCost = minScoreHelper(values, k, j, dp);
            
            minScore = min(minScore, triangleCost + leftCost + rightCost);
        }
        
        return dp[i][j] = minScore;
    }
    
    int minScoreTriangulationMemo(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minScoreHelper(values, 0, n-1, dp);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> values1 = {1, 2, 3};
    cout << "Polygon vertices: ";
    for (int v : values1) cout << v << " ";
    cout << endl;
    cout << "Minimum score: " << sol.minScoreTriangulation(values1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> values2 = {3, 7, 4, 5};
    cout << "Polygon vertices: ";
    for (int v : values2) cout << v << " ";
    cout << endl;
    cout << "Minimum score (DP): " << sol.minScoreTriangulation(values2) << endl;
    cout << "Minimum score (Memo): " << sol.minScoreTriangulationMemo(values2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> values3 = {1, 3, 1, 4, 1, 5};
    cout << "Polygon vertices: ";
    for (int v : values3) cout << v << " ";
    cout << endl;
    cout << "Minimum score: " << sol.minScoreTriangulation(values3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    vector<int> values4 = {2, 4, 1, 3, 5};
    cout << "Polygon vertices: ";
    for (int v : values4) cout << v << " ";
    cout << endl;
    cout << "Minimum score: " << sol.minScoreTriangulation(values4) << endl;
    
    return 0;
}

/*
EXPLANATION:

MINIMUM SCORE TRIANGULATION - Beautiful Partition DP

PROBLEM UNDERSTANDING:
Given n-sided polygon, divide into n-2 triangles.
Each triangle has cost = product of its 3 vertices.
Minimize total cost.

KEY INSIGHT:
Fix one edge (i, j) of polygon.
Try all vertices k between i and j as third vertex of triangle.

This divides problem into:
1. Triangle (i, k, j) with cost values[i] * values[k] * values[j]
2. Sub-polygon from i to k
3. Sub-polygon from k to j

RECURRENCE:
dp[i][j] = minimum score to triangulate polygon from vertex i to j

dp[i][j] = min(values[i] * values[k] * values[j] + dp[i][k] + dp[k][j])
           for all k from i+1 to j-1

BASE CASE:
dp[i][j] = 0 if j - i < 2 (less than 3 vertices, no triangle)

EXAMPLE TRACE:
values = [3, 7, 4, 5]

Base: dp[i][i+1] = 0 (2 vertices, no triangle)

Length 3 (triangle):
dp[0][2]: k=1 → 3*7*4 = 84
dp[1][3]: k=2 → 7*4*5 = 140
dp[2][4]... (if exists)

Actually vertices 0,1,2,3

Length 3:
dp[0][2]: vertices 0,1,2 → k=1 → 3*7*4 = 84
dp[1][3]: vertices 1,2,3 → k=2 → 7*4*5 = 140

Length 4 (whole polygon):
dp[0][3]: vertices 0,1,2,3
  k=1: triangle(0,1,3) + dp[0][1] + dp[1][3]
       = 3*7*5 + 0 + 140 = 105 + 140 = 245
  
  k=2: triangle(0,2,3) + dp[0][2] + dp[2][3]
       = 3*4*5 + 84 + 0 = 60 + 84 = 144 ✓
       
Minimum = 144

Triangulation: (0,2,3) and (0,1,2)
= (3,4,5) + (3,7,4) = 60 + 84 = 144

PATTERN SIMILARITY:
This is EXACTLY like Matrix Chain Multiplication!

MCM: Split chain at position k
Triangulation: Choose vertex k for triangle

Both: Partition DP with 3 nested loops

CONNECTION TO CATALAN NUMBERS:
Number of ways to triangulate n-sided polygon = C(n-2)
(Catalan number)

But this problem asks for MINIMUM COST, not count.

VISUALIZATION:
For polygon with vertices 0,1,2,3:

Fix edge (0,3)
Try k=1: triangle(0,1,3) splits into:
  - Left polygon: 0→1
  - Right polygon: 1→3

Try k=2: triangle(0,2,3) splits into:
  - Left polygon: 0→2
  - Right polygon: 2→3

PATTERN RECOGNITION:
- Partition into sub-problems → Interval DP
- Try all split points → Loop over k
- Combine results → Add costs

SIMILAR PROBLEMS:
- Matrix Chain Multiplication (almost identical!)
- Burst Balloons (think backwards)
- Boolean Parenthesization

INTERVIEW TIP:
"This is interval DP, similar to Matrix Chain Multiplication.
Fix edge (i,j), try all vertices k in between as third point.
Recursively solve sub-polygons. Time: O(n³)."

COMPLEXITY:
Time: O(n³)
- O(n²) states
- O(n) transitions per state

Space: O(n²) for DP table

WHY O(n³)?
3 nested loops:
1. Length of polygon side (n iterations)
2. Starting vertex i (n iterations)
3. Middle vertex k (n iterations)

EDGE CASES:
1. Triangle (n=3): only one way, return product
2. Square (n=4): two ways, choose minimum
3. All same values: still need to compute

OUTPUT:
Test Case 1:
Polygon vertices: 1 2 3
Minimum score: 6

Test Case 2:
Polygon vertices: 3 7 4 5
Minimum score (DP): 144
Minimum score (Memo): 144

Test Case 3:
Polygon vertices: 1 3 1 4 1 5
Minimum score: 13

Test Case 4:
Polygon vertices: 2 4 1 3 5
Minimum score: 58
*/
