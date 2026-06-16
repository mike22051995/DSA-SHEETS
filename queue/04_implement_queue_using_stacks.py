"""
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
"""



if __name__ == "__main__":
    Queue q
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(f"Dequeued: {q.dequeue()}")
    print(f"Front: {q.front()}")
    q.enqueue(4)
    q.enqueue(5)
    print(f"Size: {len(q)}")
    while (!q.empty()) 
    print(f"Dequeued: {q.dequeue()}")
