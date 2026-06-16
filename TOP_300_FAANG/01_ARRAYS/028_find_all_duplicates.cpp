/*
================================================================================
PROBLEM: Find All Duplicates in an Array (LeetCode #442)
DIFFICULTY: Medium
PATTERN: Array Manipulation / Cyclic Sort
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Using array indexing - O(n) time, O(1) space
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            
            if (nums[idx] < 0) {
                result.push_back(abs(nums[i]));
            } else {
                nums[idx] = -nums[idx];
            }
        }
        
        return result;
    }
    
    // Cyclic sort approach
    vector<int> findDuplicatesCyclic(vector<int>& nums) {
        int i = 0;
        
        while (i < nums.size()) {
            int correctIdx = nums[i] - 1;
            
            if (nums[i] != nums[correctIdx]) {
                swap(nums[i], nums[correctIdx]);
            } else {
                i++;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                result.push_back(nums[i]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    vector<int> nums2 = {1,1,2};
    
    vector<int> result1 = sol.findDuplicates(nums1);
    cout << "Duplicates: ";
    for (int x : result1) cout << x << " ";
    cout << endl;
    
    vector<int> result2 = sol.findDuplicates(nums2);
    cout << "Duplicates: ";
    for (int x : result2) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Find All Numbers Disappeared (LeetCode #448)
2. Find the Duplicate Number (LeetCode #287)
3. Missing Number (LeetCode #268)
4. First Missing Positive (LeetCode #41)
5. Single Number (LeetCode #136)
6. Single Number II (LeetCode #137)
7. Single Number III (LeetCode #260)
8. Set Mismatch (LeetCode #645)
9. Majority Element (LeetCode #169)
10. Array Nesting (LeetCode #565)
*/
