d/*
PROBLEM: Sqrt(x)
Difficulty: Easy
Pattern: Binary Search on Answer

DESCRIPTION:
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer 
part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator.

EXPLANATION:
Binary search for the answer:
- Search space is [0, x]
- For each mid, check if mid * mid <= x
- Find the largest such mid
- Handle overflow by using mid <= x / mid instead of mid * mid <= x

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: x = 4
Output: 2
Explanation: sqrt(4) = 2

Example 2:
Input: x = 8
Output: 2
Explanation: sqrt(8) = 2.828..., truncate to 2

Example 3:
Input: x = 1
Output: 1
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int left = 1;
        int right = x;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use mid <= x / mid to avoid overflow
            if (mid <= x / mid) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    cout << "Test 1: " << solution.mySqrt(4) << endl;
    
    // Test Case 2
    cout << "Test 2: " << solution.mySqrt(8) << endl;
    
    // Test Case 3
    cout << "Test 3: " << solution.mySqrt(1) << endl;
    
    return 0;
}
