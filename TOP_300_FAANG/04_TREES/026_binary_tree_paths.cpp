/*
================================================================================
PROBLEM: Binary Tree Paths (LeetCode #257)
DIFFICULTY: Easy
PATTERN: DFS / Backtracking
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        
        string path = "";
        dfs(root, path, result);
        
        return result;
    }
    
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;
        
        path += to_string(node->val);
        
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        
        path += "->";
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    vector<string> paths = sol.binaryTreePaths(root);
    
    cout << "All root-to-leaf paths:" << endl;
    for (string& path : paths) {
        cout << path << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Path Sum II (LeetCode #113)
2. Sum Root to Leaf Numbers (LeetCode #129)
3. Smallest String Starting From Leaf (LeetCode #988)
4. All Paths From Source to Target (LeetCode #797)
5. Path Sum III (LeetCode #437)
6. Binary Tree Maximum Path Sum (LeetCode #124)
7. Pseudo-Palindromic Paths (LeetCode #1457)
8. Count Good Nodes in Binary Tree (LeetCode #1448)
9. Step-By-Step Directions (LeetCode #2096)
10. Amount of Time for Binary Tree to Be Infected (LeetCode #2385)
*/
