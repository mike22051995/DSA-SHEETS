#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Description:
Given k sorted arrays, merge them into one sorted array.

Sample Input/Output:
1) [[1,4,7],[2,5,8],[3,6,9]] -> [1,2,3,4,5,6,7,8,9]
2) [[1,3,5],[2,4,6]] -> [1,2,3,4,5,6]
3) [[10],[1,2,3],[4,5]] -> [1,2,3,4,5,10]

Code Explanation:
Use a min-heap containing current element from each array.
Extract min and push next element from the same array.
*/

struct Node {
    int value, row, col;
};

struct CompareNode {
    bool operator()(const Node &a, const Node &b) const {
        return a.value > b.value;  // Min-heap: larger value = lower priority
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays) {
    priority_queue<Node, vector<Node>, CompareNode> minHeap;
    for (int i = 0; i < (int)arrays.size(); i++) {
        if (!arrays[i].empty()) minHeap.push({arrays[i][0], i, 0});
    }

    vector<int> merged;
    while (!minHeap.empty()) {
        Node current = minHeap.top();
        minHeap.pop();
        merged.push_back(current.value);

        int nextCol = current.col + 1;
        if (nextCol < (int)arrays[current.row].size()) {
            minHeap.push({arrays[current.row][nextCol], current.row, nextCol});
        }
    }
    return merged;
}

void printVec(const vector<int> &v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << (i + 1 == (int)v.size() ? "" : ",");
    }
    cout << "]\n";
}

int main() {
    vector<vector<int>> a1 = {{1,4,7},{2,5,8},{3,6,9}};
    vector<vector<int>> a2 = {{1,3,5},{2,4,6}};
    vector<vector<int>> a3 = {{10},{1,2,3},{4,5}};

    cout << "Output 1: "; printVec(mergeKSortedArrays(a1));
    cout << "Output 2: "; printVec(mergeKSortedArrays(a2));
    cout << "Output 3: "; printVec(mergeKSortedArrays(a3));
    return 0;
}
