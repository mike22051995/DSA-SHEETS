/*
================================================================================
PROBLEM: LRU Cache (LeetCode #146)
DIFFICULTY: Medium
PATTERN: Hash Map + Doubly Linked List
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
    
    Node* popTail() {
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
        if (!cache.count(key)) return -1;
        
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addNode(node);
            
            if (cache.size() > capacity) {
                Node* removed = popTail();
                cache.erase(removed->key);
                delete removed;
            }
        }
    }
};

int main() {
    LRUCache lru(2);
    
    lru.put(1, 1);
    lru.put(2, 2);
    cout << "get(1): " << lru.get(1) << endl;     // returns 1
    lru.put(3, 3);                                 // evicts key 2
    cout << "get(2): " << lru.get(2) << endl;     // returns -1
    lru.put(4, 4);                                 // evicts key 1
    cout << "get(1): " << lru.get(1) << endl;     // returns -1
    cout << "get(3): " << lru.get(3) << endl;     // returns 3
    cout << "get(4): " << lru.get(4) << endl;     // returns 4
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. LFU Cache (LeetCode #460)
2. Design In-Memory File System (LeetCode #588)
3. Design Browser History (LeetCode #1472)
4. Design HashMap (LeetCode #706)
5. Design Linked List (LeetCode #707)
6. Time Based Key-Value Store (LeetCode #981)
7. Design Twitter (LeetCode #355)
8. All O`one Data Structure (LeetCode #432)
9. Insert Delete GetRandom O(1) (LeetCode #380)
10. Snapshot Array (LeetCode #1146)
*/
