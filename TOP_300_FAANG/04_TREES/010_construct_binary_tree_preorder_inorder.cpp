/*
================================================================================
PROBLEM: Construct Binary Tree from Preorder and Inorder (LeetCode #105)
DIFFICULTY: Medium
PATTERN: Tree Construction with Hash Map
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<int, int> inorderMap;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build map for fast lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = inorderMap[rootVal];
        int leftSize = rootIndex - inStart;
        
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                          inorder, inStart, rootIndex - 1);
        
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                           inorder, rootIndex + 1, inEnd);
        
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
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Construct Binary Tree from Inorder and Postorder (LeetCode #106)
2. Construct Binary Tree from Preorder and Postorder (LeetCode #889)
3. Serialize and Deserialize Binary Tree (LeetCode #297)
4. Serialize and Deserialize BST (LeetCode #449)
5. Verify Preorder Serialization (LeetCode #331)
6. Recover Binary Search Tree (LeetCode #99)
7. Convert Sorted Array to BST (LeetCode #108)
8. Convert Sorted List to BST (LeetCode #109)
9. Flatten Binary Tree to Linked List (LeetCode #114)
10. Find Duplicate Subtrees (LeetCode #652)
*/
