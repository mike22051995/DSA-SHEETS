/*
================================================================================
PROBLEM: Get Equal Substrings Within Budget (LeetCode #1208)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Google
================================================================================

PROBLEM DESCRIPTION:
You are given two strings s and t of the same length and an integer maxCost.
You want to change s to t. Changing the ith character of s to ith character of
t costs |s[i] - t[i]| (absolute difference of ASCII values). Return the maximum
length of a substring of s that can be changed to be the same as the
corresponding substring of t with a cost less than or equal to maxCost. If
there is no substring, return 0.

EXAMPLES:

Example 1:
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" to "bcd" costs 3.

Example 2:
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1

Example 3:
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1

PATTERN RECOGNITION:
Use this pattern when:
- Maximum subarray/substring with cost constraint
- Sliding window with cost accumulation
- Expand window while under budget, shrink when over
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int currentCost = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            currentCost += abs(s[right] - t[right]);
            
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    cout << "abcd -> bcdf (cost=3): " << sol.equalSubstring("abcd", "bcdf", 3) << endl;
    cout << "abcd -> cdef (cost=3): " << sol.equalSubstring("abcd", "cdef", 3) << endl;
    cout << "abcd -> acde (cost=0): " << sol.equalSubstring("abcd", "acde", 0) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is string length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Longest Repeating Character Replacement (LeetCode #424)
2. Max Consecutive Ones III (LeetCode #1004)
3. Minimum Size Subarray Sum (LeetCode #209)
4. Longest Substring Without Repeating (LeetCode #3)
5. Minimum Window Substring (LeetCode #76)
6. Fruit Into Baskets (LeetCode #904)
7. Subarrays with K Different Integers (LeetCode #992)
8. Longest Continuous Subarray (LeetCode #1438)
9. Grumpy Bookstore Owner (LeetCode #1052)
10. Maximum Points from Cards (LeetCode #1423)
*/
