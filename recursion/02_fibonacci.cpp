/*
PROBLEM: Fibonacci Number
---------------------------------------------------------------------------
The Fibonacci numbers form a sequence where each number is the sum of the 
two preceding ones, starting from 0 and 1.
F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1

DIFFICULTY: Easy
PATTERN: Multiple Recursion (Tree Recursion)
TIME COMPLEXITY: O(2^n) - naive, O(n) - memoization
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 5
Output: 5
Explanation: F(5) = F(4) + F(3) = 3 + 2 = 5

Example 2:
Input: n = 10
Output: 55
Explanation: F(10) = 55
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Naive recursion - O(2^n)
    int fibNaive(int n) {
        if (n <= 1) {
            return n;
        }
        return fibNaive(n - 1) + fibNaive(n - 2);
    }
    
    // Memoization - O(n)
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return fibMemo(n, memo);
    }
    
private:
    int fibMemo(int n, vector<int>& memo) {
        if (n <= 1) {
            return n;
        }
        
        if (memo[n] != -1) {
            return memo[n];
        }
        
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
        return memo[n];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 5;
    cout << "Test 1: F(" << n1 << ") = " << sol.fib(n1) << endl;
    
    // Test case 2
    int n2 = 10;
    cout << "Test 2: F(" << n2 << ") = " << sol.fib(n2) << endl;
    
    return 0;
}
