/*
================================================================================
PROBLEM: Intersection of Two Arrays (LeetCode #349)
DIFFICULTY: Easy
PATTERN: Two Pointers / Hash Set
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any
order.

EXAMPLES:

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4] or [4,9]

PATTERN RECOGNITION:
Use this pattern when:
- Find common elements between arrays
- Hash set for O(1) lookup
- Two pointers on sorted arrays
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Hash Set approach
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;
        
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num);
            }
        }
        
        return vector<int>(resultSet.begin(), resultSet.end());
    }
    
    // Two pointers approach (after sorting)
    vector<int> intersectionTwoPointers(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        unordered_set<int> resultSet;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                resultSet.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    auto result1 = sol.intersection(nums1, nums2);
    
    cout << "Intersection: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> nums3 = {4,9,5};
    vector<int> nums4 = {9,4,9,8,4};
    auto result2 = sol.intersection(nums3, nums4);
    
    cout << "Intersection: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(m + n) for hash set, O(m log m + n log n) for two pointers
SPACE COMPLEXITY: O(min(m,n)) for result

SIMILAR PROBLEMS:
1. Intersection of Two Arrays II (LeetCode #350)
2. Intersection of Multiple Arrays (LeetCode #2248)
3. Two Sum (LeetCode #1)
4. Contains Duplicate (LeetCode #217)
5. Valid Anagram (LeetCode #242)
6. Group Anagrams (LeetCode #49)
7. Find Common Characters (LeetCode #1002)
8. Isomorphic Strings (LeetCode #205)
9. Find All Numbers Disappeared (LeetCode #448)
10. Missing Number (LeetCode #268)
*/
