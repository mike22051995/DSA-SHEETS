"""
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
"""



if __name__ == "__main__":
    Queue q
    q.enqueue(5)
    q.enqueue(10)
    q.enqueue(15)
    print(f"Dequeued: {q.dequeue()}")
    print(f"Front element: {q.front()}")
    q.enqueue(20)
    q.enqueue(25)
    print(f"Queue size: {len(q)}")
    while (!q.isEmpty()) 
    print(f"Dequeued: {q.dequeue()}")
