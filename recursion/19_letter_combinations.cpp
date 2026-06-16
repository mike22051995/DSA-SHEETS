/*
PROBLEM: Letter Combinations of a Phone Number
---------------------------------------------------------------------------
Given a string containing digits from 2-9, return all possible letter 
combinations that the number could represent (like on a phone keypad).

DIFFICULTY: Medium
PATTERN: Backtracking (Multi-branch recursion)
TIME COMPLEXITY: O(4^n) where n is length of digits
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Explanation: 2 maps to "abc", 3 maps to "def"

Example 2:
Input: digits = "2"
Output: ["a","b","c"]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, phone, result);
        return result;
    }
    
private:
    void backtrack(string& digits, int index, string& current,
                   unordered_map<char, string>& phone,
                   vector<string>& result) {
        // Base case: processed all digits
        if (index >= digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get letters for current digit
        string letters = phone[digits[index]];
        
        // Try each letter
        for (char c : letters) {
            current.push_back(c);                      // choose
            backtrack(digits, index + 1, current, phone, result); // explore
            current.pop_back();                        // unchoose
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string digits1 = "23";
    vector<string> result1 = sol.letterCombinations(digits1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"" << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    string digits2 = "2";
    vector<string> result2 = sol.letterCombinations(digits2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"" << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
