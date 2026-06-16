/*
================================================================================
PROBLEM: Clone Graph (LeetCode #133)
DIFFICULTY: Medium
PATTERN: DFS/BFS with Hash Map
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // DFS Approach
    unordered_map<Node*, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone;
    }
    
    // BFS Approach
    Node* cloneGraphBFS(Node* node) {
        if (node == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* neighbor : curr->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        
        return clone;
    }
};

int main() {
    Solution sol;
    
    // Create graph: 1-2
    //               | |
    //               4-3
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    
    Node* cloned = sol.cloneGraph(node1);
    cout << "Graph cloned successfully!" << endl;
    cout << "Clone value: " << cloned->val << ", Neighbors: " << cloned->neighbors.size() << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Copy List with Random Pointer (LeetCode #138)
2. Clone N-ary Tree (LeetCode #1490)
3. Clone Binary Tree (LeetCode #1485)
4. Reconstruct Itinerary (LeetCode #332)
5. Evaluate Division (LeetCode #399)
6. Network Delay Time (LeetCode #743)
7. Find Center of Star Graph (LeetCode #1791)
8. Number of Connected Components (LeetCode #323)
9. Graph Valid Tree (LeetCode #261)
10. All Paths From Source to Target (LeetCode #797)
*/
