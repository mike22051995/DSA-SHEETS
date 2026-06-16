/*
PROBLEM: Binary Tree Maximum Path Sum (LeetCode 124)
DIFFICULTY: Hard
PATTERN: DFS - Path Sum with Global Max

DESCRIPTION:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
has an edge. A node can only appear once in the sequence. Path sum is the sum of values.
Return the maximum path sum of any non-empty path.

EXAMPLE:
Input: root = [1,2,3]
       1
      / \
     2   3
Output: 6 (path: 2->1->3)

Input: root = [-10,9,20,null,null,15,7]
       -10
       /  \
      9   20
         /  \
        15   7
Output: 42 (path: 15->20->7)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxSum;
    
    // Returns max path sum going DOWN from this node
    int maxPathDown(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // Get max path sum from left and right children
        // Take 0 if negative (don't include that path)
        int left = max(0, maxPathDown(root->left));
        int right = max(0, maxPathDown(root->right));
        
        // Max path sum passing THROUGH current node
        // (left path + root + right path)
        int currentMax = left + root->val + right;
        
        // Update global maximum
        maxSum = max(maxSum, currentMax);
        
        // Return max path going DOWN (can only take one branch)
        return root->val + max(left, right);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathDown(root);
        return maxSum;
    }
};

TreeNode* createSampleTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* createSampleTree2() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createSampleTree3() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createSampleTree1();
    cout << "Tree 1 max path sum: " << sol.maxPathSum(root1) << endl;
    
    TreeNode* root2 = createSampleTree2();
    cout << "Tree 2 max path sum: " << sol.maxPathSum(root2) << endl;
    
    TreeNode* root3 = createSampleTree3();
    cout << "Tree 3 max path sum: " << sol.maxPathSum(root3) << endl;
    
    return 0;
}

/*
EXPLANATION:

This is a HARD problem that combines multiple concepts!

KEY INSIGHTS:

1. At each node, we have 4 choices:
   a) Just the node itself
   b) Node + left path
   c) Node + right path
   d) Node + left path + right path (inverted V shape)

2. But when returning to parent, we can only give ONE path
   (either left or right, not both)

ALGORITHM:

For each node:
1. Get max path sum from left subtree going DOWN
2. Get max path sum from right subtree going DOWN
3. Ignore negative paths (take 0 instead)
4. Current max path = left + root + right (full path through node)
5. Update global maximum
6. Return to parent: root + max(left, right) (single path down)

WHY max(0, path)?
If a subtree gives negative sum, better to not include it!
Example: root=5, left=-3 → better to take just 5 than 5+(-3)=2

TRICKY PART:
The path we return to parent is different from the path
we use for updating global max!
- Global max: can use both branches (inverted V)
- Return value: can only use one branch (straight line down)

PATTERN:
Similar to diameter problem:
- Calculate something at each node
- Use global variable for answer
- Return different value to parent

═══════════════════════════════════════════════════════════════════════
RECURSION TRACE - Tree 2 (Most Interesting Example)
═══════════════════════════════════════════════════════════════════════

Tree:          -10
               /  \
              9   20
                 /  \
                15   7

Target: Find maximum path sum = 42 (path: 15→20→7)

GOING DOWN (DFS - Left subtree first):
────────────────────────────────────────────────────────────────────────

1. Call: maxPathDown(node=-10)
   → Calls: maxPathDown(node=9)

2. Call: maxPathDown(node=9)
   → Calls: maxPathDown(node=null) for left
   → Calls: maxPathDown(node=null) for right

3. maxPathDown(null) RETURNS: 0
4. maxPathDown(null) RETURNS: 0

COMING BACK UP (Leaf to Root):
────────────────────────────────────────────────────────────────────────

5. At node=9:
   ├─ left = max(0, 0) = 0
   ├─ right = max(0, 0) = 0
   ├─ currentMax = 0 + 9 + 0 = 9
   ├─ maxSum = max(INT_MIN, 9) = 9 ✓ (update global)
   └─ RETURNS: 9 + max(0, 0) = 9
   
6. Back at node=-10, left child returned 9
   → Now explore right subtree
   → Calls: maxPathDown(node=20)

7. Call: maxPathDown(node=20)
   → Calls: maxPathDown(node=15)

8. Call: maxPathDown(node=15)
   → Calls: maxPathDown(node=null) for left
   → Calls: maxPathDown(node=null) for right

9. maxPathDown(null) RETURNS: 0
10. maxPathDown(null) RETURNS: 0

11. At node=15:
    ├─ left = max(0, 0) = 0
    ├─ right = max(0, 0) = 0
    ├─ currentMax = 0 + 15 + 0 = 15
    ├─ maxSum = max(9, 15) = 15 ✓ (update global)
    └─ RETURNS: 15 + max(0, 0) = 15

12. Back at node=20, got 15 from left child
    → Now explore right child
    → Calls: maxPathDown(node=7)

13. Call: maxPathDown(node=7)
    → Calls: maxPathDown(node=null) for left
    → Calls: maxPathDown(node=null) for right

14. maxPathDown(null) RETURNS: 0
15. maxPathDown(null) RETURNS: 0

16. At node=7:
    ├─ left = max(0, 0) = 0
    ├─ right = max(0, 0) = 0
    ├─ currentMax = 0 + 7 + 0 = 7
    ├─ maxSum = max(15, 7) = 15 (no update)
    └─ RETURNS: 7 + max(0, 0) = 7

17. Back at node=20:
    ├─ left = max(0, 15) = 15   (from node 15)
    ├─ right = max(0, 7) = 7    (from node 7)
    ├─ currentMax = 15 + 20 + 7 = 42 ← PATH: 15→20→7
    ├─ maxSum = max(15, 42) = 42 ✓✓✓ (FINAL ANSWER!)
    └─ RETURNS: 20 + max(15, 7) = 20 + 15 = 35
       (Can only take one branch going up to parent)

18. Back at node=-10:
    ├─ left = max(0, 9) = 9     (from node 9)
    ├─ right = max(0, 35) = 35  (from node 20)
    ├─ currentMax = 9 + (-10) + 35 = 34
    ├─ maxSum = max(42, 34) = 42 (no update)
    └─ RETURNS: -10 + max(9, 35) = -10 + 35 = 25

19. FINAL RESULT: maxSum = 42

═══════════════════════════════════════════════════════════════════════
KEY OBSERVATIONS:
═══════════════════════════════════════════════════════════════════════

1. TWO DIFFERENT VALUES AT EACH NODE:
   
   a) currentMax (for global maxSum update):
      - Uses BOTH left and right paths
      - Forms an inverted-V or straight line
      - Example at node 20: 15 + 20 + 7 = 42
   
   b) Return value (to parent):
      - Uses ONLY ONE path (left OR right)
      - Must be a straight line going down
      - Example at node 20: Returns 20 + 15 = 35 (takes left)

2. WHY max(0, path)?
   - Negative paths are ignored
   - Example: If left returns -5, we take 0 instead
   - Better to exclude negative contributions

3. RETURN VALUE vs GLOBAL UPDATE:
   
   Node 20:
   ├─ For global update: 15 + 20 + 7 = 42 (uses both branches)
   └─ Returns to parent: 20 + 15 = 35 (uses only best branch)
   
   Why? Parent can extend the path in ONE direction only!

4. PATH COMPOSITION:
   - At node 20: We found path 15→20→7
   - We return 35 to parent (20→15 going up)
   - Parent could extend it, but -10 + 35 = 25 < 42, so no update

═══════════════════════════════════════════════════════════════════════
SIMPLER EXAMPLE - Tree 1:
═══════════════════════════════════════════════════════════════════════

Tree:    1
        / \
       2   3

Recursion:
1. maxPathDown(2) → returns 2, updates maxSum = 2
2. maxPathDown(3) → returns 3, updates maxSum = 3
3. At node 1:
   ├─ left = 2, right = 3
   ├─ currentMax = 2 + 1 + 3 = 6 ← PATH: 2→1→3
   ├─ maxSum = max(3, 6) = 6 ✓
   └─ Returns: 1 + max(2, 3) = 4

Answer: 6

═══════════════════════════════════════════════════════════════════════
CRITICAL INSIGHT:
═══════════════════════════════════════════════════════════════════════

The PATH can bend ONLY ONCE (at any node forming inverted-V).
- That's why we update global max with left + root + right
- But return only root + max(left, right) to prevent multiple bends

OUTPUT:
Tree 1 max path sum: 6
Tree 2 max path sum: 42
Tree 3 max path sum: 4
*/
