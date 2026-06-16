/*
PROBLEM: Design Circular Queue
Difficulty: Easy
Pattern: Circular Buffer

DESCRIPTION:
Design a circular queue with fixed size that supports:
- enqueue(value): Insert element (return true if successful)
- dequeue(): Delete element (return true if successful)
- front(): Get front element
- rear(): Get rear element
- isEmpty(): Check if queue is empty
- isFull(): Check if queue is full

INPUT:
Capacity: 3
Operations: enqueue(1), enqueue(2), enqueue(3), enqueue(4), 
            dequeue(), enqueue(4), rear()

OUTPUT:
Enqueue 1: true
Enqueue 2: true
Enqueue 3: true
Enqueue 4: false (full)
Dequeue: true
Enqueue 4: true
Rear: 4

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(k) where k is capacity
*/

#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    CircularQueue(int k) {
        data.resize(k);
        capacity = k;
        head = -1;
        tail = -1;
        size = 0;
    }

    // Insert an element (O(1))
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        if (isEmpty()) {
            head = 0;
        }
        
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
        return true;
    }

    // Delete an element (O(1))
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        if (head == tail) {
            // Only one element
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }
        
        size--;
        return true;
    }

    // Get front element (O(1))
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }

    // Get rear element (O(1))
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }

    // Check if empty (O(1))
    bool isEmpty() {
        return size == 0;
    }

    // Check if full (O(1))
    bool isFull() {
        return size == capacity;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue: ";
        int i = head;
        int count = 0;
        while (count < size) {
            cout << data[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);

    cout << "Enqueue 10: " << (cq.enQueue(10) ? "true" : "false") << endl;
    cout << "Enqueue 20: " << (cq.enQueue(20) ? "true" : "false") << endl;
    cout << "Enqueue 30: " << (cq.enQueue(30) ? "true" : "false") << endl;
    cout << "Enqueue 40: " << (cq.enQueue(40) ? "true" : "false") << endl;
    cout << "Enqueue 50: " << (cq.enQueue(50) ? "true" : "false") << endl;
    
    cq.display();
    
    cout << "Enqueue 60: " << (cq.enQueue(60) ? "true" : "false") << endl; // false
    
    cout << "Front: " << cq.Front() << endl;
    cout << "Rear: " << cq.Rear() << endl;
    
    cout << "Dequeue: " << (cq.deQueue() ? "true" : "false") << endl;
    cout << "Dequeue: " << (cq.deQueue() ? "true" : "false") << endl;
    
    cq.display();
    
    cout << "Enqueue 60: " << (cq.enQueue(60) ? "true" : "false") << endl;
    cout << "Enqueue 70: " << (cq.enQueue(70) ? "true" : "false") << endl;
    
    cq.display();

    return 0;
}

/*
EXPLANATION:
1. Use array with head and tail pointers
2. Circular wrapping using modulo: (index + 1) % capacity
3. Track size to distinguish empty vs full
4. Head points to front, tail points to rear
5. When wrapping occurs, reuse freed space

KEY FORMULAS:
- Next position: (current + 1) % capacity
- Previous position: (current - 1 + capacity) % capacity
- Is Full: size == capacity
- Is Empty: size == 0

KEY LEARNING POINTS:
- Efficient space utilization
- Common in OS task scheduling, buffer management
- LeetCode 622 - Design Circular Queue
*/
