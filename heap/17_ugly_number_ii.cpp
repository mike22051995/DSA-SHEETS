#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
An ugly number has prime factors only 2,3,5. Return the n-th ugly number.

Sample Input/Output:
1) n=10 -> 12
2) n=1 -> 1
3) n=15 -> 24

Code Explanation:
Use min-heap + visited set.
Start from 1 and repeatedly generate next values by multiplying by 2,3,5.
*/

int nthUglyNumber(int n) {
    vector<long long> factors = {2, 3, 5};
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    unordered_set<long long> seen;

    minHeap.push(1);
    seen.insert(1);

    long long current = 1;
    for (int i = 0; i < n; i++) {
        current = minHeap.top();
        minHeap.pop();
        for (long long f : factors) {
            long long nextValue = current * f;
            if (!seen.count(nextValue)) {
                seen.insert(nextValue);
                minHeap.push(nextValue);
            }
        }
    }
    return (int)current;
}

int main() {
    cout << "Output 1: " << nthUglyNumber(10) << "\n";
    cout << "Output 2: " << nthUglyNumber(1) << "\n";
    cout << "Output 3: " << nthUglyNumber(15) << "\n";
    return 0;
}
