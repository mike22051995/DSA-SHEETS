#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
You can divide even numbers by 2 and multiply odd numbers by 2.
Return minimum possible deviation (max - min) of the array.

Sample Input/Output:
1) [1,2,3,4] -> 1
2) [4,1,5,20,3] -> 3
3) [2,10,8] -> 3

Code Explanation:
Convert all numbers to even (odd*2). Use max-heap and track current minimum.
Repeatedly reduce current maximum while it is even.
*/

int minimumDeviation(vector<int> &nums) {
    priority_queue<int> maxHeap;
    int currentMin = INT_MAX;

    for (int x : nums) {
        if (x % 2 == 1) x *= 2;
        maxHeap.push(x);
        currentMin = min(currentMin, x);
    }

    int answer = INT_MAX;
    while (!maxHeap.empty()) {
        int currentMax = maxHeap.top();
        maxHeap.pop();
        answer = min(answer, currentMax - currentMin);

        if (currentMax % 2 == 1) break;
        currentMax /= 2;
        currentMin = min(currentMin, currentMax);
        maxHeap.push(currentMax);
    }
    return answer;
}

int main() {
    vector<int> a1 = {1,2,3,4};
    vector<int> a2 = {4,1,5,20,3};
    vector<int> a3 = {2,10,8};

    cout << "Output 1: " << minimumDeviation(a1) << "\n";
    cout << "Output 2: " << minimumDeviation(a2) << "\n";
    cout << "Output 3: " << minimumDeviation(a3) << "\n";
    return 0;
}
