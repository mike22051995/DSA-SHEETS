/*
================================================================================
PROBLEM: 4Sum (LeetCode #18)
DIFFICULTY: Medium
PATTERN: Two Pointers / Sorting
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    cout << "4Sum quadruplets:" << endl;
    for (auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Two Sum (LeetCode #1)
2. Three Sum (LeetCode #15)
3. Three Sum Closest (LeetCode #16)
4. 4Sum II (LeetCode #454)
5. Count Quadruplets (LeetCode #1995)
6. K Sum (Generalized)
7. Combination Sum (LeetCode #39)
8. Target Sum (LeetCode #494)
9. Subarray Sum Equals K (LeetCode #560)
10. Count Pairs With XOR in Range (LeetCode #1803)
*/
