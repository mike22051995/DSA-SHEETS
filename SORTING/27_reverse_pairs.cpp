/*
PROBLEM: Reverse Pairs (LeetCode 493)
===============================================
DESCRIPTION:
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
- 0 <= i < j < nums.length
- nums[i] > 2 * nums[j]

PATTERN: Modified Merge Sort
DIFFICULTY: Hard
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Count of reverse pairs

EXAMPLE:
Input: [1,3,2,3,1]
Output: 2
Explanation: (3,1) and (3,1) → 3 > 2*1

Input: [2,4,3,5,1]
Output: 3
Explanation: (2,1), (4,1), (3,1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        
        // Count in left and right halves
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        // Count cross pairs
        count += countPairs(nums, left, mid, right);
        
        // Merge
        merge(nums, left, mid, right);
        
        return count;
    }
    
    int countPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // For each element in left half
        for (int i = left; i <= mid; i++) {
            // Find elements in right half where nums[i] > 2 * nums[j]
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        return count;
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);
        
        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 3, 2, 3, 1};
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    cout << "Reverse pairs: " << sol.reversePairs(nums1) << endl;
    
    vector<int> nums2 = {2, 4, 3, 5, 1};
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    cout << "Reverse pairs: " << sol.reversePairs(nums2) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
PROBLEM STATEMENT:
Find pairs (i,j) where i < j and nums[i] > 2 * nums[j]

NAIVE APPROACH: O(n²)
Check all pairs - too slow for large inputs

OPTIMIZED APPROACH: Modified Merge Sort
Key insight: When array is divided, count:
1. Pairs within left half
2. Pairs within right half
3. Cross pairs (one from left, one from right)

WHY MERGE SORT HELPS:
- After sorting subarrays, counting cross pairs becomes efficient
- For each element in left half, find valid elements in right half
- Both halves are sorted, use two pointers

COUNTING CROSS PAIRS:
For sorted left [left...mid] and right [mid+1...right]:
1. For each nums[i] in left half
2. Find how many nums[j] in right satisfy nums[i] > 2 * nums[j]
3. Since both sorted, if nums[i] > 2*nums[j], then:
   - All elements left[0...i] also satisfy (they're >= nums[i])
   - All elements right[0...j] also satisfy condition

ALGORITHM STEPS:
1. Divide array into two halves
2. Recursively count in left half
3. Recursively count in right half
4. Count cross pairs between sorted halves
5. Merge the two sorted halves

EXAMPLE WALKTHROUGH:
Input: [2, 4, 3, 5, 1]

Initial split: [2,4,3] | [5,1]

Left [2,4,3]:
  Split: [2] | [4,3]
  Right [4,3]: Split [4] | [3]
  Merge [4,3] → [3,4], count pairs
  Merge [2] and [3,4] → [2,3,4]

Right [5,1]:
  Split: [5] | [1]
  Cross pairs: 5 > 2*1 → count = 1
  Merge [5,1] → [1,5]

Final merge [2,3,4] and [1,5]:
Cross pairs:
- 2 > 2*1 (2>2)? No
- 3 > 2*1 (3>2)? Yes → count++
- 4 > 2*1 (4>2)? Yes → count++

Total count = 3

IMPORTANT DETAILS:
1. Count pairs BEFORE merging (need sorted halves)
2. Use 2LL to avoid integer overflow
3. Merge step is standard merge sort
4. Two-pointer technique for counting (both arrays sorted)

OVERFLOW HANDLING:
nums[i] > 2 * nums[j]
Use: nums[i] > 2LL * nums[j]
The LL suffix makes 2 a long long, preventing overflow

TIME COMPLEXITY:
T(n) = 2T(n/2) + O(n)
- 2T(n/2): recursive calls
- O(n): counting + merging
Result: O(n log n)

WHY THIS PATTERN IS IMPORTANT:
- Classic application of divide and conquer
- Shows how to count inversions with modifications
- Similar to: Count smaller after self, inversion count
- Tests understanding of merge sort modifications
- Common in advanced sorting problems
- Appears in competitive programming
- Asked at top companies (Google, Facebook, Microsoft)
*/
