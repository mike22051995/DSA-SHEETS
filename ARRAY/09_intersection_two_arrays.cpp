/*
PROBLEM: Intersection of Two Arrays II
Difficulty: Easy
Pattern: Hash Map, Two Pointers

DESCRIPTION:
Given two integer arrays nums1 and nums2, return an array of their intersection. Each 
element in the result must appear as many times as it shows in both arrays and you may 
return the result in any order.

EXPLANATION:
Method 1 (Hash Map): Count frequency of elements in first array, then check second array.
Method 2 (Two Pointers): Sort both arrays, use two pointers to find common elements.

Time Complexity: O(n + m) for hash map, O(nlogn + mlogm) for two pointers
Space Complexity: O(min(n, m))

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Explanation: 2 appears twice in both arrays

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9] or [9,4]
Explanation: Each element appears once in intersection

Example 3:
Input: nums1 = [1,2,3], nums2 = [4,5,6]
Output: []
Explanation: No common elements
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Method 1: Using Hash Map
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> result;
        
        // Count frequency of elements in nums1
        for (int num : nums1) {
            count[num]++;
        }
        
        // Check nums2 and add to result if present in nums1
        for (int num : nums2) {
            if (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        return result;
    }
    
    // Method 2: Using Two Pointers (if arrays are sorted)
    vector<int> intersectSorted(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
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
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result1 = solution.intersect(nums1, nums2);
    cout << "Test 1: ";
    printArray(result1);
    
    // Test Case 2
    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> result2 = solution.intersect(nums3, nums4);
    cout << "Test 2: ";
    printArray(result2);
    
    // Test Case 3
    vector<int> nums5 = {1, 2, 3};
    vector<int> nums6 = {4, 5, 6};
    vector<int> result3 = solution.intersect(nums5, nums6);
    cout << "Test 3: ";
    printArray(result3);
    
    return 0;
}
