/*
================================================================================
PROBLEM: Merge K Sorted Lists (LeetCode #23)
DIFFICULTY: Hard
PATTERN: Heap (Priority Queue) / Divide and Conquer
COMPANIES: Amazon, Google, Microsoft, Facebook, Apple, Bloomberg
================================================================================
DESCRIPTION:
Merge k sorted linked lists and return a single sorted list.

INPUT FORMAT:
- lists: vector of list heads, each list is sorted ascending

OUTPUT FORMAT:
- head of the merged sorted list

APPROACH (HEAP):
- Push the head of each non-empty list into a min-heap by value.
- Repeatedly pop the smallest node, append to output, and push its next node.
- Continue until the heap is empty.

CODE EXPLANATION:
- Compare sets up a min-heap by node value.
- mergeKLists seeds the heap with list heads, then always connects the smallest
    node and pushes its next pointer back into the heap.
- The dummy node simplifies head handling for the merged list.

COMPLEXITY:
- Time: O(N log k), where N is total nodes
- Space: O(k) for the heap (excluding output list)

SAMPLE INPUT/OUTPUT:
1) lists = [[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]
2) lists = [[],[1],[0,2]] -> [0,1,2]
3) lists = [[1],[1],[1]] -> [1,1,1]
4) lists = [[-2,-1,3],[0,2,2],[5]] -> [-2,-1,0,2,2,3,5]
5) lists = [] -> []
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Heap Approach
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
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
            tail = tail->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy.next;
    }
    
    // Divide and Conquer
    ListNode* mergeKListsDC(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeHelper(lists, 0, lists.size() - 1);
    }
    
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
    ListNode* result = sol.mergeKLists(lists);
    
    cout << "Merged list: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Merge Two Sorted Lists (LeetCode #21)
2. Ugly Number II (LeetCode #264)
3. Kth Smallest Element in Sorted Matrix (LeetCode #378)
4. Find K Pairs with Smallest Sums (LeetCode #373)
5. Smallest Range Covering K Lists (LeetCode #632)
6. Sort List (LeetCode #148)
7. Merge Sorted Array (LeetCode #88)
8. Merge Intervals (LeetCode #56)
9. Median of Two Sorted Arrays (LeetCode #4)
10. Sliding Window Median (LeetCode #480)
*/
