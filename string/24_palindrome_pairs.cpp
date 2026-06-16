/*
    Palindrome Pairs - LeetCode #336
    
    Given a list of unique words, return all the pairs of distinct indices (i, j) in the
    given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.
    
    Example 1:
    Input: words = ["abcd","dcba","lls","s","sssll"]
    Output: [[0,1],[1,0],[3,2],[2,4]]
    Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
    
    Example 2:
    Input: words = ["bat","tab","cat"]
    Output: [[0,1],[1,0]]
    Explanation: The palindromes are ["battab","tabbat"]
    
    Example 3:
    Input: words = ["a",""]
    Output: [[0,1],[1,0]]
    
    Constraints:
    - 1 <= words.length <= 5000
    - 0 <= words[i].length <= 300
    - words[i] consists of lowercase English letters
    
    Time Complexity: O(n * k^2) where k is average word length
    Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> wordMap;
        
        // Build word to index map
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int len = word.length();
            
            // Check all possible splits
            for (int j = 0; j <= len; j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                
                // If left is palindrome, check if reverse of right exists
                if (isPalindrome(left)) {
                    string reverseRight = right;
                    reverse(reverseRight.begin(), reverseRight.end());
                    
                    if (wordMap.count(reverseRight) && wordMap[reverseRight] != i) {
                        result.push_back({wordMap[reverseRight], i});
                    }
                }
                
                // If right is palindrome, check if reverse of left exists
                // j != len to avoid duplicates
                if (j != len && isPalindrome(right)) {
                    string reverseLeft = left;
                    reverse(reverseLeft.begin(), reverseLeft.end());
                    
                    if (wordMap.count(reverseLeft) && wordMap[reverseLeft] != i) {
                        result.push_back({i, wordMap[reverseLeft]});
                    }
                }
            }
        }
        
        return result;
    }
    
private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<string> words1 = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> result1 = sol.palindromePairs(words1);
    cout << "Test 1: ";
    for (const auto& pair : result1) {
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }
    cout << endl;
    
    // Test 2
    vector<string> words2 = {"bat", "tab", "cat"};
    vector<vector<int>> result2 = sol.palindromePairs(words2);
    cout << "Test 2: ";
    for (const auto& pair : result2) {
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
