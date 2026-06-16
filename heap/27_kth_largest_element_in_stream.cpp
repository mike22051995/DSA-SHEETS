#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Design a class that returns k-th largest element after each insertion in stream.

Sample Input/Output:
1) init k=3, nums=[4,5,8,2], add(3) -> 4
2) add(5) -> 5
3) add(10) -> 5

Code Explanation:
Store k largest elements in a min-heap.
Heap top is always current k-th largest element.
*/

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int kValue, vector<int> &nums) : k(kValue) {
        for (int x : nums) add(x);
    }

    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4,5,8,2};
    KthLargest kth(3, nums);

    cout << "Output 1: " << kth.add(3) << "\n";
    cout << "Output 2: " << kth.add(5) << "\n";
    cout << "Output 3: " << kth.add(10) << "\n";
    return 0;
}
