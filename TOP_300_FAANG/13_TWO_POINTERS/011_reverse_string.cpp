/*
================================================================================
PROBLEM: Reverse String (LeetCode #344)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Write a function that reverses a string. The input string is given as an array
of characters s. You must do this by modifying the input array in-place with
O(1) extra memory.

EXAMPLES:

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

PATTERN RECOGNITION:
Use this pattern when:
- In-place array reversal needed
- Two pointers from both ends
- Constant space constraint
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;
    
    vector<char> s1 = {'h','e','l','l','o'};
    sol.reverseString(s1);
    cout << "Reversed: ";
    for (char c : s1) {
        cout << c;
    }
    cout << endl;
    
    vector<char> s2 = {'H','a','n','n','a','h'};
    sol.reverseString(s2);
    cout << "Reversed: ";
    for (char c : s2) {
        cout << c;
    }
    cout << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is length of string
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Reverse String II (LeetCode #541)
2. Reverse Words in String (LeetCode #151)
3. Reverse Words in String III (LeetCode #557)
4. Reverse Vowels of String (LeetCode #345)
5. Valid Palindrome (LeetCode #125)
6. Valid Palindrome II (LeetCode #680)
7. Reverse Linked List (LeetCode #206)
8. Reverse Linked List II (LeetCode #92)
9. Reverse Nodes in k-Group (LeetCode #25)
10. Rotate Array (LeetCode #189)
*/
