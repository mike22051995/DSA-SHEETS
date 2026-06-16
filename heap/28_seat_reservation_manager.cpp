#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Manage seat reservations from 1 to n.
reserve() returns smallest available seat.
unreserve(seat) puts seat back.

Sample Input/Output:
1) reserve() -> 1
2) reserve() -> 2
3) unreserve(1), reserve() -> 1

Code Explanation:
Use min-heap of available seat numbers.
reserve pops smallest, unreserve pushes seat back.
*/

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) minHeap.push(i);
    }

    int reserve() {
        int seat = minHeap.top();
        minHeap.pop();
        return seat;
    }

    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

int main() {
    SeatManager manager(5);
    cout << "Output 1: " << manager.reserve() << "\n";
    cout << "Output 2: " << manager.reserve() << "\n";
    manager.unreserve(1);
    cout << "Output 3: " << manager.reserve() << "\n";
    return 0;
}
