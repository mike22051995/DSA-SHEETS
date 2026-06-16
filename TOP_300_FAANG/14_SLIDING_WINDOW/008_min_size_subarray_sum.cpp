/*
================================================================================
PROBLEM: Minimum Size Subarray Sum (LeetCode #209)
DIFFICULTY: Medium
PATTERN: Sliding Window / Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // Binary search approach - O(n log n)
    int minSubArrayLenBinarySearch(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        int minLen = INT_MAX;
        
        for (int i = 0; i <= n; i++) {
            int toFind = target + prefixSum[i];
            auto bound = lower_bound(prefixSum.begin(), prefixSum.end(), toFind);
            
            if (bound != prefixSum.end()) {
                minLen = min(minLen, (int)(bound - prefixSum.begin()) - i);
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,1,2,4,3};
    vector<int> nums2 = {1,4,4};
    
    cout << "Min subarray length (target 7): " << sol.minSubArrayLen(7, nums1) << endl;
    cout << "Min subarray length (target 4): " << sol.minSubArrayLen(4, nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximum Size Subarray Sum Equals k (LeetCode #325)
2. Subarray Sum Equals K (LeetCode #560)
3. Shortest Subarray with Sum at Least K (LeetCode #862)
4. Maximum Average Subarray I (LeetCode #643)
5. Maximum Average Subarray II (LeetCode #644)
6. Minimum Window Substring (LeetCode #76)
7. Max Consecutive Ones III (LeetCode #1004)
8. Count Subarrays With Score Less Than K (LeetCode #2302)
9. Longest Turbulent Subarray (LeetCode #978)
10. Minimum Operations to Reduce X to Zero (LeetCode #1658)
*/
