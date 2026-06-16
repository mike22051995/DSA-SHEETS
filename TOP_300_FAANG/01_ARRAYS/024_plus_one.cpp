/*
================================================================================
PROBLEM: Plus One (LeetCode #66)
DIFFICULTY: Easy
PATTERN: Array Manipulation / Math
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        // If we reach here, all digits were 9
        vector<int> result(n + 1, 0);
        result[0] = 1;
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> digits1 = {1,2,3};
    vector<int> digits2 = {4,3,2,1};
    vector<int> digits3 = {9,9,9};
    
    vector<int> result1 = sol.plusOne(digits1);
    cout << "Result: ";
    for (int x : result1) cout << x;
    cout << endl;
    
    vector<int> result2 = sol.plusOne(digits2);
    cout << "Result: ";
    for (int x : result2) cout << x;
    cout << endl;
    
    vector<int> result3 = sol.plusOne(digits3);
    cout << "Result: ";
    for (int x : result3) cout << x;
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Add Two Numbers (LeetCode #2)
2. Multiply Strings (LeetCode #43)
3. Add Binary (LeetCode #67)
4. Add to Array-Form of Integer (LeetCode #989)
5. Add Strings (LeetCode #415)
6. Add Two Numbers II (LeetCode #445)
7. String to Integer (atoi) (LeetCode #8)
8. Integer to Roman (LeetCode #12)
9. Roman to Integer (LeetCode #13)
10. Factorial Trailing Zeroes (LeetCode #172)
*/
