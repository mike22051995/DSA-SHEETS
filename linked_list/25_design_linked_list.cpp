/*
PROBLEM: Design Linked List
Difficulty: Medium
Pattern: Custom data structure implementation

DESCRIPTION:
Design your implementation of the linked list. You can choose to use a singly 
or doubly linked list.

Implement the MyLinkedList class:
- MyLinkedList() Initializes the object
- int get(int index) Get the value of the indexth node. Return -1 if invalid
- void addAtHead(int val) Add a node of value val before the first element
- void addAtTail(int val) Add a node of value val as the last element
- void addAtIndex(int index, int val) Add node before indexth node
- void deleteAtIndex(int index) Delete the indexth node if valid

EXAMPLE:
Input: ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", 
        "deleteAtIndex", "get"]
       [[], [1], [3], [1, 2], [1], [1], [1]]
Output: [null, null, null, null, 2, null, 3]

TIME COMPLEXITY: 
- get: O(n)
- addAtHead: O(1)
- addAtTail: O(n) with singly linked list, O(1) with tail pointer
- addAtIndex: O(n)
- deleteAtIndex: O(n)

SPACE COMPLEXITY: O(1) for each operation
*/

#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {}
    };
    
    Node* head;
    int size;
    
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }
        
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
    
    void printList() {
        Node* current = head;
        cout << "[";
        while (current != NULL) {
            cout << current->val;
            if (current->next != NULL) cout << ", ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    MyLinkedList* list = new MyLinkedList();
    
    cout << "addAtHead(1): ";
    list->addAtHead(1);
    list->printList();
    
    cout << "addAtTail(3): ";
    list->addAtTail(3);
    list->printList();
    
    cout << "addAtIndex(1, 2): ";
    list->addAtIndex(1, 2);
    list->printList();
    
    cout << "get(1): " << list->get(1) << endl;
    
    cout << "deleteAtIndex(1): ";
    list->deleteAtIndex(1);
    list->printList();
    
    cout << "get(1): " << list->get(1) << endl;
    
    delete list;
    return 0;
}

/*
EXPLANATION:

Data Structure:
- Internal Node structure with value and next pointer
- Head pointer to track first node
- Size variable to track number of nodes

Operations:

1. GET(index):
   - Validate index
   - Traverse to index
   - Return value

2. ADD_AT_HEAD(val):
   - Create new node
   - Point new node to current head
   - Update head to new node
   - O(1) time

3. ADD_AT_TAIL(val):
   - If empty, add at head
   - Otherwise, traverse to last node
   - Add new node at end
   - O(n) time (can be O(1) with tail pointer)

4. ADD_AT_INDEX(index, val):
   - Validate index (0 to size inclusive)
   - If index = 0, add at head
   - Otherwise, traverse to (index-1)
   - Insert new node after current

5. DELETE_AT_INDEX(index):
   - Validate index (0 to size-1)
   - If index = 0, update head
   - Otherwise, traverse to (index-1)
   - Unlink and delete target node

EDGE CASES HANDLED:
- Empty list
- Adding/deleting at head
- Invalid indices
- Adding at tail
- Single node list

OPTIMIZATION POSSIBILITIES:
- Add tail pointer for O(1) addAtTail
- Use doubly linked list for O(1) deleteAtTail
- Add sentinel nodes to simplify edge cases

KEY PATTERN: Custom linked list implementation
Essential for understanding linked list fundamentals!
Common in system design interviews.
*/
