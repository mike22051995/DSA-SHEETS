/*
================================================================================
PROBLEM: Design Add and Search Words Data Structure (LeetCode #211)
DIFFICULTY: Medium
PATTERN: Trie / DFS
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;
    
    TrieNode() {
        children.resize(26, nullptr);
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    
    bool searchHelper(string& word, int index, TrieNode* node) {
        if (!node) return false;
        
        if (index == word.length()) {
            return node->isWord;
        }
        
        char c = word[index];
        
        if (c == '.') {
            for (TrieNode* child : node->children) {
                if (child && searchHelper(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            int childIndex = c - 'a';
            return searchHelper(word, index + 1, node->children[childIndex]);
        }
    }
};

int main() {
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    
    cout << "search(pad): " << (dict.search("pad") ? "true" : "false") << endl;
    cout << "search(bad): " << (dict.search("bad") ? "true" : "false") << endl;
    cout << "search(.ad): " << (dict.search(".ad") ? "true" : "false") << endl;
    cout << "search(b..): " << (dict.search("b..") ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Implement Trie (LeetCode #208)
2. Word Search II (LeetCode #212)
3. Replace Words (LeetCode #648)
4. Design Search Autocomplete System (LeetCode #642)
5. Longest Word in Dictionary (LeetCode #720)
6. Stream of Characters (LeetCode #1032)
7. Prefix and Suffix Search (LeetCode #745)
8. Camelcase Matching (LeetCode #1023)
9. Search Suggestions System (LeetCode #1268)
10. Maximum XOR of Two Numbers (LeetCode #421)
*/
