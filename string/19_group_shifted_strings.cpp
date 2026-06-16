/*
    Group Shifted Strings - LeetCode #249 (Premium)
    
    We can shift a string by shifting each of its letters to its successive letter.
    Given an array of strings, group all strings that belong to the same shifting sequence.
    
    Example 1:
    Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
    Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
    
    Example 2:
    Input: strings = ["a"]
    Output: [["a"]]
    
    Explanation:
    "abc" can be shifted to "bcd" by shifting each letter by 1.
    "xyz" can also be shifted to "abc" (wrapping around).
    The key is to find a pattern that uniquely identifies each group.
    
    Time Complexity: O(n * m) where n is number of strings, m is avg length
    Space Complexity: O(n * m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strings) {
            string key = getShiftPattern(str);
            groups[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
private:
    string getShiftPattern(const string& s) {
        if (s.length() == 1) return "0";
        
        string pattern = "";
        for (int i = 1; i < s.length(); i++) {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            pattern += to_string(diff) + ",";
        }
        return pattern;
    }
};

int main() {
    Solution sol;
    
    vector<string> test1 = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> result1 = sol.groupStrings(test1);
    
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
