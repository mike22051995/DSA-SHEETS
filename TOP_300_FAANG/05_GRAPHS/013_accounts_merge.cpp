/*
================================================================================
PROBLEM: Accounts Merge (LeetCode #721)
DIFFICULTY: Medium
PATTERN: Union Find / DFS
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToId;
        
        // Build union find
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                
                if (emailToId.find(email) != emailToId.end()) {
                    uf.unite(i, emailToId[email]);
                } else {
                    emailToId[email] = i;
                }
            }
        }
        
        // Group emails by account
        unordered_map<int, vector<string>> components;
        
        for (auto& [email, id] : emailToId) {
            int root = uf.find(id);
            components[root].push_back(email);
        }
        
        // Build result
        vector<vector<string>> result;
        
        for (auto& [id, emails] : components) {
            sort(emails.begin(), emails.end());
            vector<string> account = {accounts[id][0]};
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    
    vector<vector<string>> result = sol.accountsMerge(accounts);
    
    cout << "Merged accounts:" << endl;
    for (auto& account : result) {
        for (string& email : account) {
            cout << email << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Redundant Connection (LeetCode #684)
2. Number of Connected Components (LeetCode #323)
3. Sentence Similarity II (LeetCode #737)
4. Most Stones Removed (LeetCode #947)
5. Satisfiability of Equality Equations (LeetCode #990)
6. Smallest String With Swaps (LeetCode #1202)
7. Minimize Malware Spread (LeetCode #924)
8. Number of Operations to Make Network Connected (LeetCode #1319)
9. Evaluate Division (LeetCode #399)
10. Longest Consecutive Sequence (LeetCode #128)
*/
