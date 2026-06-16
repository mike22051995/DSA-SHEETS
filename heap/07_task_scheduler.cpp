#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Description:
Given tasks represented by letters and cooling time n, find minimum intervals needed.

Sample Input/Output:
1) tasks = [A,A,A,B,B,B], n = 2 -> 8
2) tasks = [A,A,A,B,B,B], n = 0 -> 6
3) tasks = [A,A,A,A,B,C,D,E], n = 2 -> 10

Code Explanation:
Use max-heap by remaining frequency and process tasks in cycles of n+1 slots.
Each cycle executes most frequent tasks first.
*/

int leastInterval(vector<char> &tasks, int n) {
    vector<int> freq(26, 0);
    for (char c : tasks) freq[c - 'A']++;

    priority_queue<int> maxHeap;
    for (int f : freq) if (f > 0) maxHeap.push(f);

    int time = 0;
    while (!maxHeap.empty()) {
        vector<int> used; 
        int slots = n + 1;

        while (slots > 0 && !maxHeap.empty()) {
            int f = maxHeap.top(); maxHeap.pop();
            if (f - 1 > 0) used.push_back(f - 1);
            time++;
            slots--;
        }

        for (int f : used) maxHeap.push(f);
        if (maxHeap.empty()) break;
        time += slots;
    }
    return time;
}

int main() {
    vector<char> t1 = {'A','A','A','B','B','B'};
    vector<char> t2 = {'A','A','A','B','B','B'};
    vector<char> t3 = {'A','A','A','A','B','C','D','E'};

    cout << "Output 1: " << leastInterval(t1, 2) << "\n";
    cout << "Output 2: " << leastInterval(t2, 0) << "\n";
    cout << "Output 3: " << leastInterval(t3, 2) << "\n";
    return 0;
}
