/*
PROBLEM: Merge K Sorted Lists
Difficulty: Hard
Pattern: Divide and Conquer / Min Heap

DESCRIPTION:
You are given an array of k linked-lists lists, each linked-list is sorted 
in ascending order. Merge all the linked-lists into one sorted linked-list 
and return it.

EXAMPLE:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Input: lists = []
Output: []

TIME COMPLEXITY: O(N log k) where N is total nodes, k is number of lists
SPACE COMPLEXITY: O(log k) for recursion stack (divide & conquer)
                  O(k) for min heap approach
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Approach 1: Divide and Conquer (Most Efficient)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        
        if (left > right) {
            return NULL;
        }
        
        int mid = left + (right - left) / 2;
        ListNode* leftList = mergeKListsHelper(lists, left, mid);
        ListNode* rightList = mergeKListsHelper(lists, mid + 1, right);
        
        return mergeTwoLists(leftList, rightList);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1 != NULL) ? l1 : l2;
        return dummy.next;
    }
    
public:
    // Approach 2: Min Heap / Priority Queue
    ListNode* mergeKListsHeap(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min heap
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        // Add first node of each list to heap
        for (ListNode* list : lists) {
            if (list != NULL) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next != NULL) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};

// Utility functions
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << ",";
        head = head->next;
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test Case 1
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};
    
    vector<ListNode*> lists1;
    lists1.push_back(createList(arr1, 3));
    lists1.push_back(createList(arr2, 3));
    lists1.push_back(createList(arr3, 2));
    
    cout << "Input lists:" << endl;
    for (ListNode* list : lists1) {
        printList(list);
        cout << " ";
    }
    cout << "\nMerged list: ";
    ListNode* result1 = solution.mergeKLists(lists1);
    printList(result1);
    cout << endl << endl;
    
    // Test Case 2: Empty lists
    vector<ListNode*> lists2;
    cout << "Input: []" << endl;
    cout << "Merged list: ";
    ListNode* result2 = solution.mergeKLists(lists2);
    printList(result2);
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:

Approach 1: Divide and Conquer (Optimal)
Similar to merge sort:
1. Divide k lists into two halves
2. Recursively merge each half
3. Merge the two merged lists

VISUALIZATION (3 lists):
        [L1, L2, L3]
       /            \
   [L1, L2]        [L3]
    /    \
  [L1]  [L2]

Merge L1 & L2 → M1
Merge M1 & L3 → Final

TIME COMPLEXITY:
- Height of recursion tree: log k
- At each level, merge N total nodes: O(N)
- Total: O(N log k)

Approach 2: Min Heap
1. Add first node of each list to min heap
2. Extract minimum, add to result
3. Add next node from that list to heap
4. Repeat until heap empty

VISUALIZATION:
Initial heap: [1(L1), 1(L2), 2(L3)]
Extract 1(L1), add 4: [1(L2), 2(L3), 4(L1)]
Extract 1(L2), add 3: [2(L3), 3(L2), 4(L1)]
...continue

TIME COMPLEXITY:
- N nodes total
- Each insertion/deletion: O(log k)
- Total: O(N log k)

SPACE COMPLEXITY:
- Divide & Conquer: O(log k) recursion stack
- Min Heap: O(k) for heap

COMPARISON:
Both are O(N log k), but:
- Divide & Conquer: Better space, cleaner code
- Min Heap: More intuitive, easier to implement

WHY NOT MERGE SEQUENTIALLY?
Sequential: merge(merge(merge(L1, L2), L3), L4)
- First merge: compare 2 lists
- Second merge: compare result with 1 list (unbalanced)
- Time: O(Nk) - much slower!

KEY PATTERN: Divide and conquer on multiple sorted sequences
Classic hard problem combining multiple concepts!
*/
