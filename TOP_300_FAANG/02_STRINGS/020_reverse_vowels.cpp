/*
================================================================================
PROBLEM: Reverse Vowels of a String (LeetCode #345)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    
    cout << "hello -> " << sol.reverseVowels("hello") << endl;
    cout << "leetcode -> " << sol.reverseVowels("leetcode") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse String (LeetCode #344)
2. Reverse String II (LeetCode #541)
3. Valid Palindrome (LeetCode #125)
4. Valid Palindrome II (LeetCode #680)
5. Reverse Words in String (LeetCode #151)
6. Reverse Words in String III (LeetCode #557)
7. Two Sum II (LeetCode #167)
8. Three Sum (LeetCode #15)
9. Container With Most Water (LeetCode #11)
10. Sort Colors (LeetCode #75)
*/
