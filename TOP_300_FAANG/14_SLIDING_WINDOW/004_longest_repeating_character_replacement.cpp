/*
================================================================================
PROBLEM: Longest Repeating Character Replacement (LeetCode #424)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int maxCount = 0;
        int left = 0;
        int count[26] = {0};
        
        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            
            // If number of chars to replace > k, shrink window
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << "Max length (ABAB, k=2): " << sol.characterReplacement("ABAB", 2) << endl;
    cout << "Max length (AABABBA, k=1): " << sol.characterReplacement("AABABBA", 1) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Substring Without Repeating (LeetCode #3)
2. Longest Substring with At Most K Distinct (LeetCode #340)
3. Longest Substring At Most Two Distinct (LeetCode #159)
4. Max Consecutive Ones III (LeetCode #1004)
5. Minimum Window Substring (LeetCode #76)
6. Permutation in String (LeetCode #567)
7. Find All Anagrams in String (LeetCode #438)
8. Frequency of Most Frequent Element (LeetCode #1838)
9. Subarrays with K Different Integers (LeetCode #992)
10. Fruit Into Baskets (LeetCode #904)
*/
