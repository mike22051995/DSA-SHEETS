/*
PROBLEM: Restore IP Addresses
---------------------------------------------------------------------------
Given a string s containing only digits, return all possible valid IP 
addresses that can be formed by inserting dots into s. An IP address 
consists of exactly four integers separated by dots, each integer is 
between 0 and 255 and cannot have leading zeros.

DIFFICULTY: Medium-Hard
PATTERN: Backtracking (String Partitioning with Constraints)
TIME COMPLEXITY: O(3^4) = O(1) - max 3 digits per part, 4 parts
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        backtrack(s, 0, parts, result);
        return result;
    }
    
private:
    void backtrack(string& s, int start, vector<string>& parts,
                   vector<string>& result) {
        // Base case: found 4 parts and used all characters
        if (parts.size() == 4) {
            if (start == s.length()) {
                result.push_back(parts[0] + "." + parts[1] + "." + 
                               parts[2] + "." + parts[3]);
            }
            return;
        }
        
        // Pruning: too few characters left
        if (start >= s.length()) return;
        
        // Try 1, 2, or 3 digit segments
        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            string part = s.substr(start, len);
            
            // Validate part
            if (isValid(part)) {
                parts.push_back(part);                      // choose
                backtrack(s, start + len, parts, result);   // explore
                parts.pop_back();                           // unchoose
            }
        }
    }
    
    bool isValid(string& part) {
        // No leading zeros except "0" itself
        if (part.length() > 1 && part[0] == '0') {
            return false;
        }
        
        // Must be <= 255
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "25525511135";
    vector<string> result1 = sol.restoreIpAddresses(s1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"" << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    string s2 = "101023";
    vector<string> result2 = sol.restoreIpAddresses(s2);
    cout << "Test 2: Total IPs = " << result2.size() << endl;
    
    return 0;
}
