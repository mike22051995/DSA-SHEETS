/*
PROBLEM: Factorial of a Number
---------------------------------------------------------------------------
Given a non-negative integer n, calculate and return the factorial of n.
Factorial of n (n!) = n * (n-1) * (n-2) * ... * 1
By definition, 0! = 1

DIFFICULTY: Easy
PATTERN: Basic Recursion (Linear)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 5
Output: 120
Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

Example 2:
Input: n = 0
Output: 1
Explanation: 0! is defined as 1
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Recursive approach
    long long factorial(int n) {
        // Base case
        if (n == 0 || n == 1) {
            return 1;
        }
        
        // Recursive case
        return n * factorial(n - 1);
    }
    
    // Tail recursive optimization
    long long factorialTail(int n, long long acc = 1) {
        if (n == 0 || n == 1) {
            return acc;
        }
        return factorialTail(n - 1, n * acc);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 5;
    cout << "Test 1: " << n1 << "! = " << sol.factorial(n1) << endl;
    
    // Test case 2
    int n2 = 0;
    cout << "Test 2: " << n2 << "! = " << sol.factorial(n2) << endl;
    
    // Test tail recursive
    cout << "Tail recursive 5! = " << sol.factorialTail(5) << endl;
    
    return 0;
}
