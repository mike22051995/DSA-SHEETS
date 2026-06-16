/*
================================================================================
PROBLEM: Decode String (LeetCode #394)
DIFFICULTY: Medium
PATTERN: Stack
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (c == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                int count = countStack.top();
                countStack.pop();
                
                for (int i = 0; i < count; i++) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } else {
                currentString += c;
            }
        }
        
        return currentString;
    }
    
    // Recursive approach
    string decodeStringRecursive(string s) {
        int idx = 0;
        return helper(s, idx);
    }
    
    string helper(string& s, int& idx) {
        string result = "";
        int num = 0;
        
        while (idx < s.length()) {
            char c = s[idx];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                idx++;
                string nested = helper(s, idx);
                for (int i = 0; i < num; i++) {
                    result += nested;
                }
                num = 0;
            } else if (c == ']') {
                return result;
            } else {
                result += c;
            }
            idx++;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.decodeString("3[a]2[bc]") << endl;
    cout << sol.decodeString("3[a2[c]]") << endl;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Atoms (LeetCode #726)
2. Encode String with Shortest Length (LeetCode #471)
3. Parsing A Boolean Expression (LeetCode #1106)
4. Basic Calculator (LeetCode #224)
5. Brace Expansion (LeetCode #1087)
6. Evaluate Reverse Polish Notation (LeetCode #150)
7. Remove Comments (LeetCode #722)
8. Tag Validator (LeetCode #591)
9. Parse Lisp Expression (LeetCode #736)
10. Nested List Weight Sum (LeetCode #339)
*/
