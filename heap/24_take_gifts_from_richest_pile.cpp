#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given gift piles, perform k operations: choose largest pile and replace with floor(sqrt(pile)).
Return total gifts left.

Sample Input/Output:
1) gifts=[25,64,9,4,100], k=4 -> 29
2) gifts=[1,1,1,1], k=4 -> 4
3) gifts=[16], k=2 -> 2

Code Explanation:
Use max-heap. In each operation pop largest pile, reduce it to floor(sqrt(x)), push back.
*/

long long pickGifts(vector<int> &gifts, int k) {
    priority_queue<int> maxHeap(gifts.begin(), gifts.end());
    while (k--) {
        int top = maxHeap.top();
        maxHeap.pop();
        maxHeap.push((int)floor(sqrt(top)));
    }

    long long total = 0;
    while (!maxHeap.empty()) {
        total += maxHeap.top();
        maxHeap.pop();
    }
    return total;
}

int main() {
    vector<int> g1 = {25,64,9,4,100};
    vector<int> g2 = {1,1,1,1};
    vector<int> g3 = {16};

    cout << "Output 1: " << pickGifts(g1, 4) << "\n";
    cout << "Output 2: " << pickGifts(g2, 4) << "\n";
    cout << "Output 3: " << pickGifts(g3, 2) << "\n";
    return 0;
}
