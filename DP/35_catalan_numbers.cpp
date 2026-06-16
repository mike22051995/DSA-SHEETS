/*
PROBLEM: Catalan Numbers
DIFFICULTY: Medium
PATTERN: Combinatorial DP / Partition DP

DESCRIPTION:
Catalan numbers form a sequence of natural numbers that occur in many counting problems.
The nth Catalan number counts:
1. Number of valid parentheses expressions with n pairs
2. Number of binary search trees with n nodes
3. Number of ways to triangulate a polygon with n+2 sides
4. Number of paths in grid that don't cross diagonal
5. And many more...

Formula: C(n) = (2n)! / ((n+1)! * n!)
Or: C(n) = Σ C(i) * C(n-1-i) for i from 0 to n-1

EXAMPLE:
C(0) = 1
C(1) = 1
C(2) = 2  ((), ()())
C(3) = 5  ((())) (()()), (())(), ()(()), ()()())
C(4) = 14
C(5) = 42

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Approach 1: Direct Formula using Binomial Coefficient
    unsigned long long catalanFormula(int n) {
        if (n <= 1) return 1;
        
        // C(n) = (2n)! / ((n+1)! * n!)
        // = C(2n, n) / (n+1)
        unsigned long long result = 1;
        
        // Calculate C(2n, n)
        for (int i = 0; i < n; i++) {
            result = result * (2*n - i) / (i + 1);
        }
        
        return result / (n + 1);
    }
    
    // Approach 2: Dynamic Programming (Recurrence)
    // C(n) = Σ C(i) * C(n-1-i) for i from 0 to n-1
    unsigned long long catalanDP(int n) {
        if (n <= 1) return 1;
        
        vector<unsigned long long> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        
        return dp[n];
    }
    
    // Approach 3: Recursion with Memoization
    unsigned long long catalanMemo(int n, vector<unsigned long long>& memo) {
        if (n <= 1) return 1;
        
        if (memo[n] != 0) return memo[n];
        
        unsigned long long result = 0;
        for (int i = 0; i < n; i++) {
            result += catalanMemo(i, memo) * catalanMemo(n-1-i, memo);
        }
        
        return memo[n] = result;
    }
    
    unsigned long long catalanMemoWrapper(int n) {
        vector<unsigned long long> memo(n+1, 0);
        return catalanMemo(n, memo);
    }
    
    // Application 1: Generate Valid Parentheses
    void generateParenthesesHelper(int open, int close, string current, 
                                   vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        if (open > 0) {
            generateParenthesesHelper(open-1, close, current + '(', result);
        }
        
        if (close > open) {
            generateParenthesesHelper(open, close-1, current + ')', result);
        }
    }
    
    vector<string> generateParentheses(int n) {
        vector<string> result;
        generateParenthesesHelper(n, n, "", result);
        return result;
    }
    
    // Application 2: Number of BSTs with n nodes
    int numBSTs(int n) {
        return catalanDP(n);
    }
    
    // Application 3: Ways to triangulate polygon
    int numTriangulations(int n) {
        // n-sided polygon = C(n-2)
        return catalanDP(n - 2);
    }
};

int main() {
    Solution sol;
    
    cout << "=== CATALAN NUMBERS ===" << endl << endl;
    
    // Print first 10 Catalan numbers
    cout << "First 10 Catalan Numbers:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "C(" << i << ") = " << sol.catalanDP(i) << endl;
    }
    
    cout << "\n=== VERIFICATION ===" << endl;
    int n = 5;
    cout << "C(" << n << ") using different methods:" << endl;
    cout << "Formula: " << sol.catalanFormula(n) << endl;
    cout << "DP: " << sol.catalanDP(n) << endl;
    cout << "Memoization: " << sol.catalanMemoWrapper(n) << endl;
    
    cout << "\n=== APPLICATION: Valid Parentheses ===" << endl;
    int pairs = 3;
    cout << "Valid parentheses with " << pairs << " pairs:" << endl;
    vector<string> parens = sol.generateParentheses(pairs);
    for (const string& p : parens) {
        cout << p << endl;
    }
    cout << "Count: " << parens.size() << " = C(" << pairs << ")" << endl;
    
    cout << "\n=== APPLICATION: Number of BSTs ===" << endl;
    int nodes = 4;
    cout << "Number of BSTs with " << nodes << " nodes: " << sol.numBSTs(nodes) << endl;
    
    cout << "\n=== APPLICATION: Polygon Triangulation ===" << endl;
    int sides = 5;
    cout << "Ways to triangulate " << sides << "-sided polygon: " 
         << sol.numTriangulations(sides) << endl;
    
    return 0;
}

/*
EXPLANATION:

CATALAN NUMBERS - Beautiful Combinatorial Sequence

DEFINITION:
C(n) = (2n)! / ((n+1)! * n!)

RECURRENCE:
C(0) = 1
C(n) = Σ C(i) * C(n-1-i) for i from 0 to n-1
     = C(0)*C(n-1) + C(1)*C(n-2) + ... + C(n-1)*C(0)

WHY THIS RECURRENCE?
Think of valid parentheses with n pairs:
- First '(' at position 0
- Its matching ')' at position 2k+1
- Inside: k pairs (C(k) ways)
- After: n-k-1 pairs (C(n-k-1) ways)

EXAMPLE: n=3
C(3) = C(0)*C(2) + C(1)*C(1) + C(2)*C(0)
     = 1*2 + 1*1 + 2*1
     = 5

The 5 valid expressions:
1. ((())) - all inside first pair
2. (()()) - 1 inside, 1 after
3. (())() - 1 inside, 1 after (different arrangement)
4. ()(()) - 0 inside, 2 after
5. ()()() - all after

APPLICATIONS:

1. VALID PARENTHESES:
   C(n) = number of valid expressions with n pairs
   
2. BINARY SEARCH TREES:
   C(n) = number of BSTs with n nodes
   Why? For root at position i:
   - Left subtree: i-1 nodes (C(i-1) ways)
   - Right subtree: n-i nodes (C(n-i) ways)
   Total: Σ C(i-1) * C(n-i) = C(n)

3. POLYGON TRIANGULATION:
   C(n-2) = ways to triangulate n-sided polygon
   Choose one edge, divide into triangle and remaining

4. MOUNTAIN RANGES:
   C(n) = paths from (0,0) to (2n,0) with n up-steps
          and n down-steps, never going below x-axis

5. BINARY TREES:
   C(n) = number of full binary trees with n+1 leaves

6. DYCK PATHS:
   C(n) = lattice paths from (0,0) to (n,n) that
          don't cross diagonal

PATTERN IN RECURRENCE:
"Split into two parts, multiply counts"

Example in BST:
Root divides into left and right subtrees
Ways = (ways for left) × (ways for right)

INTERVIEW TIP:
"Catalan numbers count structures that can be recursively 
divided. The recurrence sums over all split points."

COMPLEXITY:
Formula: O(n) time, O(1) space
DP: O(n²) time, O(n) space
Memo: O(n²) time, O(n) space

SEQUENCE:
C(0)=1, C(1)=1, C(2)=2, C(3)=5, C(4)=14, C(5)=42, C(6)=132...

RELATED PROBLEMS:
- Generate Parentheses (LeetCode 22)
- Unique Binary Search Trees (LeetCode 96)
- Unique BST II (LeetCode 95)

RECOGNITION IN INTERVIEWS:
If problem asks for:
- "Count ways to..."
- "Valid arrangements..."
- "Binary trees with..."
- "Partition into pairs..."

Think: Could this be Catalan?

OUTPUT:
=== CATALAN NUMBERS ===

First 10 Catalan Numbers:
C(0) = 1
C(1) = 1
C(2) = 2
C(3) = 5
C(4) = 14
C(5) = 42
C(6) = 132
C(7) = 429
C(8) = 1430
C(9) = 4862
C(10) = 16796

=== VERIFICATION ===
C(5) using different methods:
Formula: 42
DP: 42
Memoization: 42

=== APPLICATION: Valid Parentheses ===
Valid parentheses with 3 pairs:
((()))
(()())
(())()
()(())
()()()
Count: 5 = C(3)

=== APPLICATION: Number of BSTs ===
Number of BSTs with 4 nodes: 14

=== APPLICATION: Polygon Triangulation ===
Ways to triangulate 5-sided polygon: 5
*/
