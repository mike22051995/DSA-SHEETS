/*
================================================================================
PROBLEM: 3Sum Closest (LeetCode #16)
DIFFICULTY: Medium
PATTERN: Two Pointers
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return target;
                }
            }
        }
        
        return closestSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-1,2,1,-4};
    vector<int> nums2 = {0,0,0};
    
    cout << "Closest sum to 1: " << sol.threeSumClosest(nums1, 1) << endl;
    cout << "Closest sum to 1: " << sol.threeSumClosest(nums2, 1) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Two Sum (LeetCode #1)
2. Three Sum (LeetCode #15)
3. Three Sum Smaller (LeetCode #259)
4. 4Sum (LeetCode #18)
5. Two Sum Less Than K (LeetCode #1099)
6. Minimum Absolute Difference (LeetCode #1200)
7. Find K Closest Elements (LeetCode #658)
8. K Closest Points to Origin (LeetCode #973)
9. Closest Subsequence Sum (LeetCode #1755)
10. Minimum Difference in Sums (LeetCode #2163)
*/
