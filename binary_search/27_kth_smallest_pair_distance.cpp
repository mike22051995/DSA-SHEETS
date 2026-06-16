/*
PROBLEM: Find K-th Smallest Pair Distance
Difficulty: Hard
Pattern: Binary Search on Value Range

DESCRIPTION:
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs 
nums[i] and nums[j] where 0 <= i < j < nums.length.

EXPLANATION:
Binary search on distance value:
- Sort the array first
- Min distance = 0, Max distance = max - min
- For each mid, count pairs with distance <= mid using sliding window
- Find smallest distance with at least k pairs

Time Complexity: O(n log n + n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Pairs: (1,3)=2, (1,1)=0, (3,1)=2. 1st smallest is 0

Example 2:
Input: nums = [1,1,1], k = 2
Output: 0
Explanation: All pairs have distance 0

Example 3:
Input: nums = [1,6,1], k = 3
Output: 5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (countPairs(nums, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    int countPairs(vector<int>& nums, int maxDist) {
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > maxDist) {
                left++;
            }
            count += right - left;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1,3,1};
    cout << "Test 1: " << solution.smallestDistancePair(nums1, 1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1,1,1};
    cout << "Test 2: " << solution.smallestDistancePair(nums2, 2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1,6,1};
    cout << "Test 3: " << solution.smallestDistancePair(nums3, 3) << endl;
    
    return 0;
}
