/*
PROBLEM: Balanced Binary Tree (LeetCode 110)
DIFFICULTY: Easy
PATTERN: DFS - Height with Balance Check

DESCRIPTION:
Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is one where the depth of the two subtrees 
of every node never differs by more than 1.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Output: false

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
#include <algorithm>
#include <cmath>
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
    // Optimized approach: Return -1 for unbalanced, height otherwise
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Check left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;  // Left subtree unbalanced
        
        // Check right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;  // Right subtree unbalanced
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Current node unbalanced
        }
        
        // Return height if balanced
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    // Alternative: Naive approach (less efficient)
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    bool isBalancedNaive(TreeNode* root) {
        if (root == nullptr) return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Check current node and recurse
        return abs(leftHeight - rightHeight) <= 1 &&
               isBalancedNaive(root->left) &&
               isBalancedNaive(root->right);
    }
};

TreeNode* createBalancedTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createUnbalancedTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* balanced = createBalancedTree();
    cout << "Balanced tree (Optimized): " 
         << (sol.isBalanced(balanced) ? "Yes" : "No") << endl;
    cout << "Balanced tree (Naive): " 
         << (sol.isBalancedNaive(balanced) ? "Yes" : "No") << endl;
    
    TreeNode* unbalanced = createUnbalancedTree();
    cout << "\nUnbalanced tree (Optimized): " 
         << (sol.isBalanced(unbalanced) ? "Yes" : "No") << endl;
    cout << "Unbalanced tree (Naive): " 
         << (sol.isBalancedNaive(unbalanced) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
EXPLANATION:

Two Approaches:

1. Optimized (Single Pass) - O(n):
   - Use -1 as a signal for "unbalanced"
   - While calculating height, also check balance
   - If any subtree is unbalanced, propagate -1 upward
   - Otherwise, return actual height
   - This avoids recalculating heights!

2. Naive (Multiple Passes) - O(n²) worst case:
   - For each node, calculate heights of both subtrees
   - Check if difference > 1
   - Recursively check if children are balanced
   - Problem: Recalculates height for same nodes multiple times

WHY OPTIMIZED IS BETTER:
Naive approach calculates height repeatedly:
- For root: calculates height of all nodes
- For each child: calculates height of their subtrees again
- In skewed tree, this becomes O(n²)

Optimized calculates height once while checking balance!

KEY INSIGHT:
Use return value to communicate TWO things:
1. Is balanced? (if -1, not balanced)
2. What's the height? (if not -1, that's the height)

PATTERN:
"Bottom-up" tree validation while computing property.
Similar pattern in:
- Diameter calculation
- Path sum problems
- Subtree checks

OUTPUT:
Balanced tree (Optimized): Yes
Balanced tree (Naive): Yes

Unbalanced tree (Optimized): No
Unbalanced tree (Naive): No
*/
