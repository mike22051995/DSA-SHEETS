#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
You can complete at most k projects. Project i needs capital[i] and gives profit[i].
Start with initial capital w, maximize final capital.

Sample Input/Output:
1) k=2, w=0, profits=[1,2,3], capital=[0,1,1] -> 4
2) k=3, w=0, profits=[1,2,3], capital=[0,1,2] -> 6
3) k=1, w=2, profits=[5,6], capital=[1,3] -> 7

Code Explanation:
Sort projects by required capital. Push affordable projects' profits into max-heap.
Pick max profit project up to k times.
*/

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    vector<pair<int, int>> projects;
    for (int i = 0; i < (int)profits.size(); i++) projects.push_back({capital[i], profits[i]});
    sort(projects.begin(), projects.end());

    priority_queue<int> maxProfit;
    int index = 0;

    while (k--) {
        while (index < (int)projects.size() && projects[index].first <= w) {
            maxProfit.push(projects[index].second);
            index++;
        }
        if (maxProfit.empty()) break;
        w += maxProfit.top();
        maxProfit.pop();
    }
    return w;
}

int main() {
    vector<int> p1 = {1,2,3}, c1 = {0,1,1};
    vector<int> p2 = {1,2,3}, c2 = {0,1,2};
    vector<int> p3 = {5,6}, c3 = {1,3};

    cout << "Output 1: " << findMaximizedCapital(2, 0, p1, c1) << "\n";
    cout << "Output 2: " << findMaximizedCapital(3, 0, p2, c2) << "\n";
    cout << "Output 3: " << findMaximizedCapital(1, 2, p3, c3) << "\n";
    return 0;
}
