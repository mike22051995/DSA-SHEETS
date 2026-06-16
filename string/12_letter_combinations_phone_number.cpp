/*
    Letter Combinations of a Phone Number - LeetCode #17
    
    Given a string containing digits from 2-9 inclusive, return all possible letter
    combinations that the number could represent. Return the answer in any order.
    
    A mapping of digits to letters (just like on the telephone buttons):
    2: abc, 3: def, 4: ghi, 5: jkl, 6: mno, 7: pqrs, 8: tuv, 9: wxyz
    
    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    Example 2:
    Input: digits = ""
    Output: []
    
    Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]
    
    Constraints:
    - 0 <= digits.length <= 4
    - digits[i] is a digit in the range ['2', '9']
    
    Time Complexity: O(4^n) where n is length of digits
    Space Complexity: O(n) for recursion stack
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
        backtrack(result, phone, digits, "", 0);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, unordered_map<char, string>& phone,
                   const string& digits, string current, int index) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = phone[digits[index]];
        for (char letter : letters) {
            backtrack(result, phone, digits, current + letter, index + 1);
        }
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<string> result1 = sol.letterCombinations("23");
    cout << "Test 1: ";
    for (const string& s : result1) {
        cout << s << " ";
    }
    cout << endl;
    
    // Test 2
    vector<string> result2 = sol.letterCombinations("");
    cout << "Test 2: " << (result2.empty() ? "[]" : "not empty") << endl;
    
    // Test 3
    vector<string> result3 = sol.letterCombinations("2");
    cout << "Test 3: ";
    for (const string& s : result3) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
