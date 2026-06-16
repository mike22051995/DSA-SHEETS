"""
PROBLEM: Trapping Rain Water (LeetCode 42)
DIFFICULTY: Hard
PATTERN: Stack for Water Trapping

DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of each 
bar is 1, compute how much water it can trap after raining.

INPUT: height = [0,1,0,2,1,0,1,3,2,1,2,1]
OUTPUT: 6
Explanation: 6 units of water can be trapped

INPUT: height = [4,2,0,3,2,5]
OUTPUT: 9

TIME COMPLEXITY: O(n) where n is the length of array
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Stack-based approach: Store indices in stack. When current height > stack top,
we can trap water. Pop and calculate water between current bar and the bar before
popped bar. The trapped water is min(left_height, right_height) - current_height.
"""



from typing import List


def trap(height: List[int]) -> int:
    stack = []
    water = 0
    n = len(height)

    for i in range(n):
        while stack and height[i] > height[stack[-1]]:
            top = stack.pop()
            if not stack:
                break
            distance = i - stack[-1] - 1
            bounded_height = min(height[i], height[stack[-1]]) - height[top]
            water += distance * bounded_height
        stack.append(i)

    return water


def trapTwoPointer(height: List[int]) -> int:
    left, right = 0, len(height) - 1
    left_max = right_max = 0
    water = 0

    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1

    return water


if __name__ == "__main__":
    test_cases = [
        [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],
        [4, 2, 0, 3, 2, 5],
        [3, 0, 2, 0, 4],
        [5, 4, 1, 2],
    ]
    for height in test_cases:
        result1 = trap(height)
        result2 = trapTwoPointer(height)
        print(f"Height: {height}")
        print(f"Water trapped (stack): {result1}")
        print(f"Water trapped (two pointer): {result2}")
        print()
