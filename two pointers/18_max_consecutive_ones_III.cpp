/*
PROBLEM: Max Consecutive Ones III
---------------------------------------------------------------------------
Given a binary array nums and an integer k, return the maximum number of 
consecutive 1's in the array if you can flip at most k 0's.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: Flip the two 0's at indices 4,5. Result: [1,1,1,0,0,1,1,1,1,1,1]

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: Flip 0's at indices 4,5,9. Max consecutive 1's = 10.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeros = 0;
        int maxLen = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeros++;
            }
            
            // Shrink window if we have more than k zeros
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Test 1: " << sol.longestOnes(nums1, k1) << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    cout << "Test 2: " << sol.longestOnes(nums2, k2) << endl;
    
    return 0;
}
