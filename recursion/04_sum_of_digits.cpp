/*
PROBLEM: Sum of Digits
---------------------------------------------------------------------------
Given a non-negative integer n, return the sum of its digits using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(log₁₀ n) - number of digits
SPACE COMPLEXITY: O(log₁₀ n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 1234
Output: 10
Explanation: 1 + 2 + 3 + 4 = 10

Example 2:
Input: n = 999
Output: 27
Explanation: 9 + 9 + 9 = 27
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int sumOfDigits(int n) {
        // Base case
        if (n == 0) {
            return 0;
        }
        
        // Recursive case
        return (n % 10) + sumOfDigits(n / 10);
    }
    
    // Alternative: handle negative numbers
    int sumOfDigitsAbs(int n) {
        n = abs(n);
        if (n == 0) {
            return 0;
        }
        return (n % 10) + sumOfDigitsAbs(n / 10);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 1234;
    cout << "Test 1: Sum of digits of " << n1 << " = " << sol.sumOfDigits(n1) << endl;
    
    // Test case 2
    int n2 = 999;
    cout << "Test 2: Sum of digits of " << n2 << " = " << sol.sumOfDigits(n2) << endl;
    
    return 0;
}
