/*
PROBLEM: Group Anagrams (LeetCode 49)
===============================================
DESCRIPTION:
Given an array of strings strs, group the anagrams together. You can return the 
answer in any order. An anagram is a word formed by rearranging the letters of 
a different word.

PATTERN: Sorting for Grouping / HashMap
DIFFICULTY: Medium
TIME COMPLEXITY: O(n * k log k) where n = number of strings, k = max string length
SPACE COMPLEXITY: O(n * k)

INPUT:
Array of strings

OUTPUT:
List of grouped anagrams

EXAMPLE:
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Input: [""]
Output: [[""]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Using sorted string as key
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            // Sort string to get canonical form
            string key = str;
            sort(key.begin(), key.end());
            
            // Add to corresponding group
            groups[key].push_back(str);
        }
        
        // Extract all groups
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
    // Approach 2: Using character count as key (more efficient)
    vector<vector<string>> groupAnagramsCount(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            // Create key from character frequencies
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
    // Create unique key from character frequencies
    string getKey(const string& str) {
        int count[26] = {0};
        for (char c : str) {
            count[c - 'a']++;
        }
        
        // Build key: "a#1b#2c#3..." format
        string key;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                key += char('a' + i);
                key += to_string(count[i]);
                key += '#';
            }
        }
        
        return key;
    }
};

int main() {
    Solution sol;
    
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Input: ";
    for (const string& s : strs1) cout << "\"" << s << "\" ";
    cout << endl;
    
    vector<vector<string>> result1 = sol.groupAnagrams(strs1);
    cout << "Output:" << endl;
    for (const auto& group : result1) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    cout << "\nUsing character count approach:" << endl;
    vector<vector<string>> result2 = sol.groupAnagramsCount(strs1);
    for (const auto& group : result2) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: SORTED STRING AS KEY
1. For each string, sort it to get canonical form
2. Use sorted string as key in hash map
3. All anagrams will have same sorted form
4. Group strings with same key together

Example:
"eat" → sorted: "aet"
"tea" → sorted: "aet"
"ate" → sorted: "aet"
All map to same key "aet"

Time: O(n * k log k) - n strings, each sorted in O(k log k)
Space: O(n * k) - storing all strings

APPROACH 2: CHARACTER COUNT AS KEY
1. Count frequency of each character
2. Create unique key from frequencies
3. Use this key in hash map

Example:
"eat" → key: "a1e1t1#"
"tea" → key: "a1e1t1#"
"ate" → key: "a1e1t1#"

Time: O(n * k) - n strings, each O(k) to count
Space: O(n * k)

WHY CHARACTER COUNT IS BETTER:
- O(n * k) vs O(n * k log k)
- Avoids sorting overhead
- More efficient for long strings

KEY CREATION OPTIONS:
1. Sorted string: "aet"
2. Frequency string: "a1e1t1#"
3. Array as key: [1,0,0,0,1,0...1]
4. Prime product: 2^1 * 3^1 * 5^1 (can overflow)

EDGE CASES:
1. Empty strings [""] → [[""]]
2. Single character ["a"] → [["a"]]
3. No anagrams ["abc","def"] → [["abc"],["def"]]
4. All anagrams ["ab","ba"] → [["ab","ba"]]

VISUALIZATION:
Input: ["eat","tea","tan","ate","nat","bat"]

Hash Map Building:
"aet" → ["eat", "tea", "ate"]
"ant" → ["tan", "nat"]
"abt" → ["bat"]

Result: [["eat","tea","ate"], ["tan","nat"], ["bat"]]

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates sorting for grouping/comparison
- Shows optimization from O(n k log k) to O(n k)
- Common pattern in string problems
- Uses hashing for grouping similar items
- Important for:
  * Finding duplicates
  * Grouping by properties
  * String matching problems
- Very common in FAANG interviews
*/
