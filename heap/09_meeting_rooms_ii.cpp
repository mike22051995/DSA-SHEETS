#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
Problem Description:
Given meeting time intervals, find minimum number of conference rooms required.

Sample Input/Output:
1) [[0,30],[5,10],[15,20]] -> 2
2) [[7,10],[2,4]] -> 1
3) [[1,5],[2,6],[4,8],[9,10]] -> 3

Code Explanation:
Sort intervals by start time. Use min-heap for end times of active meetings.
If next meeting starts after or at earliest ending meeting, reuse room.
*/

int minMeetingRooms(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> minEndHeap;

    for (auto &it : intervals) {
        if (!minEndHeap.empty() && minEndHeap.top() <= it[0]) minEndHeap.pop();
        minEndHeap.push(it[1]);
    }
    return (int)minEndHeap.size();
}

int main() {
    vector<vector<int>> i1 = {{0,30},{5,10},{15,20}};
    vector<vector<int>> i2 = {{7,10},{2,4}};
    vector<vector<int>> i3 = {{1,5},{2,6},{4,8},{9,10}};

    cout << "Output 1: " << minMeetingRooms(i1) << "\n";
    cout << "Output 2: " << minMeetingRooms(i2) << "\n";
    cout << "Output 3: " << minMeetingRooms(i3) << "\n";
    return 0;
}
