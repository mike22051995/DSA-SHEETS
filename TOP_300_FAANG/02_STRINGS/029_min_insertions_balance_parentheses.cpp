/*
================================================================================
PROBLEM: Minimum Insertions to Balance Parentheses (LeetCode #1541)
DIFFICULTY: Medium
PATTERN: String / Greedy
COMPANIES: Amazon, Google
================================================================================

PROBLEM DESCRIPTION:
Given a parentheses string s containing only '(' and ')'. A parentheses string
is balanced if: Any left parenthesis '(' must have a corresponding two
consecutive right parenthesis '))'. Left parenthesis '(' must go before the
corresponding two consecutive right parenthesis '))'. Return the minimum number
of insertions needed to make s balanced.

EXAMPLES:

Example 1:
Input: s = "(()))"
Output: 1
Explanation: Need to add '(' at beginning to make it balanced.

Example 2:
Input: s = "())"
Output: 0

Example 3:
Input: s = "))())("
Output: 3
Explanation: Add '(' at beginning, and add '))' at end.

Example 4:
Input: s = "(((((("
Output: 12
Explanation: Each '(' needs '))'

PATTERN RECOGNITION:
Use this pattern when:
- Parentheses with custom matching rules
- Count insertions needed for balance
- Greedy approach tracking unmatched brackets
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openNeeded = 0;  // Number of ')' needed
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openNeeded += 2;  // Each '(' needs '))'
                
                // If odd number of ')' needed, add one ')'
                if (openNeeded % 2 == 1) {
                    insertions++;
                    openNeeded--;
                }
            } else {  // s[i] == ')'
                openNeeded--;
                
                if (openNeeded < 0) {
                    // Need to add '('
                    insertions++;
                    openNeeded += 2;  // New '(' needs '))'
                    openNeeded--;     // Current ')' matches one
                }
            }
        }
        
        return insertions + openNeeded;
    }
};

int main() {
    Solution sol;
    
    cout << "(())): " << sol.minInsertions("(()))") << endl;
    cout << "()): " << sol.minInsertions("())") << endl;
    cout << "))())(: " << sol.minInsertions("))())(") << endl;
    cout << "((((((: " << sol.minInsertions("((((((") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is string length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Valid Parentheses (LeetCode #20)
2. Minimum Add to Make Parentheses Valid (LeetCode #921)
3. Minimum Remove to Make Valid Parentheses (LeetCode #1249)
4. Longest Valid Parentheses (LeetCode #32)
5. Valid Parenthesis String (LeetCode #678)
6. Score of Parentheses (LeetCode #856)
7. Generate Parentheses (LeetCode #22)
8. Remove Invalid Parentheses (LeetCode #301)
9. Check if Word Is Valid After Substitutions (LeetCode #1003)
10. Different Ways to Add Parentheses (LeetCode #241)
*/
