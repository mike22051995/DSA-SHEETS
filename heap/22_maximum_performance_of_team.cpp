#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Choose at most k engineers with speed and efficiency.
Team performance = sum(speed) * minimum(efficiency among selected).
Return maximum performance.

Sample Input/Output:
1) n=6, speed=[2,10,3,1,5,8], efficiency=[5,4,3,9,7,2], k=2 -> 60
2) same arrays, k=3 -> 68
3) n=3, speed=[2,8,2], efficiency=[2,7,1], k=2 -> 56

Code Explanation:
Sort by efficiency descending. Use min-heap for selected speeds.
At each step, current efficiency is minimum of team. Track best sum(speed)*eff.
*/

long long maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
    vector<pair<int, int>> workers;
    for (int i = 0; i < n; i++) workers.push_back({efficiency[i], speed[i]});
    sort(workers.rbegin(), workers.rend());

    priority_queue<int, vector<int>, greater<int>> minSpeedHeap;
    long long speedSum = 0, best = 0;

    for (auto &w : workers) {
        int eff = w.first, spd = w.second;
        minSpeedHeap.push(spd);
        speedSum += spd;

        if ((int)minSpeedHeap.size() > k) {
            speedSum -= minSpeedHeap.top();
            minSpeedHeap.pop();
        }

        best = max(best, speedSum * eff);
    }
    return best;
}

int main() {
    vector<int> s1 = {2,10,3,1,5,8};
    vector<int> e1 = {5,4,3,9,7,2};
    vector<int> s2 = {2,8,2};
    vector<int> e2 = {2,7,1};

    cout << "Output 1: " << maxPerformance(6, s1, e1, 2) << "\n";
    cout << "Output 2: " << maxPerformance(6, s1, e1, 3) << "\n";
    cout << "Output 3: " << maxPerformance(3, s2, e2, 2) << "\n";
    return 0;
}
