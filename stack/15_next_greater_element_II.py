"""
PROBLEM: Next Greater Element II (LeetCode 503)
DIFFICULTY: Medium
PATTERN: Monotonic Stack with Circular Array

DESCRIPTION:
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] 
is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order 
next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.

INPUT: nums = [1,2,1]
OUTPUT: [2,-1,2]
Explanation: First 1's next greater is 2, 2 has no next greater, second 1's next greater is 2.

TIME COMPLEXITY: O(n) where n is the length of array
SPACE COMPLEXITY: O(n) for the stack and result

EXPLANATION:
To handle circular array, traverse the array twice (or use modulo).
Use monotonic decreasing stack to find next greater elements.
Store indices in stack, and when we find a greater element, pop and record result.
"""



from typing import List


def nextGreaterElements(nums: List[int]) -> List[int]:
    n = len(nums)
    result = [-1] * n
    stack = []  # store indices

    for i in range(2 * n):
        num = nums[i % n]
        while stack and nums[stack[-1]] < num:
            result[stack.pop()] = num
        if i < n:
            stack.append(i)

    return result


if __name__ == "__main__":
    test_cases = [
        [1, 2, 1],
        [1, 2, 3, 4, 3],
        [5, 4, 3, 2, 1],
        [1, 1, 1, 1],
        [3, 8, 4, 1, 2],
    ]
    for nums in test_cases:
        result = nextGreaterElements(nums)
        print(f"Input:                {nums}")
        print(f"Next Greater Elements:{result}")
        print()
