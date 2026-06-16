#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Problem Description:
Given an integer array nums and an integer k, return the k-th largest element in the array.

Sample Input/Output:
1) nums = [3,2,1,5,6,4], k = 2 -> Output: 5
2) nums = [3,2,3,1,2,4,5,5,6], k = 4 -> Output: 4
3) nums = [7], k = 1 -> Output: 7

Code Explanation:
Maintain a min-heap of size k. For each number, push it into the heap.
If heap size exceeds k, pop the smallest. At the end, heap top is k-th largest.
*/

int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int value : nums) {
        minHeap.push(value);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> a1 = {3, 2, 1, 5, 6, 4};
    vector<int> a2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    vector<int> a3 = {7};

    cout << "Output 1: " << findKthLargest(a1, 2) << "\n";
    cout << "Output 2: " << findKthLargest(a2, 4) << "\n";
    cout << "Output 3: " << findKthLargest(a3, 1) << "\n";
    return 0;
}
