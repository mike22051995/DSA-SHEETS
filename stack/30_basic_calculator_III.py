"""
PROBLEM: Basic Calculator III (LeetCode 772)
DIFFICULTY: Hard
PATTERN: Stack with Recursion for Full Expression Parsing

DESCRIPTION:
Implement a basic calculator to evaluate a simple expression string.
The expression string contains:
- Non-negative integers
- '+', '-', '*', '/' operators
- '(', ')' parentheses
- Spaces ' '

INPUT: s = "2*(5+5*2)/3+(6/2+8)"
OUTPUT: 21

INPUT: s = "1 + 1"
OUTPUT: 2

INPUT: s = " 6-4 / 2 "
OUTPUT: 4

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack and recursion

EXPLANATION:
Combine Calculator I and Calculator II approaches.
Use stack for operator precedence and handling parentheses.
When encountering '(', recursively evaluate the sub-expression.
Handle *, / immediately and +, - by pushing to stack.
This is the most comprehensive calculator problem!

PATTERNS COVERED IN THIS FILE:
This is the ultimate stack problem combining multiple patterns:
1. Stack for operator precedence
2. Recursion/Stack for parentheses handling
3. Expression evaluation with multiple operators
"""


class Calculator:
    def __init__(self):
        self.index = 0

    def _calc(self, s: str) -> int:
        stack = []
        number = 0
        operation = '+'

        while self.index < len(s):
            c = s[self.index]
            self.index += 1

            if c.isdigit():
                number = number * 10 + int(c)

            if c == '(':
                number = self._calc(s)

            if (not c.isdigit() and c != ' ') or self.index == len(s):
                if operation == '+':
                    stack.append(number)
                elif operation == '-':
                    stack.append(-number)
                elif operation == '*':
                    stack.append(stack.pop() * number)
                elif operation == '/':
                    stack.append(int(stack.pop() / number))
                if c == ')':
                    break
                operation = c
                number = 0

        return sum(stack)

    def calculate(self, s: str) -> int:
        self.index = 0
        return self._calc(s)


if __name__ == "__main__":
    test_cases = [
        "1 + 1",
        " 6-4 / 2 ",
        "2*(5+5*2)/3+(6/2+8)",
        "(2+6*3+5-(3*14/7+2)*5)+3",
        "0-2147483647",
        "1+2*5/3+6/4*2",
    ]
    for test in test_cases:
        c = Calculator()
        result = c.calculate(test)
        print(f'Expression: "{test}"')
        print(f"Result: {result}")
        print()
