/*
================================================================================
PROBLEM: Kth Largest Element in Stream (LeetCode #703)
DIFFICULTY: Easy
PATTERN: Min Heap
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
DESCRIPTION:
Maintain the k-th largest element as numbers are added to a stream.

INPUT FORMAT:
- k: rank of the largest element to track
- nums: initial list of integers
- add(val): insert val and return current k-th largest

OUTPUT FORMAT:
- integer after each add operation

APPROACH (MIN-HEAP):
- Keep a min-heap of size k containing the k largest seen elements.
- The heap top is always the k-th largest.

CODE EXPLANATION:
- Constructor calls add for each initial number to build the heap.
- add pushes val, then pops if size exceeds k so top stays the k-th largest.

COMPLEXITY:
- add: O(log k)
- Space: O(k)

SAMPLE INPUT/OUTPUT:
1) k = 3, nums = [4,5,8,2], adds = [3,5,10,9,4] -> [4,5,5,8,8]
2) k = 1, nums = [], adds = [-1,-2,-3] -> [-1,-1,-1]
3) k = 2, nums = [0], adds = [-1,1] -> [-1,0]
4) k = 3, nums = [5,-1,2], adds = [4] -> [2]
5) k = 4, nums = [10,9,8,7], adds = [6,5] -> [7,7]
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    
    cout << kthLargest.add(3) << endl;   // returns 4
    cout << kthLargest.add(5) << endl;   // returns 5
    cout << kthLargest.add(10) << endl;  // returns 5
    cout << kthLargest.add(9) << endl;   // returns 8
    cout << kthLargest.add(4) << endl;   // returns 8
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Kth Largest Element in Array (LeetCode #215)
2. Find Median from Data Stream (LeetCode #295)
3. Sliding Window Median (LeetCode #480)
4. IPO (LeetCode #502)
5. Maximum Subsequence Score (LeetCode #2542)
6. Find K-th Smallest Pair Distance (LeetCode #719)
7. Kth Smallest Element in Sorted Matrix (LeetCode #378)
8. Top K Frequent Elements (LeetCode #347)
9. K Closest Points to Origin (LeetCode #973)
10. Least Number of Unique Integers (LeetCode #1481)
*/
