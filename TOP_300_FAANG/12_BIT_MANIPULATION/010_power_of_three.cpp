/*
================================================================================
PROBLEM: Power of Three (LeetCode #326)
DIFFICULTY: Easy
PATTERN: Math / Iteration
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Method 1: Iterative
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        while (n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }
    
    // Method 2: Logarithm
    bool isPowerOfThreeLog(int n) {
        if (n <= 0) return false;
        
        double logResult = log10(n) / log10(3);
        return logResult == floor(logResult);
    }
    
    // Method 3: Use max power of 3 in int range
    bool isPowerOfThreeMath(int n) {
        // 3^19 = 1162261467 is the largest power of 3 in int range
        return n > 0 && 1162261467 % n == 0;
    }
};

int main() {
    Solution sol;
    
    cout << "27 is power of 3: " << (sol.isPowerOfThree(27) ? "true" : "false") << endl;
    cout << "0 is power of 3: " << (sol.isPowerOfThree(0) ? "true" : "false") << endl;
    cout << "9 is power of 3: " << (sol.isPowerOfThree(9) ? "true" : "false") << endl;
    cout << "45 is power of 3: " << (sol.isPowerOfThree(45) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Power of Two (LeetCode #231)
2. Power of Four (LeetCode #342)
3. Ugly Number (LeetCode #263)
4. Ugly Number II (LeetCode #264)
5. Happy Number (LeetCode #202)
6. Perfect Number (LeetCode #507)
7. Check if Number is Sum of Powers of Three (LeetCode #1780)
8. Count Primes (LeetCode #204)
9. Factorial Trailing Zeroes (LeetCode #172)
10. Add Digits (LeetCode #258)
*/
