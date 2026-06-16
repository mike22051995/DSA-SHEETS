/*
================================================================================
PROBLEM: Remove Duplicate Letters (LeetCode #316)
DIFFICULTY: Medium
PATTERN: Greedy / Stack / String
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given a string s, remove duplicate letters so that every letter appears once
and only once. You must make sure your result is the smallest in lexicographical
order among all possible results.

EXAMPLES:

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

PATTERN RECOGNITION:
Use this pattern when:
- Need lexicographically smallest result
- Remove duplicates while maintaining order
- Stack with greedy removal based on future occurrences
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        
        // Count occurrences of each character
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string result;
        
        for (char c : s) {
            count[c - 'a']--;
            
            if (visited[c - 'a']) {
                continue;
            }
            
            // Remove larger characters if current char is smaller
            // and larger chars appear later
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result += c;
            visited[c - 'a'] = true;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "bcabc -> " << sol.removeDuplicateLetters("bcabc") << endl;
    cout << "cbacdcbc -> " << sol.removeDuplicateLetters("cbacdcbc") << endl;
    cout << "ecbacba -> " << sol.removeDuplicateLetters("ecbacba") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is string length
SPACE COMPLEXITY: O(26) = O(1) for fixed alphabet size

SIMILAR PROBLEMS:
1. Smallest Subsequence of Distinct Characters (LeetCode #1081)
2. Create Maximum Number (LeetCode #321)
3. Smallest K-Length Subsequence (LeetCode #2030)
4. Remove K Digits (LeetCode #402)
5. Longest Substring Without Repeating (LeetCode #3)
6. Valid Parentheses (LeetCode #20)
7. Daily Temperatures (LeetCode #739)
8. Next Greater Element (LeetCode #496)
9. Monotonic Array (LeetCode #896)
10. Find the Most Competitive Subsequence (LeetCode #1673)
*/
