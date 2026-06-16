/*
PROBLEM: Path Sum (LeetCode 112)
DIFFICULTY: Easy
PATTERN: DFS - Root to Leaf Path

DESCRIPTION:
Given the root of a binary tree and an integer targetSum, return true if the tree 
has a root-to-leaf path such that adding up all values equals targetSum.
A leaf is a node with no children.

EXAMPLE:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
         5
        / \
       4   8
      /   / \
     11  13  4
    /  \      \
   7    2      1
Output: true (5->4->11->2 = 22)

Input: root = [1,2,3], targetSum = 5
Output: false

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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Empty tree has no path
        if (root == nullptr) return false;
        
        // Leaf node - check if remaining sum equals node value
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Recursively check left and right subtrees with reduced sum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || 
               hasPathSum(root->right, remainingSum);
    }
    
    // Alternative: Top-down approach with accumulated sum
    bool hasPathSumHelper(TreeNode* root, int currentSum, int targetSum) {
        if (root == nullptr) return false;
        
        currentSum += root->val;
        
        // Check if leaf node and sum matches
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum == targetSum;
        }
        
        return hasPathSumHelper(root->left, currentSum, targetSum) ||
               hasPathSumHelper(root->right, currentSum, targetSum);
    }
    
    bool hasPathSumTopDown(TreeNode* root, int targetSum) {
        return hasPathSumHelper(root, 0, targetSum);
    }
    
    // Alternative: Complementary approach with implicit leaf check
    bool hasPathSumComplementary(TreeNode* root, int target) {
        // Base case: reached null with target = 0 means we found valid path
        if (root == nullptr && target == 0) return true;
        
        // Base case: reached null without completing sum
        if (root == nullptr) return false;
        
        // Calculate complementary (remaining sum needed)
        int complementary = target - root->val;
        
        // Recursively check left or right subtree
        // The leaf check is implicit: only when both children are null
        // and complementary is 0 will we return true
        return hasPathSumComplementary(root->left, complementary) || 
               hasPathSumComplementary(root->right, complementary);
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    int target = 22;
    cout << "Has path sum " << target << " (subtract approach)? " 
         << (sol.hasPathSum(root, target) ? "Yes" : "No") << endl;
    
    cout << "Has path sum " << target << " (accumulate approach)? " 
         << (sol.hasPathSumTopDown(root, target) ? "Yes" : "No") << endl;
    
    cout << "Has path sum " << target << " (complementary approach)? " 
         << (sol.hasPathSumComplementary(root, target) ? "Yes" : "No") << endl;
    
    target = 26;
    cout << "Has path sum " << target << "? " 
         << (sol.hasPathSum(root, target) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
EXPLANATION:

Two Approaches:

1. Subtract Approach (Preferred):
   - Subtract current node value from targetSum
   - Pass remaining sum to children
   - At leaf, check if remaining sum equals leaf value
   - Cleaner code!

2. Accumulate Approach:
   - Add current node value to running sum
   - At leaf, check if accumulated sum equals target
   - More intuitive but slightly more code

KEY INSIGHT:
Must reach a LEAF node - don't return true just because
sum equals target at an internal node!

IMPORTANT CHECKS:
1. Check for null (empty tree/subtree)
2. Check if leaf node (both children null)
3. Only at leaf, verify the sum

PATTERN:
Root-to-leaf path problems - foundation for:
- Path Sum II (find all paths)
- Binary Tree Maximum Path Sum
- Path Sum III

═══════════════════════════════════════════════════════════════════════
RECURSION TRACE - ACCUMULATE APPROACH (hasPathSumHelper)
═══════════════════════════════════════════════════════════════════════

Tree:            5
                / \
               4   8
              /   / \
             11  13  4
            /  \      \
           7    2      1

Target = 22

CALL STACK (Going Down - DFS Left Path First):
────────────────────────────────────────────────────────────────────────

1. Call: hasPathSumHelper(node=5, currentSum=0, target=22)
   → currentSum += 5  →  currentSum = 5
   → Not a leaf, recurse left and right
   → Calls: hasPathSumHelper(node=4, currentSum=5, target=22)

2. Call: hasPathSumHelper(node=4, currentSum=5, target=22)
   → currentSum += 4  →  currentSum = 9
   → Not a leaf, recurse left and right
   → Calls: hasPathSumHelper(node=11, currentSum=9, target=22)

3. Call: hasPathSumHelper(node=11, currentSum=9, target=22)
   → currentSum += 11  →  currentSum = 20
   → Not a leaf, recurse left and right
   → Calls: hasPathSumHelper(node=7, currentSum=20, target=22)

4. Call: hasPathSumHelper(node=7, currentSum=20, target=22)
   → currentSum += 7  →  currentSum = 27
   → IS A LEAF! Check: 27 == 22? NO
   → RETURNS: false

STACK UNWIND (Going Up):
────────────────────────────────────────────────────────────────────────

5. Back at: hasPathSumHelper(node=11, currentSum=20, target=22)
   → Left returned false
   → Now try right child
   → Calls: hasPathSumHelper(node=2, currentSum=20, target=22)

6. Call: hasPathSumHelper(node=2, currentSum=20, target=22)
   → currentSum += 2  →  currentSum = 22
   → IS A LEAF! Check: 22 == 22? YES!
   → RETURNS: true ✓

7. Back at: hasPathSumHelper(node=11, currentSum=20, target=22)
   → Right returned true
   → (false || true) = true
   → RETURNS: true ✓

8. Back at: hasPathSumHelper(node=4, currentSum=9, target=22)
   → Left returned true
   → Due to short-circuit evaluation, right is NOT called
   → RETURNS: true ✓

9. Back at: hasPathSumHelper(node=5, currentSum=5, target=22)
   → Left returned true
   → Due to short-circuit evaluation, right is NOT called
   → RETURNS: true ✓

10. FINAL RESULT: true

═══════════════════════════════════════════════════════════════════════
KEY OBSERVATIONS:
═══════════════════════════════════════════════════════════════════════

1. PARAMETER PASSING: 
   - currentSum is passed BY VALUE (not reference)
   - Each recursive call gets its OWN COPY
   - When you return from a call, the parent's currentSum is UNCHANGED

2. EXAMPLE - When at node 11:
   - currentSum = 20
   - Calls left child (node 7): passes 20
   - Inside node 7: currentSum becomes 27
   - Returns false, BACK AT NODE 11: currentSum is STILL 20!
   - Calls right child (node 2): passes 20 again (fresh copy)
   - Inside node 2: currentSum becomes 22
   - Returns true

3. SHORT-CIRCUIT:
   - The || operator stops evaluating once it finds true
   - That's why right subtree of node 5 (node 8) is never explored

4. STACK FRAMES:
   - Each function call has its own stack frame
   - Variables are isolated between frames
   - When returning, the frame is destroyed

═══════════════════════════════════════════════════════════════════════
SUBTRACT APPROACH TRACE (hasPathSum - Shorter)
═══════════════════════════════════════════════════════════════════════

1. Call(node=5, remaining=22)   → remaining = 22-5 = 17, recurse
2. Call(node=4, remaining=17)   → remaining = 17-4 = 13, recurse
3. Call(node=11, remaining=13)  → remaining = 13-11 = 2, recurse
4. Call(node=7, remaining=2)    → IS LEAF: 2 == 7? NO → return false
5. Back at 11, try right
6. Call(node=2, remaining=2)    → IS LEAF: 2 == 2? YES → return true ✓
7. Back at 11 → return true
8. Back at 4 → return true  
9. Back at 5 → return true

Both approaches work the same way, just subtract vs accumulate!

OUTPUT:
Has path sum 22 (subtract approach)? Yes
Has path sum 22 (accumulate approach)? Yes
Has path sum 26? Yes
*/
