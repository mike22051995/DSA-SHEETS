/*
    Palindromic Substrings - LeetCode #647
    
    Given a string s, return the number of palindromic substrings in it.
    A string is a palindrome when it reads the same backward as forward.
    A substring is a contiguous sequence of characters within the string.
    
    Example 1:
    Input: s = "abc"
    Output: 3
    Explanation: Three palindromic strings: "a", "b", "c".
    
    Example 2:
    Input: s = "aaa"
    Output: 6
    Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
    
    Constraints:
    - 1 <= s.length <= 1000
    - s consists of lowercase English letters
    
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Approach: Expand Around Center
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Count odd length palindromes
            count += expandAroundCenter(s, i, i);
            // Count even length palindromes
            count += expandAroundCenter(s, i, i + 1);
        }
        
        return count;
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.countSubstrings("abc") << endl;     // 3
    cout << "Test 2: " << sol.countSubstrings("aaa") << endl;     // 6
    cout << "Test 3: " << sol.countSubstrings("racecar") << endl; // 10
    
    return 0;
}
