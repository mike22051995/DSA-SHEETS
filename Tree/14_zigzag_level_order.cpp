/*
PROBLEM: Binary Tree Zigzag Level Order Traversal (LeetCode 103)
DIFFICULTY: Medium
PATTERN: BFS - Level Order Variant

DESCRIPTION:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: [[3],[20,9],[15,7]]

Input: root = [1,2,3,4,null,null,5]
       1
      / \
     2   3
    /     \
   4       5
Output: [[1],[3,2],[4,5]]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) where w is max width
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // Direction flag
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Find position to insert based on direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);
            leftToRight = !leftToRight;  // Toggle direction
        }
        
        return result;
    }
    
    // Alternative: Reverse odd levels
    vector<vector<int>> zigzagLevelOrderAlternate(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Reverse if odd level
            if (level % 2 == 1) {
                reverse(currentLevel.begin(), currentLevel.end());
            }
            
            result.push_back(currentLevel);
            level++;
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
    
    vector<vector<int>> result1 = sol.zigzagLevelOrder(root);
    cout << "Zigzag Level Order (Index manipulation):" << endl;
    for (int i = 0; i < result1.size(); i++) {
        cout << "Level " << i << ": ";
        for (int val : result1[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result2 = sol.zigzagLevelOrderAlternate(root);
    cout << "\nZigzag Level Order (Reverse approach):" << endl;
    for (int i = 0; i < result2.size(); i++) {
        cout << "Level " << i << ": ";
        for (int val : result2[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
EXPLANATION:

Two Approaches:

1. Index Manipulation (More efficient):
   - Pre-allocate array for each level
   - For left-to-right: insert at index i
   - For right-to-left: insert at index (levelSize - 1 - i)
   - Toggle direction after each level
   - No need to reverse!

2. Reverse Approach (Simpler code):
   - Do normal level order
   - If odd level (1, 3, 5...), reverse the array
   - Extra O(w) operation per alternate level

Both work, but approach 1 is slightly more efficient.

KEY INSIGHT:
This is just level-order traversal with alternating directions.
The tricky part is handling the direction change cleanly.

PATTERN:
Many level-order variants:
- Normal level order
- Right/Left side view
- Zigzag (this problem)
- Level order bottom (reverse final result)
- Average of levels (compute average)

All use the same BFS template with modifications!

OUTPUT:
Zigzag Level Order (Index manipulation):
Level 0: 3
Level 1: 20 9
Level 2: 15 7

Zigzag Level Order (Reverse approach):
Level 0: 3
Level 1: 20 9
Level 2: 15 7
*/
