/*
================================================================================
PROBLEM: Find the Duplicate Number (LeetCode #287)
DIFFICULTY: Medium
PATTERN: Binary Search / Floyd's Cycle Detection
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given an array of integers nums containing n + 1 integers where each integer
is in the range [1, n] inclusive. There is only one repeated number in nums,
return this repeated number. You must solve the problem without modifying the
array nums and uses only constant extra space.

EXAMPLES:

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3

PATTERN RECOGNITION:
Use this pattern when:
- Find duplicate without modifying array
- Constant space required
- Floyd's cycle detection or binary search on value range

CODE EXPLANATION:
- Binary search the value range [1, n] instead of indices.
- Count how many numbers are <= mid; if count > mid, duplicate is left side.
- Narrow the range until left == right.
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Floyd's Cycle Detection (Tortoise and Hare)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Find intersection point in cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Find entrance to cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    // Binary Search on value range
    int findDuplicateBinarySearch(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            // Count numbers <= mid
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            
            // If count > mid, duplicate is in [left, mid]
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,3,4,2,2};
    vector<int> nums2 = {3,1,3,4,2};
    vector<int> nums3 = {3,3,3,3,3};
    
    cout << "Duplicate in [1,3,4,2,2]: " << sol.findDuplicate(nums1) << endl;
    cout << "Duplicate in [3,1,3,4,2]: " << sol.findDuplicate(nums2) << endl;
    cout << "Duplicate in [3,3,3,3,3]: " << sol.findDuplicate(nums3) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) for Floyd's, O(n log n) for binary search
SPACE COMPLEXITY: O(1) for both approaches

SIMILAR PROBLEMS:
1. Linked List Cycle II (LeetCode #142)
2. Find All Duplicates in Array (LeetCode #442)
3. Find All Numbers Disappeared (LeetCode #448)
4. Set Mismatch (LeetCode #645)
5. Missing Number (LeetCode #268)
6. First Missing Positive (LeetCode #41)
7. Couples Holding Hands (LeetCode #765)
8. Array Nesting (LeetCode #565)
9. Happy Number (LeetCode #202)
10. Intersection of Two Arrays (LeetCode #349)
*/
