/*
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
*/

#include <iostream>
#include <queue>
using namespace std;

// Reverse queue using recursion
void reverseQueue(queue<int>& q) {
    // Base case: if queue is empty
    if (q.empty()) {
        return;
    }
    
    // Remove front element
    int front = q.front();
    q.pop();
    
    // Reverse the remaining queue
    reverseQueue(q);
    
    // Add the removed element at the end
    q.push(front);
}

// Reverse first k elements using recursion
void reverseKElements(queue<int>& q, int k) {
    // Base cases
    if (k <= 0 || q.empty()) {
        return;
    }
    
    // Remove front element
    int front = q.front();
    q.pop();
    
    // Reverse remaining k-1 elements
    reverseKElements(q, k - 1);
    
    // Add removed element at end
    q.push(front);
}

void reverseFirstK(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        return;
    }
    
    // Reverse first k elements
    reverseKElements(q, k);
    
    // Move remaining elements to back
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Interleave first half with second half
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }
    
    queue<int> firstHalf;
    
    // Move first half to another queue
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    
    // Interleave elements
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
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

// Create queue from array
queue<int> createQueue(int arr[], int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }
    return q;
}

int main() {
    // Test 1: Complete reversal
    cout << "=== Test 1: Complete Reversal ===" << endl;
    int arr1[] = {10, 20, 30, 40, 50};
    queue<int> q1 = createQueue(arr1, 5);
    cout << "Original Queue: ";
    printQueue(q1);
    reverseQueue(q1);
    cout << "Reversed Queue: ";
    printQueue(q1);
    
    // Test 2: Reverse first K elements
    cout << "\n=== Test 2: Reverse First K Elements ===" << endl;
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    queue<int> q2 = createQueue(arr2, 8);
    cout << "Original Queue: ";
    printQueue(q2);
    reverseFirstK(q2, 5);
    cout << "After reversing first 5 elements: ";
    printQueue(q2);
    
    // Test 3: Interleave queue
    cout << "\n=== Test 3: Interleave Queue ===" << endl;
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    queue<int> q3 = createQueue(arr3, 8);
    cout << "Original Queue: ";
    printQueue(q3);
    interleaveQueue(q3);
    cout << "Interleaved Queue: ";
    printQueue(q3);
    
    return 0;
}

/*
EXPLANATION:

1. Complete Reversal:
   - Remove front element
   - Recursively reverse remaining queue
   - Add removed element at end
   - Recursion acts as implicit stack

2. Reverse First K:
   - Reverse first k elements recursively
   - Move remaining (n-k) elements to back

3. Interleave:
   - Split queue into two halves
   - Merge by alternating elements from each half

RECURSION TRACE (for [1,2,3]):
reverseQueue([1,2,3])
  front=1, reverseQueue([2,3])
    front=2, reverseQueue([3])
      front=3, reverseQueue([])
        return
      push(3) -> []
    push(2) -> [3]
  push(1) -> [3,2]
Result: [3,2,1]

KEY LEARNING POINTS:
- Recursion provides implicit stack
- No extra data structure needed
- Call stack space is O(n)
- Understanding recursion trace is crucial
- Common follow-up: Can you do it iteratively?
*/
