/*
PROBLEM: Palindrome Partitioning
---------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition 
is a palindrome. Return all possible palindrome partitioning of s.

DIFFICULTY: Medium
PATTERN: Backtracking (String Partitioning)
TIME COMPLEXITY: O(n * 2^n)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
    
private:
    void backtrack(string& s, int start, vector<string>& current,
                   vector<vector<string>>& result) {
        // Base case: reached end of string
        if (start >= s.length()) {
            result.push_back(current);
            return;
        }
        
        // Try all possible partitions
        for (int end = start; end < s.length(); end++) {
            // If current substring is palindrome
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1)); // choose
                backtrack(s, end + 1, current, result);              // explore
                current.pop_back();                                   // unchoose
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "aab";
    vector<vector<string>> result1 = sol.partition(s1);
    cout << "Test 1: [";
    for (auto& partition : result1) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"" << (i < partition.size() - 1 ? "," : "");
        }
        cout << "] ";
    }
    cout << "]" << endl;
    
    // Test case 2
    string s2 = "a";
    vector<vector<string>> result2 = sol.partition(s2);
    cout << "Test 2: Total partitions = " << result2.size() << endl;
    
    return 0;
}
