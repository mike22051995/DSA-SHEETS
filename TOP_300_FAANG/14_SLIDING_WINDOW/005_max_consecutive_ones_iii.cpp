/*
================================================================================
PROBLEM: Max Consecutive Ones III (LeetCode #1004)
DIFFICULTY: Medium
PATTERN: Sliding Window
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeros = 0;
        int maxLen = 0;
        
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeros++;
            }
            
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    
    cout << "Max consecutive ones (k=2): " << sol.longestOnes(nums1, 2) << endl;
    cout << "Max consecutive ones (k=3): " << sol.longestOnes(nums2, 3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Max Consecutive Ones (LeetCode #485)
2. Max Consecutive Ones II (LeetCode #487)
3. Longest Substring Without Repeating (LeetCode #3)
4. Minimum Window Substring (LeetCode #76)
5. Longest Repeating Character Replacement (LeetCode #424)
6. Subarrays with K Different Integers (LeetCode #992)
7. Fruit Into Baskets (LeetCode #904)
8. Get Equal Substrings Within Budget (LeetCode #1208)
9. Grumpy Bookstore Owner (LeetCode #1052)
10. Maximize Consecutive Elements (LeetCode #2401)
*/
