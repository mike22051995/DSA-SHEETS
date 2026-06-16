/*
PROBLEM: All Nodes Distance K in Binary Tree (LeetCode 863)
DIFFICULTY: Medium/Hard
PATTERN: Tree to Graph Conversion + BFS

DESCRIPTION:
Given the root of a binary tree, a target node, and an integer k,
return an array of the values of all nodes that have a distance k from the target node.

EXAMPLE:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
         3
        / \
       5   1
      / \ / \
     6  2 0  8
       / \
      7   4
Output: [7,4,1]
Nodes at distance 2 from 5: 7, 4, 1

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    
    // Build parent pointers for all nodes
    void buildParentMap(TreeNode* node, TreeNode* par) {
        if (node == nullptr) return;
        parent[node] = par;
        buildParentMap(node->left, node);
        buildParentMap(node->right, node);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Build parent map (convert tree to graph)
        buildParentMap(root, nullptr);
        
        // Step 2: BFS from target node
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        int distance = 0;
        
        while (!q.empty()) {
            if (distance == k) {
                // Found all nodes at distance k
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                
                // Check right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                
                // Check parent
                TreeNode* par = parent[node];
                if (par && visited.find(par) == visited.end()) {
                    q.push(par);
                    visited.insert(par);
                }
            }
            
            distance++;
        }
        
        return {};
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    TreeNode* target = root->left; // Node with value 5
    
    int k = 2;
    vector<int> result = sol.distanceK(root, target, k);
    
    cout << "Nodes at distance " << k << " from target " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

The key insight: In a tree, we can only go down to children.
But we need to go UP to parents too!

SOLUTION: Convert tree to undirected graph!

TWO STEPS:

1. Build Parent Map:
   - Do DFS and store parent of each node
   - Now we can navigate: left, right, AND parent
   - Tree is now effectively a graph!

2. BFS from Target:
   - Start BFS from target node
   - Can go to: left child, right child, parent
   - Use visited set to avoid cycles
   - Stop when distance = k

ALGORITHM:

buildParentMap():
- Recursively traverse tree
- For each node, store its parent
- Root's parent is nullptr

distanceK():
- Start BFS from target
- For each node, explore 3 directions:
  * Left child (if exists and not visited)
  * Right child (if exists and not visited)
  * Parent (if exists and not visited)
- Track distance with BFS levels
- When distance = k, return all nodes in queue

WHY BFS?
Because we want nodes at EXACT distance k.
BFS naturally processes nodes level by level (distance by distance).

KEY TRICK:
Use visited set to prevent going back to already-visited nodes.
Without this, we'd have infinite loops (parent → child → parent → ...)

ALTERNATIVE:
Could use DFS with distance tracking, but BFS is more natural.

OUTPUT:
Nodes at distance 2 from target 5: 7 4 1
*/
