/*
PROBLEM: Search Suggestions System
Difficulty: Medium
Pattern: Binary Search + Trie

DESCRIPTION:
You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character 
of searchWord is typed. Suggested products should have common prefix with searchWord. If there 
are more than three products with a common prefix return the three lexicographically minimums.
Return a list of lists of the suggested products after each character of searchWord is typed.

EXPLANATION:
Binary search approach:
1. Sort products array
2. For each prefix of searchWord, use binary search to find start position
3. Collect up to 3 matching products
4. Use lower_bound to find first match efficiently

Time Complexity: O(n log n + m * n) where m = searchWord length
Space Complexity: O(1) excluding output

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],
         ["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

Example 3:
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],
         ["baggage","bags"],["bags"]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix = "";
        
        for (char c : searchWord) {
            prefix += c;
            vector<string> suggestions;
            
            // Binary search for first match
            auto it = lower_bound(products.begin(), products.end(), prefix);
            
            // Collect up to 3 matches
            for (int i = 0; i < 3 && it != products.end(); i++, it++) {
                if (it->substr(0, prefix.length()) == prefix) {
                    suggestions.push_back(*it);
                } else {
                    break;
                }
            }
            
            result.push_back(suggestions);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<string> products1 = {"mobile","mouse","moneypot","monitor","mousepad"};
    vector<vector<string>> result1 = solution.suggestedProducts(products1, "mouse");
    cout << "Test 1: " << result1.size() << " suggestion lists" << endl;
    
    // Test Case 2
    vector<string> products2 = {"havana"};
    vector<vector<string>> result2 = solution.suggestedProducts(products2, "havana");
    cout << "Test 2: " << result2.size() << " suggestion lists" << endl;
    
    // Test Case 3
    vector<string> products3 = {"bags","baggage","banner","box","cloths"};
    vector<vector<string>> result3 = solution.suggestedProducts(products3, "bags");
    cout << "Test 3: " << result3.size() << " suggestion lists" << endl;
    
    return 0;
}
