/*
================================================================================
PROBLEM: Remove Element (LeetCode #27)
DIFFICULTY: Easy
PATTERN: Two Pointers
COMPANIES: Amazon, Microsoft, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
    
    // Two pointers from both ends
    int removeElementTwoPointers(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                right--;
            } else {
                left++;
            }
        }
        
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    
    int k = sol.removeElement(nums, val);
    
    cout << "Length after removal: " << k << endl;
    cout << "Array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Remove Duplicates from Sorted Array (LeetCode #26)
2. Move Zeroes (LeetCode #283)
3. Remove All Adjacent Duplicates (LeetCode #1047)
4. Remove All Occurrences of Substring (LeetCode #1910)
5. Remove Nth Node From End (LeetCode #19)
6. Delete Node in Linked List (LeetCode #237)
7. Remove Linked List Elements (LeetCode #203)
8. Remove Palindromic Subsequences (LeetCode #1332)
9. Remove Covered Intervals (LeetCode #1288)
10. Remove Boxes (LeetCode #546)
*/
