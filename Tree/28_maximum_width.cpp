/*
PROBLEM: Binary Tree Maximum Width (LeetCode 662)
DIFFICULTY: Medium
PATTERN: BFS with Position Tracking

DESCRIPTION:
Given the root of a binary tree, return the maximum width of the given tree.
Width of one level = distance between leftmost and rightmost non-null nodes,
where null nodes in between are counted.

EXAMPLE:
Input: root = [1,3,2,5,3,null,9]
       1
      / \
     3   2
    / \   \
   5   3   9
Output: 4 (level with [5,3,null,9])

Input: root = [1,3,null,5,3]
       1
      /
     3
    / \
   5   3
Output: 2

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) where w is max width
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int maxWidth = 0;
        // Queue stores (node, position)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long leftmost = q.front().second;
            unsigned long long rightmost = leftmost;
            
            // Normalize positions to prevent overflow
            // Subtract leftmost position from all positions in this level
            unsigned long long offset = leftmost;
            
            for (int i = 0; i < size; i++) {
                auto [node, pos] = q.front();
                q.pop();
                
                // Normalize position
                pos -= offset;
                rightmost = pos;
                
                // Left child at position 2*pos
                if (node->left) {
                    q.push({node->left, 2 * pos});
                }
                
                // Right child at position 2*pos + 1
                if (node->right) {
                    q.push({node->right, 2 * pos + 1});
                }
            }
            
            // Width = rightmost - leftmost + 1
            // But leftmost is now 0 after normalization
            maxWidth = max(maxWidth, (int)(rightmost + 1));
        }
        
        return maxWidth;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

TreeNode* createSkewedTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createSampleTree();
    cout << "Maximum width of tree 1: " << sol.widthOfBinaryTree(root1) << endl;
    
    TreeNode* root2 = createSkewedTree();
    cout << "Maximum width of tree 2: " << sol.widthOfBinaryTree(root2) << endl;
    
    return 0;
}

/*
EXPLANATION:

The key is to assign positions to nodes as if it's a complete binary tree!

POSITION ASSIGNMENT (like array-based heap):
- Root at position 0
- For node at position i:
  * Left child at position 2*i
  * Right child at position 2*i + 1

EXAMPLE:
       1(0)
      / \
   3(0)  2(1)
   / \     \
 5(0) 3(1)  9(3)

Level 0: [1] at position 0
         Width = 0 - 0 + 1 = 1

Level 1: [3, 2] at positions 0, 1
         Width = 1 - 0 + 1 = 2

Level 2: [5, 3, _, 9] at positions 0, 1, 2, 3
         Width = 3 - 0 + 1 = 4 (includes the null at position 2)

ALGORITHM:

1. Use BFS with position tracking
2. For each level:
   - Track leftmost and rightmost positions
   - Width = rightmost - leftmost + 1
3. For each node at position pos:
   - Left child at 2*pos
   - Right child at 2*pos + 1

OVERFLOW PREVENTION:
Positions can grow exponentially (2^depth)!
Solution: Normalize positions at each level
- Subtract leftmost position from all positions
- Now leftmost is always 0
- Width = rightmost + 1

EXAMPLE with normalization:
Level with positions [1000, 1001, 1003]
After normalization: [0, 1, 3]
Width = 3 + 1 = 4

WHY unsigned long long?
To handle large position values before normalization.

KEY INSIGHT:
Treat tree as if it's a complete binary tree stored in an array.
Use array indices as positions!

OUTPUT:
Maximum width of tree 1: 4
Maximum width of tree 2: 1
*/
