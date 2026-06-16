#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Description:
Given points on a 2D plane and integer k, return the k closest points to the origin.

Sample Input/Output:
1) points = [[1,3],[-2,2]], k = 1 -> Output: [[-2,2]]
2) points = [[3,3],[5,-1],[-2,4]], k = 2 -> Output: [[3,3],[-2,4]]
3) points = [[0,1],[1,0]], k = 2 -> Output: [[0,1],[1,0]]

Code Explanation:
Use a max-heap of size k storing {distanceSquared, index}.
If size exceeds k, remove the farthest point.
*/

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<int, int>> maxHeap;
    for (int i = 0; i < (int)points.size(); i++) {
        int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        maxHeap.push({d, i});
        if ((int)maxHeap.size() > k) maxHeap.pop();
    }

    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }
    return result;
}

void printPoints(const vector<vector<int>> &pts) {
    cout << "[";
    for (int i = 0; i < (int)pts.size(); i++) {
        cout << "[" << pts[i][0] << "," << pts[i][1] << "]";
        if (i + 1 != (int)pts.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    vector<vector<int>> p1 = {{1,3},{-2,2}};
    vector<vector<int>> p2 = {{3,3},{5,-1},{-2,4}};
    vector<vector<int>> p3 = {{0,1},{1,0}};

    cout << "Output 1: "; printPoints(kClosest(p1, 1));
    cout << "Output 2: "; printPoints(kClosest(p2, 2));
    cout << "Output 3: "; printPoints(kClosest(p3, 2));
    return 0;
}
