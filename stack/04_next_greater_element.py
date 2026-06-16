"""
PROBLEM: Next Greater Element I (LeetCode 496)
DIFFICULTY: Easy
PATTERN: Monotonic Stack

DESCRIPTION:
You are given two arrays (without duplicates) nums1 and nums2 where nums1's elements 
are subset of nums2. Find all the next greater numbers for nums1's elements in nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its 
right in nums2. If it does not exist, output -1 for this number.

INPUT: nums1 = [4,1,2], nums2 = [1,3,4,2]
OUTPUT: [-1,3,-1]
Explanation:
For 4: No next greater element -> -1
For 1: Next greater is 3
For 2: No next greater element -> -1

TIME COMPLEXITY: O(n + m) where n = len(nums2), m = len(nums1)
SPACE COMPLEXITY: O(n) for hashmap and stack

EXPLANATION:
Use a monotonic decreasing stack to find next greater elements in nums2.
Store the results in a hashmap. Then lookup each element of nums1 in the hashmap.
The stack maintains elements in decreasing order, and when we find a larger element,
we pop and record the next greater element.
"""


from typing import List


def nextGreaterElement(nums1: List[int], nums2: List[int]) -> List[int]:
    next_greater = {}
    stack = []

    for i in range(len(nums2) - 1, -1, -1):
        num = nums2[i]
        while stack and stack[-1] <= num:
            stack.pop()
        next_greater[num] = stack[-1] if stack else -1
        stack.append(num)

    return [next_greater[n] for n in nums1]


if __name__ == "__main__":
    nums1 = [4, 1, 2]
    nums2 = [1, 3, 4, 2]
    print(f"nums1: {nums1}")
    print(f"nums2: {nums2}")
    print(f"Next Greater Elements: {nextGreaterElement(nums1, nums2)}")

    print("\nTest case 2:")
    nums3 = [2, 4]
    nums4 = [1, 2, 3, 4]
    print(f"nums1: {nums3}")
    print(f"nums2: {nums4}")
    print(f"Next Greater Elements: {nextGreaterElement(nums3, nums4)}")
