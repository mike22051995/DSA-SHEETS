/*
PROBLEM: Union-Find (Disjoint Set Union)
Difficulty: Medium
Pattern: Union-Find Data Structure

DESCRIPTION:
Implement Union-Find data structure with path compression and union by rank.
This is fundamental for many graph problems involving connected components.

UNION-FIND DIAGRAM:
  Initial (n=5):        After Union(0,1):    After Union(2,3):
  0  1  2  3  4         0                    0        2
                        |                    |        |
                        1  2  3  4           1    4   3

  After Union(0,2):
       0
      / \
     1   2
         |
     4   3

  Path Compression: Flatten tree during find()
  Union by Rank: Attach smaller tree to larger tree root

OPERATIONS:
1. Find: Find the representative/parent of a set
2. Union: Merge two sets
3. Path Compression: Optimize find operation
4. Union by Rank: Attach smaller tree under larger tree

TIME COMPLEXITY: O(α(N)) for both find and union (nearly constant)
SPACE COMPLEXITY: O(N) for parent and rank arrays
*/

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int components;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        components = n;
        
        // Initially, each element is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union by rank
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; // Already in same set
        }
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        components--;
        return true;
    }
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    
    int getComponents() {
        return components;
    }
};

int main() {
    // Example: 5 elements
    UnionFind uf(5);
    
    cout << "Initial components: " << uf.getComponents() << endl;
    
    uf.unite(0, 1);
    cout << "After union(0,1): " << uf.getComponents() << " components" << endl;
    
    uf.unite(1, 2);
    cout << "After union(1,2): " << uf.getComponents() << " components" << endl;
    
    uf.unite(3, 4);
    cout << "After union(3,4): " << uf.getComponents() << " components" << endl;
    
    cout << "\nAre 0 and 2 connected? " << (uf.isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 0 and 3 connected? " << (uf.isConnected(0, 3) ? "Yes" : "No") << endl;
    
    uf.unite(2, 3);
    cout << "\nAfter union(2,3): " << uf.getComponents() << " components" << endl;
    cout << "Are 0 and 4 connected? " << (uf.isConnected(0, 4) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT:
Operations:
- union(0,1)
- union(1,2)
- union(3,4)
- isConnected(0,2)
- isConnected(0,3)
- union(2,3)
- isConnected(0,4)

OUTPUT:
Initial components: 5
After union(0,1): 4 components
After union(1,2): 3 components
After union(3,4): 2 components
Are 0 and 2 connected? Yes
Are 0 and 3 connected? No
After union(2,3): 1 components
Are 0 and 4 connected? Yes

EXPLANATION:
Union-Find efficiently manages disjoint sets with near-constant time operations.
*/
