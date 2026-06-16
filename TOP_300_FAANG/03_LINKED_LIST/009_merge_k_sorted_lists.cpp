/*
================================================================================
PROBLEM: Merge K Sorted Lists (LeetCode #23)
DIFFICULTY: Hard
PATTERN: Divide and Conquer / Heap
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
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
    // Min Heap approach
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            curr->next = node;
            curr = curr->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy->next;
    }
    
    // Divide and Conquer
    ListNode* mergeKListsDivideConquer(vector<ListNode*>& lists) {
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
        
        if (l1->val < l2->val) {
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
2. Merge Sorted Array (LeetCode #88)
3. Sort List (LeetCode #148)
4. Ugly Number II (LeetCode #264)
5. Smallest Range Covering K Lists (LeetCode #632)
6. Find K Pairs with Smallest Sums (LeetCode #373)
7. Kth Smallest Element in Sorted Matrix (LeetCode #378)
8. Merge Intervals (LeetCode #56)
9. Employee Free Time (LeetCode #759)
10. Minimum Cost to Hire K Workers (LeetCode #857)
*/
