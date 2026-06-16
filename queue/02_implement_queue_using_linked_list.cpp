/*
PROBLEM: Implement Queue using Linked List
Difficulty: Easy
Pattern: Basic Queue Implementation

DESCRIPTION:
Implement a queue using a singly linked list with operations:
- enqueue(x): Add element to rear
- dequeue(): Remove element from front
- front(): Get front element
- isEmpty(): Check if empty

INPUT:
Operations: enqueue(5), enqueue(10), dequeue(), enqueue(15), front()

OUTPUT:
Enqueued: 5
Enqueued: 10
Dequeued: 5
Enqueued: 15
Front: 10

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(n) where n is number of elements
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    // Add element to rear
    void enqueue(int x) {
        Node* newNode = new Node(x);
        
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
        cout << "Enqueued: " << x << endl;
    }

    // Remove and return front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        Node* temp = frontNode;
        int item = temp->data;
        frontNode = frontNode->next;
        
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        
        delete temp;
        count--;
        return item;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return frontNode->data;
    }

    // Check if empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Get size
    int size() {
        return count;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element: " << q.front() << endl;

    q.enqueue(20);
    q.enqueue(25);

    cout << "Queue size: " << q.size() << endl;

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}

/*
EXPLANATION:
1. Use linked list nodes with data and next pointer
2. Maintain front and rear pointers
3. Enqueue: Add at rear, update rear pointer
4. Dequeue: Remove from front, update front pointer
5. Handle edge cases when queue becomes empty

KEY LEARNING POINTS:
- Dynamic size (no overflow)
- O(1) operations with proper pointer management
- Must handle memory deallocation properly
*/
