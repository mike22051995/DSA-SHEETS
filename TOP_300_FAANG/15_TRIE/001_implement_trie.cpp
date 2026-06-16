/*
================================================================================
PROBLEM: Implement Trie (Prefix Tree) (LeetCode #208)
DIFFICULTY: Medium
PATTERN: Trie Data Structure
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search apple: " << (trie.search("apple") ? "true" : "false") << endl;
    cout << "Search app: " << (trie.search("app") ? "true" : "false") << endl;
    cout << "Starts with app: " << (trie.startsWith("app") ? "true" : "false") << endl;
    trie.insert("app");
    cout << "Search app: " << (trie.search("app") ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Design Add and Search Words (LeetCode #211)
2. Word Search II (LeetCode #212)
3. Replace Words (LeetCode #648)
4. Implement Magic Dictionary (LeetCode #676)
5. Longest Word in Dictionary (LeetCode #720)
6. Top K Frequent Words (LeetCode #692)
7. Design Search Autocomplete (LeetCode #642)
8. Stream of Characters (LeetCode #1032)
9. Prefix and Suffix Search (LeetCode #745)
10. Maximum XOR of Two Numbers (LeetCode #421)
*/
