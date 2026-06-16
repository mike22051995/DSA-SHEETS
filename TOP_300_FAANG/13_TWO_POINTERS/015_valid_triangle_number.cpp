/*
================================================================================
PROBLEM: Valid Triangle Number (LeetCode #611)
DIFFICULTY: Medium
PATTERN: Two Pointers / Sorting
COMPANIES: Amazon, Microsoft, Google
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums, return the number of triplets chosen from the array
that can make triangles if we take them as side lengths of a triangle. A valid
triangle must satisfy: a + b > c, a + c > b, and b + c > a.

EXAMPLES:

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: [2,3,4], [2,3,4], [2,2,3]

Example 2:
Input: nums = [4,2,3,4]
Output: 4

PATTERN RECOGNITION:
Use this pattern when:
- Count triplets satisfying sum condition
- Sort array and use two pointers
- For largest side c, find pairs where a + b > c
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        
        // Fix the largest side
        for (int k = n - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] > nums[k]) {
                    // All pairs (left, right-1), (left, right-2), ..., (left, left+1)
                    // form valid triangles with nums[k]
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {2,2,3,4};
    cout << "Valid triangles: " << sol.triangleNumber(nums1) << endl;
    
    vector<int> nums2 = {4,2,3,4};
    cout << "Valid triangles: " << sol.triangleNumber(nums2) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n^2) where n is array length
SPACE COMPLEXITY: O(1) or O(log n) for sorting

SIMILAR PROBLEMS:
1. 3Sum (LeetCode #15)
2. 3Sum Closest (LeetCode #16)
3. 4Sum (LeetCode #18)
4. Two Sum (LeetCode #1)
5. Two Sum II (LeetCode #167)
6. Container With Most Water (LeetCode #11)
7. Trapping Rain Water (LeetCode #42)
8. Boats to Save People (LeetCode #881)
9. Subarray Product Less Than K (LeetCode #713)
10. Count Number of Nice Subarrays (LeetCode #1248)
*/
