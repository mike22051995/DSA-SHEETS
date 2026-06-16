/*
================================================================================
PROBLEM: Replace Words (LeetCode #648)
DIFFICULTY: Medium
PATTERN: Trie
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    
    TrieNode() {
        children.resize(26, nullptr);
        isEnd = false;
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
    }
    
    string findRoot(string word) {
        TrieNode* node = root;
        string prefix;
        
        for (char c : word) {
            int index = c - 'a';
            
            if (!node->children[index]) {
                return word;
            }
            
            prefix += c;
            node = node->children[index];
            
            if (node->isEnd) {
                return prefix;
            }
        }
        
        return word;
    }
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        
        for (string& word : dictionary) {
            insert(word);
        }
        
        stringstream ss(sentence);
        string word;
        string result;
        
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += findRoot(word);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    
    cout << "Result: " << sol.replaceWords(dictionary, sentence) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Implement Trie (LeetCode #208)
2. Add and Search Words (LeetCode #211)
3. Word Search II (LeetCode #212)
4. Longest Word in Dictionary (LeetCode #720)
5. Prefix and Suffix Search (LeetCode #745)
6. Design Search Autocomplete System (LeetCode #642)
7. Stream of Characters (LeetCode #1032)
8. Search Suggestions System (LeetCode #1268)
9. Design File System (LeetCode #1166)
10. Delete Duplicate Folders (LeetCode #1948)
*/
