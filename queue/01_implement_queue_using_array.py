"""
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
"""



if __name__ == "__main__":
    Queue q(5)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)
    print(f"Dequeued: {q.dequeue()}")
    print(f"Front element: {q.front()}")
    print(f"Queue size: {len(q)}")
    q.enqueue(50)
    q.enqueue(60)
    while (!q.isEmpty()) 
    print(f"Dequeued: {q.dequeue()}")
