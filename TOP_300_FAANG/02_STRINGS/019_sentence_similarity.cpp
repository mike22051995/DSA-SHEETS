/*
================================================================================
PROBLEM: Sentence Similarity (LeetCode #734)
DIFFICULTY: Easy
PATTERN: Hash Set
COMPANIES: Amazon, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, 
                             vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        
        unordered_set<string> pairSet;
        
        for (auto& pair : similarPairs) {
            pairSet.insert(pair[0] + "#" + pair[1]);
            pairSet.insert(pair[1] + "#" + pair[0]);
        }
        
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            
            string key = sentence1[i] + "#" + sentence2[i];
            if (pairSet.find(key) == pairSet.end()) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> s1 = {"great", "acting", "skills"};
    vector<string> s2 = {"fine", "drama", "talent"};
    vector<vector<string>> pairs = {{"great","fine"},{"acting","drama"},{"skills","talent"}};
    
    cout << "Are sentences similar: " << (sol.areSentencesSimilar(s1, s2, pairs) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sentence Similarity II (LeetCode #737)
2. Accounts Merge (LeetCode #721)
3. Evaluate Division (LeetCode #399)
4. Most Stones Removed (LeetCode #947)
5. Redundant Connection (LeetCode #684)
6. Number of Connected Components (LeetCode #323)
7. Graph Valid Tree (LeetCode #261)
8. Word Pattern (LeetCode #290)
9. Isomorphic Strings (LeetCode #205)
10. Word Pattern II (LeetCode #291)
*/
