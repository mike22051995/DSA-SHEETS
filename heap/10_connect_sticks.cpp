#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Description:
You are given stick lengths. Connecting two sticks costs their sum.
Return minimum total cost to connect all sticks into one.

Sample Input/Output:
1) [2,4,3] -> 14
2) [1,8,3,5] -> 30
3) [5] -> 0

Code Explanation:
Always combine two smallest sticks first using min-heap.
This greedy approach gives minimum total cost.
*/

int connectSticks(vector<int> &sticks) {
    if (sticks.size() <= 1) return 0;
    priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());

    int total = 0;
    while (minHeap.size() > 1) {
        int a = minHeap.top(); minHeap.pop();
        int b = minHeap.top(); minHeap.pop();
        int c = a + b;
        total += c;
        minHeap.push(c);
    }
    return total;
}

int main() {
    vector<int> s1 = {2,4,3};
    vector<int> s2 = {1,8,3,5};
    vector<int> s3 = {5};

    cout << "Output 1: " << connectSticks(s1) << "\n";
    cout << "Output 2: " << connectSticks(s2) << "\n";
    cout << "Output 3: " << connectSticks(s3) << "\n";
    return 0;
}
