/*
================================================================================
PROBLEM: Wiggle Sort II (LeetCode #324)
DIFFICULTY: Medium
PATTERN: Sorting / Array Manipulation
COMPANIES: Amazon, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int mid = (n + 1) / 2;
        int j = mid - 1;
        int k = n - 1;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--];
            } else {
                nums[i] = sorted[k--];
            }
        }
    }
    
    // Virtual indexing approach - O(n) time, O(1) space
    void wiggleSortOptimized(vector<int>& nums) {
        int n = nums.size();
        
        // Find median
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Map index i to (2*i+1) % (n|1)
        auto mapIndex = [n](int i) { return (2 * i + 1) % (n | 1); };
        
        // Three-way partition
        int i = 0, j = 0, k = n - 1;
        
        while (j <= k) {
            if (nums[mapIndex(j)] > mid) {
                swap(nums[mapIndex(i++)], nums[mapIndex(j++)]);
            } else if (nums[mapIndex(j)] < mid) {
                swap(nums[mapIndex(j)], nums[mapIndex(k--)]);
            } else {
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,5,1,1,6,4};
    vector<int> nums2 = {1,3,2,2,3,1};
    
    sol.wiggleSort(nums1);
    cout << "Wiggle sorted: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;
    
    sol.wiggleSort(nums2);
    cout << "Wiggle sorted: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Wiggle Sort (LeetCode #280)
2. Sort Colors (LeetCode #75)
3. Wiggle Subsequence (LeetCode #376)
4. Kth Largest Element (LeetCode #215)
5. Top K Frequent Elements (LeetCode #347)
6. Find K Pairs with Smallest Sums (LeetCode #373)
7. Sort Array by Parity (LeetCode #905)
8. Partition Array (LeetCode #2161)
9. Rearrange Array Elements by Sign (LeetCode #2149)
10. Maximum Gap (LeetCode #164)
*/
