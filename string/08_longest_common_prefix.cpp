/*
    Longest Common Prefix - LeetCode #14
    
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    
    Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
    
    Constraints:
    - 1 <= strs.length <= 200
    - 0 <= strs[i].length <= 200
    - strs[i] consists of only lowercase English letters
    
    Time Complexity: O(S) where S is sum of all characters
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Vertical Scanning
    string longestCommonPrefix(vector<string>& strs) {
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
    
    // Approach 2: Horizontal Scanning
    string longestCommonPrefixHorizontal(vector<string>& strs) {
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
    
    // Approach 3: Using Sorting
    string longestCommonPrefixSort(vector<string>& strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        int i = 0;
        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};

int main() {
    Solution sol;
    
    vector<string> test1 = {"flower", "flow", "flight"};
    cout << "Test 1: " << sol.longestCommonPrefix(test1) << endl;  // "fl"
    
    vector<string> test2 = {"dog", "racecar", "car"};
    cout << "Test 2: " << sol.longestCommonPrefix(test2) << endl;  // ""
    
    vector<string> test3 = {"interspecies", "interstellar", "interstate"};
    cout << "Test 3: " << sol.longestCommonPrefix(test3) << endl;  // "inters"
    
    return 0;
}
