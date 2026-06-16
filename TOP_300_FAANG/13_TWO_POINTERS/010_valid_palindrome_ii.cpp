/*
================================================================================
PROBLEM: Valid Palindrome II (LeetCode #680)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        return true;
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    cout << "aba: " << (sol.validPalindrome("aba") ? "true" : "false") << endl;
    cout << "abca: " << (sol.validPalindrome("abca") ? "true" : "false") << endl;
    cout << "abc: " << (sol.validPalindrome("abc") ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Palindrome (LeetCode #125)
2. Longest Palindromic Substring (LeetCode #5)
3. Palindromic Substrings (LeetCode #647)
4. Palindrome Linked List (LeetCode #234)
5. Remove Palindromic Subsequences (LeetCode #1332)
6. Find K-th Smallest Pair Distance (LeetCode #719)
7. Two Sum II (LeetCode #167)
8. 3Sum (LeetCode #15)
9. Container With Most Water (LeetCode #11)
10. Trapping Rain Water (LeetCode #42)
*/
