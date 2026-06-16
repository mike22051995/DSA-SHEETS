/*
================================================================================
PROBLEM: Same Tree (LeetCode #100)
DIFFICULTY: Easy
PATTERN: Tree DFS
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
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
    // Recursive DFS
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        if (p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    // Iterative BFS
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});
        
        while (!que.empty()) {
            auto [node1, node2] = que.front();
            que.pop();
            
            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;
            
            que.push({node1->left, node2->left});
            que.push({node1->right, node2->right});
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    cout << "Same tree: " << (sol.isSameTree(p, q) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Symmetric Tree (LeetCode #101)
2. Subtree of Another Tree (LeetCode #572)
3. Merge Two Binary Trees (LeetCode #617)
4. Leaf-Similar Trees (LeetCode #872)
5. Flip Equivalent Binary Trees (LeetCode #951)
6. Check if Two Trees are Identical
7. Find Duplicate Subtrees (LeetCode #652)
8. Most Frequent Subtree Sum (LeetCode #508)
9. Binary Tree Tilt (LeetCode #563)
10. Count Univalue Subtrees (LeetCode #250)
*/
