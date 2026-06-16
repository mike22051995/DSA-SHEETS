/*
PROBLEM: Majority Element
Difficulty: Easy
Pattern: Boyer-Moore Voting Algorithm, Hash Map

DESCRIPTION:
Given an array nums of size n, return the majority element. The majority element is the 
element that appears more than ⌊n / 2⌋ times. You may assume that the majority element 
always exists in the array.

EXPLANATION:
Boyer-Moore Voting Algorithm: Maintain a candidate and a count.
- If count is 0, set current element as candidate
- If current element equals candidate, increment count
- Otherwise, decrement count
The candidate at the end will be the majority element.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [3,2,3]
Output: 3
Explanation: 3 appears twice (more than n/2)

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
Explanation: 2 appears 4 times (more than 7/2)

Example 3:
Input: nums = [1]
Output: 1
Explanation: Single element is the majority
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        // Boyer-Moore Voting Algorithm
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Test 1: " << solution.majorityElement(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test 2: " << solution.majorityElement(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Test 3: " << solution.majorityElement(nums3) << endl;
    
    return 0;
}
