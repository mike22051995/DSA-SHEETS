#include <iostream>
#include <queue>
using namespace std;

/*
Problem Description:
Design a data structure that supports adding numbers and finding median at any time.

Sample Input/Output:
1) add 1,2 -> median = 1.5
2) add 3 -> median = 2
3) add 4,5 -> median = 3

Code Explanation:
Use two heaps:
- maxHeap for lower half
- minHeap for upper half
Balance sizes so maxHeap has equal or one extra element.
*/

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1); mf.addNum(2);
    cout << "Output 1: " << mf.findMedian() << "\n";

    mf.addNum(3);
    cout << "Output 2: " << mf.findMedian() << "\n";

    mf.addNum(4); mf.addNum(5);
    cout << "Output 3: " << mf.findMedian() << "\n";
    return 0;
}
