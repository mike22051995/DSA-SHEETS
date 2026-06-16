/*
================================================================================
PROBLEM: Path Sum II (LeetCode #113)
DIFFICULTY: Medium
PATTERN: Tree DFS / Backtracking
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
    
    void dfs(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;
        
        path.push_back(node->val);
        
        if (!node->left && !node->right && sum == node->val) {
            result.push_back(path);
        }
        
        dfs(node->left, sum - node->val, path, result);
        dfs(node->right, sum - node->val, path, result);
        
        path.pop_back();
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    
    vector<vector<int>> paths = sol.pathSum(root, 22);
    
    cout << "All paths with sum 22:" << endl;
    for (auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Path Sum (LeetCode #112)
2. Path Sum III (LeetCode #437)
3. Path Sum IV (LeetCode #666)
4. Binary Tree Paths (LeetCode #257)
5. Sum Root to Leaf Numbers (LeetCode #129)
6. Smallest String Starting From Leaf (LeetCode #988)
7. Insufficient Nodes in Root to Leaf (LeetCode #1080)
8. Maximum Difference Between Node and Ancestor (LeetCode #1026)
9. Pseudo-Palindromic Paths (LeetCode #1457)
10. Step-By-Step Directions (LeetCode #2096)
*/
