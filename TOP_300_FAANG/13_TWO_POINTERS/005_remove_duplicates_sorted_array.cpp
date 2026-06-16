/*
================================================================================
PROBLEM: Remove Duplicates from Sorted Array (LeetCode #26)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniquePos = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[uniquePos] = nums[i];
                uniquePos++;
            }
        }
        
        return uniquePos;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    
    int k = sol.removeDuplicates(nums);
    
    cout << "Unique elements: " << k << endl;
    cout << "Array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Remove Duplicates from Sorted Array II (LeetCode #80)
2. Remove Element (LeetCode #27)
3. Move Zeroes (LeetCode #283)
4. Remove Duplicates from Sorted List (LeetCode #83)
5. Remove Duplicates from Sorted List II (LeetCode #82)
6. Remove All Adjacent Duplicates (LeetCode #1047)
7. Remove All Adjacent Duplicates II (LeetCode #1209)
8. Sort Colors (LeetCode #75)
9. Partition Array (LeetCode #2161)
10. Sort Array By Parity (LeetCode #905)
*/
