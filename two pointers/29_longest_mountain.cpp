/*
PROBLEM: Longest Mountain in Array
---------------------------------------------------------------------------
You may recall that an array arr is a mountain array if and only if:
- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
  arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Return the length of the longest mountain.

PATTERN: Two Pointers (Expand from Center)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: Longest mountain is [1,4,7,3,2] with length 5.

Example 2:
Input: arr = [2,2,2]
Output: 0
Explanation: No mountain exists.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        
        for (int i = 1; i < n - 1; i++) {
            // Check if i is a peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;
                
                // Expand left (uphill)
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                
                // Expand right (downhill)
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }
                
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {2, 1, 4, 7, 3, 2, 5};
    cout << "Test 1: " << sol.longestMountain(arr1) << endl;
    
    // Test case 2
    vector<int> arr2 = {2, 2, 2};
    cout << "Test 2: " << sol.longestMountain(arr2) << endl;
    
    return 0;
}
