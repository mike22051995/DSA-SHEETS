/*
================================================================================
PROBLEM: Next Permutation (LeetCode #31)
DIFFICULTY: Medium
PATTERN: Array Manipulation
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Find element just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {3,2,1};
    vector<int> nums3 = {1,1,5};
    
    sol.nextPermutation(nums1);
    cout << "Next permutation: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    sol.nextPermutation(nums2);
    cout << "Next permutation: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    sol.nextPermutation(nums3);
    cout << "Next permutation: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Permutations (LeetCode #46)
2. Permutations II (LeetCode #47)
3. Permutation Sequence (LeetCode #60)
4. Previous Permutation With One Swap (LeetCode #1053)
5. Next Greater Element III (LeetCode #556)
6. Minimum Adjacent Swaps (LeetCode #1850)
7. Reverse String (LeetCode #344)
8. Rotate Array (LeetCode #189)
9. Palindrome Permutation (LeetCode #266)
10. Palindrome Permutation II (LeetCode #267)
*/
