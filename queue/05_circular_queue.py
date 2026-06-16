"""
PROBLEM: Design Circular Queue
Difficulty: Easy
Pattern: Circular Buffer

DESCRIPTION:
Design a circular queue with fixed size that supports:
- enqueue(value): Insert element (return True if successful)
- dequeue(): Delete element (return True if successful)
- front(): Get front element
- rear(): Get rear element
- isEmpty(): Check if queue is empty
- isFull(): Check if queue is full

INPUT:
Capacity: 3
Operations: enqueue(1), enqueue(2), enqueue(3), enqueue(4), 
            dequeue(), enqueue(4), rear()

OUTPUT:
Enqueue 1: True
Enqueue 2: True
Enqueue 3: True
Enqueue 4: False (full)
Dequeue: True
Enqueue 4: True
Rear: 4

TIME COMPLEXITY: O(1) for all operations
SPACE COMPLEXITY: O(k) where k is capacity
"""



if __name__ == "__main__":
    CircularQueue cq(5)
    print(f"Enqueue 10: {(cq.enQueue(10)}")
    print(f"Enqueue 20: {(cq.enQueue(20)}")
    print(f"Enqueue 30: {(cq.enQueue(30)}")
    print(f"Enqueue 40: {(cq.enQueue(40)}")
    print(f"Enqueue 50: {(cq.enQueue(50)}")
    cq.display()
    print(f"Enqueue 60: {(cq.enQueue(60)}")
    print(f"Front: {cq.Front()}")
    print(f"Rear: {cq.Rear()}")
    print(f"Dequeue: {(cq.deQueue()}")
    print(f"Dequeue: {(cq.deQueue()}")
    cq.display()
    print(f"Enqueue 60: {(cq.enQueue(60)}")
    print(f"Enqueue 70: {(cq.enQueue(70)}")
    cq.display()
