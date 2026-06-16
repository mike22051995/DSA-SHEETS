/*
================================================================================
PROBLEM: Binary Tree Maximum Path Sum (LeetCode #124)
DIFFICULTY: Hard
PATTERN: Tree DFS with Global Variable
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxSum;
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
    
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        
        // Only consider positive gains
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        // Price of new path through current node
        int priceNewPath = node->val + leftGain + rightGain;
        
        // Update global maximum
        maxSum = max(maxSum, priceNewPath);
        
        // Return max gain if continue with current node
        return node->val + max(leftGain, rightGain);
    }
};

int main() {
    Solution sol;
    
    // Create tree:    -10
    //                /    \
    //               9      20
    //                    /    \
    //                   15     7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Maximum path sum: " << sol.maxPathSum(root) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Path Sum (LeetCode #112)
2. Path Sum II (LeetCode #113)
3. Path Sum III (LeetCode #437)
4. Binary Tree Maximum Path Sum II (Follow-up)
5. Longest Univalue Path (LeetCode #687)
6. Diameter of Binary Tree (LeetCode #543)
7. Sum Root to Leaf Numbers (LeetCode #129)
8. Binary Tree Paths (LeetCode #257)
9. Smallest String Starting From Leaf (LeetCode #988)
10. Maximum Difference Between Node and Ancestor (LeetCode #1026)
*/
