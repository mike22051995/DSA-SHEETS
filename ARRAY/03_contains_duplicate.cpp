/*
PROBLEM: Contains Duplicate
Difficulty: Easy
Pattern: Hash Set

DESCRIPTION:
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

EXPLANATION:
We use a hash set to track numbers we've seen. If we encounter a number that's already 
in the set, we found a duplicate. Otherwise, we add it to the set.

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation: 1 appears twice

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements are distinct

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
Explanation: Multiple duplicates exist
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            // If number already exists in set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: " << (solution.containsDuplicate(nums1) ? "true" : "false") << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test 2: " << (solution.containsDuplicate(nums2) ? "true" : "false") << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test 3: " << (solution.containsDuplicate(nums3) ? "true" : "false") << endl;
    
    return 0;
}
