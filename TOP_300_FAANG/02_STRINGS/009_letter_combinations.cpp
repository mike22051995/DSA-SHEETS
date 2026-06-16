/*
================================================================================
PROBLEM: Letter Combinations of Phone Number (LeetCode #17)
DIFFICULTY: Medium
PATTERN: Backtracking / DFS
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if (digits.empty()) return result;
        
        string current;
        backtrack(digits, 0, current, result);
        
        return result;
    }
    
    void backtrack(string& digits, int index, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = phone[digits[index]];
        
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }
    
    // Iterative approach
    vector<string> letterCombinationsIterative(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result = {""};
        
        for (char digit : digits) {
            vector<string> temp;
            string letters = phone[digit];
            
            for (string& combo : result) {
                for (char letter : letters) {
                    temp.push_back(combo + letter);
                }
            }
            
            result = temp;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string digits = "23";
    
    vector<string> combinations = sol.letterCombinations(digits);
    
    cout << "Letter combinations: ";
    for (string& combo : combinations) {
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
4. Combinations (LeetCode #77)
5. Restore IP Addresses (LeetCode #93)
6. Word Pattern II (LeetCode #291)
7. Iterator for Combination (LeetCode #1286)
8. Count Number of Texts (LeetCode #2266)
9. Minimum Number of Pushes (LeetCode #3016)
10. Generalized Abbreviation (LeetCode #320)
*/
