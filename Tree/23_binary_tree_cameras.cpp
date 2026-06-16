/*
PROBLEM: Binary Tree Cameras (LeetCode 968)
DIFFICULTY: Hard
PATTERN: Greedy DFS - State Tracking

DESCRIPTION:
You are given the root of a binary tree. Install cameras on the tree nodes where each
camera can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes.

EXAMPLE:
Input: root = [0,0,null,0,0]
       0
      /
     0
      \
       0
      /
     0
Output: 1

Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
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
    int cameras;
    
    // States: 0 = needs coverage, 1 = has camera, 2 = covered
    int dfs(TreeNode* node) {
        if (node == nullptr) return 2; // null is covered
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        // If any child needs coverage, place camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1; // This node has camera
        }
        
        // If any child has camera, this node is covered
        if (left == 1 || right == 1) {
            return 2; // This node is covered
        }
        
        // Both children are covered but don't have cameras
        // This node needs coverage from parent
        return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        
        // If root needs coverage, place camera at root
        if (dfs(root) == 0) {
            cameras++;
        }
        
        return cameras;
    }
};

TreeNode* createTree1() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    return root;
}

TreeNode* createTree2() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->left->left = new TreeNode(0);
    root->left->left->left->right = new TreeNode(0);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createTree1();
    cout << "Minimum cameras for tree 1: " << sol.minCameraCover(root1) << endl;
    
    TreeNode* root2 = createTree2();
    cout << "Minimum cameras for tree 2: " << sol.minCameraCover(root2) << endl;
    
    return 0;
}

/*
EXPLANATION:

This is a GREEDY problem solved with DFS!

THREE STATES:
0. Node NEEDS coverage (not covered yet)
1. Node HAS a camera
2. Node is COVERED (by itself or children)

GREEDY STRATEGY:
Place cameras as low as possible in the tree!
Why? One camera can cover parent + itself + children.
Better to place at child (covers parent) than at parent (doesn't cover grandchildren).

ALGORITHM (Bottom-Up):

1. If any child needs coverage (state 0):
   → Place camera at current node (return 1)
   → This covers the child, current node, and parent

2. If any child has camera (state 1):
   → Current node is covered by child (return 2)

3. If both children are covered but no camera:
   → Current node needs coverage from parent (return 0)

Special case: If root returns 0, place camera at root.

EXAMPLE:
       0
      / \
     0   0
    / \
   0   0

Bottom-up:
- Leaves (0,0) need coverage, place cameras at their parent
- Parent has camera, covers grandparent
- Root is covered

Result: 2 cameras

WHY GREEDY WORKS:
We process bottom-up. When we see a node needing coverage,
we MUST place camera somewhere. Placing at parent is optimal
because it covers more nodes (parent + its children + grandparent).

KEY INSIGHT:
Use state to encode 3 different conditions.
Greedy choice: always place camera at parent of uncovered node.

OUTPUT:
Minimum cameras for tree 1: 1
Minimum cameras for tree 2: 2
*/
