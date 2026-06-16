"""
PROBLEM: Basic Calculator (LeetCode 224)
DIFFICULTY: Hard
PATTERN: Stack for Expression Parsing

DESCRIPTION:
Given a string s representing a valid expression, implement a basic calculator to evaluate it.
The expression may contain:
- Non-negative integers
- '+', '-' operators
- '(', ')' parentheses
- Spaces ' '

INPUT: s = "1 + 1"
OUTPUT: 2

INPUT: s = " 2-1 + 2 "
OUTPUT: 3

INPUT: s = "(1+(4+5+2)-3)+(6+8)"
OUTPUT: 23

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to handle parentheses and signs. Track current number, result, and sign.
When we see '(', push current result and sign to stack, reset for new sub-expression.
When we see ')', pop from stack and combine with current result.
This is a must-know problem for interviews!
"""



def calculate(s: str) -> int:
    stack = []
    result = 0
    number = 0
    sign = 1

    for c in s:
        if c.isdigit():
            number = number * 10 + int(c)
        elif c == '+':
            result += sign * number
            number = 0
            sign = 1
        elif c == '-':
            result += sign * number
            number = 0
            sign = -1
        elif c == '(':
            stack.append(result)
            stack.append(sign)
            result = 0
            sign = 1
        elif c == ')':
            result += sign * number
            number = 0
            result *= stack.pop()   # sign before '('
            result += stack.pop()   # result before '('

    result += sign * number
    return result


if __name__ == "__main__":
    test_cases = [
        "1 + 1",
        " 2-1 + 2 ",
        "(1+(4+5+2)-3)+(6+8)",
        "1-(5)",
        "2-(5-6)",
        "(7)-(0)+(4)",
        "1-11",
    ]
    for test in test_cases:
        result = calculate(test)
        print(f'Expression: "{test}"')
        print(f"Result: {result}")
        print()
