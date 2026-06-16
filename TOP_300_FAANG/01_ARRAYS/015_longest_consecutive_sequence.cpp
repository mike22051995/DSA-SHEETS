/*
================================================================================
PROBLEM: Longest Consecutive Sequence (LeetCode #128)
DIFFICULTY: Medium
PATTERN: Hash Set / Union Find
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Hash Set Approach - O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : numSet) {
            // Only start counting from sequence start
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentLen = 1;
                
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentLen++;
                }
                
                maxLen = max(maxLen, currentLen);
            }
        }
        
        return maxLen;
    }
    
    // Sorting Approach - O(n log n)
    int longestConsecutiveSort(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        
        int maxLen = 1, currentLen = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue; // Skip duplicates
            } else if (nums[i] == nums[i-1] + 1) {
                currentLen++;
            } else {
                maxLen = max(maxLen, currentLen);
                currentLen = 1;
            }
        }
        
        return max(maxLen, currentLen);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    cout << "Longest consecutive: " << sol.longestConsecutive(nums) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Binary Tree Longest Consecutive Sequence (LeetCode #298)
2. Longest Consecutive Sequence II (Follow-up)
3. Find All Numbers Disappeared (LeetCode #448)
4. First Missing Positive (LeetCode #41)
5. Missing Ranges (LeetCode #163)
6. Longest Arithmetic Subsequence (LeetCode #1027)
7. Arithmetic Slices (LeetCode #413)
8. Maximum Length of Repeated Subarray (LeetCode #718)
9. Longest Mountain in Array (LeetCode #845)
10. Continuous Subarray Sum (LeetCode #523)
*/
