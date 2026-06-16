/*
    Group Anagrams - LeetCode #49
    
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    
    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    
    Example 2:
    Input: strs = [""]
    Output: [[""]]
    
    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]
    
    Constraints:
    - 1 <= strs.length <= 10^4
    - 0 <= strs[i].length <= 100
    - strs[i] consists of lowercase English letters
    
    Time Complexity: O(n * k log k) where k is max length of string
    Space Complexity: O(n * k)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Sorting as Key
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            groups[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
    // Approach 2: Character Count as Key
    vector<vector<string>> groupAnagramsCount(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            string key = getKey(str);
            groups[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
private:
    string getKey(const string& str) {
        vector<int> count(26, 0);
        for (char c : str) {
            count[c - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                key += char('a' + i);
                key += to_string(count[i]);
            }
        }
        return key;
    }
};

int main() {
    Solution sol;
    
    vector<string> test1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = sol.groupAnagrams(test1);
    
    cout << "Test 1:" << endl;
    for (const auto& group : result1) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
