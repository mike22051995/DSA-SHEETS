/*
================================================================================
PROBLEM: Maximum Depth of Binary Tree (LeetCode #104)
DIFFICULTY: Easy
PATTERN: Tree DFS / BFS
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================

PROBLEM DESCRIPTION:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Tree traversal with level/depth tracking
2. Finding height/depth of tree
3. Can use DFS (recursion) or BFS (level order)
4. Base case: null node or leaf

Key Indicators:
- "Maximum depth" or "height of tree"
- Traverse entire tree
- Count levels or edges
- Simple recursion pattern

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: root = [3,9,20,null,null,15,7]
      3
     / \
    9  20
      /  \
     15   7
Output: 3
Explanation: Maximum depth is 3 (root → 20 → 15)

Example 2:
Input: root = [1,null,2]
    1
     \
      2
Output: 2

Example 3:
Input: root = []
Output: 0

Example 4:
Input: root = [0]
Output: 1

================================================================================
EXPLANATION:

DFS Approach (Recursive):
- Height = 1 + max(left_height, right_height)
- Base case: null node has depth 0
- Post-order traversal

BFS Approach (Iterative):
- Level-order traversal using queue
- Count number of levels
- Each level increases depth by 1

Time: O(n) - visit each node once
Space: O(h) for DFS, O(w) for BFS
       where h = height, w = max width

================================================================================
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Approach 1: DFS Recursive (Most Intuitive)
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
    
    // Approach 2: DFS Recursive (One-liner)
    int maxDepthOneLiner(TreeNode* root) {
        return root == nullptr ? 0 : 1 + max(maxDepthOneLiner(root->left), 
                                               maxDepthOneLiner(root->right));
    }
    
    // Approach 3: BFS Iterative (Level Order)
    int maxDepthBFS(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            depth++;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return depth;
    }
    
    // Approach 4: DFS Iterative (using stack)
    int maxDepthDFSIterative(TreeNode* root) {
        if (root == nullptr) return 0;
        
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int maxDepth = 0;
        
        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();
            
            maxDepth = max(maxDepth, depth);
            
            if (node->left) st.push({node->left, depth + 1});
            if (node->right) st.push({node->right, depth + 1});
        }
        
        return maxDepth;
    }
};

// Helper functions
TreeNode* createSampleTree1() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createSampleTree2() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    return root;
}

void runTest(TreeNode* root, string testName) {
    Solution sol;
    int depth1 = sol.maxDepth(root);
    int depth2 = sol.maxDepthBFS(root);
    
    cout << testName << ": " << endl;
    cout << "Max Depth (DFS): " << depth1 << endl;
    cout << "Max Depth (BFS): " << depth2 << endl;
    cout << "-------------------" << endl;
}

int main() {
    TreeNode* tree1 = createSampleTree1();
    runTest(tree1, "Test 1");
    
    TreeNode* tree2 = createSampleTree2();
    runTest(tree2, "Test 2");
    
    TreeNode* tree3 = nullptr;
    runTest(tree3, "Test 3 (Empty)");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Minimum Depth of Binary Tree (LeetCode #111) - Easy
   - Find shortest path to leaf

2. Balanced Binary Tree (LeetCode #110) - Easy
   - Check if height-balanced

3. Diameter of Binary Tree (LeetCode #543) - Easy
   - Longest path between any two nodes

4. Binary Tree Maximum Path Sum (LeetCode #124) - Hard
   - Maximum sum of any path

5. Lowest Common Ancestor (LeetCode #236) - Medium
   - Find LCA using depth

6. Symmetric Tree (LeetCode #101) - Easy
   - Check if mirror image

7. Count Complete Tree Nodes (LeetCode #222) - Medium
   - Optimize using completeness property

8. Path Sum (LeetCode #112) - Easy
   - Check if root-to-leaf sum exists

9. Binary Tree Level Order Traversal (LeetCode #102) - Medium
   - Level by level (same BFS pattern)

10. Maximum Width of Binary Tree (LeetCode #662) - Medium
    - Maximum width at any level

================================================================================
KEY CONCEPTS:
================================================================================

1. Tree Height vs Depth:
   - Height: edges from node to deepest leaf
   - Depth: edges from root to node
   - For root: height = depth = max depth

2. DFS vs BFS for Tree Problems:
   - DFS: Better for depth/height problems
   - BFS: Better for level-related problems
   - DFS: O(h) space, BFS: O(w) space

3. Recursion Pattern:
   ```
   if (!root) return base_case;
   left = recurse(root->left);
   right = recurse(root->right);
   return combine(left, right);
   ```

4. Common Variations:
   - Minimum depth (to nearest leaf)
   - Count nodes at depth k
   - Check if balanced (|left-right| ≤ 1)

5. Interview Tips:
   - Start with recursive DFS
   - Mention BFS alternative
   - Discuss space complexity trade-offs
   - Edge case: empty tree

================================================================================
*/
