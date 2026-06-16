/*
PROBLEM: Implement Queue using Array
Difficulty: Easy
Pattern: Basic Queue Implementation

DESCRIPTION:
Implement a queue data structure using an array with the following operations:
- enqueue(x): Add element x to the end of queue
- dequeue(): Remove and return the front element
- front(): Get the front element
- isEmpty(): Check if queue is empty
- isFull(): Check if queue is full
- size(): Get the number of elements

INPUT:
Operations: enqueue(10), enqueue(20), enqueue(30), dequeue(), front()

OUTPUT:
Dequeued: 10
Front: 20

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(n) where n is the maximum capacity
*/

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    // Add element to queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << x << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
        cout << "Enqueued: " << x << endl;
    }

    // Remove and return front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int item = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return item;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
    }

    // Get size
    int size() {
        return count;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.enqueue(50);
    q.enqueue(60);

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}

/*
EXPLANATION:
1. Use an array to store elements
2. Maintain frontIndex and rearIndex pointers
3. Use circular array concept (modulo operation) to reuse space
4. Track count to check empty/full conditions
5. All operations are O(1) time complexity

KEY LEARNING POINTS:
- Circular array implementation prevents space wastage
- Two pointers (front and rear) manage the queue
- Count variable simplifies empty/full checks
*/
