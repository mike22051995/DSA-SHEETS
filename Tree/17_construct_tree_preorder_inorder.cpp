/*
PROBLEM: Construct Binary Tree from Preorder and Inorder Traversal (LeetCode 105)
DIFFICULTY: Medium
PATTERN: Tree Construction - Divide and Conquer

DESCRIPTION:
Given two integer arrays preorder and inorder where:
- preorder is the preorder traversal of a binary tree
- inorder is the inorder traversal of the same tree
Construct and return the binary tree.

EXAMPLE:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
       3
      / \
     9  20
       /  \
      15   7
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
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
    unordered_map<int, int> inorderMap;  // value -> index mapping
    int preorderIndex;
    
    TreeNode* build(vector<int>& preorder, int left, int right) {
        // Base case: no elements to construct tree
        if (left > right) return nullptr;
        
        // First element in preorder is root
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find root position in inorder
        int inorderIndex = inorderMap[rootVal];
        
        // Build left subtree (elements before root in inorder)
        root->left = build(preorder, left, inorderIndex - 1);
        
        // Build right subtree (elements after root in inorder)
        root->right = build(preorder, inorderIndex + 1, right);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create map for O(1) lookup of inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution sol;
    
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    TreeNode* root = sol.buildTree(preorder, inorder);
    
    cout << "Constructed tree:" << endl;
    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;
    
    cout << "Inorder: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

KEY INSIGHTS:

1. Preorder gives us the ROOT first: [ROOT, LEFT_SUBTREE, RIGHT_SUBTREE]
2. Inorder separates left and right: [LEFT_SUBTREE, ROOT, RIGHT_SUBTREE]

ALGORITHM:
1. First element in preorder is always the root
2. Find this root in inorder array
3. Elements to the left of root in inorder → left subtree
4. Elements to the right of root in inorder → right subtree
5. Recursively build left and right subtrees

EXAMPLE:
preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]

Step 1: Root = 3 (first in preorder)
        In inorder: [9] | 3 | [15, 20, 7]
                    left    right

Step 2: Build left subtree from [9]
        Root = 9 (next in preorder)
        
Step 3: Build right subtree from [15, 20, 7]
        Root = 20 (next in preorder)
        In inorder: [15] | 20 | [7]
        
And so on...

OPTIMIZATION:
Use HashMap to find root index in O(1) instead of O(n).
Without this, time complexity would be O(n²).

WHY IT WORKS:
- Preorder tells us the order of roots
- Inorder tells us which elements belong to left vs right

VARIATIONS:
- Build from Inorder + Postorder (LC 106)
- Build from Preorder (for BST only, LC 1008)

OUTPUT:
Constructed tree:
Preorder: 3 9 20 15 7
Inorder: 9 3 15 20 7
*/
