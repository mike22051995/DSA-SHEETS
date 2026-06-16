/*
PROBLEM: Morris Inorder Traversal
DIFFICULTY: Hard
PATTERN: Threading Technique - O(1) Space Traversal

DESCRIPTION:
Implement inorder traversal of a binary tree using O(1) space (no recursion, no stack).
Morris Traversal uses threading to navigate without extra space.

EXAMPLE:
Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [4, 2, 5, 1, 3]

TIME COMPLEXITY: O(n) - each edge traversed at most twice
SPACE COMPLEXITY: O(1) - no recursion or stack
*/

#include <iostream>
#include <vector>
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
    vector<int> morrisInorder(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left child, process current and go right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor (rightmost node in left subtree)
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (pred->right == nullptr) {
                    // Create thread (temporary link)
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Thread exists, remove it and process current
                    pred->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
    
    // Preorder Morris Traversal
    vector<int> morrisPreorder(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (pred->right == nullptr) {
                    result.push_back(curr->val); // Process before going left
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    vector<int> inorder = sol.morrisInorder(root);
    cout << "Morris Inorder: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> preorder = sol.morrisPreorder(root);
    cout << "Morris Preorder: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

Morris Traversal is a technique to traverse tree with O(1) space!

KEY IDEA: Use "threading"
- Temporarily modify tree by creating links
- Use these links to navigate back to ancestors
- Remove links after use (restore tree structure)

ALGORITHM (Inorder):

1. Start at root, set curr = root

2. While curr is not null:
   
   Case 1: curr has no left child
   - Process curr (add to result)
   - Move to right: curr = curr->right
   
   Case 2: curr has left child
   - Find inorder predecessor (rightmost in left subtree)
   
   Sub-case 2a: Predecessor's right is null
   - Create thread: predecessor->right = curr
   - Move left: curr = curr->left
   
   Sub-case 2b: Predecessor's right points to curr (thread exists)
   - Remove thread: predecessor->right = null
   - Process curr (add to result)
   - Move right: curr = curr->right

EXAMPLE:
Tree:    1
        / \
       2   3
      / \
     4   5

Step-by-step:
1. curr=1, has left, find pred=5, create thread 5→1, curr=2
2. curr=2, has left, find pred=4, create thread 4→2, curr=4
3. curr=4, no left, process 4, curr=4->right (null)
4. curr=2 (via thread), remove thread, process 2, curr=5
5. curr=5, no left, process 5, curr=5->right (1 via thread)
6. curr=1, remove thread, process 1, curr=3
7. curr=3, no left, process 3, done

Result: 4, 2, 5, 1, 3

WHY O(1) SPACE?
- No recursion stack
- No explicit stack
- Only using existing tree nodes

WHY O(n) TIME?
Each edge is traversed at most twice:
- Once going down
- Once via thread going back up

APPLICATIONS:
- Space-constrained environments
- Flattening trees
- Finding kth element without extra space

TRADE-OFF:
More complex code vs O(1) space

OUTPUT:
Morris Inorder: 4 2 5 1 3
Morris Preorder: 1 2 4 5 3
*/
