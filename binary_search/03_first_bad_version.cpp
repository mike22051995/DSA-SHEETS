/*
PROBLEM: First Bad Version
Difficulty: Easy
Pattern: Binary Search on Answer

DESCRIPTION:
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. Since each version is developed 
based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which 
causes all the following ones to be bad. You are given an API bool isBadVersion(version) which 
returns whether version is bad.

EXPLANATION:
Binary search to find the first bad version:
- If mid is bad, the answer could be mid or earlier
- If mid is good, the answer must be after mid
- Find the leftmost bad version

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation: isBadVersion(3) -> false, isBadVersion(4) -> true

Example 2:
Input: n = 1, bad = 1
Output: 1
Explanation: First version is bad

Example 3:
Input: n = 10, bad = 6
Output: 6
*/

#include <iostream>
using namespace std;

// API provided (simulated here)
int badVersion;
bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                right = mid; // First bad could be mid or earlier
            } else {
                left = mid + 1; // First bad is after mid
            }
        }
        
        return left;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    badVersion = 4;
    cout << "Test 1: " << solution.firstBadVersion(5) << endl;
    
    // Test Case 2
    badVersion = 1;
    cout << "Test 2: " << solution.firstBadVersion(1) << endl;
    
    // Test Case 3
    badVersion = 6;
    cout << "Test 3: " << solution.firstBadVersion(10) << endl;
    
    return 0;
}
