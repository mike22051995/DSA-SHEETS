/*
================================================================================
PROBLEM: Find K Closest Elements (LeetCode #658)
DIFFICULTY: Medium
PATTERN: Binary Search / Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given a sorted array, two integers k and x, return the k closest elements to x
in ascending order. If there is a tie, pick the smaller elements.

EXAMPLES:
Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

CODE EXPLANATION:
- Binary search the left boundary of the k-length window.
- Compare distances on both ends to decide which window is closer.
- Return the k elements from the chosen window.
TIME COMPLEXITY: O(log(n - k) + k)
SPACE COMPLEXITY: O(1) extra
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Binary search + Two pointers
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
    
    // Two pointers from both ends
    vector<int> findClosestElementsTwoPointers(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (right - left >= k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            } else {
                right--;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5};
    
    vector<int> result1 = sol.findClosestElements(arr1, 4, 3);
    cout << "4 closest to 3: ";
    for (int x : result1) cout << x << " ";
    cout << endl;
    
    vector<int> result2 = sol.findClosestElements(arr2, 4, -1);
    cout << "4 closest to -1: ";
    for (int x : result2) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. K Closest Points to Origin (LeetCode #973)
2. Kth Largest Element (LeetCode #215)
3. Find K Pairs with Smallest Sums (LeetCode #373)
4. Top K Frequent Elements (LeetCode #347)
5. Kth Smallest Element in Sorted Matrix (LeetCode #378)
6. Find First and Last Position (LeetCode #34)
7. Search Insert Position (LeetCode #35)
8. Binary Search (LeetCode #704)
9. Two Sum II (LeetCode #167)
10. 3Sum Closest (LeetCode #16)
*/
