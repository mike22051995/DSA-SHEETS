/*
PROBLEM: Binary Tree Right Side View (LeetCode 199)
DIFFICULTY: Medium
PATTERN: BFS/DFS - Level Order Variant

DESCRIPTION:
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

EXAMPLE:
Input: root = [1,2,3,null,5,null,4]
       1
      / \
     2   3
      \   \
       5   4
Output: [1,3,4]

Input: root = [1,null,3]
       1
        \
         3
Output: [1,3]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) where w is max width
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
    // Approach 1: BFS Level Order (Most intuitive)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // If last node in this level, add to result
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return result;
    }
    
    // Approach 2: DFS (Right to Left)
    void dfs(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) return;
        
        // If visiting this level for first time from right
        if (level == result.size()) {
            result.push_back(root->val);
        }
        
        // Visit right first, then left
        dfs(root->right, level + 1, result);
        dfs(root->left, level + 1, result);
    }
    
    vector<int> rightSideViewDFS(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    vector<int> result1 = sol.rightSideView(root);
    cout << "Right Side View (BFS): ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> result2 = sol.rightSideViewDFS(root);
    cout << "Right Side View (DFS): ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

BFS Approach:
- Use level-order traversal
- For each level, take the rightmost node
- This is the last node processed in each level
- Simple and intuitive!

DFS Approach:
- Traverse right subtree first, then left
- Track current level
- First node we see at each level (from right) is in view
- When level == result.size(), it's a new level we haven't seen

KEY INSIGHT (DFS):
By going right first and checking if level == result.size(),
we ensure we only add the FIRST node we encounter at each level,
which is the rightmost one!

VARIATIONS:
- Left Side View: Same logic but go left first in DFS, or take first node in BFS
- Top View: Different problem, needs horizontal distance
- Bottom View: Opposite of top view

INTERVIEW TIP:
Know both approaches! BFS is more intuitive, but DFS shows
deeper understanding of recursion and level tracking.

OUTPUT:
Right Side View (BFS): 1 3 4
Right Side View (DFS): 1 3 4
*/
