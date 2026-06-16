/*
PROBLEM: Power(x, n)
---------------------------------------------------------------------------
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

DIFFICULTY: Easy-Medium
PATTERN: Divide and Conquer Recursion
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(log n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Explanation: 2^10 = 1024

Example 2:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/(2^2) = 1/4 = 0.25
*/

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    
private:
    double fastPow(double x, long long n) {
        // Base case
        if (n == 0) {
            return 1.0;
        }
        
        // Recursive case - divide and conquer
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
    
    // Test case 1
    double x1 = 2.0;
    int n1 = 10;
    cout << "Test 1: " << x1 << "^" << n1 << " = " << sol.myPow(x1, n1) << endl;
    
    // Test case 2
    double x2 = 2.0;
    int n2 = -2;
    cout << "Test 2: " << x2 << "^" << n2 << " = " << sol.myPow(x2, n2) << endl;
    
    return 0;
}
