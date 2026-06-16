/*
PROBLEM: Plus One
Difficulty: Easy
Pattern: Array Manipulation, Math

DESCRIPTION:
You are given a large integer represented as an integer array digits, where each digits[i] 
is the ith digit of the integer. The digits are ordered from most significant to least 
significant in left-to-right order. Increment the large integer by one and return the 
resulting array of digits.

EXPLANATION:
Start from the last digit and add 1. If there's a carry, propagate it to the left.
If all digits become 0 (carry propagates through all digits), we need to add a new digit 
at the beginning.

Time Complexity: O(n)
Space Complexity: O(1) or O(n) if we need to add a digit

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: 123 + 1 = 124

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: 4321 + 1 = 4322

Example 3:
Input: digits = [9,9,9]
Output: [1,0,0,0]
Explanation: 999 + 1 = 1000
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            // If digit is less than 9, just increment and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // Otherwise, set to 0 and carry over
            digits[i] = 0;
        }
        
        // If we reach here, all digits were 9
        // Need to add a 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = solution.plusOne(digits1);
    cout << "Test 1: ";
    printArray(result1);
    
    // Test Case 2
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = solution.plusOne(digits2);
    cout << "Test 2: ";
    printArray(result2);
    
    // Test Case 3
    vector<int> digits3 = {9, 9, 9};
    vector<int> result3 = solution.plusOne(digits3);
    cout << "Test 3: ";
    printArray(result3);
    
    return 0;
}
