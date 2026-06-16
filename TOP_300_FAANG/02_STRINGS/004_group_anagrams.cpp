/*
================================================================================
PROBLEM: Group Anagrams (LeetCode #49)
DIFFICULTY: Medium
PATTERN: Hash Table / Sorting
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Sorting as key
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
    // Character count as key
    vector<vector<string>> groupAnagramsCount(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string& s : strs) {
            string key = getKey(s);
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
    string getKey(string& s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string key;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                key += string(count[i], 'a' + i);
            }
        }
        return key;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto result = sol.groupAnagrams(strs);
    
    cout << "Grouped anagrams:" << endl;
    for (auto& group : result) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Anagram (LeetCode #242)
2. Find All Anagrams in String (LeetCode #438)
3. Group Shifted Strings (LeetCode #249)
4. Encode and Decode Strings (LeetCode #271)
5. Sort Characters By Frequency (LeetCode #451)
6. Top K Frequent Words (LeetCode #692)
7. Custom Sort String (LeetCode #791)
8. Minimum Index Sum of Two Lists (LeetCode #599)
9. Uncommon Words from Two Sentences (LeetCode #884)
10. Design HashMap (LeetCode #706)
*/
