/*
================================================================================
PROBLEM: Sqrt(x) (LeetCode #69)
DIFFICULTY: Easy
PATTERN: Binary Search
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given a non-negative integer x, return the integer part of its square root.
Only the floor value is returned.

EXAMPLES:
Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2

Example 3:
Input: x = 1
Output: 1

CODE EXPLANATION:
- Binary search the largest integer whose square is <= x.
- If mid * mid is too large, move left; otherwise move right.
- The final right pointer is the floor sqrt.
TIME COMPLEXITY: O(log x)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        long long left = 1;
        long long right = x / 2;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
    
    // Newton's method
    int mySqrtNewton(int x) {
        if (x < 2) return x;
        
        long long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        
        return r;
    }
};

int main() {
    Solution sol;
    
    cout << "sqrt(4) = " << sol.mySqrt(4) << endl;
    cout << "sqrt(8) = " << sol.mySqrt(8) << endl;
    cout << "sqrt(16) = " << sol.mySqrt(16) << endl;
    cout << "sqrt(100) = " << sol.mySqrt(100) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Perfect Square (LeetCode #367)
2. Pow(x, n) (LeetCode #50)
3. Count Primes (LeetCode #204)
4. Perfect Squares (LeetCode #279)
5. Nth Digit (LeetCode #400)
6. Arranging Coins (LeetCode #441)
7. Sum of Square Numbers (LeetCode #633)
8. Ugly Number (LeetCode #263)
9. Ugly Number II (LeetCode #264)
10. Super Ugly Number (LeetCode #313)
*/
