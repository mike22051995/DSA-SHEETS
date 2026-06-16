/*
PROBLEM: Implement Queue using Stacks
Difficulty: Easy
Pattern: Stack to Queue Conversion

DESCRIPTION:
Implement a queue using two stacks with operations:
- enqueue(x): Add element to queue
- dequeue(): Remove and return front element
- front(): Get front element
- empty(): Check if queue is empty

INPUT:
Operations: enqueue(1), enqueue(2), dequeue(), enqueue(3), front()

OUTPUT:
Enqueued: 1
Enqueued: 2
Dequeued: 1
Enqueued: 3
Front: 2

TIME COMPLEXITY: 
- enqueue(): O(1)
- dequeue(), front(): Amortized O(1)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2; // s1 for enqueue, s2 for dequeue

public:
    // Add element to queue (O(1))
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued: " << x << endl;
    }

    // Remove and return front element (Amortized O(1))
    int dequeue() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        // If s2 is empty, transfer all from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int item = s2.top();
        s2.pop();
        return item;
    }

    // Get front element (Amortized O(1))
    int front() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        // If s2 is empty, transfer all from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }

    // Check if queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }

    // Get size
    int size() {
        return s1.size() + s2.size();
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front: " << q.front() << endl;

    q.enqueue(4);
    q.enqueue(5);

    cout << "Size: " << q.size() << endl;

    while (!q.empty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}

/*
EXPLANATION:
1. Use two stacks: s1 for enqueue, s2 for dequeue
2. Enqueue: Simply push to s1
3. Dequeue: 
   - If s2 is not empty, pop from s2
   - If s2 is empty, transfer all from s1 to s2, then pop
4. This reverses the order, making oldest element on top of s2

AMORTIZED ANALYSIS:
- Each element is pushed once to s1 and once to s2
- Each element is popped once from s1 and once from s2
- Total operations per element: 4
- Amortized time per operation: O(1)

KEY LEARNING POINTS:
- Classic FAANG interview question
- Demonstrates amortized analysis concept
- Lazy transfer strategy is efficient
*/
