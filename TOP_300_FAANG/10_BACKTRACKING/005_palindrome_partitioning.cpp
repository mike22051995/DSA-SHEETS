/*
================================================================================
PROBLEM: Palindrome Partitioning (LeetCode #131)
DIFFICULTY: Medium
PATTERN: Backtracking with Memoization
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
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
    
    void backtrack(string& s, int start, vector<string>& current, 
                   vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    auto result = sol.partition("aab");
    
    cout << "Palindrome partitions of 'aab':" << endl;
    for (auto& partition : result) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << partition[i];
            if (i < partition.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Palindrome Partitioning II (LeetCode #132) - Min cuts
2. Palindrome Partitioning III (LeetCode #1278)
3. Palindrome Partitioning IV (LeetCode #1745)
4. Longest Palindromic Substring (LeetCode #5)
5. Palindromic Substrings (LeetCode #647)
6. Restore IP Addresses (LeetCode #93)
7. Partition Equal Subset Sum (LeetCode #416)
8. Partition to K Equal Sum Subsets (LeetCode #698)
9. Split Array Largest Sum (LeetCode #410)
10. Word Break (LeetCode #139)
*/
