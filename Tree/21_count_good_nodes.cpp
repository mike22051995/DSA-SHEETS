/*
PROBLEM: Count Good Nodes in Binary Tree (LeetCode 1448)
DIFFICULTY: Medium
PATTERN: DFS with Path Tracking

DESCRIPTION:
Given a binary tree root, a node X is named good if in the path from root to X,
there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

EXAMPLE:
Input: root = [3,1,4,3,null,1,5]
       3
      / \
     1   4
    /   / \
   3   1   5
Output: 4 (Nodes 3, 4, 3, 5)

Input: root = [3,3,null,4,2]
       3
      /
     3
    / \
   4   2
Output: 3

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
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
    int dfs(TreeNode* root, int maxSoFar) {
        if (root == nullptr) return 0;
        
        int count = 0;
        
        // Check if current node is good
        if (root->val >= maxSoFar) {
            count = 1;
        }
        
        // Update max value for children
        int newMax = max(maxSoFar, root->val);
        
        // Count good nodes in left and right subtrees
        count += dfs(root->left, newMax);
        count += dfs(root->right, newMax);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    cout << "Number of good nodes: " << sol.goodNodes(root) << endl;
    
    return 0;
}

/*
EXPLANATION:

A node is "good" if no node in the path from root to it has a greater value.

ALGORITHM:
1. Track the maximum value seen so far in the path
2. At each node:
   - If current value >= max so far → it's a good node
   - Update max for children
   - Recursively count good nodes in subtrees

EXAMPLE WALKTHROUGH:
Tree: [3,1,4,3,null,1,5]

Path to each node:
- 3: path [3], max=3, 3>=3 ✓ GOOD
- 1: path [3,1], max=3, 1>=3 ✗
- 4: path [3,4], max=3, 4>=3 ✓ GOOD
- 3 (left child of 1): path [3,1,3], max=3, 3>=3 ✓ GOOD
- 1 (left child of 4): path [3,4,1], max=4, 1>=4 ✗
- 5: path [3,4,5], max=4, 5>=4 ✓ GOOD

Total: 4 good nodes

KEY INSIGHT:
Pass down the maximum value seen in path so far.
Each node compares itself with this max.

PATTERN:
Top-down DFS with path information:
- Path sum problems
- Good nodes
- Root to leaf paths

OUTPUT:
Number of good nodes: 4
*/
