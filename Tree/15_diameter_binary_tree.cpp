/*
PROBLEM: Diameter of Binary Tree (LeetCode 543)
DIFFICULTY: Easy/Medium
PATTERN: DFS - Height with Global Variable

DESCRIPTION:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter is the length of the longest path between any two nodes in a tree.
The path may or may not pass through the root.
The length is measured in number of edges.

EXAMPLE:
Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: 3 (path: [4,2,1,3] or [5,2,1,3])

Input: root = [1,2]
       1
      /
     2
Output: 1

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
private:
    int maxDiameter;
    
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Get height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Diameter passing through current node
        int currentDiameter = leftHeight + rightHeight;
        
        // Update global maximum
        maxDiameter = max(maxDiameter, currentDiameter);
        
        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        height(root);
        return maxDiameter;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

TreeNode* createSkewedTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createSampleTree();
    cout << "Diameter of tree 1: " << sol.diameterOfBinaryTree(root1) << endl;
    
    TreeNode* root2 = createSkewedTree();
    cout << "Diameter of tree 2: " << sol.diameterOfBinaryTree(root2) << endl;
    
    return 0;
}

/*
EXPLANATION:

This is a classic problem that combines height calculation with path analysis.

KEY INSIGHTS:

1. The diameter at any node = leftHeight + rightHeight
   - This gives the longest path passing through this node
   
2. The global diameter = max diameter at any node
   - We need to check every node

3. We can compute this while calculating height:
   - For each node, calculate heights of subtrees
   - Diameter through this node = sum of heights
   - Update global maximum
   - Return height for parent's calculation

ALGORITHM:
1. For each node, recursively get height of left and right subtrees
2. Current diameter = leftHeight + rightHeight (edges)
3. Update global max diameter
4. Return height = 1 + max(leftHeight, rightHeight) to parent

COMMON MISTAKE:
Don't confuse diameter with height!
- Height: longest path from node to leaf
- Diameter: longest path between any two nodes

WHY USE GLOBAL VARIABLE:
Because diameter might not pass through root!
We need to track maximum across all nodes.

PATTERN:
This "calculate something while computing height" pattern
appears in many problems:
- Diameter
- Balanced binary tree
- Maximum path sum

OUTPUT:
Diameter of tree 1: 3
Diameter of tree 2: 4
*/
