/*
PROBLEM: Single Number II (Element Appearing Once, Others Thrice)
===================================================================
Given an array where every element appears three times except one 
which appears once, find that single element.

APPROACH:
- Count bits at each position for all numbers
- If a bit count is divisible by 3, the single number has 0 at that position
- Otherwise, it has 1 at that position
- Reconstruct the number from bit counts

PATTERN: Bit Counting - Advanced XOR Variation

INPUT/OUTPUT:
Input: nums = [2,2,3,2]
Output: 3
Explanation: 2 appears 3 times, 3 appears once

Input: nums = [0,1,0,1,0,1,99]
Output: 99

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // Check each bit position (32 bits for int)
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            // Count how many numbers have bit set at position i
            for (int num : nums) {
                if ((num >> i) & 1) {
                    bitCount++;
                }
            }
            // If count is not divisible by 3, set this bit in result
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
    
    // Alternative using ones and twos variables
    int singleNumberOptimized(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            twos |= (ones & num);
            ones ^= num;
            int threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 2, 3, 2};
    cout << "Input: [2,2,3,2]" << endl;
    cout << "Output: " << sol.singleNumber(nums1) << endl;
    cout << "Explanation: 2 appears 3 times, 3 once" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "Input: [0,1,0,1,0,1,99]" << endl;
    cout << "Output: " << sol.singleNumber(nums2) << endl;
    cout << "Explanation: 0 and 1 appear 3 times, 99 once" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {-2, -2, 1, 1, 4, 1, 4, 4, -2};
    cout << "Input: [-2,-2,1,1,4,1,4,4,-2]" << endl;
    cout << "Output: " << sol.singleNumber(nums3) << endl;
    cout << "Explanation: Works with negative numbers too" << endl;
    
    return 0;
}
