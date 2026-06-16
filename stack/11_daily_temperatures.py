"""
PROBLEM: Daily Temperatures (LeetCode 739)
DIFFICULTY: Medium
PATTERN: Monotonic Stack

DESCRIPTION:
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to 
wait after the ith day to get a warmer temperature. If there is no future day 
for which this is possible, keep answer[i] == 0.

INPUT: temperatures = [73,74,75,71,69,72,76,73]
OUTPUT: [1,1,4,2,1,1,0,0]
Explanation: Day 0: Next warmer is day 1 (1 day), Day 2: Next warmer is day 6 (4 days)

TIME COMPLEXITY: O(n) where n is the number of days
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic decreasing stack to store indices of temperatures.
For each day, pop all indices with lower temperatures and calculate the difference.
The stack maintains indices of temperatures in decreasing order, allowing us to
find the next warmer day efficiently.
"""



from typing import List


def dailyTemperatures(temperatures: List[int]) -> List[int]:
    n = len(temperatures)
    answer = [0] * n
    stack = []  # store indices

    for i in range(n):
        while stack and temperatures[i] > temperatures[stack[-1]]:
            prev_index = stack.pop()
            answer[prev_index] = i - prev_index
        stack.append(i)

    return answer


if __name__ == "__main__":
    test_cases = [
        [73, 74, 75, 71, 69, 72, 76, 73],
        [30, 40, 50, 60],
        [30, 60, 90],
        [89, 62, 70, 58, 47, 47, 46, 76, 100, 70],
    ]
    for temps in test_cases:
        result = dailyTemperatures(temps)
        print(f"Temperatures: {temps}")
        print(f"Days to wait:  {result}")
        print()
