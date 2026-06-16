/*
================================================================================
PROBLEM: Count Complete Tree Nodes (LeetCode #222)
DIFFICULTY: Medium
PATTERN: Binary Search / Tree Traversal
COMPANIES: Amazon, Microsoft, Facebook, Google
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) + countNodes(root->right);
        } else {
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
    
    int getHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Simple recursive - O(n)
    int countNodesSimple(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodesSimple(root->left) + countNodesSimple(root->right);
    }
    
    // Binary search approach
    int countNodesBinarySearch(TreeNode* root) {
        if (!root) return 0;
        
        int h = getHeight(root);
        if (h == 0) return 1;
        
        int left = 1, right = (1 << (h - 1)) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (exists(mid, h, root)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return (1 << (h - 1)) - 1 + left;
    }
    
    bool exists(int idx, int h, TreeNode* node) {
        int left = 0, right = (1 << (h - 1)) - 1;
        
        for (int i = 0; i < h - 1; i++) {
            int mid = left + (right - left) / 2;
            
            if (idx <= mid) {
                node = node->left;
                right = mid;
            } else {
                node = node->right;
                left = mid + 1;
            }
        }
        
        return node != nullptr;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    cout << "Total nodes: " << sol.countNodes(root) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Height of Binary Tree (LeetCode #104)
2. Closest Binary Search Tree Value (LeetCode #270)
3. Find Bottom Left Tree Value (LeetCode #513)
4. Maximum Depth of Binary Tree (LeetCode #104)
5. Minimum Depth of Binary Tree (LeetCode #111)
6. Balanced Binary Tree (LeetCode #110)
7. Diameter of Binary Tree (LeetCode #543)
8. Binary Tree Paths (LeetCode #257)
9. Sum of Left Leaves (LeetCode #404)
10. Path Sum II (LeetCode #113)
*/
