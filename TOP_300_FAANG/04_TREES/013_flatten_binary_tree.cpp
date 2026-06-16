/*
================================================================================
PROBLEM: Flatten Binary Tree to Linked List (LeetCode #114)
DIFFICULTY: Medium
PATTERN: Tree Traversal / Morris Traversal
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Morris Traversal - O(1) space
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                
                while (prev->right) {
                    prev = prev->right;
                }
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            curr = curr->right;
        }
    }
    
    // Recursive approach
    void flattenRecursive(TreeNode* root) {
        if (!root) return;
        
        flattenRecursive(root->left);
        flattenRecursive(root->right);
        
        TreeNode* tempRight = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        while (root->right) {
            root = root->right;
        }
        root->right = tempRight;
    }
    
    // Iterative with stack
    void flattenIterative(TreeNode* root) {
        if (!root) return;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
            
            if (!st.empty()) {
                curr->right = st.top();
            }
            curr->left = nullptr;
        }
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    sol.flatten(root);
    
    cout << "Flattened tree: ";
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Flatten Multilevel Doubly Linked List (LeetCode #430)
2. Convert BST to Greater Tree (LeetCode #538)
3. Increasing Order Search Tree (LeetCode #897)
4. Binary Tree to Doubly Linked List
5. Serialize and Deserialize Binary Tree (LeetCode #297)
6. Binary Tree Right Side View (LeetCode #199)
7. Vertical Order Traversal (LeetCode #987)
8. Recover Binary Search Tree (LeetCode #99)
9. Populating Next Right Pointers (LeetCode #116)
10. All Nodes Distance K (LeetCode #863)
*/
