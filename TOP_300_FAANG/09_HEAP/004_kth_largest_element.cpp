/*
================================================================================
PROBLEM: Kth Largest Element in Array (LeetCode #215)
DIFFICULTY: Medium
PATTERN: Heap / Quick Select
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, LinkedIn
================================================================================
DESCRIPTION:
Find the k-th largest element in an unsorted array.

INPUT FORMAT:
- nums: list of integers
- k: 1-based rank for largest element

OUTPUT FORMAT:
- integer value of the k-th largest element

APPROACH (MIN-HEAP):
- Maintain a min-heap of size k.
- Push each number; if size exceeds k, pop the smallest.
- Heap top is the k-th largest.

CODE EXPLANATION:
- findKthLargest keeps only k elements in a min-heap.
- Popping when size > k ensures the smallest of the kept elements is the answer.

COMPLEXITY:
- Time: O(n log k)
- Space: O(k)

SAMPLE INPUT/OUTPUT:
1) nums = [3,2,1,5,6,4], k = 2 -> 5
2) nums = [3,2,3,1,2,4,5,5,6], k = 4 -> 4
3) nums = [1], k = 1 -> 1
4) nums = [7,6,5,4,3,2,1], k = 7 -> 1
5) nums = [2,1], k = 1 -> 2
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Min Heap Approach - O(n log k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
    
    // Quick Select - O(n) average
    int findKthLargestQuickSelect(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        int pivotIndex = partition(nums, left, right);
        
        if (pivotIndex == k) {
            return nums[k];
        } else if (pivotIndex < k) {
            return quickSelect(nums, pivotIndex + 1, right, k);
        } else {
            return quickSelect(nums, left, pivotIndex - 1, k);
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[i], nums[right]);
        return i;
    }
    
    // STL nth_element
    int findKthLargestSTL(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
        return nums[nums.size() - k];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    cout << "Kth largest (k=2): " << sol.findKthLargest(nums, 2) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Kth Smallest Element in Sorted Matrix (LeetCode #378)
2. Top K Frequent Elements (LeetCode #347)
3. Find K Closest Elements (LeetCode #658)
4. K Closest Points to Origin (LeetCode #973)
5. Kth Smallest Element in BST (LeetCode #230)
6. Find Median from Data Stream (LeetCode #295)
7. Sliding Window Median (LeetCode #480)
8. Wiggle Sort II (LeetCode #324)
9. Third Maximum Number (LeetCode #414)
10. Split Array Largest Sum (LeetCode #410)
*/
