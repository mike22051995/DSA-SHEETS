#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given matrix, define prefix XOR value at (a,b) as XOR of submatrix (0,0) to (a,b).
Return k-th largest among all prefix XOR values.

Sample Input/Output:
1) matrix=[[5,2],[1,6]], k=1 -> 7
2) matrix=[[5,2],[1,6]], k=2 -> 5
3) matrix=[[5,2],[1,6]], k=3 -> 4

Code Explanation:
Compute prefix XOR matrix. Keep min-heap of size k for largest k values.
Heap top after processing all cells is k-th largest.
*/

int kthLargestValue(vector<vector<int>> &matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> pref(n, vector<int>(m, 0));

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = (i > 0 ? pref[i - 1][j] : 0);
            int left = (j > 0 ? pref[i][j - 1] : 0);
            int diag = (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
            pref[i][j] = up ^ left ^ diag ^ matrix[i][j];

            minHeap.push(pref[i][j]);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
    }
    return minHeap.top();
}

int main() {
    vector<vector<int>> matrix = {{5,2},{1,6}};
    cout << "Output 1: " << kthLargestValue(matrix, 1) << "\n";
    cout << "Output 2: " << kthLargestValue(matrix, 2) << "\n";
    cout << "Output 3: " << kthLargestValue(matrix, 3) << "\n";
    return 0;
}
