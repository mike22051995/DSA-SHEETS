/*
================================================================================
PROBLEM: Find the Duplicate Number (LeetCode #287)
DIFFICULTY: Medium
PATTERN: Floyd's Cycle Detection / Binary Search
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Floyd's Cycle Detection - O(n) time, O(1) space
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Find entrance to cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    // Binary search approach
    int findDuplicateBinarySearch(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            
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
    
    cout << "Duplicate: " << sol.findDuplicate(nums1) << endl;
    cout << "Duplicate: " << sol.findDuplicate(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Find All Duplicates (LeetCode #442)
2. Linked List Cycle II (LeetCode #142)
3. Missing Number (LeetCode #268)
4. First Missing Positive (LeetCode #41)
5. Set Mismatch (LeetCode #645)
6. Find All Numbers Disappeared (LeetCode #448)
7. Single Number (LeetCode #136)
8. Single Number II (LeetCode #137)
9. Single Number III (LeetCode #260)
10. Array Nesting (LeetCode #565)
*/
