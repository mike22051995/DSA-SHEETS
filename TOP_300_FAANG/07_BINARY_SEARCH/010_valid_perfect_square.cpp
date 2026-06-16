/*
================================================================================
PROBLEM: Valid Perfect Square (LeetCode #367)
DIFFICULTY: Easy
PATTERN: Binary Search / Math
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given a positive integer num, return true if it is a perfect square, otherwise
return false. Do not use built-in square root functions.

EXAMPLES:
Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false

Example 3:
Input: num = 1
Output: true

CODE EXPLANATION:
- Binary search a value mid such that mid * mid equals num.
- Narrow the range based on whether mid * mid is too small or too large.
- The math method subtracts consecutive odd numbers until reaching 0.
TIME COMPLEXITY: O(log num) for binary search
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        if (num == 1) return true;
        
        long long left = 1;
        long long right = num / 2;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
    
    // Math approach using 1 + 3 + 5 + ... = n^2
    bool isPerfectSquareMath(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

int main() {
    Solution sol;
    
    cout << "16 is perfect square: " << (sol.isPerfectSquare(16) ? "true" : "false") << endl;
    cout << "14 is perfect square: " << (sol.isPerfectSquare(14) ? "true" : "false") << endl;
    cout << "1 is perfect square: " << (sol.isPerfectSquare(1) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sqrt(x) (LeetCode #69)
2. Valid Perfect Square (LeetCode #367)
3. Count Primes (LeetCode #204)
4. Pow(x, n) (LeetCode #50)
5. Perfect Squares (LeetCode #279)
6. Sum of Square Numbers (LeetCode #633)
7. Minimum Cost For Tickets (LeetCode #983)
8. Fair Candy Swap (LeetCode #888)
9. Prison Cells After N Days (LeetCode #957)
10. Reordered Power of 2 (LeetCode #869)
*/
