/*
PROBLEM: Intersection of Two Arrays (LeetCode 349/350)
===============================================
DESCRIPTION:
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

PATTERN: Sorting + Two Pointer
DIFFICULTY: Easy
TIME COMPLEXITY: O(n log n + m log m)
SPACE COMPLEXITY: O(1) excluding output array

INPUT:
Two arrays of integers

OUTPUT:
Array containing intersection elements

EXAMPLE:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4] or [4,9]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Approach 1: Sorting + Two Pointers
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                // Found common element
                // Add only if not already added (for uniqueness)
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        
        return result;
    }
    
    // Approach 2: Using Set (simpler)
    vector<int> intersectionV2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;
        
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num);
            }
        }
        
        return vector<int>(resultSet.begin(), resultSet.end());
    }
    
    // Intersection II: With duplicates (each element can appear multiple times)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    cout << "nums1: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nnums2: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    vector<int> result1 = sol.intersection(nums1, nums2);
    cout << "\nIntersection (unique): ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    
    vector<int> result2 = sol.intersectionV2(nums1, nums2);
    cout << "Intersection (using set): ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    
    vector<int> result3 = sol.intersect(nums1, nums2);
    cout << "Intersection (with duplicates): ";
    for (int num : result3) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
PROBLEM VARIATION 1: Unique Elements Only (LeetCode 349)
APPROACH 1: Sorting + Two Pointers
1. Sort both arrays
2. Use two pointers to traverse both arrays
3. If elements match, add to result (if not duplicate)
4. Move pointer of smaller element forward

APPROACH 2: Using Set
1. Convert first array to set
2. For each element in second array, check if in set
3. Add to result set if found
4. Return as vector

PROBLEM VARIATION 2: With Duplicates (LeetCode 350)
- Allow duplicate elements in intersection
- Same two-pointer approach but add all matches

COMPARISON:
Sorting Approach:
- Time: O(n log n + m log m)
- Space: O(1)
- Good when arrays can be modified

Set Approach:
- Time: O(n + m)
- Space: O(n)
- Faster but uses more space

WHY THIS PATTERN IS IMPORTANT:
- Two pointer technique on sorted arrays
- Trade-off between time and space
- Common in array intersection/union problems
- Foundation for more complex merge operations
- Follow-up questions test optimization thinking
*/
