/*
================================================================================
PROBLEM: Restore IP Addresses (LeetCode #93)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }
    
    void backtrack(string& s, int start, int part, string current, vector<string>& result) {
        if (part == 4) {
            if (start == s.length()) {
                result.push_back(current.substr(0, current.length() - 1)); // Remove trailing dot
            }
            return;
        }
        
        if (start >= s.length()) return;
        
        // Try 1 digit
        backtrack(s, start + 1, part + 1, current + s.substr(start, 1) + ".", result);
        
        // Try 2 digits
        if (start + 1 < s.length() && s[start] != '0') {
            backtrack(s, start + 2, part + 1, current + s.substr(start, 2) + ".", result);
        }
        
        // Try 3 digits
        if (start + 2 < s.length() && s[start] != '0') {
            int num = stoi(s.substr(start, 3));
            if (num <= 255) {
                backtrack(s, start + 3, part + 1, current + s.substr(start, 3) + ".", result);
            }
        }
    }
};

int main() {
    Solution sol;
    string s1 = "25525511135";
    string s2 = "0000";
    
    vector<string> result1 = sol.restoreIpAddresses(s1);
    cout << "Valid IP addresses for " << s1 << ":" << endl;
    for (string& ip : result1) {
        cout << ip << endl;
    }
    
    vector<string> result2 = sol.restoreIpAddresses(s2);
    cout << "\nValid IP addresses for " << s2 << ":" << endl;
    for (string& ip : result2) {
        cout << ip << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. IP to CIDR (LeetCode #751)
2. Validate IP Address (LeetCode #468)
3. Split Array into Fibonacci Sequence (LeetCode #842)
4. Partition to K Equal Sum Subsets (LeetCode #698)
5. Add Bold Tag in String (LeetCode #616)
6. Ambiguous Coordinates (LeetCode #816)
7. Parsing A Boolean Expression (LeetCode #1106)
8. Different Ways to Add Parentheses (LeetCode #241)
9. Decode Ways (LeetCode #91)
10. Decode Ways II (LeetCode #639)
*/
