/*
PROBLEM: Same Tree (LeetCode 100)
DIFFICULTY: Easy
PATTERN: DFS - Tree Comparison

DESCRIPTION:
Given the roots of two binary trees p and q, write a function to check if they are the same.
Two binary trees are considered the same if they are structurally identical and nodes have same values.

EXAMPLE:
Input: p = [1,2,3], q = [1,2,3]
       1       1
      / \     / \
     2   3   2   3
Output: true

Input: p = [1,2], q = [1,null,2]
       1       1
      /         \
     2           2
Output: false

TIME COMPLEXITY: O(min(n,m)) - n and m are sizes of two trees
SPACE COMPLEXITY: O(min(h1,h2)) - recursion stack
*/

#include <iostream>
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
    // Recursive DFS Approach
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both null - same
        if (p == nullptr && q == nullptr) return true;
        
        // One null, other not - different
        if (p == nullptr || q == nullptr) return false;
        
        // Check current node and recurse for children
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
    
    // Iterative BFS Approach
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        
        while (!queue.empty()) {
            TreeNode* node1 = queue.front(); queue.pop();
            TreeNode* node2 = queue.front(); queue.pop();
            
            if (node1 == nullptr && node2 == nullptr) continue;
            if (node1 == nullptr || node2 == nullptr) return false;
            if (node1->val != node2->val) return false;
            
            queue.push(node1->left);
            queue.push(node2->left);
            queue.push(node1->right);
            queue.push(node2->right);
        }
        
        return true;
    }
};

TreeNode* createTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* createTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* p = createTree1();
    TreeNode* q = createTree2();
    
    cout << "Are trees same (Recursive)? " 
         << (sol.isSameTree(p, q) ? "Yes" : "No") << endl;
    
    TreeNode* p2 = createTree1();
    TreeNode* q2 = createTree2();
    cout << "Are trees same (Iterative)? " 
         << (sol.isSameTreeBFS(p2, q2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
EXPLANATION:

Recursive Approach:
1. Base cases:
   - If both nodes are null → same
   - If one is null and other isn't → different
2. Recursive case:
   - Current values must match
   - Left subtrees must be same
   - Right subtrees must be same

Iterative BFS:
- Use queue to store pairs of nodes
- Compare corresponding nodes level by level
- Push children in same order for both trees

KEY INSIGHT:
This is a fundamental comparison pattern. The logic is:
- Check structure (both null or both non-null)
- Check values
- Recursively check children

VARIATIONS:
- Same Tree (this problem)
- Subtree of Another Tree (uses this as helper)
- Merge Two Binary Trees

OUTPUT:
Are trees same (Recursive)? Yes
Are trees same (Iterative)? Yes
*/
