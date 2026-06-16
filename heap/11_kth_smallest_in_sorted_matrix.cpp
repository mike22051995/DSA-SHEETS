#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Description:
Given an n x n matrix with sorted rows and columns, return the k-th smallest element.

Sample Input/Output:
1) [[1,5,9],[10,11,13],[12,13,15]], k=8 -> 13
2) [[-5]], k=1 -> -5
3) [[1,2],[1,3]], k=2 -> 1

Code Explanation:
Use a min-heap of first element from each row.
Pop smallest k times, each time push next column element from same row.
*/

struct Node {
    int value, row, col;
    bool operator>(const Node &other) const { return value > other.value; }
};

int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    for (int r = 0; r < n; r++) minHeap.push({matrix[r][0], r, 0});

    while (--k) {
        Node cur = minHeap.top();
        minHeap.pop();
        if (cur.col + 1 < n) minHeap.push({matrix[cur.row][cur.col + 1], cur.row, cur.col + 1});
    }
    return minHeap.top().value;
}

int main() {
    vector<vector<int>> m1 = {{1,5,9},{10,11,13},{12,13,15}};
    vector<vector<int>> m2 = {{-5}};
    vector<vector<int>> m3 = {{1,2},{1,3}};

    cout << "Output 1: " << kthSmallest(m1, 8) << "\n";
    cout << "Output 2: " << kthSmallest(m2, 1) << "\n";
    cout << "Output 3: " << kthSmallest(m3, 2) << "\n";
    return 0;
}
