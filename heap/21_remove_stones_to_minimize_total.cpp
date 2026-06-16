#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
You have piles of stones. In one move, choose a pile and remove floor(pile/2) stones.
Do exactly k moves and return minimum total stones left.

Sample Input/Output:
1) piles=[5,4,9], k=2 -> 12
2) piles=[4,3,6,7], k=3 -> 12
3) piles=[10], k=3 -> 2

Code Explanation:
Use max-heap. Each operation reduce largest pile to ceil(pile/2).
This greedy approach minimizes total quickly.
*/

int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> maxHeap(piles.begin(), piles.end());
    while (k--) {
        int top = maxHeap.top();
        maxHeap.pop();
        top -= top / 2;
        maxHeap.push(top);
    }

    int total = 0;
    while (!maxHeap.empty()) {
        total += maxHeap.top();
        maxHeap.pop();
    }
    return total;
}

int main() {
    vector<int> p1 = {5,4,9};
    vector<int> p2 = {4,3,6,7};
    vector<int> p3 = {10};

    cout << "Output 1: " << minStoneSum(p1, 2) << "\n";
    cout << "Output 2: " << minStoneSum(p2, 3) << "\n";
    cout << "Output 3: " << minStoneSum(p3, 3) << "\n";
    return 0;
}
