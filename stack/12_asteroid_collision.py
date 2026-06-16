"""
PROBLEM: Asteroid Collision (LeetCode 735)
DIFFICULTY: Medium
PATTERN: Stack for Collision Detection

DESCRIPTION:
We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents 
its direction (positive = right, negative = left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions.

INPUT: asteroids = [5,10,-5]
OUTPUT: [5,10]
Explanation: 10 and -5 collide, -5 explodes. 5 and 10 never collide.

INPUT: asteroids = [8,-8]
OUTPUT: []
Explanation: 8 and -8 collide and both explode.

TIME COMPLEXITY: O(n) where n is the number of asteroids
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to track surviving asteroids. When a right-moving asteroid meets a 
left-moving one, they collide. Compare sizes and destroy the smaller one.
Only right-moving asteroids can collide with future left-moving ones.
"""



from typing import List


def asteroidCollision(asteroids: List[int]) -> List[int]:
    stack = []
    for asteroid in asteroids:
        alive = True
        while alive and asteroid < 0 and stack and stack[-1] > 0:
            if stack[-1] < -asteroid:
                stack.pop()
                continue
            elif stack[-1] == -asteroid:
                stack.pop()
            alive = False
        if alive:
            stack.append(asteroid)
    return stack


if __name__ == "__main__":
    test_cases = [
        [5, 10, -5],
        [8, -8],
        [10, 2, -5],
        [-2, -1, 1, 2],
        [1, -2, -2, -2],
    ]
    for asteroids in test_cases:
        result = asteroidCollision(asteroids)
        print(f"Asteroids:       {asteroids}")
        print(f"After collision: {result}")
        print()
