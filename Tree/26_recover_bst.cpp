/*
PROBLEM: Recover Binary Search Tree (LeetCode 99)
DIFFICULTY: Medium/Hard
PATTERN: BST - Inorder with Anomaly Detection

DESCRIPTION:
You are given the root of a binary search tree (BST) where the values of exactly
two nodes have been swapped by mistake. Recover the tree without changing its structure.

EXAMPLE:
Input: root = [1,3,null,null,2]
   1
  /
 3
  \
   2
Output: [3,1,null,null,2]
   3
  /
 1
  \
   2

Input: root = [3,1,4,null,null,2]
   3
  / \
 1   4
    /
   2
Output: [2,1,4,null,null,3]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h) for recursion, O(1) with Morris traversal
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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        
        inorder(root->left);
        
        // Check if previous node is greater than current (violation)
        if (prev != nullptr && prev->val > root->val) {
            // First violation: mark 'first'
            if (first == nullptr) {
                first = prev;
            }
            // Mark 'second' in both first and second violation
            second = root;
        }
        
        prev = root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        // Swap the values of the two nodes
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

TreeNode* createTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    return root;
}

TreeNode* createTree2() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createTree1();
    cout << "Before recovery: ";
    printInorder(root1);
    cout << endl;
    
    sol.recoverTree(root1);
    cout << "After recovery: ";
    printInorder(root1);
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

KEY INSIGHT:
In a valid BST, inorder traversal gives sorted array.
If two nodes are swapped, we get anomalies in the sorted order.

TWO CASES:

1. Adjacent nodes swapped:
   Sorted: [1, 2, 3, 4, 5]
   Swapped 2,3: [1, 3, 2, 4, 5]
                     ↑ ↑
   One violation: prev(3) > curr(2)
   first = 3, second = 2

2. Non-adjacent nodes swapped:
   Sorted: [1, 2, 3, 4, 5]
   Swapped 2,5: [1, 5, 3, 4, 2]
                     ↑ ↑     ↑ ↑
   Two violations:
   - first at: prev(5) > curr(3), first = 5
   - second at: prev(4) > curr(2), second = 2

ALGORITHM:

1. Do inorder traversal
2. Track previous node
3. When prev > current (violation):
   - If first violation: first = prev, second = current
   - If second violation: second = current (keep first same)
4. After traversal, swap values of first and second

WHY THIS WORKS:

Adjacent swap: Only one violation
- first points to larger element
- second points to smaller element

Non-adjacent swap: Two violations
- first points to the element that should be later (first violation)
- second keeps getting updated until we find the element that should be earlier

EXAMPLE:
Inorder of [3,1,4,2]:
3, 1, 2, 4
↑  ↑  ↑
3 > 1: first=3, second=1
4 > 2: NO! (4 is actually correct position)
Wait, we have: 1, 2, 3, 4 after swap of values at nodes

Actually for tree [3,1,4,null,null,2]:
Inorder: 1, 3, 2, 4
      3 > 2: first=3, second=2
Result: Swap 3 and 2

SPACE OPTIMIZATION:
Can use Morris Traversal for O(1) space, but O(h) is fine.

OUTPUT:
Before recovery: 3 2 1
After recovery: 1 2 3
*/
