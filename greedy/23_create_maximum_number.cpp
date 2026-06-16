/*
PROBLEM: Create Maximum Number (LeetCode 321)
DIFFICULTY: Hard
PATTERN: Monotonic Stack + Merge Strategy

DESCRIPTION:
You are given two integer arrays nums1 and nums2 of lengths m and n respectively. They 
represent the digits of two numbers. You are also given an integer k.
Create the maximum number of length k <= m + n from digits of the two arrays. The relative 
order of digits from the same array must be preserved.
Return an array of the k digits representing the answer.

INPUT:
- nums1, nums2: two arrays of digits
- k: length of result

OUTPUT:
- Array of k digits forming maximum number

APPROACH:
1. For each split i (take i from nums1, k-i from nums2)
2. Find max subsequence of length i from nums1 (monotonic stack)
3. Find max subsequence of length k-i from nums2
4. Merge these two sequences to form maximum number
5. Keep track of overall maximum

WHY GREEDY WORKS:
Monotonic stack gives maximum subsequence. Greedy merge ensures maximum combined result.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result(k, 0);
        
        // Try all possible splits
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> candidate = merge(
                maxSubsequence(nums1, i),
                maxSubsequence(nums2, k - i)
            );
            if (greater(candidate, 0, result, 0)) {
                result = candidate;
            }
        }
        
        return result;
    }
    
private:
    // Get maximum subsequence of length k from nums using monotonic stack
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int drop = nums.size() - k;  // How many to drop
        vector<int> result;
        
        for (int num : nums) {
            // Remove smaller elements while we can still drop
            while (!result.empty() && result.back() < num && drop > 0) {
                result.pop_back();
                drop--;
            }
            result.push_back(num);
        }
        
        result.resize(k);  // Keep only k elements
        return result;
    }
    
    // Merge two sequences to form maximum number
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() || j < nums2.size()) {
            if (greater(nums1, i, nums2, j)) {
                result.push_back(nums1[i++]);
            } else {
                result.push_back(nums2[j++]);
            }
        }
        
        return result;
    }
    
    // Compare which sequence is greater from given positions
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j >= nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1_1 = {3, 4, 6, 5};
    vector<int> nums2_1 = {9, 1, 2, 5, 8, 3};
    cout << "Test 1 - nums1: [3,4,6,5], nums2: [9,1,2,5,8,3], k=5" << endl;
    cout << "Output: ";
    vector<int> result1 = sol.maxNumber(nums1_1, nums2_1, 5);
    for (int x : result1) cout << x << " ";
    cout << "\nExpected: [9,8,6,5,3]" << endl << endl;
    
    // Test Case 2
    vector<int> nums1_2 = {6, 7};
    vector<int> nums2_2 = {6, 0, 4};
    cout << "Test 2 - nums1: [6,7], nums2: [6,0,4], k=5" << endl;
    cout << "Output: ";
    vector<int> result2 = sol.maxNumber(nums1_2, nums2_2, 5);
    for (int x : result2) cout << x << " ";
    cout << "\nExpected: [6,7,6,0,4]" << endl << endl;
    
    // Test Case 3
    vector<int> nums1_3 = {3, 9};
    vector<int> nums2_3 = {8, 9};
    cout << "Test 3 - nums1: [3,9], nums2: [8,9], k=3" << endl;
    cout << "Output: ";
    vector<int> result3 = sol.maxNumber(nums1_3, nums2_3, 3);
    for (int x : result3) cout << x << " ";
    cout << "\nExpected: [9,8,9]" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(k * (m + n)^2) in worst case
SPACE COMPLEXITY: O(k)

KEY LEARNING:
- Complex greedy: break into subproblems
- Monotonic stack for maximum subsequence
- Greedy merge of two sequences
- Try all valid splits and keep maximum
- Very challenging problem combining multiple patterns
- Tests understanding of greedy + stack + merge
*/
