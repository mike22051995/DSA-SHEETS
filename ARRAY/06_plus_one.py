"""
PROBLEM: Plus One
Difficulty: Easy
Pattern: Array Manipulation, Math

DESCRIPTION:
You are given a large integer represented as an integer array digits, where each digits[i] 
is the ith digit of the integer. The digits are ordered from most significant to least 
significant in left-to-right order. Increment the large integer by one and return the 
resulting array of digits.

EXPLANATION:
Start from the last digit and add 1. If there's a carry, propagate it to the left.
If all digits become 0 (carry propagates through all digits), we need to add a new digit 
at the beginning.

Time Complexity: O(n)
Space Complexity: O(1) or O(n) if we need to add a digit

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: 123 + 1 = 124

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: 4321 + 1 = 4322

Example 3:
Input: digits = [9,9,9]
Output: [1,0,0,0]
Explanation: 999 + 1 = 1000
"""

from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            # If digit is less than 9, just increment and return
            if digits[i] < 9:
                digits[i] += 1
                return digits
            # Otherwise, set to 0 and carry over
            digits[i] = 0
        return [1] + digits


if __name__ == "__main__":
    solution = Solution()
    digits1 = [1, 2, 3]
    print(f"Test 1: {solution.plusOne(digits1)}")
    digits2 = [4, 3, 2, 1]
    print(f"Test 2: {solution.plusOne(digits2)}")
    digits3 = [9, 9, 9]
    print(f"Test 3: {solution.plusOne(digits3)}")
    result3 = solution.plusOne(digits3)
    print("Test 3: ")
    printArray(result3)
