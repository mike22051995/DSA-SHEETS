/*
================================================================================
PROBLEM: Binary Tree Zigzag Level Order Traversal (LeetCode #103)
DIFFICULTY: Medium
PATTERN: BFS / Tree Traversal
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    
    cout << "Zigzag level order:" << endl;
    for (auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Binary Tree Level Order Traversal (LeetCode #102)
2. Binary Tree Level Order Traversal II (LeetCode #107)
3. Binary Tree Right Side View (LeetCode #199)
4. Populating Next Right Pointers (LeetCode #116)
5. Vertical Order Traversal (LeetCode #987)
6. Binary Tree Vertical Order (LeetCode #314)
7. N-ary Tree Level Order Traversal (LeetCode #429)
8. Average of Levels (LeetCode #637)
9. Find Largest Value in Each Row (LeetCode #515)
10. Reverse Odd Levels of Binary Tree (LeetCode #2415)
*/
