/*
================================================================================
PROBLEM: House Robber (LeetCode #198)
DIFFICULTY: Medium
PATTERN: Dynamic Programming (Decision Making)
COMPANIES: Amazon, Microsoft, Google, Apple, Adobe
================================================================================

PROBLEM DESCRIPTION:
You are a professional robber planning to rob houses along a street. Each 
house has a certain amount of money stashed, the only constraint stopping you 
from robbing each of them is that adjacent houses have security systems 
connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Decision at each step: include or exclude current element
2. Cannot take adjacent elements
3. Maximize/minimize with constraints
4. Previous decisions affect current choice

Key Indicators:
- "Cannot take adjacent" or "skip one element"
- "Maximum value" with constraints
- Decision-making DP
- Can be optimized to O(1) space

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and house 3 (money = 3)
Total = 1 + 3 = 4

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (2), house 3 (9), and house 5 (1)
Total = 2 + 9 + 1 = 12

Example 3:
Input: nums = [2,1,1,2]
Output: 4
Explanation: Rob house 1 (2) and house 4 (2)
Total = 2 + 2 = 4

Example 4:
Input: nums = [5,3,4,11,2]
Output: 16
Explanation: Rob house 1 (5) and house 4 (11)
Total = 5 + 11 = 16

================================================================================
EXPLANATION:

Decision at Each House:
1. Rob current house + max from (i-2) houses
2. Don't rob current house, take max from (i-1) houses

Recurrence Relation:
dp[i] = max(nums[i] + dp[i-2], dp[i-1])

Base Cases:
- dp[0] = nums[0] (only one house)
- dp[1] = max(nums[0], nums[1]) (two houses)

Intuition:
At each house, decide whether robbing it gives more money than skipping it.
If we rob house i, we must skip i-1, so add dp[i-2].
If we skip house i, we take max up to i-1.

Space Optimization:
Only need last two values, not entire array.

Time: O(n)
Space: O(1) with optimization, O(n) with DP array

================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: DP with Array
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
    
    // Approach 2: Space Optimized (Best for Interviews)
    int robOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];              // dp[i-2]
        int prev1 = max(nums[0], nums[1]); // dp[i-1]
        
        for (int i = 2; i < n; i++) {
            int current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
    
    // Approach 3: Most Elegant (Variable Names)
    int robElegant(vector<int>& nums) {
        int rob = 0;     // Max if we rob current house
        int notRob = 0;  // Max if we don't rob current house
        
        for (int num : nums) {
            int newRob = notRob + num;  // Rob current + prev notRob
            notRob = max(notRob, rob);   // Don't rob = max of previous
            rob = newRob;
        }
        
        return max(rob, notRob);
    }
    
    // Approach 4: Recursion with Memoization (Top-down)
    int robMemo(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return robHelper(nums, nums.size() - 1, memo);
    }
    
    int robHelper(vector<int>& nums, int i, vector<int>& memo) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];
        if (memo[i] != -1) return memo[i];
        
        // Rob current or skip
        int rob = nums[i] + robHelper(nums, i - 2, memo);
        int skip = robHelper(nums, i - 1, memo);
        
        memo[i] = max(rob, skip);
        return memo[i];
    }
    
    // Approach 5: With House Selection Tracking
    pair<int, vector<int>> robWithHouses(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {0, {}};
        if (n == 1) return {nums[0], {0}};
        
        vector<int> dp(n);
        vector<vector<int>> houses(n);
        
        dp[0] = nums[0];
        houses[0] = {0};
        
        if (nums[1] > nums[0]) {
            dp[1] = nums[1];
            houses[1] = {1};
        } else {
            dp[1] = nums[0];
            houses[1] = {0};
        }
        
        for (int i = 2; i < n; i++) {
            if (nums[i] + dp[i-2] > dp[i-1]) {
                dp[i] = nums[i] + dp[i-2];
                houses[i] = houses[i-2];
                houses[i].push_back(i);
            } else {
                dp[i] = dp[i-1];
                houses[i] = houses[i-1];
            }
        }
        
        return {dp[n-1], houses[n-1]};
    }
};

void runTest(vector<int> nums, string testName) {
    Solution sol;
    int result = sol.robOptimized(nums);
    auto [maxMoney, houses] = sol.robWithHouses(nums);
    
    cout << testName << ": " << endl;
    cout << "Houses: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Maximum Money: " << result << endl;
    cout << "Rob Houses at indices: [";
    for (int i = 0; i < houses.size(); i++) {
        cout << houses[i];
        if (i < houses.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    runTest(nums1, "Test 1");
    
    vector<int> nums2 = {2, 7, 9, 3, 1};
    runTest(nums2, "Test 2");
    
    vector<int> nums3 = {2, 1, 1, 2};
    runTest(nums3, "Test 3");
    
    vector<int> nums4 = {5, 3, 4, 11, 2};
    runTest(nums4, "Test 4");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. House Robber II (LeetCode #213) - Medium
   - Houses arranged in a circle (first and last are adjacent)
   - Solution: Rob [0, n-2] or [1, n-1], take max

2. House Robber III (LeetCode #337) - Medium
   - Binary tree structure instead of array
   - Use DFS with state tracking

3. Delete and Earn (LeetCode #740) - Medium
   - Very similar pattern
   - Group numbers and apply house robber logic

4. Paint House (LeetCode #256) - Medium
   - Choose colors with constraints
   - Similar decision-making DP

5. Paint Fence (LeetCode #276) - Medium
   - Paint k colors with no 3 consecutive same
   - Decision DP

6. Best Time to Buy and Sell Stock with Cooldown (LeetCode #309) - Medium
   - Stock trading with cooldown
   - State machine DP

7. Coin Change (LeetCode #322) - Medium
   - Different DP pattern but similar decision making

8. Climbing Stairs (LeetCode #70) - Easy
   - Simpler version of decision DP

9. Maximum Alternating Subsequence Sum (LeetCode #1911) - Medium
   - Alternating selection pattern

10. Longest Palindromic Subsequence (LeetCode #516) - Medium
    - Different DP but similar complexity

================================================================================
KEY INSIGHTS:
================================================================================

1. DP State Definition:
   - dp[i] = maximum money robbing up to house i
   - Alternatively: rob/notRob states

2. Decision Tree:
   At each house:
   ```
   House i
   ├─ Rob: nums[i] + dp[i-2]
   └─ Skip: dp[i-1]
   Take maximum
   ```

3. Space Optimization Journey:
   - O(n) array → O(1) with two variables
   - Only need previous two states
   - Common pattern in linear DP

4. Variations:
   - Circular (House Robber II): Split into two problems
   - Tree (House Robber III): DFS with states
   - 2D grid: Extend to 2D DP

5. Interview Strategy:
   - Start with recurrence relation
   - Implement with DP array
   - Optimize to O(1) space
   - Mention time/space complexity

6. Common Mistakes:
   - Forgetting base cases (n=0, n=1)
   - Not handling edge cases
   - Wrong initialization

7. Extension Questions:
   - What if we must rob exactly k houses?
   - What if some houses have alarms?
   - What if we can rob at most k adjacent?

================================================================================
PATTERN: DECISION DP
================================================================================

Template:
```cpp
for each element:
    option1 = include current + dp[i-k]
    option2 = exclude current + dp[i-1]
    dp[i] = best(option1, option2)
```

Similar Problems:
- Can't take adjacent elements
- Choose subset with constraints
- Maximize/minimize with restrictions

================================================================================
*/
