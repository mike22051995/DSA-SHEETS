/*
PROBLEM: Longest Consecutive Sequence
Difficulty: Hard
Pattern: Hash Set

DESCRIPTION:
Given an unsorted array of integers nums, return the length of the longest consecutive 
elements sequence. You must write an algorithm that runs in O(n) time.

EXPLANATION:
Use a hash set:
1. Add all numbers to set for O(1) lookup
2. For each number, check if it's the start of a sequence (num-1 not in set)
3. If yes, count consecutive numbers from there
4. Track maximum length

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: Sequence [1,2,3,4] has length 4

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Explanation: Sequence [0,1,2,3,4,5,6,7,8] has length 9

Example 3:
Input: nums = [1,2,0,1]
Output: 3
Explanation: Sequence [0,1,2] has length 3
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        
        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;
                
                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }
                
                maxLength = max(maxLength, currentLength);
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: " << solution.longestConsecutive(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2: " << solution.longestConsecutive(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 0, 1};
    cout << "Test 3: " << solution.longestConsecutive(nums3) << endl;
    
    return 0;
}
