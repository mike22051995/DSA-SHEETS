/*
================================================================================
PROBLEM: Kth Smallest Element in BST (LeetCode #230)
DIFFICULTY: Medium
PATTERN: Inorder Traversal (BST Property)
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <stack>
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
    // Iterative Inorder
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            
            k--;
            if (k == 0) return curr->val;
            
            curr = curr->right;
        }
        
        return -1;
    }
    
    // Recursive Inorder
    int kthSmallestRecursive(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorder(root, k, count, result);
        return result;
    }
    
    void inorder(TreeNode* node, int k, int& count, int& result) {
        if (!node || count >= k) return;
        
        inorder(node->left, k, count, result);
        
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        
        inorder(node->right, k, count, result);
    }
};

int main() {
    Solution sol;
    
    // Create BST:    3
    //              /   \
    //             1     4
    //              \
    //               2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    cout << "Kth smallest (k=1): " << sol.kthSmallest(root, 1) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Kth Largest Element in Array (LeetCode #215)
2. Kth Largest Element in Stream (LeetCode #703)
3. Inorder Successor in BST (LeetCode #285)
4. Inorder Successor in BST II (LeetCode #510)
5. Binary Search Tree Iterator (LeetCode #173)
6. Closest Binary Search Tree Value (LeetCode #270)
7. Closest Binary Search Tree Value II (LeetCode #272)
8. Count of Smaller Numbers After Self (LeetCode #315)
9. Range Sum of BST (LeetCode #938)
10. Convert Sorted Array to BST (LeetCode #108)
*/
