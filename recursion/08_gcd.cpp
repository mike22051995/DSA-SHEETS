/*
PROBLEM: Greatest Common Divisor (GCD) - Euclidean Algorithm
---------------------------------------------------------------------------
Given two non-negative integers a and b, find their GCD using recursion.
GCD is the largest positive integer that divides both numbers.

DIFFICULTY: Easy
PATTERN: Euclidean Algorithm (Divide and Conquer)
TIME COMPLEXITY: O(log(min(a,b)))
SPACE COMPLEXITY: O(log(min(a,b))) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: a = 48, b = 18
Output: 6
Explanation: Divisors of 48: 1,2,3,4,6,8,12,16,24,48. Divisors of 18: 1,2,3,6,9,18. GCD = 6

Example 2:
Input: a = 100, b = 50
Output: 50
Explanation: 50 divides both 100 and 50
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // Euclidean Algorithm
    int gcd(int a, int b) {
        // Base case
        if (b == 0) {
            return a;
        }
        
        // Recursive case
        return gcd(b, a % b);
    }
    
    // LCM using GCD
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int a1 = 48, b1 = 18;
    cout << "Test 1: GCD(" << a1 << ", " << b1 << ") = " << sol.gcd(a1, b1) << endl;
    
    // Test case 2
    int a2 = 100, b2 = 50;
    cout << "Test 2: GCD(" << a2 << ", " << b2 << ") = " << sol.gcd(a2, b2) << endl;
    cout << "         LCM(" << a2 << ", " << b2 << ") = " << sol.lcm(a2, b2) << endl;
    
    return 0;
}
