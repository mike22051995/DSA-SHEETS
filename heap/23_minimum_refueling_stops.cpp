#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
You travel to target distance with startFuel and stations [position, fuel].
Return minimum refueling stops, or -1 if impossible.

Sample Input/Output:
1) target=100, startFuel=10, stations=[[10,60],[20,30],[30,30],[60,40]] -> 2
2) target=100, startFuel=1, stations=[[10,100]] -> -1
3) target=100, startFuel=100, stations=[] -> 0

Code Explanation:
Traverse stations. Keep max-heap of fuels from passed stations.
When fuel insufficient to continue, refuel with largest available previous station.
*/

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    priority_queue<int> maxHeap;
    long long fuel = startFuel;
    int index = 0, stops = 0;

    while (fuel < target) {
        while (index < (int)stations.size() && stations[index][0] <= fuel) {
            maxHeap.push(stations[index][1]);
            index++;
        }

        if (maxHeap.empty()) return -1;
        fuel += maxHeap.top();
        maxHeap.pop();
        stops++;
    }
    return stops;
}

int main() {
    vector<vector<int>> st1 = {{10,60},{20,30},{30,30},{60,40}};
    vector<vector<int>> st2 = {{10,100}};
    vector<vector<int>> st3 = {};

    cout << "Output 1: " << minRefuelStops(100, 10, st1) << "\n";
    cout << "Output 2: " << minRefuelStops(100, 1, st2) << "\n";
    cout << "Output 3: " << minRefuelStops(100, 100, st3) << "\n";
    return 0;
}
