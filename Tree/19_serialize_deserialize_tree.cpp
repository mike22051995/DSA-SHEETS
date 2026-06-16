/*
PROBLEM: Serialize and Deserialize Binary Tree (LeetCode 297)
DIFFICULTY: Hard
PATTERN: Tree Serialization - DFS/BFS

DESCRIPTION:
Design an algorithm to serialize and deserialize a binary tree.
Serialization is converting a tree to a string.
Deserialization is converting string back to tree.

EXAMPLE:
Input: root = [1,2,3,null,null,4,5]
       1
      / \
     2   3
        / \
       4   5
Output: "1,2,#,#,3,4,#,#,5,#,#"

TIME COMPLEXITY: O(n) for both operations
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize using preorder traversal
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << "# ";
            return;
        }
        
        out << root->val << " ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }
    
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Deserialize using preorder
    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val;
        
        if (val == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);
        
        return root;
    }
    
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Alternative: BFS approach
class CodecBFS {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == nullptr) {
                out << "# ";
            } else {
                out << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return out.str();
    }
    
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        istringstream in(data);
        string val;
        in >> val;
        
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Read left child
            if (!(in >> val)) break;
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            
            // Read right child
            if (!(in >> val)) break;
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    return root;
}

int main() {
    // Test DFS approach
    Codec codec;
    TreeNode* root = createSampleTree();
    
    cout << "Original tree (preorder): ";
    printPreorder(root);
    cout << endl;
    
    string serialized = codec.serialize(root);
    cout << "Serialized (DFS): " << serialized << endl;
    
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized tree (preorder): ";
    printPreorder(deserialized);
    cout << endl;
    
    // Test BFS approach
    CodecBFS codecBFS;
    TreeNode* root2 = createSampleTree();
    
    string serializedBFS = codecBFS.serialize(root2);
    cout << "\nSerialized (BFS): " << serializedBFS << endl;
    
    TreeNode* deserializedBFS = codecBFS.deserialize(serializedBFS);
    cout << "Deserialized tree (preorder): ";
    printPreorder(deserializedBFS);
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

Two Approaches:

1. DFS (Preorder) Approach:
   Serialize:
   - Use preorder: root, left, right
   - Use "#" for null nodes
   - String: "1 2 # # 3 4 # # 5 # #"
   
   Deserialize:
   - Read values in preorder
   - First value is root
   - Recursively build left subtree
   - Recursively build right subtree
   
2. BFS (Level Order) Approach:
   Serialize:
   - Level order traversal
   - Include null markers
   - String: "1 2 3 # # 4 5 # # # #"
   
   Deserialize:
   - Use queue
   - Read root, push to queue
   - For each node, read and attach left and right children

KEY INSIGHTS:

DFS Advantage:
- Natural recursion
- Preorder makes deserialization straightforward
- More compact for sparse trees

BFS Advantage:
- More intuitive (level by level)
- Better for wide trees

IMPORTANT:
Must include null markers! Otherwise can't distinguish:
   1          1
  /          /
 2      vs  2
           /
          #

WHY THIS WORKS:
Both traversals uniquely define the tree structure when
null nodes are included.

INTERVIEW TIP:
Know both approaches. DFS is usually preferred for elegance.

OUTPUT:
Original tree (preorder): 1 2 3 4 5
Serialized (DFS): 1 2 # # 3 4 # # 5 # #
Deserialized tree (preorder): 1 2 3 4 5

Serialized (BFS): 1 2 3 # # 4 5 # # # #
Deserialized tree (preorder): 1 2 3 4 5
*/
