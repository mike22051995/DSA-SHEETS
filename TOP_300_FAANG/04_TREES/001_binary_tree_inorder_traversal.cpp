/*
================================================================================
PROBLEM: Binary Tree Inorder Traversal (LeetCode #94)
DIFFICULTY: Easy
PATTERN: Tree Traversal / DFS
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Inorder: Left -> Root -> Right

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Need to traverse binary tree
2. Order matters: inorder, preorder, postorder
3. Can solve recursively or iteratively
4. BST inorder gives sorted sequence

Key Indicators:
- "Tree traversal"
- Visit nodes in specific order
- DFS-based exploration
- Iterative version uses stack

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: root = [1,null,2,3]
      1
       \
        2
       /
      3
Output: [1,3,2]
Explanation: Inorder = left, root, right

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2,3,4,5]
        1
       / \
      2   3
     / \
    4   5
Output: [4,2,5,1,3]

================================================================================
EXPLANATION:

Inorder Traversal Order:
1. Visit left subtree
2. Visit current node
3. Visit right subtree

For BST: produces sorted order

Recursive Approach:
- Base case: null node
- Recursively traverse left
- Process current
- Recursively traverse right

Iterative Approach (Stack):
- Use stack to simulate recursion
- Go left as far as possible
- Process node, then go right

Time: O(n), Space: O(h) where h is height

================================================================================
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive Solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        inorderHelper(node->left, result);   // Left
        result.push_back(node->val);          // Root
        inorderHelper(node->right, result);  // Right
    }
    
    // Iterative Solution using Stack
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            // Go to leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // Process current node
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            
            // Go to right subtree
            curr = curr->right;
        }
        
        return result;
    }
    
    // Morris Traversal - O(1) Space
    vector<int> inorderTraversalMorris(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left child, process current and go right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (pred->right == nullptr) {
                    // Create thread
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove thread
                    pred->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
};

// Helper function to create tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

void printVector(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    TreeNode* root = createTree();
    
    cout << "Recursive Inorder: ";
    vector<int> result1 = sol.inorderTraversal(root);
    printVector(result1);
    
    cout << "Iterative Inorder: ";
    vector<int> result2 = sol.inorderTraversalIterative(root);
    printVector(result2);
    
    cout << "Morris Inorder: ";
    vector<int> result3 = sol.inorderTraversalMorris(root);
    printVector(result3);
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Binary Tree Preorder Traversal (LeetCode #144) - Easy
   - Root -> Left -> Right

2. Binary Tree Postorder Traversal (LeetCode #145) - Easy
   - Left -> Right -> Root

3. Binary Tree Level Order Traversal (LeetCode #102) - Medium
   - BFS, level by level

4. Validate Binary Search Tree (LeetCode #98) - Medium
   - Use inorder to check sorted

5. Binary Search Tree Iterator (LeetCode #173) - Medium
   - Implement next() for inorder

6. Kth Smallest Element in BST (LeetCode #230) - Medium
   - Inorder gives sorted order

7. Recover Binary Search Tree (LeetCode #99) - Medium
   - Two swapped nodes in BST

8. Flatten Binary Tree to Linked List (LeetCode #114) - Medium
   - Preorder flattening

9. Construct Binary Tree from Traversals (LeetCode #105, #106) - Medium
   - Given inorder + preorder/postorder

10. Vertical Order Traversal (LeetCode #987) - Hard
    - Custom ordering

================================================================================
ALL THREE TRAVERSALS:
================================================================================

Inorder (Left-Root-Right):
- For BST: gives sorted order
- Recursive is most intuitive
- Iterative uses stack

Preorder (Root-Left-Right):
- Good for copying tree
- DFS exploration order
- Easy iterative with stack

Postorder (Left-Right-Root):
- Good for deleting tree
- Bottom-up processing
- Slightly tricky iterative

Level Order (BFS):
- Use queue instead of stack
- Level by level
- Good for shortest path

================================================================================
*/
