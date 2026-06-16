"""
PROBLEM: Evaluate Reverse Polish Notation (LeetCode 150)
DIFFICULTY: Medium
PATTERN: Stack for Expression Evaluation

DESCRIPTION:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Division between two integers should truncate toward zero.

INPUT: tokens = ["2","1","+","3","*"]
OUTPUT: 9
Explanation: ((2 + 1) * 3) = 9

INPUT: tokens = ["4","13","5","/","+"]
OUTPUT: 6
Explanation: (4 + (13 / 5)) = 6

TIME COMPLEXITY: O(n) where n is the number of tokens
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
In RPN, operators come after operands. Use a stack to store numbers.
When we encounter a number, push it. When we encounter an operator,
pop two operands, apply the operation, and push the result back.
"""



from typing import List
import math


def evalRPN(tokens: List[str]) -> int:
    stack = []
    for token in tokens:
        if token in ('+', '-', '*', '/'):
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            else:
                stack.append(int(a / b))  # truncate toward zero
        else:
            stack.append(int(token))
    return stack[0]


if __name__ == "__main__":
    test_cases = [
        ["2", "1", "+", "3", "*"],
        ["4", "13", "5", "/", "+"],
        ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"],
        ["3", "4", "+", "2", "*", "7", "/"],
        ["18"],
    ]
    for tokens in test_cases:
        result = evalRPN(tokens)
        print(f"Tokens: {tokens}")
        print(f"Result: {result}")
        print()
