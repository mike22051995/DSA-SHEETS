/*
PROBLEM: Design Skip List
Difficulty: Hard
Pattern: Probabilistic data structure with multiple levels

DESCRIPTION:
Design a skip list that supports search, insertion, and deletion operations 
in O(log n) average time complexity.

Skip list is a probabilistic data structure that allows O(log n) search, 
insertion, and deletion by maintaining multiple levels of linked lists.

Operations:
- bool search(int target): Return true if target exists
- void add(int num): Insert num into the skip list
- bool erase(int num): Remove one occurrence of num, return true if removed

EXAMPLE:
Input: ["Skiplist", "add", "add", "add", "search", "add", "search", "erase", 
        "erase", "search"]
       [[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
Output: [null, null, null, null, false, null, true, false, true, false]

TIME COMPLEXITY: O(log n) average for all operations
SPACE COMPLEXITY: O(n log n) average
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Skiplist {
private:
    struct Node {
        int val;
        vector<Node*> forward;
        
        Node(int v, int level) : val(v), forward(level + 1, NULL) {}
    };
    
    static const int MAX_LEVEL = 16;
    Node* head;
    int currentLevel;
    
    // Random level generator (50% probability for each level)
    int randomLevel() {
        int level = 0;
        while (level < MAX_LEVEL && (rand() % 2) == 0) {
            level++;
        }
        return level;
    }
    
public:
    Skiplist() {
        srand(time(0));
        head = new Node(-1, MAX_LEVEL);
        currentLevel = 0;
    }
    
    bool search(int target) {
        Node* current = head;
        
        // Start from highest level, go down
        for (int i = currentLevel; i >= 0; i--) {
            // Move forward while next is less than target
            while (current->forward[i] != NULL && 
                   current->forward[i]->val < target) {
                current = current->forward[i];
            }
        }
        
        // Move to level 0
        current = current->forward[0];
        
        return (current != NULL && current->val == target);
    }
    
    void add(int num) {
        vector<Node*> update(MAX_LEVEL + 1);
        Node* current = head;
        
        // Find position to insert
        for (int i = currentLevel; i >= 0; i--) {
            while (current->forward[i] != NULL && 
                   current->forward[i]->val < num) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        
        // Generate random level
        int newLevel = randomLevel();
        
        // Update current level if needed
        if (newLevel > currentLevel) {
            for (int i = currentLevel + 1; i <= newLevel; i++) {
                update[i] = head;
            }
            currentLevel = newLevel;
        }
        
        // Create new node
        Node* newNode = new Node(num, newLevel);
        
        // Insert node at all levels
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL + 1);
        Node* current = head;
        
        // Find the node
        for (int i = currentLevel; i >= 0; i--) {
            while (current->forward[i] != NULL && 
                   current->forward[i]->val < num) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        
        current = current->forward[0];
        
        // Node not found
        if (current == NULL || current->val != num) {
            return false;
        }
        
        // Remove node from all levels
        for (int i = 0; i <= currentLevel; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        
        delete current;
        
        // Update current level
        while (currentLevel > 0 && head->forward[currentLevel] == NULL) {
            currentLevel--;
        }
        
        return true;
    }
    
    void display() {
        cout << "\n=== Skip List Structure ===" << endl;
        for (int i = currentLevel; i >= 0; i--) {
            cout << "Level " << i << ": HEAD";
            Node* node = head->forward[i];
            while (node != NULL) {
                cout << " -> " << node->val;
                node = node->forward[i];
            }
            cout << " -> NULL" << endl;
        }
        cout << "==========================\n" << endl;
    }
};

int main() {
    Skiplist skiplist;
    
    cout << "add(1)" << endl;
    skiplist.add(1);
    skiplist.display();
    
    cout << "add(2)" << endl;
    skiplist.add(2);
    skiplist.display();
    
    cout << "add(3)" << endl;
    skiplist.add(3);
    skiplist.display();
    
    cout << "search(0): " << (skiplist.search(0) ? "true" : "false") << endl;
    
    cout << "add(4)" << endl;
    skiplist.add(4);
    skiplist.display();
    
    cout << "search(1): " << (skiplist.search(1) ? "true" : "false") << endl;
    
    cout << "erase(0): " << (skiplist.erase(0) ? "true" : "false") << endl;
    
    cout << "erase(1): " << (skiplist.erase(1) ? "true" : "false") << endl;
    skiplist.display();
    
    cout << "search(1): " << (skiplist.search(1) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:

Skip List Structure:
Multiple levels of linked lists where:
- Level 0: Contains all elements (regular linked list)
- Level 1+: Contains subset of elements (express lanes)

VISUALIZATION:
Level 3: HEAD -----------------> 7 -----------> NULL
Level 2: HEAD ---------> 4 ----> 7 -----------> NULL
Level 1: HEAD -> 2 ----> 4 ----> 7 -> 9 ------> NULL
Level 0: HEAD -> 2 -> 3 -> 4 -> 6 -> 7 -> 9 -> NULL

SEARCH Algorithm:
1. Start at highest level, leftmost position
2. Move right while next < target
3. Drop down one level
4. Repeat until level 0
5. Check if found

INSERTION Algorithm:
1. Find insertion position (like search)
2. Generate random level for new node
3. Create node with that many levels
4. Insert at all levels up to random level

DELETION Algorithm:
1. Find node to delete
2. Update all pointers at all levels
3. Delete the node
4. Reduce current level if needed

RANDOM LEVEL Generation:
- 50% probability for each level
- Average node has ~2 levels
- Height grows as O(log n) with high probability

WHY SKIP LIST?
Advantages:
- Simpler than balanced trees
- No rebalancing needed
- Good cache performance (sequential access)
- O(log n) expected time

Disadvantages:
- Probabilistic (not guaranteed O(log n))
- More space than simple linked list
- Slower than hash table for exact match

TIME COMPLEXITY:
- Search: O(log n) expected
- Insert: O(log n) expected
- Delete: O(log n) expected

SPACE COMPLEXITY:
- O(n log n) expected
- Each node appears in ~2 levels on average

KEY INSIGHT:
Express lanes allow "skipping" over many nodes,
similar to how binary search skips half the elements.

KEY PATTERN: Probabilistic data structure with layered lists
Advanced data structure combining linked lists with randomization!
*/
