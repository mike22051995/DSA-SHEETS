/*
================================================================================
PROBLEM: Construct Binary Tree from Inorder and Postorder (LeetCode #106)
DIFFICULTY: Medium
PATTERN: Tree Construction / Recursion
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int postIdx = postorder.size() - 1;
        
        return build(postorder, inorderMap, postIdx, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& inorderMap, 
                    int& postIdx, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIdx = inorderMap[rootVal];
        
        // Build right subtree first (postorder: left -> right -> root)
        root->right = build(postorder, inorderMap, postIdx, inIdx + 1, inEnd);
        root->left = build(postorder, inorderMap, postIdx, inStart, inIdx - 1);
        
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    
    TreeNode* root = sol.buildTree(inorder, postorder);
    
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Construct Binary Tree from Preorder and Inorder (LeetCode #105)
2. Construct Binary Search Tree from Preorder (LeetCode #1008)
3. Serialize and Deserialize Binary Tree (LeetCode #297)
4. Verify Preorder Serialization (LeetCode #331)
5. Find Duplicate Subtrees (LeetCode #652)
6. Convert Sorted Array to BST (LeetCode #108)
7. Convert Sorted List to BST (LeetCode #109)
8. Maximum Binary Tree (LeetCode #654)
9. Recover Binary Search Tree (LeetCode #99)
10. Unique Binary Search Trees II (LeetCode #95)
*/
