/*
================================================================================
PROBLEM: Minimum Depth of Binary Tree (LeetCode #111)
DIFFICULTY: Easy
PATTERN: BFS / DFS
COMPANIES: Amazon, Microsoft, Facebook
================================================================================
*/

#include <iostream>
#include <queue>
#include <algorithm>
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (!node->left && !node->right) {
                    return depth;
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            depth++;
        }
        
        return depth;
    }
    
    // DFS approach
    int minDepthDFS(TreeNode* root) {
        if (!root) return 0;
        
        if (!root->left) return minDepthDFS(root->right) + 1;
        if (!root->right) return minDepthDFS(root->left) + 1;
        
        return min(minDepthDFS(root->left), minDepthDFS(root->right)) + 1;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Minimum depth: " << sol.minDepth(root) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximum Depth of Binary Tree (LeetCode #104)
2. Balanced Binary Tree (LeetCode #110)
3. Binary Tree Level Order Traversal (LeetCode #102)
4. Path Sum (LeetCode #112)
5. Path Sum II (LeetCode #113)
6. Symmetric Tree (LeetCode #101)
7. Same Tree (LeetCode #100)
8. Count Complete Tree Nodes (LeetCode #222)
9. Find Bottom Left Tree Value (LeetCode #513)
10. Sum Root to Leaf Numbers (LeetCode #129)
*/
