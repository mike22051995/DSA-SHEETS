/*
PROBLEM: LRU Cache
Difficulty: Hard
Pattern: Hash Map + Doubly Linked List

DESCRIPTION:
Design a data structure that follows the constraints of a Least Recently 
Used (LRU) cache.

Implement the LRUCache class:
- LRUCache(int capacity) Initialize with positive size capacity
- int get(int key) Return value if exists, else -1
- void put(int key, int value) Update or insert the key-value pair

Both get and put must run in O(1) average time complexity.

EXAMPLE:
Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
       [[2], [1,1], [2,2], [1], [3,3], [2], [4,4], [1], [3], [4]]
Output: [null, null, null, 1, null, -1, null, -1, 3, 4]

TIME COMPLEXITY: O(1) for both get and put
SPACE COMPLEXITY: O(capacity)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;  // Dummy head (most recent)
    Node* tail;  // Dummy tail (least recent)
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        moveToHead(node);  // Mark as recently used
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update value
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // New key
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            
            if (cache.size() > capacity) {
                // Remove LRU
                Node* lru = removeTail();
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
    
    void printCache() {
        cout << "Cache (MRU -> LRU): ";
        Node* current = head->next;
        while (current != tail) {
            cout << "[" << current->key << ":" << current->value << "] ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(2);
    
    cout << "put(1, 1)" << endl;
    cache.put(1, 1);
    cache.printCache();
    
    cout << "put(2, 2)" << endl;
    cache.put(2, 2);
    cache.printCache();
    
    cout << "get(1): " << cache.get(1) << endl;
    cache.printCache();
    
    cout << "put(3, 3) - evicts key 2" << endl;
    cache.put(3, 3);
    cache.printCache();
    
    cout << "get(2): " << cache.get(2) << endl;
    
    cout << "put(4, 4) - evicts key 1" << endl;
    cache.put(4, 4);
    cache.printCache();
    
    cout << "get(1): " << cache.get(1) << endl;
    cout << "get(3): " << cache.get(3) << endl;
    cout << "get(4): " << cache.get(4) << endl;
    
    return 0;
}

/*
EXPLANATION:

Data Structures:
1. Hash Map: key -> Node pointer (O(1) access)
2. Doubly Linked List: maintains LRU order
   - Head (dummy): Most Recently Used
   - Tail (dummy): Least Recently Used

Operations:

GET(key):
1. Check if key exists in map
2. If yes, move node to head (mark as recently used)
3. Return value
4. If no, return -1

PUT(key, value):
1. If key exists:
   - Update value
   - Move to head
2. If key doesn't exist:
   - Create new node
   - Add to head
   - Add to map
   - If capacity exceeded, remove LRU (tail's prev)

WHY DOUBLY LINKED LIST?
- Need to remove from middle (when moving to head): O(1) with prev pointer
- Need to add to head: O(1)
- Need to remove from tail: O(1)

WHY DUMMY NODES?
- Simplify edge cases (empty list, single element)
- No special handling for head/tail

VISUALIZATION (capacity=2):

Initial: head <-> tail

put(1,1): head <-> [1:1] <-> tail

put(2,2): head <-> [2:2] <-> [1:1] <-> tail

get(1): head <-> [1:1] <-> [2:2] <-> tail
        (moved 1 to head as recently used)

put(3,3): head <-> [3:3] <-> [1:1] <-> tail
          (evicted 2 as LRU)

TIME COMPLEXITY ANALYSIS:
- Hash map operations: O(1)
- List operations (add/remove): O(1)
- Overall: O(1) for both get and put

SPACE COMPLEXITY:
- Hash map: O(capacity)
- Linked list: O(capacity)
- Total: O(capacity)

KEY PATTERN: Hash Map + Doubly Linked List
Classic design pattern for O(1) cache with eviction!
Common in system design interviews!
*/
