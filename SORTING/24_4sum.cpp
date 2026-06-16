/*
PROBLEM: 4Sum (LeetCode 18)
===============================================
DESCRIPTION:
Given an array nums of n integers, return all unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

PATTERN: Sorting + Two Pointer (Extended 3Sum)
DIFFICULTY: Medium
TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(1) excluding output

INPUT:
Array of integers and target sum

OUTPUT:
List of quadruplets that sum to target

EXAMPLE:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
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
        
        // Sort array
        sort(nums.begin(), nums.end());
        
        // Fix first two elements, use two pointers for remaining two
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                // Use long long to avoid overflow
                long long twoSum = (long long)target - nums[i] - nums[j];
                
                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right];
                    
                    if (sum == twoSum) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < twoSum) {
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
    
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nTarget: " << target1 << endl;
    
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    cout << "Output:" << endl;
    for (auto& quad : result1) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nTarget: " << target2 << endl;
    
    vector<vector<int>> result2 = sol.fourSum(nums2, target2);
    cout << "Output:" << endl;
    for (auto& quad : result2) {
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
EXPLANATION:
============
ALGORITHM:
1. Sort the array
2. Fix first element (i)
3. Fix second element (j)
4. Use two pointers (left, right) for remaining two elements
5. Skip duplicates at all levels

STRUCTURE:
for i:           O(n)
  for j:         O(n)
    two pointers: O(n)
Total: O(n³)

RELATIONSHIP TO 3SUM:
- 3Sum: Fix 1 element, use 2 pointers → O(n²)
- 4Sum: Fix 2 elements, use 2 pointers → O(n³)
- kSum: Fix k-2 elements, use 2 pointers → O(n^(k-1))

TWO SUM CALCULATION:
After fixing nums[i] and nums[j]:
target = nums[i] + nums[j] + nums[left] + nums[right]
twoSum = target - nums[i] - nums[j]
Find: nums[left] + nums[right] = twoSum

OVERFLOW HANDLING:
Use long long for intermediate calculations:
- target can be large
- Sum of four integers can overflow int
- Convert to long long before operations

DUPLICATE HANDLING:
Level 1 (i): if (i > 0 && nums[i] == nums[i-1]) continue
Level 2 (j): if (j > i+1 && nums[j] == nums[j-1]) continue
Level 3 (left): while (nums[left] == nums[left+1]) left++
Level 4 (right): while (nums[right] == nums[right-1]) right--

EXAMPLE WALKTHROUGH:
Input: [1,0,-1,0,-2,2], target = 0
After sort: [-2,-1,0,0,1,2]

i=0(-2), j=1(-1), twoSum=3:
  left=2(0), right=5(2): sum=2 < 3, left++
  left=3(0), right=5(2): sum=2 < 3, left++
  left=4(1), right=5(2): sum=3 == 3 ✓ → [-2,-1,1,2]

i=0(-2), j=2(0), twoSum=2:
  left=3(0), right=5(2): sum=2 == 2 ✓ → [-2,0,0,2]

... and so on

OPTIMIZATIONS:
1. Early pruning (optional)
2. Skip duplicates immediately
3. Use long long to avoid overflow
4. Break early when remaining elements too large

WHY THIS PATTERN IS IMPORTANT:
- Extension of 3Sum pattern
- Demonstrates nested two-pointer approach
- Common in sum problems
- Shows generalization to kSum
- Important for understanding time complexity progression
- Frequent in interviews (Google, Facebook, Amazon)
*/
