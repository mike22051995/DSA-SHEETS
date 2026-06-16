/*
PROBLEM: Print All Subsequences of a String
---------------------------------------------------------------------------
Given a string, print all possible subsequences (subsets) using recursion.
A subsequence is a sequence derived by deleting some or no characters 
without changing the order of remaining characters.

DIFFICULTY: Medium
PATTERN: Recursion Tree (Include/Exclude)
TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "abc"
Output: "", "a", "b", "c", "ab", "ac", "bc", "abc"
Explanation: All 2^3 = 8 subsequences

Example 2:
Input: s = "ab"
Output: "", "a", "b", "ab"
Explanation: All 2^2 = 4 subsequences
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> getAllSubsequences(string s) {
        vector<string> result;
        string current = "";
        generateSubsequences(s, 0, current, result);
        return result;
    }
    
    // Print directly without storing
    void printSubsequences(string s) {
        string current = "";
        printHelper(s, 0, current);
    }
    
    // Method 1: Handle duplicates using set
    vector<string> getUniqueSubsequencesSet(string s) {
        set<string> uniqueSet;
        string current = "";
        generateWithSet(s, 0, current, uniqueSet);
        return vector<string>(uniqueSet.begin(), uniqueSet.end());
    }
    
    // Method 2: Handle duplicates by sorting and skipping (Optimal)
    vector<string> getUniqueSubsequencesSkip(string s) {
        sort(s.begin(), s.end());
        vector<string> result;
        string current = "";
        generateWithSkip(s, 0, current, result);
        return result;
    }
    
private:
    void generateSubsequences(string& s, int index, string& current, 
                             vector<string>& result) {
        // Base case: processed all characters
        if (index >= s.length()) {
            result.push_back(current);
            return;
        }
        
        // Exclude current character
        generateSubsequences(s, index + 1, current, result);
        
        // Include current character
        current.push_back(s[index]);
        generateSubsequences(s, index + 1, current, result);
        current.pop_back(); // backtrack
    }
    
    void printHelper(string& s, int index, string& current) {
        if (index >= s.length()) {
            cout << "\"" << current << "\" ";
            return;
        }
        
        // Exclude
        printHelper(s, index + 1, current);
        
        // Include
        current.push_back(s[index]);
        printHelper(s, index + 1, current);
        current.pop_back();
    }
    
    // Helper for set-based approach
    void generateWithSet(string& s, int index, string& current, 
                        set<string>& result) {
        if (index >= s.length()) {
            result.insert(current);
            return;
        }
        
        // Exclude current character
        generateWithSet(s, index + 1, current, result);
        
        // Include current character
        current.push_back(s[index]);
        generateWithSet(s, index + 1, current, result);
        current.pop_back();
    }
    
    // Helper for skip duplicates approach
    void generateWithSkip(string& s, int index, string& current, 
                         vector<string>& result) {
        if (index >= s.length()) {
            result.push_back(current);
            return;
        }
        
        // Include current character
        current.push_back(s[index]);
        generateWithSkip(s, index + 1, current, result);
        current.pop_back();
        
        // Skip all duplicates before excluding
        int j = index;
        while (j < s.length() && s[j] == s[index]) {
            j++;
        }
        
        // Exclude current character (jump to next different character)
        generateWithSkip(s, j, current, result);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "abc";
    cout << "Test 1: Subsequences of '" << s1 << "': ";
    sol.printSubsequences(s1);
    cout << endl;
    
    // Test case 2
    string s2 = "ab";
    vector<string> result = sol.getAllSubsequences(s2);
    cout << "Test 2: Subsequences of '" << s2 << "': ";
    for (const string& sub : result) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
    
    // Test case 3: String with duplicates using set
    string s3 = "aab";
    vector<string> uniqueSet = sol.getUniqueSubsequencesSet(s3);
    cout << "Test 3: Unique subsequences of '" << s3 << "' (using set): ";
    for (const string& sub : uniqueSet) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
    
    // Test case 4: String with duplicates using skip method
    string s4 = "aab";
    vector<string> uniqueSkip = sol.getUniqueSubsequencesSkip(s4);
    cout << "Test 4: Unique subsequences of '" << s4 << "' (skip duplicates): ";
    for (const string& sub : uniqueSkip) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
    
    return 0;
}
