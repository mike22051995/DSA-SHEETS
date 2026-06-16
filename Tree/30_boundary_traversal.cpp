/*
PROBLEM: Boundary Traversal of Binary Tree
DIFFICULTY: Medium
PATTERN: Three Separate Traversals

DESCRIPTION:
Given a binary tree, return the boundary traversal in anti-clockwise direction.
Boundary includes:
1. Left boundary (excluding leaf)
2. All leaf nodes (left to right)
3. Right boundary in reverse order (excluding leaf)

EXAMPLE:
Input: root = [1,2,3,4,5,6,7,null,null,8,9]
         1
        / \
       2   3
      / \ / \
     4  5 6  7
       / \
      8   9

Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:
- Left boundary: 1, 2, 4
- Leaves: 8, 9, 6, 7
- Right boundary (reverse): 3
Note: 4, 8, 9, 7 are leaves, so not repeated

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
#include <vector>
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
    // Check if node is leaf
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
    
    // Add left boundary (top to bottom, excluding leaves)
    void addLeftBoundary(TreeNode* root, vector<int>& result) {
        TreeNode* curr = root->left;
        
        while (curr) {
            if (!isLeaf(curr)) {
                result.push_back(curr->val);
            }
            
            // Go left if possible, else go right
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    
    // Add all leaves (left to right)
    void addLeaves(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        if (isLeaf(root)) {
            result.push_back(root->val);
            return;
        }
        
        addLeaves(root->left, result);
        addLeaves(root->right, result);
    }
    
    // Add right boundary (bottom to top, excluding leaves)
    void addRightBoundary(TreeNode* root, vector<int>& result) {
        TreeNode* curr = root->right;
        vector<int> temp;
        
        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->val);
            }
            
            // Go right if possible, else go left
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        // Add in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }
    
    vector<int> boundaryTraversal(TreeNode* root) {
        vector<int> result;
        
        if (root == nullptr) return result;
        
        // Add root if it's not a leaf
        if (!isLeaf(root)) {
            result.push_back(root->val);
        }
        
        // Add left boundary
        addLeftBoundary(root, result);
        
        // Add all leaves
        addLeaves(root, result);
        
        // Add right boundary
        addRightBoundary(root, result);
        
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    return root;
}

TreeNode* createSimpleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createSampleTree();
    vector<int> result1 = sol.boundaryTraversal(root1);
    
    cout << "Boundary Traversal: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;
    
    TreeNode* root2 = createSimpleTree();
    vector<int> result2 = sol.boundaryTraversal(root2);
    
    cout << "Simple tree boundary: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

Boundary traversal goes anti-clockwise around the tree!

THREE PARTS:

1. LEFT BOUNDARY (top to bottom):
   - Start from root's left child
   - Keep going left if possible, else go right
   - Don't include leaves
   - Stop when we reach a leaf

2. LEAVES (left to right):
   - Do inorder-like traversal
   - Add only leaf nodes
   - This covers bottom boundary

3. RIGHT BOUNDARY (bottom to top):
   - Start from root's right child
   - Keep going right if possible, else go left
   - Don't include leaves
   - Collect in temp array and reverse

EXAMPLE WALKTHROUGH:
         1
        / \
       2   3
      / \ / \
     4  5 6  7
       / \
      8   9

Step 1: Root (if not leaf): [1]
Step 2: Left boundary: [1, 2] (not 4, it's a leaf)
Step 3: Leaves left to right: [1, 2, 4, 8, 9, 6, 7]
Step 4: Right boundary reverse: [1, 2, 4, 8, 9, 6, 7, 3]

IMPORTANT CASES:

1. Node on boundary AND leaf:
   - Include only once, as leaf

2. Single node tree:
   - Just return [root]

3. Only left/right subtree:
   - Handle appropriately

ALTERNATIVE VIEWS:
- Left view: leftmost at each level
- Right view: rightmost at each level
- Boundary: outer edge in anti-clockwise

This is a popular interview problem, especially for tree visualization!

OUTPUT:
Boundary Traversal: 1 2 4 8 9 6 7 3
Simple tree boundary: 1 2 4 5 3
*/
