#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


/*
Problem Description:
Given an integer array nums and an integer k, return the k most frequent elements.

Sample Input/Output:
1) nums = [1,1,1,2,2,3], k = 2 -> Output: [1,2]
2) nums = [1], k = 1 -> Output: [1]
3) nums = [4,4,4,6,6,7], k = 2 -> Output: [4,6]

Code Explanation:
Count frequencies using a hash map. Keep a min-heap of size k on frequency.
When heap grows beyond k, remove the smallest frequency.
*/

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto &entry : freq) {
        minHeap.push({entry.second, entry.first});
        if ((int)minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

void printVec(const vector<int> &v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << (i + 1 == (int)v.size() ? "" : ",");
    }
    cout << "]\n";
}

int main() {
    vector<int> a1 = {1,1,1,2,2,3};
    vector<int> a2 = {1};
    vector<int> a3 = {4,4,4,6,6,7};

    cout << "Output 1: "; printVec(topKFrequent(a1, 2));
    cout << "Output 2: "; printVec(topKFrequent(a2, 1));
    cout << "Output 3: "; printVec(topKFrequent(a3, 2));
    return 0;
}
