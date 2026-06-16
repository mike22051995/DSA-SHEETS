/*
PROBLEM: Patching Array (LeetCode 330)
DIFFICULTY: Hard
PATTERN: Greedy Range Coverage

DESCRIPTION:
Given a sorted integer array nums and an integer n, add/patch elements to the array such 
that any number in the range [1, n] inclusive can be formed by the sum of some elements 
in the array. Return the minimum number of patches required.

INPUT:
- nums: sorted array of positive integers
- n: target range upper bound

OUTPUT:
- Minimum patches needed

APPROACH:
1. Track maximum reachable sum (miss)
2. If current number <= miss, we can extend range to miss + num
3. If current number > miss, we have a gap, add miss as patch
4. Continue until miss > n

WHY GREEDY WORKS:
Always patching with "miss" value maximizes range extension. This is optimal because
it doubles our reachable range.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;  // Smallest sum we can't make yet (use long to avoid overflow)
        int patches = 0;
        int i = 0;
        
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // Use current number to extend range
                miss += nums[i];
                i++;
            } else {
                // Add "miss" as a patch to double our range
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 3};
    cout << "Test 1 - nums: [1,3], n=6" << endl;
    cout << "Output: " << sol.minPatches(nums1, 6) << endl;
    cout << "Expected: 1 (add 2, can form [1,2,3,4,5,6])" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 5, 10};
    cout << "Test 2 - nums: [1,5,10], n=20" << endl;
    cout << "Output: " << sol.minPatches(nums2, 20) << endl;
    cout << "Expected: 2 (add 2 and 4)" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 2};
    cout << "Test 3 - nums: [1,2,2], n=5" << endl;
    cout << "Output: " << sol.minPatches(nums3, 5) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test Case 4
    vector<int> nums4 = {};
    cout << "Test 4 - nums: [], n=7" << endl;
    cout << "Output: " << sol.minPatches(nums4, 7) << endl;
    cout << "Expected: 3 (add 1,2,4)" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(m + log n) where m is array length
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Greedy range coverage: track what we can reach
- Key insight: if we can make [1, miss-1], adding miss doubles range
- Always patch with the missing value for maximum extension
- Handle overflow with long type
- Very tricky problem requiring mathematical insight
- Tests deep understanding of greedy + number theory
*/
