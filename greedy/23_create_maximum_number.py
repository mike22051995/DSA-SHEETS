"""
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
"""

from typing import List, Optional

class Solution:
    def for(self, max(0, min(k, i++):
        public:
        maxNumber(vector<int>& nums1, vector<int>& nums2, int k):
        m = len(nums1), n = len(nums2)
        result(k, 0)
        # Try all possible splits
        for i in range(max(0, k - n), = min(k, m)):
        candidate = merge(
        maxSubsequence(nums1, i),
        maxSubsequence(nums2, k - i)
        )
        if (greater(candidate, 0, result, 0)):
        result = candidate
        return result
        private:
        # Get maximum subsequence of length k from nums using monotonic stack
        maxSubsequence(vector<int>& nums, int k):
        drop = len(nums) - k;  # How many to drop
        result
        for num in nums:
        # Remove smaller elements while we can still drop
        while (!not result and result.back() < num and drop > 0):
        result.pop_back()
        drop -= 1
        result.append(num)
        result.resize(k);  # Keep only k elements
        return result
        # Merge two sequences to form maximum number
        merge(nums1, nums2):
        result
        i = 0, j = 0
        while (i < len(nums1) or j < len(nums2)):
        if (greater(nums1, i, nums2, j)):
        result.append(nums1[i++])
        } else 
        result.append(nums2[j++])
        return result
        # Compare which sequence is greater from given positions
        bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j):
        while (i < len(nums1) and j < len(nums2) and nums1[i] == nums2[j]):
        i += 1
        j += 1
        return j >= len(nums2) or (i < len(nums1) and nums1[i] > nums2[j])


if __name__ == "__main__":
    sol = Solution()
    nums1_1 = [3, 4, 6, 5]
    nums2_1 = [9, 1, 2, 5, 8, 3]
    print(f"Test 1 - nums1: [3,4,6,5], nums2: [9,1,2,5,8,3], k=5")
    print("Output: ")
    result1 = sol.maxNumber(nums1_1, nums2_1, 5)
    for (int x : result1) print(x, end=" ")
    print(f"\nExpected: [9,8,6,5,3]")
    nums1_2 = [6, 7]
    nums2_2 = [6, 0, 4]
    print(f"Test 2 - nums1: [6,7], nums2: [6,0,4], k=5")
    print("Output: ")
    result2 = sol.maxNumber(nums1_2, nums2_2, 5)
    for (int x : result2) print(x, end=" ")
    print(f"\nExpected: [6,7,6,0,4]")
    nums1_3 = [3, 9]
    nums2_3 = [8, 9]
    print(f"Test 3 - nums1: [3,9], nums2: [8,9], k=3")
    print("Output: ")
    result3 = sol.maxNumber(nums1_3, nums2_3, 3)
    for (int x : result3) print(x, end=" ")
    print(f"\nExpected: [9,8,9]")
