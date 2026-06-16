#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
Problem Description:
Given two sorted arrays nums1 and nums2, return k pairs (u,v) with smallest sums.

Sample Input/Output:
1) nums1=[1,7,11], nums2=[2,4,6], k=3 -> [[1,2],[1,4],[1,6]]
2) nums1=[1,1,2], nums2=[1,2,3], k=2 -> [[1,1],[1,1]]
3) nums1=[1,2], nums2=[3], k=3 -> [[1,3],[2,3]]

Code Explanation:
Use min-heap with state {sum, i, j}. Start with all pairs (i,0) for first min(k,n1) indices.
Pop smallest pair and push next pair (i,j+1).
*/

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k == 0) return result;

    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> minHeap;

    for (int i = 0; i < (int)nums1.size() && i < k; i++) {
        minHeap.push({nums1[i] + nums2[0], i, 0});
    }

    while (!minHeap.empty() && k--) {
        T top = minHeap.top();
        minHeap.pop();
        int i = get<1>(top);
        int j = get<2>(top);
        result.push_back({nums1[i], nums2[j]});

        if (j + 1 < (int)nums2.size()) {
            minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
    }
    return result;
}

void printPairs(const vector<vector<int>> &pairs) {
    cout << "[";
    for (int i = 0; i < (int)pairs.size(); i++) {
        cout << "[" << pairs[i][0] << "," << pairs[i][1] << "]";
        if (i + 1 != (int)pairs.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    vector<int> a1 = {1,7,11}, b1 = {2,4,6};
    vector<int> a2 = {1,1,2}, b2 = {1,2,3};
    vector<int> a3 = {1,2}, b3 = {3};

    cout << "Output 1: "; printPairs(kSmallestPairs(a1, b1, 3));
    cout << "Output 2: "; printPairs(kSmallestPairs(a2, b2, 2));
    cout << "Output 3: "; printPairs(kSmallestPairs(a3, b3, 3));
    return 0;
}
