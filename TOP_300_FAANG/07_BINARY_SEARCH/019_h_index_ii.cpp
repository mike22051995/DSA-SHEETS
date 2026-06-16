/*
================================================================================
PROBLEM: H-Index II (LeetCode #275)
DIFFICULTY: Medium
PATTERN: Binary Search
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given an array of integers citations where citations[i] is the number of
citations a researcher received for their ith paper and citations is sorted in
ascending order, return the researcher's h-index. The h-index is defined as the
maximum value of h such that the given researcher has published at least h
papers that have each been cited at least h times.

EXAMPLES:

Example 1:
Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers with 0,1,3,5,6
citations. Since the researcher has 3 papers with at least 3 citations each,
h-index is 3.

Example 2:
Input: citations = [1,2,100]
Output: 2

PATTERN RECOGNITION:
Use this pattern when:
- Array is sorted, need O(log n) solution
- Find threshold where condition changes
- Binary search on answer

CODE EXPLANATION:
- Binary search on index to find the smallest index where citations[i] >= n - i.
- The h-index is n - i when this condition first holds.
- If condition fails, move right; else move left to find the first valid index.
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int h = n - mid;  // Number of papers from mid to end
            
            if (citations[mid] >= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return n - left;
    }
    
    // Linear approach for comparison
    int hIndexLinear(vector<int>& citations) {
        int n = citations.size();
        
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) {
                return h;
            }
        }
        
        return 0;
    }
};

int main() {
    Solution sol;
    
    vector<int> citations1 = {0,1,3,5,6};
    cout << "H-Index: " << sol.hIndex(citations1) << endl;
    
    vector<int> citations2 = {1,2,100};
    cout << "H-Index: " << sol.hIndex(citations2) << endl;
    
    vector<int> citations3 = {0,0};
    cout << "H-Index: " << sol.hIndex(citations3) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(log n) for binary search
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. H-Index (LeetCode #274)
2. Find First and Last Position (LeetCode #34)
3. Search Insert Position (LeetCode #35)
4. Find Peak Element (LeetCode #162)
5. Single Element in Sorted Array (LeetCode #540)
6. Search in Rotated Sorted Array (LeetCode #33)
7. Find Minimum in Rotated Sorted Array (LeetCode #153)
8. Kth Smallest Element in Sorted Matrix (LeetCode #378)
9. Split Array Largest Sum (LeetCode #410)
10. Capacity To Ship Packages (LeetCode #1011)
*/
