"""
PROBLEM: Basic Calculator II (LeetCode 227)
DIFFICULTY: Hard/Medium
PATTERN: Stack for Operator Precedence

DESCRIPTION:
Given a string s which represents an expression, evaluate this expression and return its value.
The expression contains:
- Non-negative integers
- '+', '-', '*', '/' operators
- Spaces ' '

INPUT: s = "3+2*2"
OUTPUT: 7

INPUT: s = " 3/2 "
OUTPUT: 1

INPUT: s = " 3+5 / 2 "
OUTPUT: 5

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Process operators based on precedence. Use a stack to store intermediate results.
For '+' and '-', push to stack with appropriate sign.
For '*' and '/', immediately pop and compute, then push result.
Finally, sum all elements in stack.
"""



def calculate(s: str) -> int:
    stack = []
    number = 0
    operation = '+'

    for i, c in enumerate(s):
        if c.isdigit():
            number = number * 10 + int(c)

        if (not c.isdigit() and c != ' ') or i == len(s) - 1:
            if operation == '+':
                stack.append(number)
            elif operation == '-':
                stack.append(-number)
            elif operation == '*':
                stack.append(stack.pop() * number)
            elif operation == '/':
                stack.append(int(stack.pop() / number))  # truncate toward zero
            operation = c
            number = 0

    return sum(stack)


if __name__ == "__main__":
    test_cases = [
        "3+2*2",
        " 3/2 ",
        " 3+5 / 2 ",
        "42",
        "1-1+1",
        "14-3/2",
        "100000000/1/2/3/4/5/6/7/8/9/10",
    ]
    for test in test_cases:
        result = calculate(test)
        print(f'Expression: "{test}"')
        print(f"Result: {result}")
        print()
