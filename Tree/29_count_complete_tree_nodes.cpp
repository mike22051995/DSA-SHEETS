/*
PROBLEM: Count Complete Tree Nodes (LeetCode 222)
DIFFICULTY: Medium
PATTERN: Binary Search on Tree Height

DESCRIPTION:
Given the root of a complete binary tree, return the number of nodes.
A complete binary tree has all levels fully filled except possibly the last,
which is filled from left to right.

Design an algorithm that runs in less than O(n) time.

EXAMPLE:
Input: root = [1,2,3,4,5,6]
       1
      / \
     2   3
    / \ /
   4  5 6
Output: 6

TIME COMPLEXITY: O(log²n)
SPACE COMPLEXITY: O(log n)
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
public:
    // Get height by going left
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Get height by going right
    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftH = getLeftHeight(root);
        int rightH = getRightHeight(root);
        
        // If left height = right height, tree is perfect
        if (leftH == rightH) {
            // Perfect binary tree has 2^h - 1 nodes
            return (1 << leftH) - 1;  // 2^leftH - 1
        }
        
        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Alternative: More explicit binary search approach
    bool exists(int idx, int height, TreeNode* root) {
        int left = 0, right = (1 << (height - 1)) - 1;
        
        for (int i = 0; i < height - 1; i++) {
            int mid = left + (right - left) / 2;
            if (idx <= mid) {
                root = root->left;
                right = mid;
            } else {
                root = root->right;
                left = mid + 1;
            }
        }
        
        return root != nullptr;
    }
    
    int countNodesBS(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int height = getLeftHeight(root);
        
        // Last level has at most 2^(h-1) nodes
        int left = 0, right = (1 << (height - 1)) - 1;
        
        // Binary search for the last node
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (exists(mid, height, root)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Total = nodes in complete levels + nodes in last level
        return ((1 << (height - 1)) - 1) + left;
    }
};

TreeNode* createCompleteTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}

TreeNode* createPerfectTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createCompleteTree();
    cout << "Complete tree nodes (recursive): " << sol.countNodes(root1) << endl;
    
    TreeNode* root2 = createCompleteTree();
    cout << "Complete tree nodes (binary search): " << sol.countNodesBS(root2) << endl;
    
    TreeNode* root3 = createPerfectTree();
    cout << "Perfect tree nodes: " << sol.countNodes(root3) << endl;
    
    return 0;
}

/*
EXPLANATION:

Naive solution: O(n) - traverse all nodes
Better solution: Use complete tree property! O(log²n)

TWO APPROACHES:

1. Recursive with Perfect Tree Detection:
   
   Key insight: A complete tree's subtrees might be perfect!
   
   Algorithm:
   - Get leftmost height (keep going left)
   - Get rightmost height (keep going right)
   - If equal → perfect tree → nodes = 2^h - 1
   - If not equal → recursively count left + right + 1
   
   Why O(log²n)?
   - At each level, we compute height: O(log n)
   - We recurse at most O(log n) levels
   - Total: O(log n × log n)

2. Binary Search Approach:
   
   Insight: Last level is filled left to right
   
   Algorithm:
   - Find height h
   - All levels except last are full: 2^(h-1) - 1 nodes
   - Last level has [0 to 2^(h-1)] nodes
   - Binary search to find last existing node in last level
   
   To check if node k exists in last level:
   - Use binary search path from root
   - At each level, go left or right based on k's position

EXAMPLE:
       1
      / \
     2   3
    / \ /
   4  5 6

Height = 3
Full levels (0-1): 2^2 - 1 = 3 nodes
Last level: Binary search finds 3 nodes exist
Total: 3 + 3 = 6

WHY APPROACH 1 IS EASIER:
Simpler code, same complexity.
At each step, one subtree is guaranteed to be perfect!

PERFECT TREE CHECK:
Left height = right height only for perfect trees!
For complete non-perfect tree, they differ.

OUTPUT:
Complete tree nodes (recursive): 6
Complete tree nodes (binary search): 6
Perfect tree nodes: 7
*/
