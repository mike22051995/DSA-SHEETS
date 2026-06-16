/*
================================================================================
PROBLEM: Valid Palindrome (LeetCode #125)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            if (tolower(s[left]) != tolower(s[right])) {
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
    cout << "Is palindrome (A man, a plan, a canal: Panama): " 
         << (sol.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << endl;
    cout << "Is palindrome (race a car): " 
         << (sol.isPalindrome("race a car") ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Palindrome II (LeetCode #680) - Delete one char
2. Palindrome Number (LeetCode #9)
3. Longest Palindromic Substring (LeetCode #5)
4. Palindrome Linked List (LeetCode #234)
5. Palindrome Partitioning (LeetCode #131)
6. Valid Anagram (LeetCode #242)
7. Reverse String (LeetCode #344)
8. Reverse Words in String (LeetCode #151)
9. Find Closest Palindrome (LeetCode #564)
10. Shortest Palindrome (LeetCode #214)
*/
