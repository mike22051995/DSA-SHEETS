/*
PROBLEM: Find K Closest Elements
Difficulty: Medium
Pattern: Binary Search + Two Pointers

DESCRIPTION:
Given a sorted integer array arr, two integers k and x, return the k closest integers to x 
in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or |a - x| == |b - x| and a < b

EXPLANATION:
Binary search to find the starting position:
- Search for the left boundary of the k-length window
- Window slides based on which end is farther from x
- Return k elements starting from left boundary

Time Complexity: O(log(n - k) + k)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Example 3:
Input: arr = [1,1,1,10,10,10], k = 1, x = 9
Output: [10]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Compare distance of left and right boundaries
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> result1 = solution.findClosestElements(arr1, 4, 3);
    cout << "Test 1: ";
    printArray(result1);
    
    // Test Case 2
    vector<int> arr2 = {1,2,3,4,5};
    vector<int> result2 = solution.findClosestElements(arr2, 4, -1);
    cout << "Test 2: ";
    printArray(result2);
    
    // Test Case 3
    vector<int> arr3 = {1,1,1,10,10,10};
    vector<int> result3 = solution.findClosestElements(arr3, 1, 9);
    cout << "Test 3: ";
    printArray(result3);
    
    return 0;
}
