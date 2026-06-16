/*
================================================================================
PROBLEM: Longest Substring with At Most K Distinct Characters (LeetCode #340)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        
        unordered_map<char, int> charCount;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;
            
            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s1 = "eceba";
    string s2 = "aa";
    
    cout << "Length (k=2): " << sol.lengthOfLongestSubstringKDistinct(s1, 2) << endl;
    cout << "Length (k=1): " << sol.lengthOfLongestSubstringKDistinct(s2, 1) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Substring with At Most Two Distinct (LeetCode #159)
2. Longest Substring Without Repeating (LeetCode #3)
3. Fruit Into Baskets (LeetCode #904)
4. Subarrays with K Different Integers (LeetCode #992)
5. Max Consecutive Ones III (LeetCode #1004)
6. Minimum Window Substring (LeetCode #76)
7. Longest Repeating Character Replacement (LeetCode #424)
8. Find All Anagrams in String (LeetCode #438)
9. Permutation in String (LeetCode #567)
10. Grumpy Bookstore Owner (LeetCode #1052)
*/
