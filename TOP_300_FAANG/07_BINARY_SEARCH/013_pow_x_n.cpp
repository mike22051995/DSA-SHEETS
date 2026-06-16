/*
================================================================================
PROBLEM: Pow(x, n) (LeetCode #50)
DIFFICULTY: Medium
PATTERN: Binary Search / Recursion / Math
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Implement pow(x, n), which returns x raised to the power n. n can be negative.

EXAMPLES:
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000

CODE EXPLANATION:
- Use fast exponentiation: square the base and halve the exponent each step.
- If the exponent is negative, invert the base and use its absolute value.
- Multiply the result when the current bit of the exponent is 1.
TIME COMPLEXITY: O(log |n|)
SPACE COMPLEXITY: O(1) iterative, O(log |n|) recursive
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Iterative approach
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double currentProduct = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= currentProduct;
            }
            currentProduct *= currentProduct;
            N /= 2;
        }
        
        return result;
    }
    
    // Recursive approach
    double myPowRecursive(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return fastPow(x, N);
    }
    
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        
        double half = fastPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};

int main() {
    Solution sol;
    
    cout << "2.0^10 = " << sol.myPow(2.0, 10) << endl;
    cout << "2.1^3 = " << sol.myPow(2.1, 3) << endl;
    cout << "2.0^-2 = " << sol.myPow(2.0, -2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sqrt(x) (LeetCode #69)
2. Super Pow (LeetCode #372)
3. Valid Perfect Square (LeetCode #367)
4. Count Primes (LeetCode #204)
5. Divide Two Integers (LeetCode #29)
6. Fibonacci Number (LeetCode #509)
7. Climbing Stairs (LeetCode #70)
8. Nth Tribonacci Number (LeetCode #1137)
9. K-th Symbol in Grammar (LeetCode #779)
10. Minimum Non-Zero Product (LeetCode #1969)
*/
