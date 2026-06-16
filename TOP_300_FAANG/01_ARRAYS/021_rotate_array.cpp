/*
================================================================================
PROBLEM: Rotate Array (LeetCode #189)
DIFFICULTY: Medium
PATTERN: Array Manipulation
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Reverse approach - O(n) time, O(1) space
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    
    // Cyclic replacement
    void rotateCyclic(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;
        
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,4,5,6,7};
    vector<int> nums2 = {-1,-100,3,99};
    
    sol.rotate(nums1, 3);
    cout << "Rotated by 3: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    
    sol.rotate(nums2, 2);
    cout << "Rotated by 2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Rotate Image (LeetCode #48)
2. Reverse String (LeetCode #344)
3. Rotate List (LeetCode #61)
4. Reverse Words in String (LeetCode #151)
5. Reverse String II (LeetCode #541)
6. Rotate Function (LeetCode #396)
7. K-Concatenation Maximum Sum (LeetCode #1191)
8. Circular Array Loop (LeetCode #457)
9. Maximum Swap (LeetCode #670)
10. Minimum Swaps to Group All 1's Together (LeetCode #1151)
*/
