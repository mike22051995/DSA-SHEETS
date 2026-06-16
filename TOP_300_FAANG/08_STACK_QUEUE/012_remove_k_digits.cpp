/*
================================================================================
PROBLEM: Remove K Digits (LeetCode #402)
DIFFICULTY: Medium
PATTERN: Stack / Greedy
COMPANIES: Amazon, Google, Facebook
================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        
        for (char c : num) {
            while (!stk.empty() && k > 0 && stk.top() > c) {
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        
        // Remove remaining k digits from the end
        while (k > 0) {
            stk.pop();
            k--;
        }
        
        // Build result
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        // Remove leading zeros
        int i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);
        
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution sol;
    string num1 = "1432219";
    string num2 = "10200";
    string num3 = "10";
    
    cout << "Remove 3 digits from " << num1 << ": " << sol.removeKdigits(num1, 3) << endl;
    cout << "Remove 1 digit from " << num2 << ": " << sol.removeKdigits(num2, 1) << endl;
    cout << "Remove 2 digits from " << num3 << ": " << sol.removeKdigits(num3, 2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Create Maximum Number (LeetCode #321)
2. Monotone Increasing Digits (LeetCode #738)
3. Find the Most Competitive Subsequence (LeetCode #1673)
4. Remove Duplicate Letters (LeetCode #316)
5. Smallest Subsequence of Distinct Characters (LeetCode #1081)
6. Minimum Deletions to Make String Balanced (LeetCode #1653)
7. Maximum Binary String After Change (LeetCode #1702)
8. Removing Minimum and Maximum (LeetCode #2091)
9. Removing Stars From a String (LeetCode #2390)
10. Shortest Unsorted Continuous Subarray (LeetCode #581)
*/
