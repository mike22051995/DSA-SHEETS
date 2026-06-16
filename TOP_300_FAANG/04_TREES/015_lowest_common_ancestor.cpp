/*
================================================================================
PROBLEM: Lowest Common Ancestor of Binary Tree (LeetCode #236)
DIFFICULTY: Medium
PATTERN: Tree DFS / Recursion
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        
        return left ? left : right;
    }
    
    // Iterative with parent pointers
    TreeNode* lowestCommonAncestorIterative(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!parent.count(p) || !parent.count(q)) {
            TreeNode* node = st.top();
            st.pop();
            
            if (node->left) {
                parent[node->left] = node;
                st.push(node->left);
            }
            
            if (node->right) {
                parent[node->right] = node;
                st.push(node->right);
            }
        }
        
        unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }
        
        while (!ancestors.count(q)) {
            q = parent[q];
        }
        
        return q;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA: " << lca->val << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Lowest Common Ancestor of BST (LeetCode #235)
2. Lowest Common Ancestor III (LeetCode #1644)
3. Lowest Common Ancestor IV (LeetCode #1676)
4. Step-By-Step Directions (LeetCode #2096)
5. Kth Ancestor of Tree Node (LeetCode #1483)
6. Distance Between Two Nodes
7. All Nodes Distance K (LeetCode #863)
8. Smallest Common Region (LeetCode #1257)
9. Maximum Difference Between Node and Ancestor (LeetCode #1026)
10. Smallest Subtree with Deepest Nodes (LeetCode #865)
*/
