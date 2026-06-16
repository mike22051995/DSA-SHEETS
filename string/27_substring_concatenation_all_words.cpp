/*
    Substring with Concatenation of All Words - LeetCode #30
    
    You are given a string s and an array of strings words. All the strings of words are of
    the same length. A concatenated substring in s is a substring that contains all the strings
    of any permutation of words concatenated.
    
    Return the starting indices of all the concatenated substrings in s.
    
    Example 1:
    Input: s = "barfoothefoobarman", words = ["foo","bar"]
    Output: [0,9]
    Explanation: The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"].
    The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"].
    
    Example 2:
    Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
    Output: []
    Explanation: There is no concatenated substring.
    
    Example 3:
    Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
    Output: [6,9,12]
    
    Constraints:
    - 1 <= s.length <= 10^4
    - 1 <= words.length <= 5000
    - 1 <= words[i].length <= 30
    - s and words[i] consist of lowercase English letters
    
    Time Complexity: O(n * m * len) where n is length of s, m is number of words
    Space Complexity: O(m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        if (s.length() < totalLen) return result;
        
        // Count frequency of each word
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        // Check each possible starting position
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> windowFreq;
            
            for (int right = i; right <= s.length() - wordLen; right += wordLen) {
                string word = s.substr(right, wordLen);
                
                if (wordFreq.count(word)) {
                    windowFreq[word]++;
                    count++;
                    
                    // If word appears more than needed, shrink window
                    while (windowFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    // If all words matched
                    if (count == wordCount) {
                        result.push_back(left);
                        
                        // Move left pointer
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // Reset window
                    windowFreq.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = sol.findSubstring("barfoothefoobarman", words1);
    cout << "Test 1: ";
    for (int idx : result1) cout << idx << " ";
    cout << endl;
    
    // Test 2
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = sol.findSubstring("wordgoodgoodgoodbestword", words2);
    cout << "Test 2: ";
    for (int idx : result2) cout << idx << " ";
    cout << endl;
    
    // Test 3
    vector<string> words3 = {"bar", "foo", "the"};
    vector<int> result3 = sol.findSubstring("barfoofoobarthefoobarman", words3);
    cout << "Test 3: ";
    for (int idx : result3) cout << idx << " ";
    cout << endl;
    
    return 0;
}
