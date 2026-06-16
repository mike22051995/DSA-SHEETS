/*
PROBLEM: Vertical Order Traversal of a Binary Tree (LeetCode 987)
DIFFICULTY: Hard
PATTERN: DFS/BFS with Coordinate Tracking

DESCRIPTION:
Given the root of a binary tree, return the vertical order traversal of its nodes' values.
For each node at position (row, col):
- Its left child is at (row + 1, col - 1)
- Its right child is at (row + 1, col + 1)
Return values from left to right. If multiple nodes at same position, sort by value.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3(0,0)
      / \
  9(1,-1) 20(1,1)
          /  \
      15(2,0) 7(2,2)

Output: [[9],[3,15],[20],[7]]

TIME COMPLEXITY: O(n log n) due to sorting
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map: column -> (row, value) pairs
        map<int, vector<pair<int, int>>> columnMap;
        
        // Queue: (node, row, col)
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();
            
            // Store node value with its row
            columnMap[col].push_back({row, node->val});
            
            // Add children with updated positions
            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }
            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }
        
        // Build result
        vector<vector<int>> result;
        
        for (auto& [col, values] : columnMap) {
            // Sort by row first, then by value
            sort(values.begin(), values.end());
            
            vector<int> column;
            for (auto& [row, val] : values) {
                column.push_back(val);
            }
            result.push_back(column);
        }
        
        return result;
    }
    
    // Alternative: DFS approach
    map<int, vector<pair<int, int>>> colMap;
    
    void dfs(TreeNode* node, int row, int col) {
        if (node == nullptr) return;
        
        colMap[col].push_back({row, node->val});
        
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
    
    vector<vector<int>> verticalTraversalDFS(TreeNode* root) {
        dfs(root, 0, 0);
        
        vector<vector<int>> result;
        
        for (auto& [col, values] : colMap) {
            sort(values.begin(), values.end());
            
            vector<int> column;
            for (auto& [row, val] : values) {
                column.push_back(val);
            }
            result.push_back(column);
        }
        
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* createComplexTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    
    TreeNode* root1 = createSampleTree();
    auto result1 = sol.verticalTraversal(root1);
    
    cout << "Vertical order traversal:" << endl;
    for (int i = 0; i < result1.size(); i++) {
        cout << "Column " << i << ": ";
        for (int val : result1[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    TreeNode* root2 = createComplexTree();
    auto result2 = sol.verticalTraversalDFS(root2);
    
    cout << "\nComplex tree vertical order:" << endl;
    for (int i = 0; i < result2.size(); i++) {
        cout << "Column " << i << ": ";
        for (int val : result2[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
EXPLANATION:

COORDINATE SYSTEM:
- Root is at (row=0, col=0)
- Left child: row+1, col-1 (go down and left)
- Right child: row+1, col+1 (go down and right)

ALGORITHM:

1. Traverse tree (BFS or DFS) and track (row, col) for each node

2. Store nodes in map: column -> list of (row, value) pairs
   - Map automatically sorts by column (key)

3. For each column, sort the (row, value) pairs:
   - Primary sort: by row (top to bottom)
   - Secondary sort: by value (if same position)

4. Extract values and build result

WHY BOTH SORTS?
- Map sorts by column (left to right)
- Manual sort within column by row, then value

EDGE CASE:
Multiple nodes at same (row, col) → sort by value
Example:
    1
   / \
  2   2
Both children at (1, -1) and (1, 1) respectively, but if overlapping,
need to sort by value.

BFS vs DFS:
- BFS: Level-by-level, easier to understand
- DFS: Simpler code, same result after sorting

PATTERN:
Coordinate tracking in trees:
- Vertical order
- Top view / Bottom view
- Diagonal traversal

OUTPUT:
Vertical order traversal:
Column 0: 9
Column 1: 3 15
Column 2: 20
Column 3: 7

Complex tree vertical order:
Column 0: 4
Column 1: 2
Column 2: 1 5 6
Column 3: 3
Column 4: 7
*/
