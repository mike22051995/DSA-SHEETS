#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given an integer n and list of primes, return the n-th super ugly number.
A super ugly number has prime factors only from given primes.

Sample Input/Output:
1) n=12, primes=[2,7,13,19] -> 32
2) n=1, primes=[2,3,5] -> 1
3) n=5, primes=[3,5,7,11] -> 9

Code Explanation:
Use min-heap and visited set. Start from 1.
Each popped number generates next values by multiplying each allowed prime.
*/

int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    unordered_set<long long> seen;

    minHeap.push(1);
    seen.insert(1);

    long long current = 1;
    for (int i = 0; i < n; i++) {
        current = minHeap.top();
        minHeap.pop();

        for (long long p : primes) {
            long long nextValue = current * p;
            if (!seen.count(nextValue)) {
                seen.insert(nextValue);
                minHeap.push(nextValue);
            }
        }
    }
    return (int)current;
}

int main() {
    vector<int> p1 = {2,7,13,19};
    vector<int> p2 = {2,3,5};
    vector<int> p3 = {3,5,7,11};

    cout << "Output 1: " << nthSuperUglyNumber(12, p1) << "\n";
    cout << "Output 2: " << nthSuperUglyNumber(1, p2) << "\n";
    cout << "Output 3: " << nthSuperUglyNumber(5, p3) << "\n";
    return 0;
}
