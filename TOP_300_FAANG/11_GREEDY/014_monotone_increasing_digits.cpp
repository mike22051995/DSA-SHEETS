/*
================================================================================
PROBLEM: Monotone Increasing Digits (LeetCode #738)
DIFFICULTY: Medium
PATTERN: Greedy
COMPANIES: Google
================================================================================

PROBLEM DESCRIPTION:
An integer has monotone increasing digits if and only if each pair of adjacent
digits x and y satisfies x <= y. Given an integer n, return the largest number
that is less than or equal to n with monotone increasing digits.

EXAMPLES:

Example 1:
Input: n = 10
Output: 9

Example 2:
Input: n = 1234
Output: 1234

Example 3:
Input: n = 332
Output: 299

PATTERN RECOGNITION:
Use this pattern when:
- Find largest number with specific digit property
- Greedy approach adjusting from left to right
- Decrease digit and set following digits to 9
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int marker = str.length();
        
        // Find first decreasing position from right
        for (int i = str.length() - 1; i > 0; i--) {
            if (str[i] < str[i-1]) {
                marker = i;
                str[i-1]--;
            }
        }
        
        // Set all digits after marker to 9
        for (int i = marker; i < str.length(); i++) {
            str[i] = '9';
        }
        
        return stoi(str);
    }
};

int main() {
    Solution sol;
    
    cout << "10 -> " << sol.monotoneIncreasingDigits(10) << endl;
    cout << "1234 -> " << sol.monotoneIncreasingDigits(1234) << endl;
    cout << "332 -> " << sol.monotoneIncreasingDigits(332) << endl;
    cout << "100 -> " << sol.monotoneIncreasingDigits(100) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(log n) where n is the input number (digits)
SPACE COMPLEXITY: O(log n) for string conversion

SIMILAR PROBLEMS:
1. Remove K Digits (LeetCode #402)
2. Next Greater Element III (LeetCode #556)
3. Next Permutation (LeetCode #31)
4. Self Dividing Numbers (LeetCode #728)
5. Strictly Palindromic Number (LeetCode #2396)
6. Count Numbers with Unique Digits (LeetCode #357)
7. Numbers At Most N Given Digit Set (LeetCode #902)
8. Largest Time for Given Digits (LeetCode #949)
9. Largest Number (LeetCode #179)
10. Maximum Swap (LeetCode #670)
*/
