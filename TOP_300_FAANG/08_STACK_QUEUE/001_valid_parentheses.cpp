/*
================================================================================
PROBLEM: Valid Parentheses (LeetCode #20)
DIFFICULTY: Easy
PATTERN: Stack
COMPANIES: Amazon, Microsoft, Facebook, Google, Bloomberg, Apple
================================================================================

PROBLEM DESCRIPTION:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Matching pairs or nested structures
2. Need to track most recent unmatched element
3. LIFO (Last In First Out) behavior needed
4. Parentheses, brackets, tags matching

Key Indicators:
- "Valid parentheses" or "balanced brackets"
- Matching opening and closing symbols
- Nested structure validation
- Stack naturally handles nesting

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: s = "()"
Output: true
Explanation: Correctly matched pair

Example 2:
Input: s = "()[]{}"
Output: true
Explanation: All pairs correctly matched

Example 3:
Input: s = "(]"
Output: false
Explanation: Mismatched types

Example 4:
Input: s = "([)]"
Output: false
Explanation: Incorrect order - ] closes before (

Example 5:
Input: s = "{[]}"
Output: true
Explanation: Properly nested

================================================================================
EXPLANATION:

Stack-Based Approach:
1. For each character:
   - If opening bracket: push to stack
   - If closing bracket: 
     * Check if stack is empty (invalid)
     * Check if top matches (invalid if not)
     * Pop from stack
2. At end, stack should be empty

Why Stack?
- Stack maintains order of opening brackets
- Most recent opening bracket should match next closing
- LIFO property perfect for nesting

Time Complexity: O(n)
Space Complexity: O(n) for stack

================================================================================
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            // If closing bracket
            if (closeToOpen.count(c)) {
                // Check if stack is empty or top doesn't match
                if (st.empty() || st.top() != closeToOpen[c]) {
                    return false;
                }
                st.pop();
            } 
            // If opening bracket
            else {
                st.push(c);
            }
        }
        
        // Valid only if all brackets matched (stack empty)
        return st.empty();
    }
    
    // Alternative: Without hash map
    bool isValidAlt(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};

void runTest(string s, string testName) {
    Solution sol;
    bool result = sol.isValid(s);
    
    cout << testName << ": " << endl;
    cout << "Input:  \"" << s << "\"" << endl;
    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "-------------------" << endl;
}

int main() {
    runTest("()", "Test 1");
    runTest("()[]{}", "Test 2");
    runTest("(]", "Test 3");
    runTest("([)]", "Test 4");
    runTest("{[]}", "Test 5");
    runTest("(((", "Test 6 - Only opening");
    runTest(")))", "Test 7 - Only closing");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Generate Parentheses (LeetCode #22) - Medium
   - Generate all valid combinations

2. Longest Valid Parentheses (LeetCode #32) - Hard
   - Find longest valid substring

3. Remove Invalid Parentheses (LeetCode #301) - Hard
   - Minimum removals for valid string

4. Minimum Add to Make Parentheses Valid (LeetCode #921) - Medium
   - Count additions needed

5. Minimum Remove to Make Valid Parentheses (LeetCode #1249) - Medium
   - Remove minimum to make valid

6. Valid Parenthesis String (LeetCode #678) - Medium
   - With wildcard '*' character

7. Score of Parentheses (LeetCode #856) - Medium
   - Calculate score based on nesting

8. Check if Word Is Valid After Substitutions (LeetCode #1003) - Medium
   - Similar validation pattern

9. Remove Outermost Parentheses (LeetCode #1021) - Easy
   - Remove outer layer

10. Crawler Log Folder (LeetCode #1598) - Easy
    - Stack-based path navigation

================================================================================
EXTENDED PATTERNS:
================================================================================

1. HTML/XML Tag Matching:
   - Similar stack approach
   - Check tag names match

2. Expression Evaluation:
   - Evaluate mathematical expressions
   - Handle operator precedence

3. Balanced Binary String:
   - Count balance of characters
   - Similar validation logic

4. Nested Structures:
   - JSON validation
   - Directory structure validation

================================================================================
KEY INSIGHTS:
================================================================================

1. Why Stack is Perfect:
   - Handles nesting naturally
   - LIFO matches closing order
   - O(n) time and space

2. Common Mistakes:
   - Not checking if stack is empty before pop
   - Forgetting to check stack empty at end
   - Not handling all bracket types

3. Edge Cases:
   - Empty string (valid)
   - Only opening brackets
   - Only closing brackets
   - Interleaved but mismatched

4. Optimization:
   - Early termination if more closing than opening
   - Count-based approach for single type

5. Follow-up Questions:
   - Make string valid with minimum changes?
   - Generate all valid strings?
   - Handle wildcards?

================================================================================
*/
