/*
================================================================================
PROBLEM: Longest Word in Dictionary (LeetCode #720)
DIFFICULTY: Medium
PATTERN: Trie / DFS
COMPANIES: Amazon, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    string word;
    
    TrieNode() {
        children.resize(26, nullptr);
        isEnd = false;
        word = "";
    }
};

class Solution {
private:
    TrieNode* root;
    
    void insert(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        
        node->isEnd = true;
        node->word = word;
    }
    
    string dfs(TrieNode* node) {
        string longest = node->word;
        
        for (TrieNode* child : node->children) {
            if (child && child->isEnd) {
                string childWord = dfs(child);
                
                if (childWord.length() > longest.length() || 
                    (childWord.length() == longest.length() && childWord < longest)) {
                    longest = childWord;
                }
            }
        }
        
        return longest;
    }
    
public:
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        root->isEnd = true;
        
        for (string& word : words) {
            insert(word);
        }
        
        return dfs(root);
    }
};

int main() {
    Solution sol;
    vector<string> words1 = {"w","wo","wor","worl","world"};
    vector<string> words2 = {"a","banana","app","appl","ap","apply","apple"};
    
    cout << "Longest word: " << sol.longestWord(words1) << endl;
    cout << "Longest word: " << sol.longestWord(words2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Implement Trie (LeetCode #208)
2. Longest Common Prefix (LeetCode #14)
3. Longest Uncommon Subsequence II (LeetCode #522)
4. Replace Words (LeetCode #648)
5. Longest Duplicate Substring (LeetCode #1044)
6. Stream of Characters (LeetCode #1032)
7. Longest Happy Prefix (LeetCode #1392)
8. Delete Duplicate Folders (LeetCode #1948)
9. Design File System (LeetCode #1166)
10. Maximum Product of Word Lengths (LeetCode #318)
*/
