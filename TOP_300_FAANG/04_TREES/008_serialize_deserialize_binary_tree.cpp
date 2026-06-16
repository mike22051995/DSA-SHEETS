/*
================================================================================
PROBLEM: Serialize and Deserialize Binary Tree (LeetCode #297)
DIFFICULTY: Hard
PATTERN: Tree Traversal with Encoding
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, LinkedIn
================================================================================
*/

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string (Preorder)
    string serialize(TreeNode* root) {
        if (!root) return "null";
        
        return to_string(root->val) + "," + 
               serialize(root->left) + "," + 
               serialize(root->right);
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string token;
        
        while (getline(ss, token, ',')) {
            nodes.push(token);
        }
        
        return deserializeHelper(nodes);
    }
    
private:
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        
        if (val == "null") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);
        
        return node;
    }
};

// Alternative: Level Order (BFS) Approach
class CodecBFS {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(ss, token, ',')) {
                if (token != "null") {
                    node->left = new TreeNode(stoi(token));
                    q.push(node->left);
                }
            }
            
            if (getline(ss, token, ',')) {
                if (token != "null") {
                    node->right = new TreeNode(stoi(token));
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};

int main() {
    Codec codec;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;
    
    TreeNode* deserialized = codec.deserialize(serialized);
    string reserialized = codec.serialize(deserialized);
    cout << "Reserialized: " << reserialized << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Serialize and Deserialize BST (LeetCode #449)
2. Serialize and Deserialize N-ary Tree (LeetCode #428)
3. Encode and Decode Strings (LeetCode #271)
4. Encode N-ary Tree to Binary Tree (LeetCode #431)
5. Construct Binary Tree from Preorder and Inorder (LeetCode #105)
6. Construct Binary Tree from Inorder and Postorder (LeetCode #106)
7. Verify Preorder Serialization (LeetCode #331)
8. Find Duplicate Subtrees (LeetCode #652)
9. Recover Binary Search Tree (LeetCode #99)
10. Clone Graph (LeetCode #133)
*/
