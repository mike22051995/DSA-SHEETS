"""
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
"""



if __name__ == "__main__":
    print(f"=== Method 1: Using Stack ===")
    queue<int> q1
    for (i = 1; i <= 5; i++) 
    q1.push(i)
    print("Original Queue: ")
    printQueue(q1)
    reverseQueueUsingStack(q1)
    print("Reversed Queue: ")
    printQueue(q1)
    print(f"\n=== Method 2: Using Recursion ===")
    queue<int> q2
    for (i = 10; i <= 50; i += 10) 
    q2.push(i)
    print("Original Queue: ")
    printQueue(q2)
    reverseQueueRecursive(q2)
    print("Reversed Queue: ")
    printQueue(q2)
    print(f"\n=== Method 3: Reverse first K elements ===")
    queue<int> q3
    for (i = 1; i <= 7; i++) 
    q3.push(i)
    print("Original Queue: ")
    printQueue(q3)
    reverseFirstK(q3, 4)
    print("After reversing first 4 elements: ")
    printQueue(q3)
