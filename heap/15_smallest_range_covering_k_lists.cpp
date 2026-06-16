#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given k sorted lists, find the smallest range [l,r] that includes at least one number from each list.

Sample Input/Output:
1) [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]] -> [20,24]
2) [[1,2,3],[1,2,3],[1,2,3]] -> [1,1]
3) [[1],[2],[3]] -> [1,3]

Code Explanation:
Use min-heap to track smallest current element and track current maximum.
Advance pointer in list of extracted min element.
*/

struct Node {
    int value, listIdx, idx;
    bool operator>(const Node &other) const { return value > other.value; }
};

vector<int> smallestRange(vector<vector<int>> &nums) {
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    int currentMax = INT_MIN;

    for (int i = 0; i < (int)nums.size(); i++) {
        minHeap.push({nums[i][0], i, 0});
        currentMax = max(currentMax, nums[i][0]);
    }

    int bestL = 0, bestR = INT_MAX;
    while ((int)minHeap.size() == (int)nums.size()) {
        Node cur = minHeap.top(); minHeap.pop();
        if (currentMax - cur.value < bestR - bestL) {
            bestL = cur.value;
            bestR = currentMax;
        }

        int nextIdx = cur.idx + 1;
        if (nextIdx < (int)nums[cur.listIdx].size()) {
            int nextVal = nums[cur.listIdx][nextIdx];
            minHeap.push({nextVal, cur.listIdx, nextIdx});
            currentMax = max(currentMax, nextVal);
        }
    }
    return {bestL, bestR};
}

int main() {
    vector<vector<int>> n1 = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<vector<int>> n2 = {{1,2,3},{1,2,3},{1,2,3}};
    vector<vector<int>> n3 = {{1},{2},{3}};

    auto r1 = smallestRange(n1);
    auto r2 = smallestRange(n2);
    auto r3 = smallestRange(n3);

    cout << "Output 1: [" << r1[0] << "," << r1[1] << "]\n";
    cout << "Output 2: [" << r2[0] << "," << r2[1] << "]\n";
    cout << "Output 3: [" << r3[0] << "," << r3[1] << "]\n";
    return 0;
}
