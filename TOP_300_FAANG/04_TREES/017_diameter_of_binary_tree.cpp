/*
================================================================================
PROBLEM: Diameter of Binary Tree (LeetCode #543)
DIFFICULTY: Easy
PATTERN: Tree DFS / Recursion
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
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
private:
    int maxDiameter = 0;
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
    
    int height(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Diameter: " << sol.diameterOfBinaryTree(root) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Diameter of N-Ary Tree (LeetCode #1522)
2. Binary Tree Maximum Path Sum (LeetCode #124)
3. Longest Univalue Path (LeetCode #687)
4. Height of Binary Tree (LeetCode #104)
5. Balanced Binary Tree (LeetCode #110)
6. Tree Diameter (Graph version)
7. Subtree of Another Tree (LeetCode #572)
8. Closest Leaf in Binary Tree (LeetCode #742)
9. Sum of Distances in Tree (LeetCode #834)
10. All Nodes Distance K (LeetCode #863)
*/
