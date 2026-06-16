/*
PROBLEM: Count of Smaller Numbers After Self (LeetCode 315)
===============================================
DESCRIPTION:
Given an integer array nums, return an integer array counts where counts[i] is 
the number of smaller elements to the right of nums[i].

PATTERN: Merge Sort with Index Tracking / Binary Indexed Tree
DIFFICULTY: Hard
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Array where each element = count of smaller elements to its right

EXAMPLE:
Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
- To the right of 5: [2,1] are smaller → 2
- To the right of 2: [1] is smaller → 1
- To the right of 6: [1] is smaller → 1
- To the right of 1: [] → 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<pair<int, int>> pairs(n); // (value, original_index)
        
        // Create pairs of (value, index)
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }
        
        // Merge sort with counting
        mergeSort(pairs, 0, n - 1, result);
        
        return result;
    }
    
private:
    void mergeSort(vector<pair<int, int>>& pairs, int left, int right, vector<int>& result) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        
        mergeSort(pairs, left, mid, result);
        mergeSort(pairs, mid + 1, right, result);
        
        merge(pairs, left, mid, right, result);
    }
    
    void merge(vector<pair<int, int>>& pairs, int left, int mid, int right, vector<int>& result) {
        vector<pair<int, int>> temp;
        int i = left;      // Left array pointer
        int j = mid + 1;   // Right array pointer
        int rightCount = 0; // Count of elements from right that are smaller
        
        while (i <= mid && j <= right) {
            if (pairs[i].first <= pairs[j].first) {
                // Element from right array is larger
                // All elements from j to right are larger than pairs[i]
                result[pairs[i].second] += rightCount;
                temp.push_back(pairs[i]);
                i++;
            } else {
                // Element from right array is smaller
                rightCount++;
                temp.push_back(pairs[j]);
                j++;
            }
        }
        
        // Process remaining elements from left
        while (i <= mid) {
            result[pairs[i].second] += rightCount;
            temp.push_back(pairs[i]);
            i++;
        }
        
        // Process remaining elements from right
        while (j <= right) {
            temp.push_back(pairs[j]);
            j++;
        }
        
        // Copy back to original array
        for (int k = left; k <= right; k++) {
            pairs[k] = temp[k - left];
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {5, 2, 6, 1};
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    vector<int> result1 = sol.countSmaller(nums1);
    cout << "Output: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    
    vector<int> nums2 = {-1, -1};
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    vector<int> result2 = sol.countSmaller(nums2);
    cout << "Output: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
KEY INSIGHT:
During merge sort, when we merge two sorted halves:
- If element from left > element from right
- All remaining elements in right array are smaller
- Count these for the left element

ALGORITHM:
1. Create pairs (value, original_index) to track positions
2. Perform modified merge sort
3. During merge, when element from left is placed:
   - Add count of elements already placed from right array
4. These right elements are smaller and to the right in original array

MERGE PROCESS DETAILS:
When merging [left...mid] and [mid+1...right]:
- If pairs[i] <= pairs[j]: Place pairs[i], add rightCount to result
- If pairs[i] > pairs[j]: Place pairs[j], increment rightCount

rightCount tracks how many elements from right subarray have been placed
These are all smaller than current left element

EXAMPLE WALKTHROUGH:
Input: [5, 2, 6, 1]
Pairs: [(5,0), (2,1), (6,2), (1,3)]

Split:
[(5,0), (2,1)] | [(6,2), (1,3)]

Split again:
[(5,0)] [(2,1)] | [(6,2)] [(1,3)]

Merge [(5,0)] and [(2,1)]:
- 2 < 5: place (2,1), rightCount=1
- place (5,0), result[0] += 1
Result after: [(2,1), (5,0)], counts=[1,0,0,0]

Merge [(6,2)] and [(1,3)]:
- 1 < 6: place (1,3), rightCount=1
- place (6,2), result[2] += 1
Result after: [(1,3), (6,2)], counts=[1,0,1,0]

Final merge [(2,1), (5,0)] and [(1,3), (6,2)]:
- 1 < 2: place (1,3), rightCount=1
- 2 < 6: place (2,1), result[1] += 1, now counts=[1,1,1,0]
- 5 < 6: place (5,0), result[0] += 1, now counts=[2,1,1,0]
- place (6,2)

Final: [2,1,1,0]

WHY THIS WORKS:
- Merge sort naturally processes elements from left to right
- During merge, right elements that are placed before left element
  are smaller and to the right in original array
- Tracking count during merge captures this information

TIME COMPLEXITY:
- Merge sort: O(n log n)
- Each merge: O(n)
- Total: O(n log n)

ALTERNATIVE APPROACHES:
1. Brute Force: O(n²) - check all pairs
2. Binary Indexed Tree: O(n log n)
3. Segment Tree: O(n log n)
4. AVL Tree: O(n log n)

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates modification of classic algorithms
- Shows how to augment merge sort for counting
- Important for inversion counting problems
- Common in problems requiring order statistics
- Appears in: Reverse pairs, count of range sum
- Tests deep understanding of merge sort
- Very challenging interview problem (Google, Facebook)
*/
