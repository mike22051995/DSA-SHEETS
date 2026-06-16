/*
================================================================================
PROBLEM: First Missing Positive (LeetCode #41)
DIFFICULTY: Hard
PATTERN: Array / Hash Table
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Place each number in its right place
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,0};
    vector<int> nums2 = {3,4,-1,1};
    vector<int> nums3 = {7,8,9,11,12};
    
    cout << "First missing positive: " << sol.firstMissingPositive(nums1) << endl;
    cout << "First missing positive: " << sol.firstMissingPositive(nums2) << endl;
    cout << "First missing positive: " << sol.firstMissingPositive(nums3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Missing Number (LeetCode #268)
2. Find All Numbers Disappeared (LeetCode #448)
3. Find All Duplicates (LeetCode #442)
4. Find Duplicate Number (LeetCode #287)
5. Couples Holding Hands (LeetCode #765)
6. Missing Ranges (LeetCode #163)
7. Set Mismatch (LeetCode #645)
8. Smallest Missing Integer (LeetCode #2598)
9. Minimum Number of Operations (LeetCode #2557)
10. Maximum Gap (LeetCode #164)
*/
