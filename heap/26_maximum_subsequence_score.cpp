#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given nums1 and nums2, choose k indices to maximize:
(sum of chosen nums1) * (minimum of chosen nums2).

Sample Input/Output:
1) nums1=[1,3,3,2], nums2=[2,1,3,4], k=3 -> 12
2) nums1=[4,2,3,1,1], nums2=[7,5,10,9,6], k=1 -> 30
3) nums1=[2,1,14,12], nums2=[11,7,13,6], k=3 -> 168

Code Explanation:
Sort pairs by nums2 descending so current nums2 acts as minimum.
Maintain min-heap of k nums1 values with running sum.
*/

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < (int)nums1.size(); i++) pairs.push_back({nums2[i], nums1[i]});
    sort(pairs.rbegin(), pairs.rend());

    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long sum = 0, answer = 0;

    for (auto &p : pairs) {
        int n2 = p.first, n1 = p.second;
        minHeap.push(n1);
        sum += n1;

        if ((int)minHeap.size() > k) {
            sum -= minHeap.top();
            minHeap.pop();
        }

        if ((int)minHeap.size() == k) {
            answer = max(answer, sum * n2);
        }
    }
    return answer;
}

int main() {
    vector<int> a1 = {1,3,3,2}, b1 = {2,1,3,4};
    vector<int> a2 = {4,2,3,1,1}, b2 = {7,5,10,9,6};
    vector<int> a3 = {2,1,14,12}, b3 = {11,7,13,6};

    cout << "Output 1: " << maxScore(a1, b1, 3) << "\n";
    cout << "Output 2: " << maxScore(a2, b2, 1) << "\n";
    cout << "Output 3: " << maxScore(a3, b3, 3) << "\n";
    return 0;
}
