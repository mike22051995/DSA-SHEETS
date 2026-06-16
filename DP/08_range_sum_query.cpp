/*
PROBLEM: Range Sum Query - Immutable
Difficulty: Easy
Pattern: Prefix Sum DP

DESCRIPTION:
Given an integer array nums, handle multiple queries of the following type:
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

INPUT:
nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> -2 + 0 + 3 = 1
sumRange(2, 5) -> 3 + (-5) + 2 + (-1) = -1
sumRange(0, 5) -> -2 + 0 + 3 + (-5) + 2 + (-1) = -3

OUTPUT:
[1, -1, -3]

TIME COMPLEXITY: O(1) per query, O(n) for preprocessing
SPACE COMPLEXITY: O(n) for prefix sum array
*/

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefixSum;
    
public:
    // Constructor: Build prefix sum array
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0);
        
        // prefixSum[i] = sum of elements from index 0 to i-1
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    // Query in O(1) time
    int sumRange(int left, int right) {
        // Sum from left to right = prefixSum[right+1] - prefixSum[left]
        return prefixSum[right + 1] - prefixSum[left];
    }
};

int main() {
    // Test Case
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    
    cout << "Input: nums = [-2, 0, 3, -5, 2, -1]" << endl;
    NumArray numArray(nums);
    
    cout << "sumRange(0, 2) = " << numArray.sumRange(0, 2) << endl;
    cout << "sumRange(2, 5) = " << numArray.sumRange(2, 5) << endl;
    cout << "sumRange(0, 5) = " << numArray.sumRange(0, 5) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Prefix Sum Array:
   - prefixSum[0] = 0
   - prefixSum[i] = sum of elements from index 0 to i-1
   
2. For range [left, right]:
   - Sum = prefixSum[right+1] - prefixSum[left]
   
3. Example: nums = [-2, 0, 3, -5, 2, -1]
   - prefixSum = [0, -2, -2, 1, -4, -2, -3]
   - sumRange(2, 5) = prefixSum[6] - prefixSum[2] = -3 - (-2) = -1

4. Trade-off:
   - O(n) preprocessing time
   - O(1) query time
   - Better than O(n) per query without preprocessing

KEY LEARNING:
- Prefix sum pattern for range queries
- Precompute to optimize repeated queries
- Common in interview problems involving ranges
- Can be extended to 2D arrays (2D prefix sums)
*/
