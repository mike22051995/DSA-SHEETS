/*
================================================================================
PROBLEM: Letter Combinations of a Phone Number (LeetCode #17)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, string> phoneMap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
    
    void backtrack(string& digits, int index, string& current, 
                   vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = phoneMap[digits[index]];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    auto result = sol.letterCombinations("23");
    
    cout << "Letter combinations for '23':" << endl;
    for (string& combo : result) {
        cout << combo << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Generate Parentheses (LeetCode #22)
2. Combination Sum (LeetCode #39)
3. Permutations (LeetCode #46)
4. Subsets (LeetCode #78)
5. Combinations (LeetCode #77)
6. Iterator for Combination (LeetCode #1286)
7. Construct String from Binary Tree (LeetCode #606)
8. Count Number of Texts (LeetCode #2266)
9. Unique Paths II (LeetCode #63)
10. Different Ways to Add Parentheses (LeetCode #241)
*/
