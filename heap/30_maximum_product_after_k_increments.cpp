#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given nums and k operations, in each operation increment one element by 1.
Return maximum possible product of array after k operations.

Sample Input/Output:
1) nums=[0,4], k=5 -> 20
2) nums=[6,3,3,2], k=2 -> 216
3) nums=[1,1,1], k=3 -> 8

Code Explanation:
To maximize product, always increment smallest element.
Use min-heap for k operations, then multiply all values.
*/

long long maximumProduct(vector<int> &nums, int k) {
    const long long MOD = 1'000'000'007;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int x : nums) minHeap.push(x);

    while (k--) {
        long long x = minHeap.top();
        minHeap.pop();
        minHeap.push(x + 1);
    }

    long long product = 1;
    while (!minHeap.empty()) {
        product = (product * minHeap.top()) % MOD;
        minHeap.pop();
    }
    return product;
}

int main() {
    vector<int> a1 = {0,4};
    vector<int> a2 = {6,3,3,2};
    vector<int> a3 = {1,1,1};

    cout << "Output 1: " << maximumProduct(a1, 5) << "\n";
    cout << "Output 2: " << maximumProduct(a2, 2) << "\n";
    cout << "Output 3: " << maximumProduct(a3, 3) << "\n";
    return 0;
}
