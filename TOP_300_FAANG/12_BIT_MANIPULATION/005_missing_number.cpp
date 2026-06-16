/*
================================================================================
PROBLEM: Missing Number (LeetCode #268)
DIFFICULTY: Easy
PATTERN: Bit Manipulation / Math
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // XOR approach
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            result ^= i ^ nums[i];
        }
        
        return result;
    }
    
    // Math approach - Gauss formula
    int missingNumberMath(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = accumulate(nums.begin(), nums.end(), 0);
        return expectedSum - actualSum;
    }
    
    // Sorting approach
    int missingNumberSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        
        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3,0,1};
    vector<int> nums2 = {0,1};
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    
    cout << "Missing: " << sol.missingNumber(nums1) << endl;
    cout << "Missing: " << sol.missingNumber(nums2) << endl;
    cout << "Missing: " << sol.missingNumber(nums3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. First Missing Positive (LeetCode #41)
2. Find All Numbers Disappeared (LeetCode #448)
3. Find All Duplicates (LeetCode #442)
4. Find Duplicate Number (LeetCode #287)
5. Single Number (LeetCode #136)
6. Single Number II (LeetCode #137)
7. Single Number III (LeetCode #260)
8. Missing Ranges (LeetCode #163)
9. Set Mismatch (LeetCode #645)
10. Couples Holding Hands (LeetCode #765)
*/
