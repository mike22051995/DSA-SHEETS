/*
================================================================================
PROBLEM: Contains Duplicate (LeetCode #217)
DIFFICULTY: Easy
PATTERN: Hash Set / Sorting
COMPANIES: Amazon, Google, Microsoft, Apple, Adobe
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums, return true if any value appears at least twice 
in the array, and return false if every element is distinct.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. You need to detect duplicates in an array
2. You need to track "seen" elements
3. Problem asks about uniqueness or distinctness
4. Need O(n) time with O(n) space trade-off

Key Indicators:
- "Contains duplicate" or "unique elements"
- Need to check if element appeared before
- Set operations (membership testing)
- Distinctness validation

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation: Element 1 appears at index 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
Explanation: Multiple duplicates exist.

================================================================================
EXPLANATION:

Approach 1 - Hash Set (Optimal for most cases):
- Use a hash set to track seen elements
- For each element, check if it's in set
- If yes, return true (duplicate found)
- If no, add to set and continue
Time: O(n), Space: O(n)

Approach 2 - Sorting:
- Sort the array first
- Check adjacent elements for duplicates
- If any two adjacent elements are equal, return true
Time: O(n log n), Space: O(1) or O(n) depending on sort

Approach 3 - Brute Force:
- Compare every pair of elements
- Time: O(n²), Space: O(1)

================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Hash Set (Optimal)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            // If element already exists in set, we found a duplicate
            if (seen.count(num) > 0) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
    
    // Approach 2: Sorting
    bool containsDuplicateSorting(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        
        sort(nums.begin(), nums.end());
        
        // Check adjacent elements
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        
        return false;
    }
    
    // Approach 3: Using set size comparison
    bool containsDuplicateSetSize(vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        return uniqueNums.size() < nums.size();
    }
    
    // Approach 4: Brute Force
    bool containsDuplicateBruteForce(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

void runTest(vector<int> nums, string testName) {
    Solution sol;
    bool result = sol.containsDuplicate(nums);
    
    cout << testName << ": ";
    cout << "nums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Contains Duplicate: " << (result ? "true" : "false") << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    runTest(nums1, "Test 1");
    
    vector<int> nums2 = {1, 2, 3, 4};
    runTest(nums2, "Test 2");
    
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    runTest(nums3, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Contains Duplicate II (LeetCode #219) - Easy
   - Find duplicates within distance k
   - Use sliding window with hash set

2. Contains Duplicate III (LeetCode #220) - Hard
   - Value difference ≤ t and index difference ≤ k
   - Use bucket sort or balanced BST

3. Find All Duplicates in an Array (LeetCode #442) - Medium
   - Array elements in range [1, n]
   - Can use array indexing trick

4. Find the Duplicate Number (LeetCode #287) - Medium
   - Only one duplicate, may repeat multiple times
   - Floyd's cycle detection

5. Single Number (LeetCode #136) - Easy
   - All duplicates except one
   - Use XOR operation

6. First Missing Positive (LeetCode #41) - Hard
   - Find missing positive integer
   - In-place hash approach

7. Remove Duplicates from Sorted Array (LeetCode #26) - Easy
   - Two pointers approach

8. Intersection of Two Arrays (LeetCode #349) - Easy
   - Find common elements using sets

9. Intersection of Two Arrays II (LeetCode #350) - Easy
   - With frequency consideration

10. Happy Number (LeetCode #202) - Easy
    - Detect cycle using hash set

================================================================================
*/
