/*
================================================================================
PROBLEM: Longest Common Prefix (LeetCode #14)
DIFFICULTY: Easy
PATTERN: String Matching
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
    
    // Vertical scanning
    string longestCommonPrefixVertical(vector<string>& strs) {
        if (strs.empty()) return "";
        
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
    
    // Binary search approach
    string longestCommonPrefixBinarySearch(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int minLen = INT_MAX;
        for (string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }
        
        int left = 0, right = minLen;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isCommonPrefix(strs, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return strs[0].substr(0, (left + right) / 2);
    }
    
    bool isCommonPrefix(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].find(prefix) != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> strs1 = {"flower","flow","flight"};
    vector<string> strs2 = {"dog","racecar","car"};
    
    cout << "LCP: " << sol.longestCommonPrefix(strs1) << endl;
    cout << "LCP: " << sol.longestCommonPrefix(strs2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Common Subsequence (LeetCode #1143)
2. Find Words That Can Be Formed (LeetCode #1408)
3. Delete Columns to Make Sorted (LeetCode #944)
4. Verifying an Alien Dictionary (LeetCode #953)
5. Shortest Way to Form String (LeetCode #1055)
6. Compare Version Numbers (LeetCode #165)
7. Camelcase Matching (LeetCode #1023)
8. Implement Trie (LeetCode #208)
9. Design Add and Search Words (LeetCode #211)
10. Search Suggestions System (LeetCode #1268)
*/
