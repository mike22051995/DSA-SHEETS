/*
PROBLEM: Minimum Depth of Binary Tree (LeetCode 111)
DIFFICULTY: Easy
PATTERN: BFS/DFS - Depth Calculation

DESCRIPTION:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: 2 (path: 3->9)

Input: root = [2,null,3,null,4,null,5,null,6]
       2
        \
         3
          \
           4
            \
             5
              \
               6
Output: 5

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) for BFS, O(h) for DFS
*/

#include <iostream>
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
    // Approach 1: BFS (Better for this problem!)
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Found first leaf - this is minimum depth!
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        
        return depth;
    }
    
    // Approach 2: DFS Recursive
    int minDepthDFS(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // If leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        // If only right child exists
        if (root->left == nullptr) {
            return 1 + minDepthDFS(root->right);
        }
        
        // If only left child exists
        if (root->right == nullptr) {
            return 1 + minDepthDFS(root->left);
        }
        
        // Both children exist - take minimum
        return 1 + min(minDepthDFS(root->left), minDepthDFS(root->right));
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

TreeNode* createSkewedTree() {
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createSampleTree();
    cout << "Minimum Depth (BFS): " << sol.minDepth(root1) << endl;
    cout << "Minimum Depth (DFS): " << sol.minDepthDFS(root1) << endl;
    
    TreeNode* root2 = createSkewedTree();
    cout << "\nSkewed tree:" << endl;
    cout << "Minimum Depth (BFS): " << sol.minDepth(root2) << endl;
    cout << "Minimum Depth (DFS): " << sol.minDepthDFS(root2) << endl;
    
    return 0;
}

/*
EXPLANATION:

BFS Approach (BETTER for this problem):
- Process level by level
- Return immediately when first leaf is found
- This leaf is at minimum depth!
- Advantage: Can return early without exploring entire tree

DFS Approach:
- Must explore all paths to find minimum
- Special cases:
  * Leaf node → return 1
  * Only left child → return 1 + minDepth(left)
  * Only right child → return 1 + minDepth(right)
  * Both children → return 1 + min(left, right)

CRITICAL DIFFERENCE from Maximum Depth:
- For max depth: max(left, right)
- For min depth: CANNOT just do min(left, right) when one child is null!
  Because null subtree doesn't represent a path to leaf

WHEN TO USE BFS vs DFS:
- BFS: When you want to find shortest path (min depth, level order)
- DFS: When you want max depth or need to explore all paths

OUTPUT:
Minimum Depth (BFS): 2
Minimum Depth (DFS): 2

Skewed tree:
Minimum Depth (BFS): 5
Minimum Depth (DFS): 5
*/
