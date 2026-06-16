/*
PROBLEM: Invert Binary Tree (LeetCode 226)
DIFFICULTY: Easy
PATTERN: DFS - Tree Modification

DESCRIPTION:
Given the root of a binary tree, invert the tree, and return its root.
Inverting means swapping left and right children at every node.

EXAMPLE:
Input: root = [4,2,7,1,3,6,9]
       4
      / \
     2   7
    / \ / \
   1  3 6  9

Output: [4,7,2,9,6,3,1]
       4
      / \
     7   2
    / \ / \
   9  6 3  1

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack
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
    // Approach 1: Recursive DFS
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
    
    // Approach 2: BFS Iterative
    TreeNode* invertTreeBFS(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Swap children
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            
            // Add children to queue
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    cout << "Original tree (inorder): ";
    printInorder(root);
    cout << endl;
    
    root = sol.invertTree(root);
    
    cout << "Inverted tree (inorder): ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

Recursive Approach:
1. Base case: if node is null, return null
2. Swap left and right children of current node
3. Recursively invert left subtree
4. Recursively invert right subtree
5. Return root

BFS Approach:
1. Use queue for level-order traversal
2. For each node, swap its children
3. Add children to queue
4. Continue until queue is empty

KEY INSIGHT:
Both approaches work because we swap at every node.
The order doesn't matter - we can swap first then recurse,
or recurse first then swap. Result is the same.

FAMOUS STORY:
Max Howell (creator of Homebrew) was rejected by Google
because he couldn't solve this on the whiteboard!

OUTPUT:
Original tree (inorder): 1 2 3 4 6 7 9
Inverted tree (inorder): 9 7 6 4 3 2 1
*/
