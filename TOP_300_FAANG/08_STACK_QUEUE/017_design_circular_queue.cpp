/*
================================================================================
PROBLEM: Design Circular Queue (LeetCode #622)
DIFFICULTY: Medium
PATTERN: Queue Design / Array
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Design your implementation of the circular queue. The circular queue is a
linear data structure in which operations are performed based on FIFO principle
and the last position is connected back to the first position to make a circle.

EXAMPLES:

MyCircularQueue circularQueue = new MyCircularQueue(3);
circularQueue.enQueue(1);  // return True
circularQueue.enQueue(2);  // return True
circularQueue.enQueue(3);  // return True
circularQueue.enQueue(4);  // return False (queue is full)
circularQueue.Rear();      // return 3
circularQueue.isFull();    // return True
circularQueue.deQueue();   // return True
circularQueue.enQueue(4);  // return True
circularQueue.Rear();      // return 4

PATTERN RECOGNITION:
Use this pattern when:
- Need circular buffer implementation
- Fixed size queue with wrap-around
- Track head, tail pointers with modulo arithmetic
*/

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        if (isEmpty()) {
            head = 0;
        }
        
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }
        
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue queue(3);
    
    cout << "enQueue(1): " << (queue.enQueue(1) ? "true" : "false") << endl;
    cout << "enQueue(2): " << (queue.enQueue(2) ? "true" : "false") << endl;
    cout << "enQueue(3): " << (queue.enQueue(3) ? "true" : "false") << endl;
    cout << "enQueue(4): " << (queue.enQueue(4) ? "true" : "false") << endl;
    cout << "Rear: " << queue.Rear() << endl;
    cout << "isFull: " << (queue.isFull() ? "true" : "false") << endl;
    cout << "deQueue: " << (queue.deQueue() ? "true" : "false") << endl;
    cout << "enQueue(4): " << (queue.enQueue(4) ? "true" : "false") << endl;
    cout << "Rear: " << queue.Rear() << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(k) where k is queue capacity

SIMILAR PROBLEMS:
1. Design Circular Deque (LeetCode #641)
2. Implement Queue using Stacks (LeetCode #232)
3. Implement Stack using Queues (LeetCode #225)
4. Moving Average from Data Stream (LeetCode #346)
5. Design Hit Counter (LeetCode #362)
6. LRU Cache (LeetCode #146)
7. LFU Cache (LeetCode #460)
8. Design Browser History (LeetCode #1472)
9. Design Parking System (LeetCode #1603)
10. Design Most Recently Used Queue (LeetCode #1756)
*/
