/*
================================================================================
PROBLEM: Serialize and Deserialize BST (LeetCode #449)
DIFFICULTY: Medium
PATTERN: Tree Traversal / String Processing
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Preorder traversal
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }
    
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) return;
        
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string val;
        queue<int> values;
        
        while (getline(ss, val, ',')) {
            if (!val.empty()) {
                values.push(stoi(val));
            }
        }
        
        return deserializeHelper(values, INT_MIN, INT_MAX);
    }
    
    TreeNode* deserializeHelper(queue<int>& values, int minVal, int maxVal) {
        if (values.empty()) return nullptr;
        
        int val = values.front();
        
        if (val < minVal || val > maxVal) {
            return nullptr;
        }
        
        values.pop();
        TreeNode* node = new TreeNode(val);
        
        node->left = deserializeHelper(values, minVal, val);
        node->right = deserializeHelper(values, val, maxVal);
        
        return node;
    }
};

int main() {
    Codec codec;
    
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;
    
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized root: " << deserialized->val << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Serialize and Deserialize Binary Tree (LeetCode #297)
2. Serialize and Deserialize N-ary Tree (LeetCode #428)
3. Encode and Decode Strings (LeetCode #271)
4. Construct Binary Search Tree from Preorder (LeetCode #1008)
5. Construct Binary Tree from Preorder and Inorder (LeetCode #105)
6. Construct Binary Tree from Inorder and Postorder (LeetCode #106)
7. Verify Preorder Serialization (LeetCode #331)
8. Find Duplicate Subtrees (LeetCode #652)
9. Recover Binary Search Tree (LeetCode #99)
10. Convert Sorted Array to BST (LeetCode #108)
*/
