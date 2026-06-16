/*
================================================================================
PROBLEM: Move Zeroes (LeetCode #283)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroPos = 0;
        
        // Move all non-zero elements to front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroPos++] = nums[i];
            }
        }
        
        // Fill remaining with zeros
        while (nonZeroPos < nums.size()) {
            nums[nonZeroPos++] = 0;
        }
    }
    
    // Swap approach - maintains relative order
    void moveZeroesSwap(vector<int>& nums) {
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    
    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Remove Element (LeetCode #27)
2. Remove Duplicates from Sorted Array (LeetCode #26)
3. Sort Colors (LeetCode #75)
4. Remove Duplicates from Sorted Array II (LeetCode #80)
5. Move All Balls to Same Box (LeetCode #1769)
6. Partition Array (LeetCode #2161)
7. Separate Black and White Balls (LeetCode #2938)
8. Sort Array By Parity (LeetCode #905)
9. Sort Array By Parity II (LeetCode #922)
10. Squares of Sorted Array (LeetCode #977)
*/
