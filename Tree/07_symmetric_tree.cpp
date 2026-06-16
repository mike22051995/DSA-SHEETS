/*
PROBLEM: Symmetric Tree (LeetCode 101)
DIFFICULTY: Easy
PATTERN: DFS - Mirror Comparison

DESCRIPTION:
Given the root of a binary tree, check whether it is a mirror of itself
(i.e., symmetric around its center).

EXAMPLE:
Input: root = [1,2,2,3,4,4,3]
       1
      / \
     2   2
    / \ / \
   3  4 4  3
Output: true

Input: root = [1,2,2,null,3,null,3]
       1
      / \
     2   2
      \   \
       3   3
Output: false

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
#include <queue>
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
    // Helper function to check if two trees are mirrors
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both null - symmetric
        if (left == nullptr && right == nullptr) return true;
        
        // One null, other not - not symmetric
        if (left == nullptr || right == nullptr) return false;
        
        // Values must match and subtrees must be mirrors
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&   // outer pair
               isMirror(left->right, right->left);     // inner pair
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
    
    // Iterative approach using queue
    bool isSymmetricIterative(TreeNode* root) {
        if (root == nullptr) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;
            if (left->val != right->val) return false;
            
            // Add outer pair
            q.push(left->left);
            q.push(right->right);
            
            // Add inner pair
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
};

TreeNode* createSymmetricTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSymmetricTree();
    
    cout << "Is Symmetric (Recursive): " 
         << (sol.isSymmetric(root) ? "Yes" : "No") << endl;
    
    cout << "Is Symmetric (Iterative): " 
         << (sol.isSymmetricIterative(root) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
EXPLANATION:

Recursive Approach:
- A tree is symmetric if left subtree is mirror of right subtree
- Two trees are mirrors if:
  1. Their root values are same
  2. Left subtree of one is mirror of right subtree of other
  3. Right subtree of one is mirror of left subtree of other

Key insight: Compare outer pairs (left.left with right.right)
            and inner pairs (left.right with right.left)

Iterative Approach:
- Use queue to store pairs of nodes to compare
- Always push nodes in pairs: (left.left, right.right) and (left.right, right.left)
- If any pair doesn't match, return false

PATTERN:
This "mirror comparison" pattern appears in many problems:
- Symmetric tree
- Same tree
- Subtree of another tree

OUTPUT:
Is Symmetric (Recursive): Yes
Is Symmetric (Iterative): Yes
*/
