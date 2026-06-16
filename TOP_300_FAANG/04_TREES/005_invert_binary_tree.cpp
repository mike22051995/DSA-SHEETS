/*
================================================================================
PROBLEM: Invert Binary Tree (LeetCode #226)
DIFFICULTY: Easy
PATTERN: Tree Traversal (DFS/BFS)
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================
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
    // Recursive DFS
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        return root;
    }
    
    // Iterative BFS
    TreeNode* invertTreeBFS(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            swap(node->left, node->right);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        return root;
    }
};

int main() {
    Solution sol;
    
    // Create tree:     4
    //                /   \
    //               2     7
    //              / \   / \
    //             1   3 6   9
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    root = sol.invertTree(root);
    cout << "Tree inverted successfully!" << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Symmetric Tree (LeetCode #101)
2. Mirror Reflection (LeetCode #858)
3. Flip Equivalent Binary Trees (LeetCode #951)
4. Maximum Depth of Binary Tree (LeetCode #104)
5. Minimum Depth of Binary Tree (LeetCode #111)
6. Same Tree (LeetCode #100)
7. Subtree of Another Tree (LeetCode #572)
8. Merge Two Binary Trees (LeetCode #617)
9. Binary Tree Paths (LeetCode #257)
10. Sum of Left Leaves (LeetCode #404)
*/
