#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
Problem Description:
Given hiring costs array, hire exactly k workers.
In each session choose minimum from first 'candidates' or last 'candidates' workers.
Return total minimum cost.

Sample Input/Output:
1) costs=[17,12,10,2,7,2,11,20,8], k=3, candidates=4 -> 11
2) costs=[1,2,4,1], k=3, candidates=3 -> 4
3) costs=[5,3,8,2], k=2, candidates=1 -> 7

Code Explanation:
Use two min-heaps for left and right candidate windows.
Each hire selects lower top, then expands corresponding side.
*/

long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size();
    int left = 0, right = n - 1;
    priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;

    for (int i = 0; i < candidates && left <= right; i++) leftHeap.push(costs[left++]);
    for (int i = 0; i < candidates && left <= right; i++) rightHeap.push(costs[right--]);

    long long answer = 0;
    while (k--) {
        int leftCost = leftHeap.empty() ? INT_MAX : leftHeap.top();
        int rightCost = rightHeap.empty() ? INT_MAX : rightHeap.top();

        if (leftCost <= rightCost) {
            answer += leftCost;
            leftHeap.pop();
            if (left <= right) leftHeap.push(costs[left++]);
        } else {
            answer += rightCost;
            rightHeap.pop();
            if (left <= right) rightHeap.push(costs[right--]);
        }
    }
    return answer;
}

int main() {
    vector<int> c1 = {17,12,10,2,7,2,11,20,8};
    vector<int> c2 = {1,2,4,1};
    vector<int> c3 = {5,3,8,2};

    cout << "Output 1: " << totalCost(c1, 3, 4) << "\n";
    cout << "Output 2: " << totalCost(c2, 3, 3) << "\n";
    cout << "Output 3: " << totalCost(c3, 2, 1) << "\n";
    return 0;
}
