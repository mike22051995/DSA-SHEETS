/*
================================================================================
PROBLEM: Find Median from Data Stream (LeetCode #295)
DIFFICULTY: Hard
PATTERN: Two Heaps
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
DESCRIPTION:
Design a data structure that supports adding numbers and retrieving the median.

INPUT FORMAT:
- stream of integers, inserted one by one

OUTPUT FORMAT:
- median as a double after queries

APPROACH (TWO HEAPS):
- Max-heap for the lower half, min-heap for the upper half.
- Keep sizes balanced so max-heap has either equal or one extra element.
- Median is top of max-heap, or average of both tops.

CODE EXPLANATION:
- addNum pushes into maxHeap, then moves the top to minHeap to keep order.
- If sizes are unbalanced, move one back to maxHeap.
- findMedian uses heap tops to compute the median in O(1).

COMPLEXITY:
- addNum: O(log n)
- findMedian: O(1)
- Space: O(n)

SAMPLE INPUT/OUTPUT:
1) stream = [1,2] -> median = 1.5
2) stream = [1,2,3] -> median = 2
3) stream = [5] -> median = 5
4) stream = [2,3,4,5] -> median = 3.5
5) stream = [1,1,1,1] -> median = 1
================================================================================
*/

#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left half (smaller elements)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right half (larger)
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Add to max heap first
        maxHeap.push(num);
        
        // Balance: move largest from max heap to min heap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Keep max heap size >= min heap size
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // 2.0
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sliding Window Median (LeetCode #480)
2. Find K Closest Elements (LeetCode #658)
3. IPO (LeetCode #502)
4. Kth Largest Element in Stream (LeetCode #703)
5. Find Median in Data Stream II (Follow-up)
6. Data Stream as Disjoint Intervals (LeetCode #352)
7. Moving Average from Data Stream (LeetCode #346)
8. Shortest Subarray with Sum at Least K (LeetCode #862)
9. Minimum Cost to Hire K Workers (LeetCode #857)
10. Maximum Performance of Team (LeetCode #1383)
*/
