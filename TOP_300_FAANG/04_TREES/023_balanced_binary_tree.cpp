/*
================================================================================
PROBLEM: Balanced Binary Tree (LeetCode #110)
DIFFICULTY: Easy
PATTERN: Tree Traversal / DFS
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;
        
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Is balanced: " << (sol.isBalanced(root) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximum Depth of Binary Tree (LeetCode #104)
2. Minimum Depth of Binary Tree (LeetCode #111)
3. Diameter of Binary Tree (LeetCode #543)
4. Binary Tree Maximum Path Sum (LeetCode #124)
5. Validate Binary Search Tree (LeetCode #98)
6. Symmetric Tree (LeetCode #101)
7. Invert Binary Tree (LeetCode #226)
8. Convert Sorted Array to BST (LeetCode #108)
9. Same Tree (LeetCode #100)
10. Subtree of Another Tree (LeetCode #572)
*/
