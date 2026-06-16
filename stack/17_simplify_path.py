"""
PROBLEM: Simplify Path (LeetCode 71)
DIFFICULTY: Medium
PATTERN: Stack for Path Processing

DESCRIPTION:
Given an absolute path for a Unix-style file system, simplify it.
Rules:
- "." refers to current directory
- ".." refers to parent directory
- Multiple consecutive slashes should be treated as a single slash
- The path must start with "/"
- The path must not end with "/" unless it is the root

INPUT: path = "/home/"
OUTPUT: "/home"

INPUT: path = "/../"
OUTPUT: "/"

INPUT: path = "/home#foo/"
OUTPUT: "/home/foo"

TIME COMPLEXITY: O(n) where n is the length of path
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Split the path by '/' and process each component:
- If empty or ".", skip
- If "..", pop from stack (if not empty)
- Otherwise, push to stack
Finally, join stack elements with '/' to form simplified path.
"""


def simplifyPath(path: str) -> str:
    stack = []
    for component in path.split('/'):
        if component == '' or component == '.':
            continue
        elif component == '..':
            if stack:
                stack.pop()
        else:
            stack.append(component)
    return '/' + '/'.join(stack)


if __name__ == "__main__":
    test_cases = [
        "/home/",
        "/../",
        "/home//foo/",
        "/a/./b/../../c/",
        "/a/../../b/../c//.//",
        "/a//b////c/d//././/..",
        "/",
    ]
    for test in test_cases:
        result = simplifyPath(test)
        print(f'Input:  "{test}"')
        print(f'Output: "{result}"')
        print()
