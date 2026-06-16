/*
PROBLEM: Binary Tree Level Order Traversal (LeetCode 102)
DIFFICULTY: Medium (but fundamental)
PATTERN: BFS - Level Order Traversal

DESCRIPTION:
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: [[3],[9,20],[15,7]]

Input: root = [1]
Output: [[1]]

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(w) - w is max width of tree (queue size)
*/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level
            vector<int> currentLevel;
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->val);
                
                // Add children to queue for next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    vector<vector<int>> result = sol.levelOrder(root);
    
    cout << "Level Order Traversal:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Level " << i << ": ";
        for (int val : result[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
EXPLANATION:
BFS using Queue - Most important tree pattern!

Algorithm:
1. Use a queue to store nodes
2. Start with root
3. For each level:
   - Get current queue size (number of nodes in this level)
   - Process exactly that many nodes
   - Add their children to queue for next level
4. Repeat until queue is empty

KEY INSIGHT:
The queue size at the beginning of each iteration tells us
exactly how many nodes are at the current level.

This pattern is the foundation for:
- Zigzag level order
- Right side view
- Level order bottom
- Average of levels
- And many more problems!

OUTPUT:
Level Order Traversal:
Level 0: 3
Level 1: 9 20
Level 2: 15 7
*/
