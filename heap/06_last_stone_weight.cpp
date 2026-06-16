#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Description:
Given stones where stones[i] is weight, repeatedly smash two heaviest stones.
Return final stone weight (or 0 if none).

Sample Input/Output:
1) [2,7,4,1,8,1] -> 1
2) [1] -> 1
3) [9,3,2,10] -> 0

Code Explanation:
Use max-heap. Pop two largest a and b.
If a != b, push |a-b| back. Continue until <= 1 stone remains.
*/

int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> maxHeap(stones.begin(), stones.end());
    while (maxHeap.size() > 1) {
        int a = maxHeap.top(); maxHeap.pop();
        int b = maxHeap.top(); maxHeap.pop();
        if (a != b) maxHeap.push(abs(a - b));
    }
    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main() {
    vector<int> s1 = {2,7,4,1,8,1};
    vector<int> s2 = {1};
    vector<int> s3 = {9,3,2,10};

    cout << "Output 1: " << lastStoneWeight(s1) << "\n";
    cout << "Output 2: " << lastStoneWeight(s2) << "\n";
    cout << "Output 3: " << lastStoneWeight(s3) << "\n";
    return 0;
}
