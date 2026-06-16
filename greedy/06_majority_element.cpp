/*
PROBLEM: Majority Element (Boyer-Moore Voting Algorithm) (LeetCode 169)
DIFFICULTY: Easy
PATTERN: Voting/Cancellation Strategy

DESCRIPTION:
Given an array nums of size n, return the majority element. The majority element is 
the element that appears more than ⌊n/2⌋ times. You may assume that the majority 
element always exists in the array.

INPUT:
- nums: array of integers

OUTPUT:
- The majority element

APPROACH (Boyer-Moore Voting Algorithm):
1. Maintain a candidate and count
2. When count is 0, pick current element as candidate
3. If current element matches candidate, increment count; otherwise decrement
4. Greedy insight: pairs of different elements cancel out

WHY GREEDY WORKS:
Since majority element appears >n/2 times, after all cancellations, 
it will survive as the candidate.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        // Phase 1: Find candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;  // New candidate
            }
            
            // Vote for or against current candidate
            if (num == candidate) {
                count++;
            } else {
                count--;  // Cancellation
            }
        }
        
        // Phase 2: Verify (not needed if majority always exists)
        // Uncomment if verification is required
        /*
        count = 0;
        for (int num : nums) {
            if (num == candidate) count++;
        }
        return (count > nums.size() / 2) ? candidate : -1;
        */
        
        return candidate;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Test 1 - Array: [3,2,3]" << endl;
    cout << "Output: " << sol.majorityElement(nums1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Test 2 - Array: [2,2,1,1,1,2,2]" << endl;
    cout << "Output: " << sol.majorityElement(nums2) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Test 3 - Array: [1]" << endl;
    cout << "Output: " << sol.majorityElement(nums3) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 4
    vector<int> nums4 = {6, 5, 5};
    cout << "Test 4 - Array: [6,5,5]" << endl;
    cout << "Output: " << sol.majorityElement(nums4) << endl;
    cout << "Expected: 5" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is array size
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Voting algorithm: powerful greedy technique for finding majority
- Cancellation strategy: pairs of different elements eliminate each other
- Works only when majority element is guaranteed to exist (>n/2 occurrences)
- Can be extended to find elements appearing >n/3 times (with 2 candidates)
- Much more efficient than sorting O(n log n) or hash map O(n) space solutions
*/
