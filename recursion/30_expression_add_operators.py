"""
PROBLEM: Expression Add Operators
---------------------------------------------------------------------------
Given a string num that contains only digits and an integer target, return 
all possibilities to insert the binary operators '+', '-', and '*' between 
the digits of num so that the resultant expression evaluates to target.

DIFFICULTY: Hard
PATTERN: Backtracking (Expression Building)
TIME COMPLEXITY: O(4^n) - 4 choices per position
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: num = "123", target = 6
Output: ["1+2+3","1*2*3"]
Explanation: Both expressions evaluate to 6

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both expressions evaluate to 8
"""

from typing import List


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        result = []
        self._backtrack(num, target, 0, 0, 0, "", result)
        return result

    def _backtrack(self, num: str, target: int, pos: int, eval_: int,
                   multed: int, expr: str, result: List[str]) -> None:
        if pos >= len(num):
            if eval_ == target:
                result.append(expr)
            return
        for i in range(pos, len(num)):
            # Skip numbers with leading zeros
            if i > pos and num[pos] == '0':
                break
            curr_str = num[pos:i + 1]
            curr_num = int(curr_str)
            if pos == 0:
                self._backtrack(num, target, i + 1, curr_num, curr_num,
                                curr_str, result)
            else:
                # Try '+'
                self._backtrack(num, target, i + 1, eval_ + curr_num, curr_num,
                                expr + '+' + curr_str, result)
                # Try '-'
                self._backtrack(num, target, i + 1, eval_ - curr_num, -curr_num,
                                expr + '-' + curr_str, result)
                # Try '*'
                self._backtrack(num, target, i + 1,
                                eval_ - multed + multed * curr_num,
                                multed * curr_num,
                                expr + '*' + curr_str, result)


if __name__ == "__main__":
    sol = Solution()
    num1, target1 = "123", 6
    result1 = sol.addOperators(num1, target1)
    print(f"Test 1: {result1}")
    num2, target2 = "232", 8
    result2 = sol.addOperators(num2, target2)
    print(f"Test 2: {result2}")