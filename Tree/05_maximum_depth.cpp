/*
PROBLEM: Maximum Depth of Binary Tree (LeetCode 104)
DIFFICULTY: Easy
PATTERN: DFS - Height Calculation

DESCRIPTION:
Given the root of a binary tree, return its maximum depth.
Maximum depth is the number of nodes along the longest path from root to leaf.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: 3

Input: root = [1,null,2]
       1
        \
         2
Output: 2

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack, h is height
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Approach 1: Recursive DFS (Most elegant)
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
    
    // Approach 2: BFS Level Order
    int maxDepthBFS(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            depth++;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return depth;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    cout << "Maximum Depth (DFS): " << sol.maxDepth(root) << endl;
    cout << "Maximum Depth (BFS): " << sol.maxDepthBFS(root) << endl;
    
    return 0;
}

/*
EXPLANATION:

DFS Approach (Recursive):
- Base case: null node has depth 0
- For any node, its depth = 1 + max(left_depth, right_depth)
- This is a bottom-up approach

BFS Approach:
- Count number of levels in the tree
- Each level adds 1 to depth
- Process level by level using queue

WHEN TO USE WHICH:
- DFS: More intuitive, cleaner code, less space for balanced trees
- BFS: Better for very deep trees (prevents stack overflow)

KEY INSIGHT:
This is a fundamental pattern - many tree problems ask you to
compute something based on the depth/height of subtrees.

OUTPUT:
Maximum Depth (DFS): 3
Maximum Depth (BFS): 3
*/
