/*
================================================================================
PROBLEM: Binary Tree Level Order Traversal (LeetCode #102)
DIFFICULTY: Medium
PATTERN: BFS (Breadth-First Search) / Queue
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given the root of a binary tree, return the level order traversal of its nodes' 
values. (i.e., from left to right, level by level).

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Process tree level by level
2. BFS traversal needed
3. Need nodes at same depth together
4. Queue-based solution

Key Indicators:
- "Level by level" or "level order"
- "Same depth" nodes together
- BFS requirement
- Process by levels

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

================================================================================
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
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
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
            
            result.push_back(currentLevel);
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
    
    auto result = sol.levelOrder(root);
    
    cout << "Level order: " << endl;
    for (auto& level : result) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Binary Tree Zigzag Level Order (LeetCode #103)
2. Binary Tree Right Side View (LeetCode #199)
3. Average of Levels in Binary Tree (LeetCode #637)
4. N-ary Tree Level Order Traversal (LeetCode #429)
5. Minimum Depth of Binary Tree (LeetCode #111)
6. Maximum Level Sum (LeetCode #1161)
7. Vertical Order Traversal (LeetCode #987)
8. Cousins in Binary Tree (LeetCode #993)
9. Maximum Width of Binary Tree (LeetCode #662)
10. Even Odd Tree (LeetCode #1609)
================================================================================
*/
