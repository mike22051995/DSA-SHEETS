/*
PROBLEM: Validate Binary Search Tree (LeetCode 98)
DIFFICULTY: Medium
PATTERN: BST Validation - Range Checking

DESCRIPTION:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree contains only nodes with keys greater than the node's key.
- Both left and right subtrees must also be binary search trees.

EXAMPLE:
Input: root = [2,1,3]
    2
   / \
  1   3
Output: true

Input: root = [5,1,4,null,null,3,6]
    5
   / \
  1   4
     / \
    3   6
Output: false (3 < 5 but it's in right subtree)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
#include <climits>
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
    // Approach 1: Range Validation (Best approach)
    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;
        
        // Current node must be in valid range
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        
        // Left subtree: all values must be < root->val
        // Right subtree: all values must be > root->val
        return isValidBSTHelper(root->left, minVal, root->val) &&
               isValidBSTHelper(root->right, root->val, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
    
    // Approach 2: Inorder Traversal (should be sorted)
    void inorder(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
    
    bool isValidBSTInorder(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        
        // Check if strictly increasing
        for (int i = 1; i < values.size(); i++) {
            if (values[i] <= values[i-1]) return false;
        }
        return true;
    }
    
    // Approach 3: Inorder with prev pointer (Space optimized)
    TreeNode* prev = nullptr;
    
    bool isValidBSTInorderOptimized(TreeNode* root) {
        if (root == nullptr) return true;
        
        // Check left subtree
        if (!isValidBSTInorderOptimized(root->left)) return false;
        
        // Check current node with previous
        if (prev != nullptr && root->val <= prev->val) return false;
        prev = root;
        
        // Check right subtree
        return isValidBSTInorderOptimized(root->right);
    }
};

TreeNode* createValidBST() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* createInvalidBST() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* validBST = createValidBST();
    cout << "Valid BST (Range): " << (sol.isValidBST(validBST) ? "Yes" : "No") << endl;
    cout << "Valid BST (Inorder): " << (sol.isValidBSTInorder(validBST) ? "Yes" : "No") << endl;
    
    TreeNode* invalidBST = createInvalidBST();
    cout << "\nInvalid BST (Range): " << (sol.isValidBST(invalidBST) ? "Yes" : "No") << endl;
    cout << "Invalid BST (Inorder): " << (sol.isValidBSTInorder(invalidBST) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
EXPLANATION:

Approach 1: Range Validation (BEST)
- Each node must be in a valid range [min, max]
- For left child: range is [min, parent_val)
- For right child: range is (parent_val, max]
- Start with root in range (-∞, +∞)

Approach 2: Inorder Traversal
- For valid BST, inorder gives sorted array
- Do inorder, store values, check if strictly increasing
- Space: O(n) to store all values

Approach 3: Inorder with Previous
- Same idea but track only previous node
- Space: O(h) for recursion stack only

COMMON MISTAKES:
1. Only checking immediate children (wrong!)
   Example: [5,1,4,null,null,3,6] - 3 < 5 but in right subtree
2. Not handling INT_MIN/INT_MAX edge cases
3. Allowing equal values (BST requires strictly less/greater)

WHY RANGE APPROACH IS BEST:
- Catches all violations
- Clean and intuitive
- No extra space for values

OUTPUT:
Valid BST (Range): Yes
Valid BST (Inorder): Yes

Invalid BST (Range): No
Invalid BST (Inorder): No
*/
