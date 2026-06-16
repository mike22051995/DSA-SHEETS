/*
PROBLEM: Lowest Common Ancestor of a Binary Tree (LeetCode 236)
DIFFICULTY: Medium
PATTERN: LCA - Recursive Search

DESCRIPTION:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes.
LCA is the lowest node that has both p and q as descendants (a node can be a descendant of itself).

EXAMPLE:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
Output: 3 (LCA of 5 and 1) 

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5 (LCA of 5 and 4, node can be ancestor of itself)

MORE EXAMPLES:

Example 1: Balanced Tree
        6
      /   \
     2     8
    / \   / \
   0   4 7   9
      / \
     3   5
- LCA(2, 8) = 6 (nodes in different subtrees)
- LCA(2, 4) = 2 (ancestor of itself)
- LCA(3, 5) = 4
- LCA(0, 9) = 6

Example 2: Left-Heavy Tree
       10
      /  \
     5    15
    / \
   3   7
  /   / \
 1   6   8
- LCA(1, 8) = 5
- LCA(6, 7) = 7
- LCA(3, 15) = 10

Example 3: Right-Heavy Tree
     1
    / \
   2   3
      / \
     4   5
        / \
       6   7
- LCA(2, 7) = 1
- LCA(4, 6) = 3
- LCA(6, 7) = 5

Example 4: Complete Binary Tree
        1
       / \
      2   3
     / \ / \
    4  5 6  7
- LCA(4, 5) = 2
- LCA(4, 6) = 1
- LCA(6, 7) = 3
- LCA(5, 7) = 1

Example 5: Skewed Tree (Left)
      20
     /
    15
   /
  10
 /
5
- LCA(15, 5) = 15
- LCA(20, 5) = 20
- LCA(10, 5) = 10

Example 6: Skewed Tree (Right)
   1
    \
     2
      \
       3
        \
         4
- LCA(1, 4) = 1
- LCA(2, 4) = 2
- LCA(3, 4) = 3

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: reached null or found one of the nodes
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are non-null, root is LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // Otherwise return the non-null one (or null if both are null)
        return left != nullptr ? left : right;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->right;       // Node 1
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    
    p = root->left;                  // Node 5
    q = root->left->right->right;    // Node 4
    lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    
    p = root->left->left;            // Node 6
    q = root->left->right->right;    // Node 4
    lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    
    return 0;
}

/*
EXPLANATION:

The algorithm works on these key insights:

1. If current node is null or equals p or q, return it
   - This handles base case and finding target nodes

2. Recursively search left and right subtrees

3. After recursion, we have 4 cases:
   a) Both left and right are non-null
      → p and q are in different subtrees
      → Current node is LCA!
   
   b) Only left is non-null
      → Both p and q are in left subtree
      → Return left result
   
   c) Only right is non-null
      → Both p and q are in right subtree
      → Return right result
   
   d) Both are null
      → Neither p nor q found in this subtree
      → Return null

BEAUTIFUL RECURSION:
The magic is that each recursive call returns:
- The LCA if both nodes are in its subtree
- The found node if only one is in its subtree
- null if neither is in its subtree

TIME: O(n) - might visit all nodes
SPACE: O(h) - recursion stack

IMPORTANT:
This works because we're guaranteed p and q exist in the tree.
If not guaranteed, we'd need to verify both are found.

OUTPUT:
LCA of 5 and 1 is: 3
LCA of 5 and 4 is: 5
LCA of 6 and 4 is: 5
*/
