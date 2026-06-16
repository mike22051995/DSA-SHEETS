/*
PROBLEM: Count Digits
---------------------------------------------------------------------------
Given a non-negative integer n, count the number of digits using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(log₁₀ n)
SPACE COMPLEXITY: O(log₁₀ n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 12345
Output: 5
Explanation: The number has 5 digits

Example 2:
Input: n = 7
Output: 1
Explanation: Single digit number
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        // Base case
        if (n < 10) {
            return 1;
        }
        
        // Recursive case
        return 1 + countDigits(n / 10);
    }
    
    // Handle zero and negative numbers
    int countDigitsComplete(int n) {
        if (n == 0) {
            return 1;
        }
        
        n = abs(n);
        if (n < 10) {
            return 1;
        }
        
        return 1 + countDigitsComplete(n / 10);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 12345;
    cout << "Test 1: Number of digits in " << n1 << " = " << sol.countDigits(n1) << endl;
    
    // Test case 2
    int n2 = 7;
    cout << "Test 2: Number of digits in " << n2 << " = " << sol.countDigits(n2) << endl;
    
    return 0;
}
