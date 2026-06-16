/*
PROBLEM: Kth Smallest Element in a BST (LeetCode 230)
DIFFICULTY: Medium
PATTERN: BST - Inorder Traversal

DESCRIPTION:
Given the root of a binary search tree, and an integer k,
return the kth smallest value (1-indexed) of all the values in the tree.

EXAMPLE:
Input: root = [3,1,4,null,2], k = 1
       3
      / \
     1   4
      \
       2
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

TIME COMPLEXITY: O(H + k) where H is height
SPACE COMPLEXITY: O(H) for recursion stack
*/

#include <iostream>
#include <vector>
#include <stack>
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
    // Approach 1: Inorder traversal - stop at kth element
    int count;
    int result;
    
    void inorder(TreeNode* root, int k) {
        if (root == nullptr) return;
        
        // Traverse left
        inorder(root->left, k);
        
        // Process current node
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        
        // Traverse right
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return result;
    }
    
    // Approach 2: Iterative inorder using stack
    int kthSmallestIterative(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        int count = 0;
        
        while (curr != nullptr || !stk.empty()) {
            // Go to leftmost node
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            // Process current node
            curr = stk.top();
            stk.pop();
            count++;
            
            if (count == k) return curr->val;
            
            // Move to right subtree
            curr = curr->right;
        }
        
        return -1; // Should never reach here
    }
    
    // Approach 3: Store all in array (if multiple queries)
    void getAllInorder(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;
        getAllInorder(root->left, values);
        values.push_back(root->val);
        getAllInorder(root->right, values);
    }
    
    int kthSmallestArray(TreeNode* root, int k) {
        vector<int> values;
        getAllInorder(root, values);
        return values[k - 1];  // k is 1-indexed
    }
};

TreeNode* createSampleBST() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleBST();
    
    cout << "BST inorder: 1 2 3 4 5 6" << endl;
    cout << "1st smallest: " << sol.kthSmallest(root, 1) << endl;
    cout << "3rd smallest: " << sol.kthSmallest(root, 3) << endl;
    cout << "6th smallest: " << sol.kthSmallest(root, 6) << endl;
    
    cout << "\nUsing iterative approach:" << endl;
    cout << "4th smallest: " << sol.kthSmallestIterative(root, 4) << endl;
    
    return 0;
}

/*
EXPLANATION:

KEY INSIGHT:
Inorder traversal of BST gives sorted order!
So kth smallest = kth element in inorder traversal.

Three Approaches:

1. Recursive Inorder with Early Stop:
   - Do inorder traversal
   - Count elements as we visit
   - Stop when count reaches k
   - Most elegant!
   - Time: O(H + k) - go down H, then process k nodes

2. Iterative Inorder:
   - Use stack to simulate recursion
   - Same logic but iterative
   - Useful to avoid recursion overhead
   - Same time complexity

3. Store All Values:
   - Get all values in sorted array
   - Return kth element
   - Good if there are MULTIPLE queries
   - Time: O(n) always, Space: O(n)

WHEN TO USE WHICH:

Single query, small k: Approach 1 or 2 (early termination)
Multiple queries: Approach 3 (precompute once)
Large k: Doesn't matter much

FOLLOW-UP:
What if BST is modified often?
- Use augmented BST with size of subtree stored in each node
- Can find kth smallest in O(H) time

IMPORTANT:
For BST problems, always think:
- Can inorder traversal help? (gives sorted order)
- Can BST property help? (left < root < right)

OUTPUT:
BST inorder: 1 2 3 4 5 6
1st smallest: 1
3rd smallest: 3
6th smallest: 6

Using iterative approach:
4th smallest: 4
*/
