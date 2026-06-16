/*
================================================================================
PROBLEM: Find All Numbers Disappeared in an Array (LeetCode #448)
DIFFICULTY: Easy
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
    // Using index marking - O(n) time, O(1) space
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
    
    // Cyclic sort approach
    vector<int> findDisappearedNumbersCyclic(vector<int>& nums) {
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
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    vector<int> nums2 = {1,1};
    
    vector<int> result1 = sol.findDisappearedNumbers(nums1);
    cout << "Disappeared numbers: ";
    for (int x : result1) cout << x << " ";
    cout << endl;
    
    vector<int> result2 = sol.findDisappearedNumbers(nums2);
    cout << "Disappeared numbers: ";
    for (int x : result2) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Find All Duplicates in Array (LeetCode #442)
2. Missing Number (LeetCode #268)
3. First Missing Positive (LeetCode #41)
4. Find the Duplicate Number (LeetCode #287)
5. Set Mismatch (LeetCode #645)
6. Single Number (LeetCode #136)
7. Single Number II (LeetCode #137)
8. Array Nesting (LeetCode #565)
9. Couples Holding Hands (LeetCode #765)
10. Missing Ranges (LeetCode #163)
*/
