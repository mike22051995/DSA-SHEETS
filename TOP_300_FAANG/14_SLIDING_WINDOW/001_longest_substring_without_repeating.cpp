/*
================================================================================
PROBLEM: Longest Substring Without Repeating Characters (LeetCode #3)
DIFFICULTY: Medium
PATTERN: Sliding Window / Hash Map
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given a string s, find the length of the longest substring without 
repeating characters.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Finding longest/shortest substring with condition
2. Contiguous elements in array/string
3. Window expands and contracts dynamically
4. Need O(n) solution for substring problems

Key Indicators:
- "Longest/shortest substring"
- "Without repeating" or "with at most K distinct"
- Contiguous elements
- Can use two pointers/sliding window

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: Answer is "abc", length is 3

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: Answer is "b", length is 1

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: Answer is "wke", length is 3
Note: "pwke" is subsequence, not substring

Example 4:
Input: s = ""
Output: 0

Example 5:
Input: s = "abcdefgh"
Output: 8

================================================================================
EXPLANATION:

Sliding Window Approach:
1. Use two pointers: left and right
2. Expand window by moving right
3. Track characters in window using hash map
4. If duplicate found:
   - Shrink window from left
   - Update character positions
5. Track maximum window size

Why Sliding Window?
- Efficiently handles contiguous subarrays
- Avoids checking all substrings (O(n²))
- Dynamic expansion and contraction

Time Complexity: O(n) - each char visited at most twice
Space Complexity: O(min(n, m)) where m is charset size

================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Sliding Window with Hash Map (Optimal)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;  // char -> last seen index
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            // If character seen before and within current window
            if (charIndex.count(c) && charIndex[c] >= left) {
                left = charIndex[c] + 1;  // Move left pointer
            }
            
            charIndex[c] = right;  // Update last seen position
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
    // Approach 2: Sliding Window with Set
    int lengthOfLongestSubstringSet(string s) {
        unordered_set<char> window;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Shrink window until no duplicate
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }
            
            window.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
    // Approach 3: Brute Force (Not optimal)
    int lengthOfLongestSubstringBrute(string s) {
        int n = s.length();
        int maxLength = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (seen.count(s[j])) {
                    break;
                }
                seen.insert(s[j]);
                maxLength = max(maxLength, j - i + 1);
            }
        }
        
        return maxLength;
    }
    
    // With actual substring tracking
    string getLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;
        int startIndex = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            if (charIndex.count(c) && charIndex[c] >= left) {
                left = charIndex[c] + 1;
            }
            
            charIndex[c] = right;
            
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                startIndex = left;
            }
        }
        
        return s.substr(startIndex, maxLength);
    }
};

void runTest(string s, string testName) {
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    string substring = sol.getLongestSubstring(s);
    
    cout << testName << ": " << endl;
    cout << "Input: \"" << s << "\"" << endl;
    cout << "Length: " << result << endl;
    cout << "Substring: \"" << substring << "\"" << endl;
    cout << "-------------------" << endl;
}

int main() {
    runTest("abcabcbb", "Test 1");
    runTest("bbbbb", "Test 2");
    runTest("pwwkew", "Test 3");
    runTest("", "Test 4");
    runTest("abcdefgh", "Test 5");
    runTest("dvdf", "Test 6");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Longest Substring with At Most K Distinct Characters (LeetCode #340) - Medium
   - Variation with K distinct chars

2. Longest Repeating Character Replacement (LeetCode #424) - Medium
   - Can replace K characters

3. Minimum Window Substring (LeetCode #76) - Hard
   - Find smallest window containing all chars

4. Substring with Concatenation of All Words (LeetCode #30) - Hard
   - Multiple word matching

5. Longest Substring with At Most Two Distinct Characters (LeetCode #159) - Medium
   - Limit of 2 distinct

6. Permutation in String (LeetCode #567) - Medium
   - Check if permutation exists

7. Find All Anagrams in a String (LeetCode #438) - Medium
   - All anagram positions

8. Minimum Size Subarray Sum (LeetCode #209) - Medium
   - Sum >= target

9. Maximum Length of Repeated Subarray (LeetCode #718) - Medium
   - Between two arrays

10. Longest Palindromic Substring (LeetCode #5) - Medium
    - Different pattern but related

================================================================================
SLIDING WINDOW PATTERN:
================================================================================

Template:
```
left = 0
for right in range(len(arr)):
    # Expand window
    add arr[right] to window
    
    # Shrink window if condition violated
    while condition_violated:
        remove arr[left] from window
        left++
    
    # Update result
    result = max(result, window_size)
```

When to use:
1. Contiguous subarray/substring problems
2. Need to find min/max length
3. Condition based on window contents
4. O(n) or O(n*k) solution needed

Types:
1. Fixed window size
2. Dynamic window (this problem)
3. Window with k distinct elements

================================================================================
KEY INSIGHTS:
================================================================================

1. Why Hash Map over Set?
   - Map stores last index
   - Can jump left pointer directly
   - More efficient than incrementing left

2. Common Mistakes:
   - Not checking if duplicate is in current window
   - Forgetting to update max length
   - Off-by-one errors in window size

3. Edge Cases:
   - Empty string
   - Single character
   - All unique characters
   - All same characters

4. Follow-ups:
   - What if we need at most K distinct? (similar window)
   - What if we can replace K characters? (LRCR problem)
   - Return actual substring? (track start index)

5. Time Complexity Analysis:
   - Right pointer: 0 to n (O(n))
   - Left pointer: 0 to n total (O(n))
   - Total: O(n)

================================================================================
*/
