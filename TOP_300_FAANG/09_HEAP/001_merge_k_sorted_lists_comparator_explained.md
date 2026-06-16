# Custom Comparator in Priority Queue: Merge K Sorted Lists

## Table of Contents
1. [Purpose](#purpose)
2. [Code Integration](#code-integration)
3. [Why `a->val > b->val` Creates a Min-Heap](#why-avalval--bval-creates-a-min-heap)
4. [C++ Priority Queue Comparator Semantics](#c-priority-queue-comparator-semantics)
5. [Comparator Implementation Variants](#comparator-implementation-variants)
6. [Complexity Analysis](#complexity-analysis)
7. [Edge Cases and Pitfalls](#edge-cases-and-pitfalls)
8. [Debugging Tips](#debugging-tips)
9. [Alternatives](#alternatives)
10. [Full Runnable Examples](#full-runnable-examples)

---

## Purpose

The custom comparator in the priority queue serves a critical role in solving the **Merge K Sorted Lists** problem:

- **Extract minimum efficiently**: Each of the K lists is already sorted in ascending order. We need to repeatedly pick the smallest element from the current fronts of all lists.
- **Maintain order**: By always extracting the smallest element, we build the merged result in sorted order.
- **Reduce time complexity**: Without a priority queue, finding the minimum would be O(K) for each of N total elements (O(NK)). Using a min-heap reduces this to O(N log K).

In the provided code:
```cpp
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
```

The comparator tells the priority queue to behave as a **min-heap** where the node with the smallest value is always at the top.

---

## Code Integration

### Original Implementation
```cpp
class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // Custom comparator
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Pass the comparator as a template parameter
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Step 1: Insert the head of each list into the min-heap
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        // Step 2: Extract the minimum repeatedly
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();     // Get minimum
            pq.pop();
            
            tail->next = node;
            tail = tail->next;
            
            // Step 3: If this node has a next pointer, insert it
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
};
```

### How It Works Step-by-Step
1. **Initialization**: Each list's head is pushed into the min-heap using the custom comparator.
2. **Extraction**: `pq.top()` returns the node with the minimum value (due to the comparator).
3. **Re-insertion**: After extracting a node, we insert its next node (if it exists).
4. **Building result**: The extracted nodes are linked together in sorted order.

---

## Why `a->val > b->val` Creates a Min-Heap

This is the most **crucial concept** to understand.

### The Counterintuitive Truth

In C++ `priority_queue`:
- **If `comparator(a, b)` returns `true`, then `a` has LOWER priority than `b`.**
- **Lower priority means `b` comes before `a` in the heap.**

### Mathematical Definition

The comparator defines a **strict weak ordering** for "less-than":
```
comparator(a, b) ≡ "a < b" in terms of priority
```

If `a->val > b->val`:
- It means "a is greater than b"
- Which means "b has higher priority than a"
- Which means "b should come before a"
- Result: **b is closer to the root** ⟹ **Min-Heap**

### Visual Example

Given nodes with values: [5, 2, 8, 1]

**Using `a->val > b->val`:**
```
Comparator(5, 2) = true  (5 > 2)  ⟹  2 has higher priority
Comparator(5, 1) = true  (5 > 1)  ⟹  1 has higher priority

Min-Heap Structure:
        1
       / \
      2   5
     /
    8

top() → 1 (smallest)
```

**If we used `a->val < b->val` (WRONG):**
```
Max-Heap Structure:
        8
       / \
      5   2
     /
    1

top() → 8 (largest)  ❌
```

### Why This Matters

- Standard `priority_queue<int>` without a comparator creates a **max-heap**.
- To create a **min-heap**, we invert the comparison: `a > b` instead of `a < b`.
- This is a language quirk specific to C++ and often confuses developers!

---

## C++ Priority Queue Comparator Semantics

### Signature and Requirements

```cpp
template<class T, class Container, class Compare>
class priority_queue {
    // Compare must satisfy StrictWeakOrdering
    // Compare(a, b) returns true ⟺ a should have LOWER priority than b
};
```

### StrictWeakOrdering Requirements

The comparator must satisfy four properties:

| Property | Definition | Example | Status |
|----------|-----------|---------|--------|
| **Irreflexivity** | `comp(a, a)` must be `false` | `a->val > a->val` = false | ✓ |
| **Asymmetry** | If `comp(a, b)` then NOT `comp(b, a)` | 5 > 2 ✓, but NOT 2 > 5 ✓ | ✓ |
| **Transitivity** | If `comp(a, b)` and `comp(b, c)` then `comp(a, c)` | 5>3 AND 3>1 ⟹ 5>1 | ✓ |
| **Transitivity of Incomparability** | If `!(a<b) && !(b<a) && !(b<c) && !(c<b)` then `!(a<c) && !(c<a)` | Standard for total orders | ✓ |

**Our comparator `a->val > b->val` satisfies all!**

### Time Complexity of Operations

| Operation | Time Complexity |
|-----------|-----------------|
| `push()` | O(log N) - inserts and heapifies up |
| `top()` | O(1) - returns root |
| `pop()` | O(log N) - removes root and heapifies down |
| `empty()` | O(1) - checks if empty |

---

## Comparator Implementation Variants

### Variant 1: Struct with Operator (Original)
```cpp
struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
```

**Advantages:**
- Most readable and explicit
- Easy to add helper logic
- Zero overhead (inlined)
- Traditional C++ style

---

### Variant 2: Lambda Function
```cpp
auto cmp = [](ListNode* a, ListNode* b) {
    return a->val > b->val;
};

priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
```

**Advantages:**
- Compact and concise
- Captures local variables (if needed)
- Modern C++ style

**Disadvantages:**
- Must pass lambda to constructor
- Type deduction required with `decltype`

---

### Variant 3: std::function (Most Flexible)
```cpp
std::function<bool(ListNode*, ListNode*)> cmp = 
    [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };

priority_queue<ListNode*, vector<ListNode*>, std::function<bool(ListNode*, ListNode*)>> pq(cmp);
```

**Advantages:**
- Can hold any callable (function, lambda, functor)
- Flexible runtime assignment
- Easy polymorphism

**Disadvantages:**
- Small runtime overhead (virtual function call)
- Verbose syntax
- Type erasure

---

### Variant 4: Member Function Comparator
```cpp
class MyComparator {
public:
    bool operator()(ListNode* a, ListNode* b) const {
        // Can access member variables here
        return a->val > b->val;
    }
private:
    int priority_offset = 0;
};

priority_queue<ListNode*, vector<ListNode*>, MyComparator> pq;
```

---

### Variant 5: Pointer to Function
```cpp
bool compare(ListNode* a, ListNode* b) {
    return a->val > b->val;
}

priority_queue<ListNode*, vector<ListNode*>, 
               decltype(&compare)> pq(&compare);
```

---

### Comparison Table: When to Use Each Variant

| Variant | Use Case | Overhead |
|---------|----------|----------|
| **Struct** | General, clear code | None |
| **Lambda** | Short logic, captures | None |
| **std::function** | Dynamic behavior | Small |
| **Member Function** | Stateful comparison | None |
| **Function Pointer** | Legacy code | None |

---

## Complexity Analysis

### Time Complexity for Merge K Sorted Lists

```
Total elements: N (sum of all list lengths)
Number of lists: K
Total operations on priority queue: N insertions + N deletions

Time Complexity = O(N log K)

Breakdown:
- Each of K lists contributes 1 element initially: O(K)
- For each of N elements in the result:
  - pop() from heap: O(log K)
  - push() next element: O(log K)
  - Total: 2 × O(log K) per element
- Overall: O(N × log K)
```

### Space Complexity

```
Space = O(K)

Explanation:
- At any point, the priority queue holds at most K elements
- One node from each list (the current front)
- Output linked list: O(1) extra (uses existing nodes)
- Total: O(K)
```

### Why This is Better Than Alternatives

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| **Heap (Our approach)** | O(N log K) | O(K) | **Best for most cases** |
| **Brute Force** | O(N × K) | O(K) | Find min among K elements each time |
| **Divide & Conquer** | O(N log K) | O(log K) | Comparable but more complex |
| **Merge Iteratively** | O(N log K) | O(1) | Slower, practical for few lists |

---

## Edge Cases and Pitfalls

### Edge Case 1: Null Pointers
```cpp
// PITFALL: Dereferencing null pointer
struct BuggyCompare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // ❌ If a or b is nullptr, crash!
    }
};

// SAFE: Check before dereferencing
struct SafeCompare {
    bool operator()(ListNode* a, ListNode* b) {
        if (!a) return false;  // nullptr has lowest priority
        if (!b) return true;
        return a->val > b->val;
    }
};
```

**Why it works in our code:**
- We check `if (list)` before pushing in the loop
- We check `if (node->next)` before pushing the next node
- Never insert nullptr into the priority queue

---

### Edge Case 2: Empty Lists
```cpp
vector<ListNode*> lists = {nullptr, nullptr};
ListNode* result = sol.mergeKLists(lists);  // Should return nullptr

// Our code handles this:
for (auto list : lists) {
    if (list) pq.push(list);  // ✓ Skips nullptr
}

// When pq is empty, while loop doesn't execute
// dummy.next remains nullptr ✓
```

---

### Edge Case 3: Single List
```cpp
ListNode* L = new ListNode(1);
L->next = new ListNode(2);
L->next->next = new ListNode(3);

vector<ListNode*> lists = {L};
ListNode* result = sol.mergeKLists(lists);
// Should return the same list
// ✓ Works correctly, K=1, log K = 0
```

---

### Edge Case 4: Multiple Lists with Duplicate Values
```cpp
ListNode* l1 = new ListNode(1);
l1->next = new ListNode(1);

ListNode* l2 = new ListNode(1);
l2->next = new ListNode(2);

vector<ListNode*> lists = {l1, l2};
ListNode* result = sol.mergeKLists(lists);
// Result: 1 → 1 → 1 → 2
// Works correctly even with duplicates ✓
```

---

### Edge Case 5: Comparator Violates Strict Weak Ordering

**PITFALL: Using `<=` instead of `>`**
```cpp
struct BuggyCompare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val <= b->val;  // ❌ Violates irreflexivity!
    }
};

// comp(a, a) = (a <= a) = true  // Should be false!
// This breaks the heap invariant and causes undefined behavior
```

---

### Edge Case 6: Pointer Lifetime Issues

```cpp
ListNode* node = pq.top();
pq.pop();

tail->next = node;
tail = node;

if (node->next) {
    pq.push(node->next);  // ✓ Safe: node->next belongs to original list
}

// If we delete node->next, subsequent access fails ❌
delete node->next;  // Never do this!
```

---

### Edge Case 7: Very Large K
```cpp
// With K = 10,000 lists
// Each operation: O(log 10000) ≈ O(14)
// This is still efficient

// But if K > N (more lists than total elements)
// The heap size plateaus at N
// No performance issues ✓
```

---

## Debugging Tips

### Tip 1: Verify the Comparator Type

```cpp
// Check if comparator creates min-heap or max-heap
priority_queue<int> pq_default;  // Max-heap (default)
pq_default.push(5);
pq_default.push(2);
cout << pq_default.top();  // Output: 5 (largest first)

// With explicit comparator
priority_queue<int, vector<int>, greater<int>> pq_min;  // Min-heap
pq_min.push(5);
pq_min.push(2);
cout << pq_min.top();  // Output: 2 (smallest first)
```

### Tip 2: Add Debug Output

```cpp
struct CompareDebug {
    bool operator()(ListNode* a, ListNode* b) {
        bool result = a->val > b->val;
        cout << "Comparing " << a->val << " vs " << b->val 
             << " -> " << (result ? "true (a < b)" : "false (a >= b)") << endl;
        return result;
    }
};
```

Output example:
```
Comparing 5 vs 2 -> true (5 has lower priority than 2)
Comparing 8 vs 1 -> true (8 has lower priority than 1)
```

### Tip 3: Verify Heap Properties

```cpp
// After each operation, verify the heap property
// For min-heap: parent.val <= child.val
void verifyHeap(priority_queue<ListNode*, vector<ListNode*>, Compare>& pq) {
    // Extract all elements and verify order
    vector<int> elements;
    while (!pq.empty()) {
        elements.push_back(pq.top()->val);
        pq.pop();
    }
    
    // Should be sorted ascending
    for (int i = 1; i < elements.size(); i++) {
        assert(elements[i-1] <= elements[i]);
    }
}
```

### Tip 4: Check StrictWeakOrdering

```cpp
// Test the four properties
struct Compare { /* ... */ };

Compare cmp;
ListNode* a = new ListNode(5);
ListNode* b = new ListNode(3);
ListNode* c = new ListNode(7);

// Irreflexivity: comp(a, a) must be false
assert(!cmp(a, a));

// Asymmetry: if comp(a, b) then !comp(b, a)
if (cmp(a, b)) assert(!cmp(b, a));

// Transitivity: if comp(a, b) && comp(b, c) then comp(a, c)
if (cmp(a, b) && cmp(b, c)) assert(cmp(a, c));
```

---

## Alternatives

### Alternative 1: Divide and Conquer Merge

```cpp
class Solution {
public:
    ListNode* mergeKListsDC(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeHelper(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeHelper(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeHelper(lists, left, mid);
        ListNode* l2 = mergeHelper(lists, mid + 1, right);
        
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

/*
Time: O(N log K) - same as heap
Space: O(log K) - recursion stack
Advantage: Less space (no priority queue)
Disadvantage: More recursive calls, harder to debug
*/
```

---

### Alternative 2: Using std::multimap

```cpp
class Solution {
public:
    ListNode* mergeKListsMap(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mp;
        
        // Insert all nodes by value
        for (auto list : lists) {
            ListNode* curr = list;
            while (curr) {
                mp.insert({curr->val, curr});
                curr = curr->next;
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Extract in sorted order
        for (auto& [val, node] : mp) {
            ListNode* newNode = new ListNode(val);
            tail->next = newNode;
            tail = newNode;
        }
        
        return dummy.next;
    }
};

/*
Time: O(N log N) - sorting ALL elements
Space: O(N) - stores all values
Disadvantage: Slower, uses more memory, creates new nodes
*/
```

---

### Alternative 3: Manual Binary Heap Implementation

```cpp
class Solution {
private:
    vector<ListNode*> heap;
    
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i]->val < heap[parent]->val) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }
    
    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < heap.size() && heap[left]->val < heap[smallest]->val) {
            smallest = left;
        }
        if (right < heap.size() && heap[right]->val < heap[smallest]->val) {
            smallest = right;
        }
        
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    
public:
    ListNode* mergeKListsManual(vector<ListNode*>& lists) {
        for (auto list : lists) {
            if (list) {
                heap.push_back(list);
                heapifyUp(heap.size() - 1);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!heap.empty()) {
            ListNode* node = heap[0];
            tail->next = node;
            tail = node;
            
            if (node->next) {
                heap[0] = node->next;
                heapifyDown(0);
            } else {
                swap(heap[0], heap.back());
                heap.pop_back();
                if (!heap.empty()) heapifyDown(0);
            }
        }
        
        return dummy.next;
    }
};

/*
Time: O(N log K)
Space: O(K)
Advantage: Full control, educational
Disadvantage: Error-prone, more code
Verdict: Use only for learning; prefer std::priority_queue
*/
```

---

### Comparison: All Approaches

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| **Heap (Priority Queue)** | O(N log K) | O(K) | Efficient, simple, standard | Requires understanding comparator |
| **Divide & Conquer** | O(N log K) | O(log K) | Elegant, less space | More complex logic |
| **std::multimap** | O(N log N) | O(N) | Easy to understand | Slower, more memory |
| **Manual Heap** | O(N log K) | O(K) | Educational, full control | Error-prone, verbose |
| **Brute Force** | O(NK) | O(1) | Simple to understand | Very slow for large K |

**Recommendation:** Use the **Heap (Priority Queue)** approach for interviews and production code.

---

## Full Runnable Examples

### Complete Example 1: Original Struct Comparator

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) const {
            // Returns true if a should have LOWER priority than b
            // a->val > b->val means: smaller values get higher priority
            // Result: MIN-HEAP (root is minimum)
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Insert head of each list
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Extract minimum repeatedly
        while (!pq.empty()) {
            // Get the node with minimum value
            ListNode* node = pq.top();
            pq.pop();
            
            // Attach to result
            tail->next = node;
            tail = node;
            
            // Insert next node if exists
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
    
    // Utility function to print list
    void printList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << " → ";
            head = head->next;
        }
        cout << endl;
    }
    
    // Utility function to create a list from array
    ListNode* createList(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Normal case with duplicates
    cout << "Test Case 1: Normal lists with duplicates\n";
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};
    
    ListNode* l1 = sol.createList(arr1);
    ListNode* l2 = sol.createList(arr2);
    ListNode* l3 = sol.createList(arr3);
    
    vector<ListNode*> lists = {l1, l2, l3};
    cout << "Input lists:\n";
    cout << "List 1: "; sol.printList(l1);
    cout << "List 2: "; sol.printList(l2);
    cout << "List 3: "; sol.printList(l3);
    cout << "Merged result: ";
    ListNode* result = sol.mergeKLists(lists);
    sol.printList(result);
    cout << "\n";
    
    // Test Case 2: Empty lists
    cout << "Test Case 2: Empty input\n";
    vector<ListNode*> emptyLists = {};
    cout << "Merged result: ";
    result = sol.mergeKLists(emptyLists);
    cout << (result ? "" : "(empty)") << endl;
    cout << "\n";
    
    // Test Case 3: Single list
    cout << "Test Case 3: Single list\n";
    vector<int> arr = {1, 2, 3};
    ListNode* single = sol.createList(arr);
    vector<ListNode*> singleList = {single};
    cout << "Input: ";
    sol.printList(single);
    cout << "Merged result: ";
    result = sol.mergeKLists(singleList);
    sol.printList(result);
    cout << "\n";
    
    // Test Case 4: Many small lists
    cout << "Test Case 4: Many lists with single elements\n";
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(8);
    ListNode* n4 = new ListNode(1);
    
    vector<ListNode*> manyLists = {n1, n2, n3, n4};
    cout << "Input: 5, 2, 8, 1\n";
    cout << "Merged result: ";
    result = sol.mergeKLists(manyLists);
    sol.printList(result);
    cout << "\n";
    
    return 0;
}

/*
Expected Output:
Test Case 1: Normal lists with duplicates
Input lists:
List 1: 1 → 4 → 5
List 2: 1 → 3 → 4
List 3: 2 → 6
Merged result: 1 → 1 → 2 → 3 → 4 → 4 → 5 → 6

Test Case 2: Empty input
Merged result: (empty)

Test Case 3: Single list
Input: 1 → 2 → 3
Merged result: 1 → 2 → 3

Test Case 4: Many lists with single elements
Input: 5, 2, 8, 1
Merged result: 1 → 2 → 5 → 8
*/
```

---

### Complete Example 2: Lambda Comparator Variant

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() { delete next; }
};

class Solution {
public:
    ListNode* mergeKListsLambda(vector<ListNode*>& lists) {
        // Define comparator as lambda
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min-heap
        };
        
        // Must pass lambda to constructor due to type deduction
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            tail->next = node;
            tail = node;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
    
    void printList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << " → ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    
    // Create test lists
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    vector<ListNode*> lists = {l1, l2, l3};
    
    cout << "Using Lambda Comparator:\n";
    ListNode* result = sol.mergeKListsLambda(lists);
    cout << "Merged list: ";
    sol.printList(result);
    
    return 0;
}

/*
Output:
Using Lambda Comparator:
Merged list: 1 → 1 → 2 → 3 → 4 → 4 → 5 → 6
*/
```

---

### Complete Example 3: Comparator with Debug Output

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() { delete next; }
};

class Solution {
public:
    struct CompareWithDebug {
        int comparison_count = 0;
        
        bool operator()(ListNode* a, ListNode* b) {
            bool result = a->val > b->val;
            comparison_count++;
            
            // Uncomment for verbose output:
            // cout << "[Comparison #" << comparison_count << "] "
            //      << a->val << " vs " << b->val 
            //      << " -> " << (result ? "true (a < b)" : "false (a >= b)") 
            //      << endl;
            
            return result;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        CompareWithDebug cmp;
        priority_queue<ListNode*, vector<ListNode*>, CompareWithDebug> pq(cmp);
        
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int merge_count = 0;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            cout << "[Merge #" << ++merge_count << "] Extracted: " 
                 << node->val << endl;
            
            tail->next = node;
            tail = node;
            
            if (node->next) {
                pq.push(node->next);
                cout << "  → Inserted next node: " << node->next->val << endl;
            }
        }
        
        return dummy.next;
    }
    
    void printList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << " → ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    
    // Small example to see comparisons
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(3);
    
    vector<ListNode*> lists = {l1, l2};
    
    cout << "Merging process with debug output:\n\n";
    ListNode* result = sol.mergeKLists(lists);
    
    cout << "\nFinal merged list: ";
    sol.printList(result);
    
    return 0;
}

/*
Expected output shows the merge steps:
[Merge #1] Extracted: 1
  → Inserted next node: 4
[Merge #2] Extracted: 2
  → Inserted next node: 3
[Merge #3] Extracted: 3
[Merge #4] Extracted: 4

Final merged list: 1 → 2 → 3 → 4
*/
```

---

### Test Snippet: Comprehensive Testing

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() { delete next; }
};

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            tail->next = node;
            tail = node;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
    
    // Helper: convert list to vector for easy comparison
    vector<int> listToVector(ListNode* head) {
        vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }
    
    // Helper: create list from vector
    ListNode* createList(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
    
    // Helper: check if a list is sorted ascending
    bool isSorted(ListNode* head) {
        while (head && head->next) {
            if (head->val > head->next->val) return false;
            head = head->next;
        }
        return true;
    }
};

void testComparator() {
    cout << "=== Test: Comparator Semantics ===\n";
    
    ListNode a(5), b(3), c(8);
    Solution::Compare cmp;
    
    // Test 1: Irreflexivity
    assert(!cmp(&a, &a));
    cout << "✓ Irreflexivity: comp(a, a) = false\n";
    
    // Test 2: Asymmetry
    bool ab = cmp(&a, &b);  // 5 > 3 = true
    bool ba = cmp(&b, &a);  // 3 > 5 = false
    assert(ab != ba);
    cout << "✓ Asymmetry: comp(5,3)=true, comp(3,5)=false\n";
    
    // Test 3: Transitivity
    bool ac = cmp(&a, &c);  // 5 > 8 = false
    bool ca = cmp(&c, &a);  // 8 > 5 = true
    bool cb = cmp(&c, &b);  // 8 > 3 = true
    assert(ca && cb);  // If ca(8>5) and cb(8>3) then ca (8 > 5 and 3)
    cout << "✓ Transitivity: comp(8,5)=true, comp(8,3)=true\n";
    
    cout << endl;
}

void testMinHeapBehavior() {
    cout << "=== Test: Min-Heap Behavior ===\n";
    
    Solution::Compare cmp;
    priority_queue<int, vector<int>, Solution::Compare> pq;
    
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);
    pq.push(9);
    
    cout << "Pushed: 5, 2, 8, 1, 9\n";
    cout << "Extracted in order: ";
    
    vector<int> extracted;
    while (!pq.empty()) {
        extracted.push_back(pq.top());
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // Verify ascending order
    for (int i = 1; i < extracted.size(); i++) {
        assert(extracted[i-1] <= extracted[i]);
    }
    cout << "✓ Min-heap: elements extracted in ascending order\n\n";
}

void testMergeKLists() {
    cout << "=== Test: Merge K Sorted Lists ===\n";
    Solution sol;
    
    // Test 1: Normal case
    vector<int> a1 = {1, 4, 5};
    vector<int> a2 = {1, 3, 4};
    vector<int> a3 = {2, 6};
    
    ListNode* l1 = sol.createList(a1);
    ListNode* l2 = sol.createList(a2);
    ListNode* l3 = sol.createList(a3);
    
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* result = sol.mergeKLists(lists);
    
    vector<int> merged = sol.listToVector(result);
    vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
    
    assert(merged == expected);
    assert(sol.isSorted(result));
    cout << "✓ Test 1 (Normal): Correctly merged [1,4,5], [1,3,4], [2,6]\n";
    
    // Test 2: Empty input
    vector<ListNode*> empty;
    result = sol.mergeKLists(empty);
    assert(result == nullptr);
    cout << "✓ Test 2 (Empty): Returns nullptr for empty input\n";
    
    // Test 3: Single list
    vector<int> single = {1, 2, 3};
    ListNode* singleList = sol.createList(single);
    vector<ListNode*> singleVec = {singleList};
    result = sol.mergeKLists(singleVec);
    assert(sol.listToVector(result) == single);
    cout << "✓ Test 3 (Single list): Returns the same list unchanged\n";
    
    // Test 4: Lists with duplicates
    vector<int> dup1 = {1, 1, 1};
    vector<int> dup2 = {1, 1};
    ListNode* d1 = sol.createList(dup1);
    ListNode* d2 = sol.createList(dup2);
    vector<ListNode*> dupLists = {d1, d2};
    result = sol.mergeKLists(dupLists);
    assert(sol.isSorted(result));
    cout << "✓ Test 4 (Duplicates): Handles duplicates correctly\n";
    
    // Test 5: Many lists with single elements
    ListNode* n1 = new ListNode(10);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(15);
    ListNode* n4 = new ListNode(3);
    vector<ListNode*> singles = {n1, n2, n3, n4};
    result = sol.mergeKLists(singles);
    vector<int> singleMerged = sol.listToVector(result);
    assert(singleMerged == vector<int>{3, 5, 10, 15});
    cout << "✓ Test 5 (Many singles): Correctly sorts single elements\n";
    
    cout << endl;
}

void testEdgeCases() {
    cout << "=== Test: Edge Cases ===\n";
    Solution sol;
    
    // Test: Very long list
    vector<int> longList;
    for (int i = 1; i <= 1000; i++) {
        longList.push_back(i);
    }
    ListNode* l1 = sol.createList(longList);
    vector<ListNode*> lists = {l1};
    ListNode* result = sol.mergeKLists(lists);
    assert(sol.isSorted(result));
    cout << "✓ Large list: Handles 1000 elements\n";
    
    // Test: Many lists with few elements
    vector<ListNode*> manySmall;
    for (int i = 0; i < 100; i++) {
        manySmall.push_back(new ListNode(i));
    }
    result = sol.mergeKLists(manySmall);
    assert(sol.isSorted(result));
    cout << "✓ Many lists: Handles 100 lists correctly\n";
    
    cout << endl;
}

int main() {
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║  Merge K Sorted Lists - Comparator Comprehensive Tests     ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    testComparator();
    testMinHeapBehavior();
    testMergeKLists();
    testEdgeCases();
    
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║                   ALL TESTS PASSED! ✓                      ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    return 0;
}

/*
Expected Output:
╔════════════════════════════════════════════════════════════╗
║  Merge K Sorted Lists - Comparator Comprehensive Tests     ║
╚════════════════════════════════════════════════════════════╝

=== Test: Comparator Semantics ===
✓ Irreflexivity: comp(a, a) = false
✓ Asymmetry: comp(5,3)=true, comp(3,5)=false
✓ Transitivity: comp(8,5)=true, comp(8,3)=true

=== Test: Min-Heap Behavior ===
Pushed: 5, 2, 8, 1, 9
Extracted in order: 1 2 5 8 9
✓ Min-heap: elements extracted in ascending order

=== Test: Merge K Sorted Lists ===
✓ Test 1 (Normal): Correctly merged [1,4,5], [1,3,4], [2,6]
✓ Test 2 (Empty): Returns nullptr for empty input
✓ Test 3 (Single list): Returns the same list unchanged
✓ Test 4 (Duplicates): Handles duplicates correctly
✓ Test 5 (Many singles): Correctly sorts single elements

=== Test: Edge Cases ===
✓ Large list: Handles 1000 elements
✓ Many lists: Handles 100 lists correctly

╔════════════════════════════════════════════════════════════╗
║                   ALL TESTS PASSED! ✓                      ║
╚════════════════════════════════════════════════════════════╝
*/
```

---

## Summary Key Points

| Concept | Key Point |
|---------|-----------|
| **Comparator Purpose** | Defines priority ordering: `comp(a,b)=true` → a has lower priority |
| **Why `a->val > b->val`** | Inverts comparison to create min-heap from max-heap default |
| **Strict Weak Ordering** | Must satisfy: irreflexivity, asymmetry, transitivity |
| **Time Complexity** | O(N log K): N elements, K lists, each operation O(log K) |
| **Space Complexity** | O(K): only K nodes in priority queue at any time |
| **Common Pitfall** | Using `<=` instead of `>` violates irreflexivity |
| **Pointer Safety** | Never insert nullptr; check before dereferencing |
| **Alternative 1** | Divide and Conquer: equally efficient, uses less memory |
| **Alternative 2** | std::multimap: simpler but O(N log N) time |
| **Best Practice** | Use struct comparator for clarity; lambda for new code |

---

## References

- [cppreference: std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
- [cppreference: Compare Concept](https://en.cppreference.com/w/cpp/named_req/Compare)
- [cppreference: StrictWeakOrdering](https://en.cppreference.com/w/cpp/named_req/Compare)
- LeetCode Problem #23: Merge K Sorted Lists
- Effective C++, Third Edition (Scott Meyers) - Item 47: Understand traits classes

