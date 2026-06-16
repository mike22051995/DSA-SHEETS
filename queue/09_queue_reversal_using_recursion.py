"""
PROBLEM: Queue Reversal Using Recursion (No Extra Space)
Difficulty: Easy
Pattern: Recursion with Queue

DESCRIPTION:
Reverse a queue using recursion without using any other data structure
like stack or array. Only queue operations are allowed.

INPUT:
Queue: 10 20 30 40 50

OUTPUT:
Reversed Queue: 50 40 30 20 10

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion call stack
"""



if __name__ == "__main__":
    print(f"=== Test 1: Complete Reversal ===")
    int arr1[] = [10, 20, 30, 40, 50]
    queue<int> q1 = createQueue(arr1, 5)
    print("Original Queue: ")
    printQueue(q1)
    reverseQueue(q1)
    print("Reversed Queue: ")
    printQueue(q1)
    print(f"\n=== Test 2: Reverse First K Elements ===")
    int arr2[] = [1, 2, 3, 4, 5, 6, 7, 8]
    queue<int> q2 = createQueue(arr2, 8)
    print("Original Queue: ")
    printQueue(q2)
    reverseFirstK(q2, 5)
    print("After reversing first 5 elements: ")
    printQueue(q2)
    print(f"\n=== Test 3: Interleave Queue ===")
    int arr3[] = [1, 2, 3, 4, 5, 6, 7, 8]
    queue<int> q3 = createQueue(arr3, 8)
    print("Original Queue: ")
    printQueue(q3)
    interleaveQueue(q3)
    print("Interleaved Queue: ")
    printQueue(q3)
