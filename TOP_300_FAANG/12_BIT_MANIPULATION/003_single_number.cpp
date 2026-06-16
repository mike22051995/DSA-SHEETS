/*
================================================================================
PROBLEM: Single Number (LeetCode #136)
DIFFICULTY: Easy
PATTERN: Bit Manipulation (XOR)
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // XOR approach: a ^ a = 0, a ^ 0 = a
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,2,1};
    vector<int> nums2 = {4,1,2,1,2};
    
    cout << "Single number [2,2,1]: " << sol.singleNumber(nums1) << endl;
    cout << "Single number [4,1,2,1,2]: " << sol.singleNumber(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Single Number II (LeetCode #137) - Appears 3 times
2. Single Number III (LeetCode #260) - Two unique
3. Missing Number (LeetCode #268)
4. Find the Duplicate Number (LeetCode #287)
5. Find All Numbers Disappeared (LeetCode #448)
6. Find All Duplicates (LeetCode #442)
7. Set Mismatch (LeetCode #645)
8. XOR Operation in Array (LeetCode #1486)
9. Count Triplets XOR (LeetCode #1442)
10. Decode XORed Array (LeetCode #1720)
*/
