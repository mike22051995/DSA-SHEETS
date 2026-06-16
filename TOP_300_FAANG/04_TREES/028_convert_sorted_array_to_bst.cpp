/*
================================================================================
PROBLEM: Convert Sorted Array to Binary Search Tree (LeetCode #108)
DIFFICULTY: Easy
PATTERN: Tree Construction / Divide and Conquer
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
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
    vector<int> nums = {-10,-3,0,5,9};
    
    TreeNode* root = sol.sortedArrayToBST(nums);
    
    cout << "Inorder traversal: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Convert Sorted List to BST (LeetCode #109)
2. Construct Binary Tree from Preorder and Inorder (LeetCode #105)
3. Construct Binary Tree from Inorder and Postorder (LeetCode #106)
4. Construct BST from Preorder (LeetCode #1008)
5. Balance a BST (LeetCode #1382)
6. Maximum Binary Tree (LeetCode #654)
7. Merge Two Binary Trees (LeetCode #617)
8. Trim a BST (LeetCode #669)
9. Search in BST (LeetCode #700)
10. Insert into BST (LeetCode #701)
*/
