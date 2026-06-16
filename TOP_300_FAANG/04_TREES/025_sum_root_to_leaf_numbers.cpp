/*
================================================================================
PROBLEM: Sum Root to Leaf Numbers (LeetCode #129)
DIFFICULTY: Medium
PATTERN: DFS / Tree Traversal
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;
        
        current = current * 10 + node->val;
        
        if (!node->left && !node->right) {
            return current;
        }
        
        return dfs(node->left, current) + dfs(node->right, current);
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    cout << "Sum of root to leaf numbers: " << sol.sumNumbers(root) << endl;
    
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(0);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(1);
    
    cout << "Sum of root to leaf numbers: " << sol.sumNumbers(root2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Path Sum (LeetCode #112)
2. Path Sum II (LeetCode #113)
3. Path Sum III (LeetCode #437)
4. Binary Tree Maximum Path Sum (LeetCode #124)
5. Smallest String Starting From Leaf (LeetCode #988)
6. Sum of Root to Leaf Binary Numbers (LeetCode #1022)
7. Pseudo-Palindromic Paths (LeetCode #1457)
8. Binary Tree Paths (LeetCode #257)
9. All Paths From Source to Target (LeetCode #797)
10. Most Profitable Path in Tree (LeetCode #2467)
*/
