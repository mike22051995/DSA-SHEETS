/*
================================================================================
PROBLEM: Binary Tree Right Side View (LeetCode #199)
DIFFICULTY: Medium
PATTERN: BFS / DFS
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // BFS approach
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return result;
    }
    
    // DFS approach
    vector<int> rightSideViewDFS(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
    
    void dfs(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;
        
        if (level == result.size()) {
            result.push_back(node->val);
        }
        
        dfs(node->right, level + 1, result);
        dfs(node->left, level + 1, result);
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    vector<int> result = sol.rightSideView(root);
    
    cout << "Right side view: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Binary Tree Left Side View
2. Boundary of Binary Tree (LeetCode #545)
3. Populating Next Right Pointers (LeetCode #116)
4. Binary Tree Vertical Order Traversal (LeetCode #314)
5. Binary Tree Level Order Traversal (LeetCode #102)
6. Binary Tree Zigzag Level Order (LeetCode #103)
7. Vertical Order Traversal (LeetCode #987)
8. Maximum Width of Binary Tree (LeetCode #662)
9. Find Bottom Left Tree Value (LeetCode #513)
10. Average of Levels (LeetCode #637)
*/
