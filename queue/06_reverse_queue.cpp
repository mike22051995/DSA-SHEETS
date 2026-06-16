/*
PROBLEM: Reverse a Queue
Difficulty: Easy
Pattern: Queue Reversal using Stack/Recursion

DESCRIPTION:
Reverse the order of elements in a queue using:
1. Stack (iterative)
2. Recursion

INPUT:
Queue: 1 2 3 4 5

OUTPUT:
Reversed Queue: 5 4 3 2 1

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Method 1: Using Stack
void reverseQueueUsingStack(queue<int>& q) {
    stack<int> s;
    
    // Push all elements to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Pop from stack and enqueue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// Method 2: Using Recursion
void reverseQueueRecursive(queue<int>& q) {
    // Base case
    if (q.empty()) {
        return;
    }
    
    // Remove front element
    int front = q.front();
    q.pop();
    
    // Reverse remaining queue
    reverseQueueRecursive(q);
    
    // Add front element at the end
    q.push(front);
}

// Method 3: Reverse first K elements
void reverseFirstK(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        return;
    }
    
    stack<int> s;
    
    // Push first k elements to stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Pop from stack and enqueue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    // Move remaining (n-k) elements to back
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Utility function to print queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    // Test Method 1: Using Stack
    cout << "=== Method 1: Using Stack ===" << endl;
    queue<int> q1;
    for (int i = 1; i <= 5; i++) {
        q1.push(i);
    }
    cout << "Original Queue: ";
    printQueue(q1);
    
    reverseQueueUsingStack(q1);
    cout << "Reversed Queue: ";
    printQueue(q1);

    // Test Method 2: Using Recursion
    cout << "\n=== Method 2: Using Recursion ===" << endl;
    queue<int> q2;
    for (int i = 10; i <= 50; i += 10) {
        q2.push(i);
    }
    cout << "Original Queue: ";
    printQueue(q2);
    
    reverseQueueRecursive(q2);
    cout << "Reversed Queue: ";
    printQueue(q2);

    // Test Method 3: Reverse first K elements
    cout << "\n=== Method 3: Reverse first K elements ===" << endl;
    queue<int> q3;
    for (int i = 1; i <= 7; i++) {
        q3.push(i);
    }
    cout << "Original Queue: ";
    printQueue(q3);
    
    reverseFirstK(q3, 4);
    cout << "After reversing first 4 elements: ";
    printQueue(q3);

    return 0;
}

/*
EXPLANATION:

Method 1 (Stack):
1. Dequeue all elements and push to stack
2. Pop from stack and enqueue back to queue
3. Stack's LIFO reverses the order

Method 2 (Recursion):
1. Remove front element
2. Recursively reverse remaining queue
3. Add removed element at the end
4. Call stack acts as implicit stack

Method 3 (Reverse first K):
1. Push first k elements to stack
2. Pop from stack and enqueue (reverses first k)
3. Move remaining elements to back

KEY LEARNING POINTS:
- Stack is natural choice for reversal
- Recursion uses call stack implicitly
- Can reverse partial queue (first k elements)
- Important for interleaving queue problems
*/
