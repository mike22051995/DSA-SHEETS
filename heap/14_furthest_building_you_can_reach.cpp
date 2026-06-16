#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given building heights, bricks, and ladders, find furthest building index you can reach.

Sample Input/Output:
1) heights=[4,2,7,6,9,14,12], bricks=5, ladders=1 -> 4
2) heights=[4,12,2,7,3,18,20,3,19], bricks=10, ladders=2 -> 7
3) heights=[14,3,19,3], bricks=17, ladders=0 -> 3

Code Explanation:
Use min-heap for positive climbs. Treat climbs as ladder usage first.
If climbs exceed ladders, pay smallest climb with bricks.
*/

int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < (int)heights.size() - 1; i++) {
        int climb = heights[i + 1] - heights[i];
        if (climb <= 0) continue;

        minHeap.push(climb);
        if ((int)minHeap.size() > ladders) {
            bricks -= minHeap.top();
            minHeap.pop();
            if (bricks < 0) return i;
        }
    }
    return heights.size() - 1;
}

int main() {
    vector<int> h1 = {4,2,7,6,9,14,12};
    vector<int> h2 = {4,12,2,7,3,18,20,3,19};
    vector<int> h3 = {14,3,19,3};

    cout << "Output 1: " << furthestBuilding(h1, 5, 1) << "\n";
    cout << "Output 2: " << furthestBuilding(h2, 10, 2) << "\n";
    cout << "Output 3: " << furthestBuilding(h3, 17, 0) << "\n";
    return 0;
}
