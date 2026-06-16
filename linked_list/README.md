# 🔗 Linked List - FAANG Interview Preparation

Complete guide with **30 curated problems** covering all patterns and theoretical concepts for cracking FAANG interviews.

---

## 📚 Table of Contents
- [Problem List](#problem-list)
- [Linked List Fundamentals](#linked-list-fundamentals)
- [Key Patterns & Techniques](#key-patterns--techniques)
- [Interview Theoretical Questions](#interview-theoretical-questions)
- [Time & Space Complexity Guide](#time--space-complexity-guide)
- [Tips & Strategies](#tips--strategies)
- [Common Pitfalls](#common-pitfalls)

---

## 📋 Problem List

### Easy Problems (1-10)
| # | Problem | Pattern | Time | Space | File |
|---|---------|---------|------|-------|------|
| 1 | Reverse Linked List | Three-pointer reversal | O(n) | O(1) | [01_reverse_linked_list.cpp](01_reverse_linked_list.cpp) |
| 2 | Detect Cycle | Floyd's Algorithm | O(n) | O(1) | [02_detect_cycle.cpp](02_detect_cycle.cpp) |
| 3 | Middle of Linked List | Slow-Fast Pointer | O(n) | O(1) | [03_middle_of_linked_list.cpp](03_middle_of_linked_list.cpp) |
| 4 | Merge Two Sorted Lists | Two-pointer merge | O(m+n) | O(1) | [04_merge_two_sorted_lists.cpp](04_merge_two_sorted_lists.cpp) |
| 5 | Remove Duplicates (Sorted) | Single pointer | O(n) | O(1) | [05_remove_duplicates_from_sorted_list.cpp](05_remove_duplicates_from_sorted_list.cpp) |
| 6 | Palindrome Linked List | Reverse + Compare | O(n) | O(1) | [06_palindrome_linked_list.cpp](06_palindrome_linked_list.cpp) |
| 7 | Intersection of Lists | Two-pointer path switch | O(m+n) | O(1) | [07_intersection_of_two_linked_lists.cpp](07_intersection_of_two_linked_lists.cpp) |
| 8 | Delete Node | Value swapping | O(1) | O(1) | [08_delete_node_in_linked_list.cpp](08_delete_node_in_linked_list.cpp) |
| 9 | Remove Elements | Dummy head | O(n) | O(1) | [09_remove_linked_list_elements.cpp](09_remove_linked_list_elements.cpp) |
| 10 | Has Cycle | Floyd's Detection | O(n) | O(1) | [10_linked_list_cycle_return_boolean.cpp](10_linked_list_cycle_return_boolean.cpp) |

### Medium Problems (11-25)
| # | Problem | Pattern | Time | Space | File |
|---|---------|---------|------|-------|------|
| 11 | Add Two Numbers | Digit-by-digit with carry | O(max(m,n)) | O(max(m,n)) | [11_add_two_numbers.cpp](11_add_two_numbers.cpp) |
| 12 | Remove Nth from End | Two-pointer with gap | O(n) | O(1) | [12_remove_nth_node_from_end.cpp](12_remove_nth_node_from_end.cpp) |
| 13 | Reorder List | Find mid + Reverse + Merge | O(n) | O(1) | [13_reorder_list.cpp](13_reorder_list.cpp) |
| 14 | Sort List | Merge Sort | O(n log n) | O(log n) | [14_sort_list.cpp](14_sort_list.cpp) |
| 15 | Partition List | Two dummy nodes | O(n) | O(1) | [15_partition_list.cpp](15_partition_list.cpp) |
| 16 | Rotate List | Connect + Break | O(n) | O(1) | [16_rotate_list.cpp](16_rotate_list.cpp) |
| 17 | Swap Nodes in Pairs | Pointer manipulation | O(n) | O(1) | [17_swap_nodes_in_pairs.cpp](17_swap_nodes_in_pairs.cpp) |
| 18 | Odd Even List | Two-pointer grouping | O(n) | O(1) | [18_odd_even_linked_list.cpp](18_odd_even_linked_list.cpp) |
| 19 | Copy Random List | Interleaving nodes | O(n) | O(1) | [19_copy_list_with_random_pointer.cpp](19_copy_list_with_random_pointer.cpp) |
| 20 | Find Cycle Start | Floyd's + Math | O(n) | O(1) | [20_linked_list_cycle_II.cpp](20_linked_list_cycle_II.cpp) |
| 21 | Reverse List II | Partial reversal | O(n) | O(1) | [21_reverse_linked_list_II.cpp](21_reverse_linked_list_II.cpp) |
| 22 | Remove All Duplicates | Skip all occurrences | O(n) | O(1) | [22_remove_duplicates_from_sorted_list_II.cpp](22_remove_duplicates_from_sorted_list_II.cpp) |
| 23 | Insertion Sort List | Build sorted gradually | O(n²) | O(1) | [23_insertion_sort_list.cpp](23_insertion_sort_list.cpp) |
| 24 | Split in Parts | Fair distribution | O(n) | O(k) | [24_split_linked_list_in_parts.cpp](24_split_linked_list_in_parts.cpp) |
| 25 | Design Linked List | Custom implementation | O(n) | O(1) | [25_design_linked_list.cpp](25_design_linked_list.cpp) |

### Hard Problems (26-30)
| # | Problem | Pattern | Time | Space | File |
|---|---------|---------|------|-------|------|
| 26 | Merge K Sorted Lists | Divide & Conquer | O(N log k) | O(log k) | [26_merge_k_sorted_lists.cpp](26_merge_k_sorted_lists.cpp) |
| 27 | Reverse in K-Groups | Recursive reversal | O(n) | O(n/k) | [27_reverse_nodes_in_k_group.cpp](27_reverse_nodes_in_k_group.cpp) |
| 28 | LRU Cache | HashMap + DLL | O(1) | O(capacity) | [28_lru_cache.cpp](28_lru_cache.cpp) |
| 29 | Flatten Multilevel List | DFS with stack | O(n) | O(n) | [29_flatten_multilevel_doubly_linked_list.cpp](29_flatten_multilevel_doubly_linked_list.cpp) |
| 30 | Design Skip List | Probabilistic DS | O(log n) | O(n log n) | [30_design_skip_list.cpp](30_design_skip_list.cpp) |

---

## 🔰 Linked List Fundamentals

### What is a Linked List?
A **linked list** is a linear data structure where elements (nodes) are stored in non-contiguous memory locations. Each node contains:
- **Data**: The value stored
- **Pointer(s)**: Reference to next (and possibly previous) node

### Types of Linked Lists

#### 1. Singly Linked List
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
```
- Each node points to the next node
- Last node points to NULL
- Can only traverse forward

#### 2. Doubly Linked List
```cpp
struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(NULL), next(NULL) {}
};
```
- Each node has pointers to both next and previous nodes
- Can traverse in both directions
- More memory overhead

#### 3. Circular Linked List
- Last node points back to the head
- No NULL pointer at the end
- Can be singly or doubly linked

### Advantages of Linked Lists
✅ **Dynamic Size**: Grow/shrink at runtime  
✅ **Efficient Insertion/Deletion**: O(1) if position known  
✅ **No Memory Waste**: Allocate only what's needed  
✅ **Implementation of Other DS**: Stacks, queues, graphs

### Disadvantages
❌ **No Random Access**: Must traverse from head (O(n))  
❌ **Extra Memory**: Pointers require additional space  
❌ **Cache Unfriendly**: Non-contiguous memory  
❌ **Reverse Traversal**: Difficult in singly linked lists

---

## 🎯 Key Patterns & Techniques

### 1. Two-Pointer Technique

#### Slow-Fast Pointer (Floyd's Tortoise & Hare)
**Use Cases**: Cycle detection, finding middle, finding nth from end

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast != NULL && fast->next != NULL) {
    slow = slow->next;          // 1 step
    fast = fast->next->next;    // 2 steps
}
// slow is at middle when fast reaches end
```

**Applications**:
- Detect cycle: If slow == fast, cycle exists
- Find middle: slow will be at middle
- Find kth from end: Start fast k steps ahead

#### Two-Pointer with Gap
**Use Case**: Remove nth node from end

```cpp
ListNode* first = head;
ListNode* second = head;

// Create gap of n
for (int i = 0; i < n; i++) {
    first = first->next;
}

// Move both together
while (first != NULL) {
    first = first->next;
    second = second->next;
}
// second is now at (length - n)th position
```

### 2. Dummy Head Pattern
**Use Case**: When head might be modified/removed

```cpp
ListNode dummy(0);
dummy.next = head;
ListNode* current = &dummy;

// Perform operations...

return dummy.next;  // New head
```

**Why Use It**:
- Eliminates special case for modifying head
- Simplifies code logic
- No need to check if we're at head

### 3. Reversal Patterns

#### Basic Reversal (Three Pointers)
```cpp
ListNode* prev = NULL;
ListNode* current = head;
ListNode* next = NULL;

while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
return prev;  // new head
```

#### Partial Reversal
```cpp
// Reverse from position left to right
// Keep track of:
// 1. Node before reversal start
// 2. Start of reversal
// 3. End of reversal
// 4. Node after reversal end
```

### 4. Merge Patterns

#### Merge Two Sorted Lists
```cpp
ListNode dummy(0);
ListNode* tail = &dummy;

while (l1 && l2) {
    if (l1->val <= l2->val) {
        tail->next = l1;
        l1 = l1->next;
    } else {
        tail->next = l2;
        l2 = l2->next;
    }
    tail = tail->next;
}
tail->next = l1 ? l1 : l2;
```

#### Merge K Sorted Lists (Divide & Conquer)
```cpp
// Split into halves, merge recursively
// Time: O(N log k) where N = total nodes, k = number of lists
```

### 5. Cycle Detection & Location

#### Floyd's Cycle Detection
```cpp
// Phase 1: Detect cycle
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;  // Cycle found
}

// Phase 2: Find cycle start
slow = head;
while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}
return slow;  // Cycle start
```

**Mathematical Proof**:
- Distance from head to cycle start = a
- Distance from cycle start to meeting point = b
- When they meet: 2(a+b) = a+b+nc → a = nc-b

### 6. Sorting Algorithms

#### Merge Sort (Best for Linked Lists)
```cpp
// O(n log n) time, O(log n) space
// Steps:
// 1. Find middle (slow-fast pointer)
// 2. Split into two halves
// 3. Recursively sort each half
// 4. Merge sorted halves
```

#### Insertion Sort
```cpp
// O(n²) time, O(1) space
// Good for small or nearly sorted lists
// Build sorted list gradually by inserting each node
```

### 7. Advanced Patterns

#### Interleaving Technique (Deep Copy)
```cpp
// For copying list with random pointers:
// 1. Create copies interleaved: A->A'->B->B'->C->C'
// 2. Set random pointers: A'->random = A->random->next
// 3. Separate lists
```

#### DFS on Linked Structures
```cpp
// For multilevel/nested lists:
// - Use stack or recursion
// - Process children before siblings (DFS)
// - Flatten while traversing
```

---

## 💬 Interview Theoretical Questions

### Basic Concepts

#### Q1: What is a linked list? How is it different from an array?
**Answer**: A linked list is a linear data structure where elements are stored in nodes connected via pointers, not in contiguous memory locations.

**Key Differences**:
| Feature | Array | Linked List |
|---------|-------|-------------|
| Memory | Contiguous | Non-contiguous |
| Access | O(1) random access | O(n) sequential access |
| Insertion/Deletion | O(n) (shifting needed) | O(1) if position known |
| Size | Fixed (static arrays) | Dynamic |
| Memory Overhead | No extra space | Extra space for pointers |
| Cache Performance | Better (locality) | Worse (scattered) |

#### Q2: What are the types of linked lists?
**Answer**: 
1. **Singly Linked List**: Each node points to next node only
2. **Doubly Linked List**: Each node has prev and next pointers
3. **Circular Linked List**: Last node points back to head
4. **Circular Doubly Linked List**: Combination of circular and doubly

#### Q3: Why use a linked list over an array?
**Answer**:
- **Dynamic size**: No need to specify size upfront
- **Efficient insertion/deletion**: O(1) at known position (no shifting)
- **No memory waste**: Allocate only needed memory
- **Flexibility**: Easy to implement stacks, queues, graphs

**When to Use**:
- Frequent insertions/deletions
- Unknown size in advance
- Don't need random access
- Implementing other data structures

#### Q4: What is the difference between singly and doubly linked lists?
**Answer**:

**Singly Linked List**:
- ✅ Less memory (one pointer per node)
- ✅ Simpler implementation
- ❌ Can't traverse backward
- ❌ Can't delete node given only that node

**Doubly Linked List**:
- ✅ Can traverse both directions
- ✅ Easier deletion (have prev pointer)
- ✅ Can delete given just the node
- ❌ More memory (two pointers per node)
- ❌ More complex operations

### Operations & Complexity

#### Q5: What are the time complexities of basic operations?
**Answer**:

| Operation | Singly LL | Doubly LL | Array |
|-----------|-----------|-----------|-------|
| Access by index | O(n) | O(n) | O(1) |
| Search | O(n) | O(n) | O(n) |
| Insert at head | O(1) | O(1) | O(n) |
| Insert at tail | O(n) or O(1)* | O(1)* | O(1)** |
| Insert at position | O(n) | O(n) | O(n) |
| Delete at head | O(1) | O(1) | O(n) |
| Delete at tail | O(n) | O(1)* | O(1) |
| Delete at position | O(n) | O(n) | O(n) |

*With tail pointer  
**For dynamic arrays, amortized O(1)

#### Q6: How do you reverse a linked list?
**Answer**: Use three pointers (prev, current, next):

```cpp
prev = NULL, current = head
while (current):
    next = current->next
    current->next = prev
    prev = current
    current = next
return prev
```

**Approaches**:
1. **Iterative (3 pointers)**: O(n) time, O(1) space ✓ Best
2. **Recursive**: O(n) time, O(n) space
3. **Using Stack**: O(n) time, O(n) space

#### Q7: Can you reverse a linked list in-place?
**Answer**: Yes! The iterative three-pointer approach reverses in-place with O(1) extra space by only manipulating pointers, not creating new nodes.

### Cycle Detection

#### Q8: How do you detect a cycle in a linked list?
**Answer**: **Floyd's Cycle Detection Algorithm** (Tortoise and Hare):

```cpp
slow = fast = head
while (fast && fast->next):
    slow = slow->next
    fast = fast->next->next
    if (slow == fast):
        return true  // Cycle exists
return false
```

**Why it works**: In a cycle, fast pointer will eventually catch up to slow pointer. If no cycle, fast reaches NULL.

**Time**: O(n), **Space**: O(1)

#### Q9: How do you find the start of the cycle?
**Answer**: After detecting cycle using Floyd's algorithm:

```cpp
// Phase 1: Detect cycle (slow meets fast)
// Phase 2: Find start
slow = head
while (slow != fast):
    slow = slow->next
    fast = fast->next
return slow  // This is the cycle start
```

**Mathematical Proof**:
- Let distance from head to cycle start = `a`
- Distance from cycle start to meeting point = `b`
- At meeting: `2(a+b) = a+b+nc` → `a = nc-b`
- Moving slow from head and fast from meeting point, they meet at cycle start!

#### Q10: What are other ways to detect a cycle?
**Answer**:
1. **Hash Set**: Store visited nodes, check if revisited. O(n) space.
2. **Modify nodes**: Mark visited nodes (destructive).
3. **Floyd's Algorithm**: O(1) space ✓ Best
4. **Count nodes**: If count exceeds expected, cycle exists.

### Advanced Concepts

#### Q11: How do you find the middle of a linked list?
**Answer**: Use **slow-fast pointer**:

```cpp
slow = fast = head
while (fast && fast->next):
    slow = slow->next
    fast = fast->next->next
return slow  // Middle node
```

When fast reaches end, slow is at middle.
- Odd length: exact middle
- Even length: second middle node

#### Q12: How do you merge K sorted linked lists?
**Answer**: 

**Approach 1: Divide & Conquer** (Optimal)
- Split K lists into two halves
- Recursively merge each half
- Merge the two results
- **Time**: O(N log K), **Space**: O(log K)

**Approach 2: Min Heap**
- Add first node of each list to min heap
- Extract minimum, add its next to heap
- Repeat until heap empty
- **Time**: O(N log K), **Space**: O(K)

**Approach 3: Sequential Merge** (Inefficient)
- Merge list1 with list2, result with list3, etc.
- **Time**: O(NK) - Avoid this!

#### Q13: What is a dummy/sentinel node? When do you use it?
**Answer**: A dummy node is a placeholder node created at the beginning of a list to simplify operations.

**Why Use**:
- Eliminates special case for head modifications
- No need to check if operating on head
- Cleaner code, fewer edge cases

**When to Use**:
- Merging lists
- Removing nodes (including head)
- Inserting nodes
- Any operation that might modify head

```cpp
ListNode dummy(0);
dummy.next = head;
// ... operations on dummy.next ...
return dummy.next;  // Actual head
```

#### Q14: How do you remove the nth node from the end?
**Answer**: Use **two-pointer with gap**:

```cpp
// Create gap of n between two pointers
for (i = 0; i < n; i++)
    first = first->next

// Move both together
while (first->next):
    first = first->next
    second = second->next

// second is now before the node to remove
second->next = second->next->next
```

**Single pass solution!** Time: O(n), Space: O(1)

#### Q15: Explain LRU Cache implementation
**Answer**: Use **HashMap + Doubly Linked List**:

**Structure**:
- HashMap: O(1) access to nodes
- DLL: Maintain LRU order (head = MRU, tail = LRU)

**Operations**:
- **Get**: Move accessed node to head (mark as recent)
- **Put**: Add to head, evict tail if capacity exceeded

**Why DLL**:
- Need O(1) removal from middle
- Need O(1) addition to head
- Need O(1) removal from tail

**Time**: O(1) for both get and put  
**Space**: O(capacity)

### Problem-Solving Strategies

#### Q16: How do you detect if two linked lists intersect?
**Answer**:

**Approach 1: Length Alignment**
1. Calculate lengths of both lists
2. Advance longer list by difference
3. Traverse together until nodes match

**Approach 2: Path Switching** (Elegant!)
```cpp
ptrA = headA, ptrB = headB
while (ptrA != ptrB):
    ptrA = ptrA ? ptrA->next : headB
    ptrB = ptrB ? ptrB->next : headA
return ptrA  // Intersection or NULL
```

**Why it works**: Both travel same total distance (lenA + lenB)

#### Q17: How do you check if a linked list is a palindrome?
**Answer**:

**Optimal Approach** (O(n) time, O(1) space):
1. Find middle using slow-fast pointer
2. Reverse second half
3. Compare first half with reversed second half
4. (Optional) Restore original list

**Alternative**: Use stack to store first half (O(n) space)

#### Q18: What is the best sorting algorithm for linked lists?
**Answer**: **Merge Sort** is the best choice!

**Why Merge Sort**:
- ✅ O(n log n) time complexity
- ✅ Works well with sequential access
- ✅ Stable sort
- ✅ O(log n) space (recursion stack)

**Why NOT QuickSort**: Needs random access (inefficient for linked lists)

**Why NOT Others**: 
- Insertion Sort: O(n²) - only good for small/nearly sorted
- Bubble Sort: O(n²) - inefficient

#### Q19: How would you implement a stack using a linked list?
**Answer**:

```cpp
class Stack {
    ListNode* top;
public:
    void push(int val) {
        ListNode* node = new ListNode(val);
        node->next = top;
        top = node;
    }
    
    int pop() {
        if (!top) throw exception();
        int val = top->val;
        ListNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    
    int peek() { return top->val; }
    bool isEmpty() { return top == NULL; }
};
```

**All operations**: O(1) time!

#### Q20: How would you implement a queue using a linked list?
**Answer**:

```cpp
class Queue {
    ListNode *front, *rear;
public:
    void enqueue(int val) {
        ListNode* node = new ListNode(val);
        if (rear) rear->next = node;
        rear = node;
        if (!front) front = node;
    }
    
    int dequeue() {
        if (!front) throw exception();
        int val = front->val;
        ListNode* temp = front;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
        return val;
    }
};
```

**All operations**: O(1) time with tail pointer!

### Memory & Edge Cases

#### Q21: What are common edge cases to consider?
**Answer**:

**Always Test**:
1. **Empty list** (head = NULL)
2. **Single node** (head->next = NULL)
3. **Two nodes**
4. **List with cycle**
5. **Lists of different lengths** (for merge/intersection)
6. **All duplicates** (for duplicate removal)
7. **Very large lists** (performance)

**Boundary Conditions**:
- Removing head
- Removing tail
- Removing only node
- Operating on NULL
- Index out of bounds

#### Q22: How do you handle memory leaks in linked lists?
**Answer**:

**Always**:
1. Delete removed nodes
2. Clear entire list in destructor
3. Use smart pointers (C++): `unique_ptr`, `shared_ptr`

```cpp
// Bad - memory leak
node->next = node->next->next;

// Good - free memory
ListNode* temp = node->next;
node->next = node->next->next;
delete temp;

// Destructor
~LinkedList() {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
```

#### Q23: What is the space complexity of recursive solutions?
**Answer**: **O(n)** for recursion call stack in worst case.

**Example**: Reversing linked list recursively
- Each call adds a frame to stack
- Maximum depth = length of list = n
- Space: O(n)

**Comparison**:
- Iterative: O(1) space ✓ Better
- Recursive: O(n) space, but cleaner code

#### Q24: Can you do binary search on a linked list?
**Answer**: **Theoretically yes, but impractical!**

**Why Impractical**:
- Finding middle takes O(n) time (no random access)
- Each level of binary search: O(n) to find middle
- Total: O(n log n) - worse than linear search O(n)!

**Better**: Convert to array if frequent searches needed

**For Linked Lists**: Linear search is actually optimal!

### Design & Trade-offs

#### Q25: When would you use a linked list over an array?
**Answer**:

**Use Linked List When**:
- ✅ Frequent insertions/deletions in middle
- ✅ Size changes frequently
- ✅ Don't need random access
- ✅ Implementing stacks/queues
- ✅ Memory fragmentation is a concern

**Use Array When**:
- ✅ Need random access frequently
- ✅ Size is mostly fixed
- ✅ Need cache-friendly performance
- ✅ Need binary search
- ✅ Less memory overhead needed

#### Q26: How do you optimize linked list performance?
**Answer**:

**Optimization Strategies**:
1. **Keep tail pointer**: O(1) append instead of O(n)
2. **Cache list length**: Avoid counting every time
3. **Use doubly linked list**: When backward traversal needed
4. **Pool allocation**: Pre-allocate nodes to reduce malloc calls
5. **Prefetching**: Hint to CPU for next node (advanced)

**Example**:
```cpp
class LinkedList {
    ListNode *head, *tail;
    int length;
    // Faster operations with these!
};
```

#### Q27: What is Skip List? When would you use it?
**Answer**: Skip List is a **probabilistic data structure** with multiple levels of linked lists.

**Structure**:
- Level 0: All elements
- Level 1+: Subset of elements (express lanes)

**Operations**: O(log n) average time
- Search, insert, delete

**When to Use**:
- Need O(log n) operations
- Simpler than balanced trees
- Good for concurrent access
- Alternative to BST

**Advantages**:
- No rebalancing needed
- Simpler than AVL/Red-Black trees
- Good cache performance

#### Q28: Compare linked list implementations of stack vs queue
**Answer**:

**Stack** (using linked list):
- ✅ All operations O(1)
- ✅ Only need head pointer
- ✅ Very simple implementation
- Push/Pop at head

**Queue** (using linked list):
- ✅ All operations O(1) **with tail pointer**
- ⚠️ Enqueue O(n) **without tail pointer**
- Need both head and tail pointers
- Enqueue at tail, dequeue at head

**Conclusion**: Both are efficient with linked lists!

#### Q29: What are the pros and cons of circular linked lists?
**Answer**:

**Advantages**:
- ✅ Can traverse entire list from any node
- ✅ No NULL checks needed
- ✅ Good for round-robin scheduling
- ✅ Efficient for some algorithms (Josephus problem)

**Disadvantages**:
- ❌ Risk of infinite loops if not careful
- ❌ More complex termination conditions
- ❌ Harder to detect end of list
- ❌ Must track start node explicitly

**Use Cases**:
- Round-robin scheduling
- Circular buffers
- Implementation of circular queues

#### Q30: How would you implement a doubly linked list?
**Answer**:

```cpp
struct DLLNode {
    int val;
    DLLNode *prev, *next;
    DLLNode(int x) : val(x), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
    DLLNode *head, *tail;
    
public:
    void insertAtHead(int val) {
        DLLNode* node = new DLLNode(val);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    
    void insertAtTail(int val) {
        DLLNode* node = new DLLNode(val);
        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    
    void deleteNode(DLLNode* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        
        delete node;
    }
};
```

**Benefits**: O(1) deletion given node pointer!

---

## ⏱️ Time & Space Complexity Guide

### Common Operations

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Access by index | O(n) | O(1) | Must traverse from head |
| Search | O(n) | O(1) | Linear search only |
| Insert at head | O(1) | O(1) | Direct pointer update |
| Insert at tail | O(n) / O(1)* | O(1) | *O(1) with tail pointer |
| Insert at position | O(n) | O(1) | Must traverse to position |
| Delete at head | O(1) | O(1) | Direct pointer update |
| Delete at tail | O(n) / O(1)* | O(1) | *O(1) in doubly linked list |
| Delete given node | O(1) | O(1) | In doubly linked list |
| Reverse list | O(n) | O(1) | Iterative approach |
| Find middle | O(n) | O(1) | Using slow-fast pointer |
| Detect cycle | O(n) | O(1) | Floyd's algorithm |
| Merge two lists | O(m+n) | O(1) | In-place merge |
| Sort | O(n log n) | O(log n) | Using merge sort |

### Algorithm Complexity Comparison

| Problem | Naive | Optimal | Key Technique |
|---------|-------|---------|---------------|
| Detect Cycle | O(n²) or O(n) space | O(n) time, O(1) space | Floyd's Algorithm |
| Find Middle | Count then traverse: 2 passes | O(n) time, 1 pass | Slow-Fast Pointer |
| Nth from End | Count then traverse: 2 passes | O(n) time, 1 pass | Two-pointer with gap |
| Intersection | O(m×n) | O(m+n) time, O(1) space | Path switching |
| Palindrome Check | O(n) space with stack | O(n) time, O(1) space | Reverse half + compare |
| Merge K Lists | O(NK) sequential | O(N log K) | Divide & Conquer |
| LRU Cache | O(n) per operation | O(1) per operation | HashMap + DLL |

---

## 💡 Tips & Strategies

### General Approach

1. **Understand the Problem**
   - What type of linked list? (Singly/Doubly/Circular)
   - What's the expected input/output?
   - Are there cycles? Duplicates?
   - What are the constraints?

2. **Consider Edge Cases First**
   ```cpp
   if (head == NULL) return NULL;           // Empty list
   if (head->next == NULL) return head;     // Single node
   ```

3. **Choose Right Pattern**
   - Head modification? → Dummy node
   - Cycle related? → Floyd's algorithm
   - Middle/End related? → Slow-fast pointer
   - Grouping/Splitting? → Multiple pointers

4. **Draw It Out**
   - Visualize with diagrams
   - Trace pointer movements
   - Check boundary conditions

5. **Dry Run**
   - Test with small examples (1, 2, 3 nodes)
   - Test edge cases
   - Verify pointer movements

### Common Mistakes to Avoid

❌ **Losing references**
```cpp
// Bad - loses access to rest of list
head = head->next;

// Good - save reference first
ListNode* temp = head;
head = head->next;
```

❌ **Not checking NULL**
```cpp
// Bad - crash if head is NULL
return head->next;

// Good
return (head != NULL) ? head->next : NULL;
```

❌ **Infinite loops**
```cpp
// Bad - infinite loop in cycle
while (current != NULL)  // Never NULL in cycle!

// Good - use Floyd's algorithm for cycles
while (fast && fast->next) ...
```

❌ **Memory leaks**
```cpp
// Bad - memory leak
node->next = node->next->next;

// Good - delete removed node
ListNode* temp = node->next;
node->next = node->next->next;
delete temp;
```

### Problem-Solving Checklist

Before coding:
- [ ] Understand input/output format
- [ ] Identify edge cases
- [ ] Choose appropriate pattern
- [ ] Plan pointer movements
- [ ] Consider dummy node if needed

While coding:
- [ ] Initialize pointers correctly
- [ ] Check for NULL before dereferencing
- [ ] Update all necessary pointers
- [ ] Handle edge cases explicitly
- [ ] Free memory for deleted nodes

After coding:
- [ ] Test with empty list
- [ ] Test with single node
- [ ] Test with two nodes
- [ ] Test general case
- [ ] Verify no memory leaks

### Debugging Tips

1. **Print intermediate states**
   ```cpp
   void printList(ListNode* head) {
       while (head) {
           cout << head->val << " -> ";
           head = head->next;
       }
       cout << "NULL\n";
   }
   ```

2. **Check pointer consistency**
   - Is prev actually pointing to previous node?
   - Is next saved before modifying pointers?
   - Are all pointers initialized?

3. **Use debugger**
   - Set breakpoints at pointer updates
   - Watch pointer values
   - Step through loop iterations

4. **Trace with small examples**
   - Draw state after each operation
   - Verify expected vs actual state

---

## 🚨 Common Pitfalls

### 1. Null Pointer Dereference
```cpp
// Dangerous
if (head->next == NULL) ...  // Crashes if head is NULL!

// Safe
if (head == NULL || head->next == NULL) ...
```

### 2. Losing Head Reference
```cpp
// Wrong - loses original head
ListNode* current = head;
while (current->next != NULL) {
    current = current->next;
}
// head is still at beginning (good!)
```

### 3. Incorrect Loop Condition
```cpp
// Wrong for cycle detection
while (fast != NULL) ...  // Might skip checking fast->next

// Correct
while (fast != NULL && fast->next != NULL) ...
```

### 4. Off-by-One Errors
```cpp
// To reach node before target:
for (int i = 0; i < pos - 1; i++) ...  // Not i < pos!
```

### 5. Not Handling Single Node
```cpp
// Wrong - crashes for single node
ListNode* middle = head;
while (fast->next->next != NULL) ...

// Correct
while (fast->next != NULL && fast->next->next != NULL) ...
```

### 6. Forgetting to Update All Pointers
```cpp
// In doubly linked list, update BOTH directions:
node->next = newNode;
newNode->prev = node;  // Don't forget this!
```

### 7. Creating Cycles Accidentally
```cpp
// Wrong - creates cycle
tail->next = head;  // Only do this for circular list!

// Correct for regular list
tail->next = NULL;
```

---

## 🎓 Study Plan

### Day 1-2: Fundamentals (Easy Problems 1-10)
- Master two-pointer technique
- Practice basic reversal
- Understand dummy node pattern

### Day 3-4: Intermediate Patterns (Medium Problems 11-18)
- Learn merge patterns
- Practice partial operations
- Master sorting algorithms

### Day 5-6: Advanced Techniques (Medium Problems 19-25)
- Deep copy techniques
- Design problems
- Complex pointer manipulation

### Day 7: Hard Problems (26-30)
- Divide & conquer
- Advanced data structures
- System design aspects

### Interview Day Preparation
- Review key patterns
- Practice explaining solutions
- Memorize common templates
- Review theoretical questions

---

## 📌 Quick Reference Templates

### Reverse Linked List
```cpp
ListNode* reverse(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

### Detect Cycle
```cpp
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### Find Middle
```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### Merge Two Lists
```cpp
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0), *tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

---

## 🎯 Final Tips for Interview Day

1. **Start with Brute Force**: Explain naive approach first
2. **Optimize Gradually**: Show thought process
3. **Communicate**: Explain what you're doing
4. **Handle Edge Cases**: Show you're thorough
5. **Test Your Code**: Walk through with examples
6. **Analyze Complexity**: Always mention time/space
7. **Ask Questions**: Clarify requirements upfront
8. **Stay Calm**: Take your time to think

---

## 📚 Additional Resources

- **LeetCode**: Practice all 30 problems here
- **GeeksforGeeks**: More linked list problems
- **Visualizations**: [VisuAlgo](https://visualgo.net/en/list)
- **Book**: "Cracking the Coding Interview" - Chapter on Linked Lists

---

## ✅ Progress Tracker

Track your progress:
```
Easy Problems:     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
Medium Problems:   [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
Hard Problems:     [ ] [ ] [ ] [ ] [ ]
Theory Review:     [ ]
Practice Interview:[ ]
```

---

**Good luck with your FAANG interview! 🚀**

*Remember: It's not about memorizing solutions, it's about understanding patterns and being able to think through problems systematically.*

---

**Created**: December 27, 2025  
**Interview Date**: Friday  
**Total Problems**: 30 (10 Easy + 15 Medium + 5 Hard)  
**Patterns Covered**: 10+ essential patterns  
**Theory Questions**: 30+ comprehensive questions
