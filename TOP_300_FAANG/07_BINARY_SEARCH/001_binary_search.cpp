/*
================================================================================
PROBLEM: Binary Search (LeetCode #704)
DIFFICULTY: Easy
PATTERN: Binary Search (Template)
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
Given a sorted array of integers and a target value, return the index of the
target if it exists, otherwise return -1.

EXAMPLES:
Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1

CODE EXPLANATION:
- Use left/right bounds and check the middle element.
- If the middle is too small, search the right half; otherwise search the left.
- When bounds cross, the target is not present.
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Iterative Binary Search
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    // Recursive Binary Search
    int searchRecursive(vector<int>& nums, int target) {
        return binarySearchHelper(nums, target, 0, nums.size() - 1);
    }
    
    int binarySearchHelper(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearchHelper(nums, target, mid + 1, right);
        } else {
            return binarySearchHelper(nums, target, left, mid - 1);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    cout << "Search 9: index = " << sol.search(nums, 9) << endl;
    cout << "Search 2: index = " << sol.search(nums, 2) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Search Insert Position (LeetCode #35)
2. First Bad Version (LeetCode #278)
3. Find Minimum in Rotated Sorted Array (LeetCode #153)
4. Search in Rotated Sorted Array (LeetCode #33)
5. Find Peak Element (LeetCode #162)
6. Search a 2D Matrix (LeetCode #74)
7. Sqrt(x) (LeetCode #69)
8. Valid Perfect Square (LeetCode #367)
9. Koko Eating Bananas (LeetCode #875)
10. Capacity To Ship Packages (LeetCode #1011)
*/
