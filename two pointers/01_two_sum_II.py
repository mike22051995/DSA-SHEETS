"""
PROBLEM: Two Sum II - Input Array Is Sorted
---------------------------------------------------------------------------
Given a 1-indexed array of integers that is already sorted in non-decreasing 
order, find two numbers such that they add up to a specific target number.
Return the indices of the two numbers (1-indexed) as an integer array.

You must use only constant extra space.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2.

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore, index1 = 1, index2 = 3.
"""

from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        while left < right:
            s = numbers[left] + numbers[right]
            if s == target:
                return [left + 1, right + 1]
            elif s < target:
                left += 1
            else:
                right -= 1

        return [-1, -1]


if __name__ == "__main__":
    sol = Solution()
    numbers1 = [2, 7, 11, 15]
    target1 = 9
    result1 = sol.twoSum(numbers1, target1)
    print(f"Test 1: {result1}")
    numbers2 = [2, 3, 4]
    target2 = 6
    result2 = sol.twoSum(numbers2, target2)
    print(f"Test 2: {result2}")
