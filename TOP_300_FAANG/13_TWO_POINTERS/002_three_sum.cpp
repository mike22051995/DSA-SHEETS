/*
================================================================================
PROBLEM: 3Sum (LeetCode #15)
DIFFICULTY: Medium
PATTERN: Two Pointers with Sorting
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for second element
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates for third element
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto result = sol.threeSum(nums);
    
    cout << "3Sum results:" << endl;
    for (auto& triplet : result) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Two Sum (LeetCode #1)
2. 3Sum Closest (LeetCode #16)
3. 4Sum (LeetCode #18)
4. 3Sum Smaller (LeetCode #259)
5. 3Sum With Multiplicity (LeetCode #923)
6. Two Sum II (LeetCode #167)
7. 4Sum II (LeetCode #454)
8. Combination Sum (LeetCode #39)
9. Subarray Sum Equals K (LeetCode #560)
10. Count Pairs With Given Sum (Multiple variants)
*/
