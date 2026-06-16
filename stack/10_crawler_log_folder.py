"""
PROBLEM: Crawler Log Folder (LeetCode 1598)
DIFFICULTY: Easy
PATTERN: Stack for Navigation/Path Tracking

DESCRIPTION:
The Leetcode file system keeps a log each time some user performs a change folder operation.
Operations are described below:
- "../" : Move to the parent folder (if at main, remain)
- "./" : Remain in the same folder
- "x/" : Move to the child folder named x

Given logs of operations, return minimum number of operations needed to go back to main folder.

INPUT: logs = ["d1/","d2/","../","d21/","./"]
OUTPUT: 2
Explanation: cd d1/ -> cd d2/ -> cd ../ (back to d1/) -> cd d21/ -> ./ (stay)
Need to go back 2 levels: d1/d21/ -> d1/ -> main/

TIME COMPLEXITY: O(n) where n is number of operations
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack (or counter) to track depth. "../" pops from stack, "./" does nothing,
any other operation pushes to stack. Final stack size is the answer.
"""



from typing import List


def minOperations(logs: List[str]) -> int:
    stack = []
    for op in logs:
        if op == "../":
            if stack:
                stack.pop()
        elif op == "./":
            continue
        else:
            stack.append(op)
    return len(stack)


def minOperationsOptimized(logs: List[str]) -> int:
    depth = 0
    for op in logs:
        if op == "../":
            depth = max(0, depth - 1)
        elif op != "./":
            depth += 1
    return depth


if __name__ == "__main__":
    test_cases = [
        ["d1/", "d2/", "../", "d21/", "./"],
        ["d1/", "d2/", "./", "d3/", "../", "../"],
        ["d1/", "../", "../", "../"],
        ["./", "../", "./"],
    ]
    for logs in test_cases:
        print(f"Logs: {logs}")
        result1 = minOperations(logs)
        result2 = minOperationsOptimized(logs)
        print(f"Min operations (stack): {result1}")
        print(f"Min operations (optimized): {result2}")
        print()
