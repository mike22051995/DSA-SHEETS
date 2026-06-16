/*
================================================================================
PROBLEM: Sliding Window Maximum (LeetCode #239)
DIFFICULTY: Hard
PATTERN: Deque (Monotonic Decreasing)
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Store indices
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Add to result once window is full
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto result = sol.maxSlidingWindow(nums, 3);
    
    cout << "Sliding window maximums: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Min Stack (LeetCode #155)
2. Max Stack (LeetCode #716)
3. Sliding Window Median (LeetCode #480)
4. Longest Continuous Subarray (LeetCode #1438)
5. Constrained Subsequence Sum (LeetCode #1425)
6. Jump Game VI (LeetCode #1696)
7. Shortest Subarray with Sum at Least K (LeetCode #862)
8. Find Median from Data Stream (LeetCode #295)
9. Moving Average from Data Stream (LeetCode #346)
10. Max Value of Equation (LeetCode #1499)
*/
