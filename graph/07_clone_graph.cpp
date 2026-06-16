/*
PROBLEM: Clone Graph (LeetCode 133)
Difficulty: Medium
Pattern: DFS/BFS with HashMap

DESCRIPTION:
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node contains a value and a list of its neighbors.

GRAPH DIAGRAM:
  Original Graph:              Cloned Graph:
      1 ---- 2                     1' --- 2'
      |      |                     |      |
      |      |          -->        |      |
      4 ---- 3                     4' --- 3'

  Node 1: neighbors = [2, 4]      All nodes and edges are duplicated
  Node 2: neighbors = [1, 3]      Each clone maintains same structure
  Node 3: neighbors = [2, 4]      Use HashMap to track original -> clone
  Node 4: neighbors = [1, 3]

APPROACH:
1. Use a hashmap to store mapping of original node to cloned node
2. Use DFS to traverse the graph
3. For each node, create a clone and add to hashmap
4. Recursively clone all neighbors

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for hashmap and recursion stack
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<Node*, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        // If already cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        // Create a new node with same value
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        
        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};

void printGraph(Node* node, unordered_map<Node*, bool>& printed) {
    if (node == nullptr || printed[node]) {
        return;
    }
    
    printed[node] = true;
    cout << "Node " << node->val << " neighbors: ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;
    
    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, printed);
    }
}

int main() {
    // Create a sample graph: 1--2
    //                         |  |
    //                         4--3
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    
    Solution sol;
    Node* cloned = sol.cloneGraph(node1);
    
    cout << "Original Graph:" << endl;
    unordered_map<Node*, bool> printed1;
    printGraph(node1, printed1);
    
    cout << "\nCloned Graph:" << endl;
    unordered_map<Node*, bool> printed2;
    printGraph(cloned, printed2);
    
    return 0;
}

/*
INPUT:
adjList = [[2,4],[1,3],[2,4],[1,3]]

OUTPUT:
Same structure as input (deep copy)

EXPLANATION:
- Node 1 is connected to nodes 2 and 4
- Node 2 is connected to nodes 1 and 3
- Node 3 is connected to nodes 2 and 4
- Node 4 is connected to nodes 1 and 3
The clone has the same structure but different memory addresses.
*/
