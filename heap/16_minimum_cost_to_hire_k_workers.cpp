#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given quality and wage arrays, hire exactly k workers with minimum total cost.

Sample Input/Output:
1) quality=[10,20,5], wage=[70,50,30], k=2 -> 105.00
2) quality=[3,1,10,10,1], wage=[4,8,2,2,7], k=3 -> 30.67
3) quality=[5,5,5], wage=[5,5,5], k=2 -> 10.00

Code Explanation:
Sort workers by wage/quality ratio. Maintain max-heap of selected qualities.
For each worker as highest ratio, compute candidate cost = ratio * totalQuality.
*/

struct Worker {
    double ratio;
    int quality;
};

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    vector<Worker> workers;
    for (int i = 0; i < (int)quality.size(); i++) {
        workers.push_back({(double)wage[i] / quality[i], quality[i]});
    }
    sort(workers.begin(), workers.end(), [](const Worker &a, const Worker &b) {
        return a.ratio < b.ratio;
    });

    priority_queue<int> maxHeap;
    int qualitySum = 0;
    double answer = 1e18;

    for (auto &w : workers) {
        maxHeap.push(w.quality);
        qualitySum += w.quality;

        if ((int)maxHeap.size() > k) {
            qualitySum -= maxHeap.top();
            maxHeap.pop();
        }

        if ((int)maxHeap.size() == k) {
            answer = min(answer, qualitySum * w.ratio);
        }
    }
    return answer;
}

int main() {
    vector<int> q1 = {10,20,5}, w1 = {70,50,30};
    vector<int> q2 = {3,1,10,10,1}, w2 = {4,8,2,2,7};
    vector<int> q3 = {5,5,5}, w3 = {5,5,5};

    cout << fixed << setprecision(2);
    cout << "Output 1: " << mincostToHireWorkers(q1, w1, 2) << "\n";
    cout << "Output 2: " << mincostToHireWorkers(q2, w2, 3) << "\n";
    cout << "Output 3: " << mincostToHireWorkers(q3, w3, 2) << "\n";
    return 0;
}
