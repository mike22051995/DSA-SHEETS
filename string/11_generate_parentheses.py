"""
    Generate Parentheses - LeetCode #22
    
    Given n pairs of parentheses, write a function to generate all combinations
    of well-formed parentheses.
    
    Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
    
    Example 2:
    Input: n = 1
    Output: ["()"]
    
    Constraints:
    - 1 <= n <= 8
    
    Time Complexity: O(4^n / sqrt(n)) - Catalan number
    Space Complexity: O(n) for recursion stack
"""

from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        
        def backtrack(current: str, open_count: int, close_count: int):
            # Base case: if current string is complete
            if len(current) == n * 2:
                result.append(current)
                return
            
            # Add opening bracket if we haven't used all
            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)
            
            # Add closing bracket if it doesn't exceed opening
            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)
        
        backtrack("", 0, 0)
        return result

if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    result1 = sol.generateParenthesis(3)
    print(f"Test 1 (n=3): {result1}")
    
    # Test 2
    result2 = sol.generateParenthesis(1)
    print(f"Test 2 (n=1): {result2}")
    
    # Test 3
    result3 = sol.generateParenthesis(2)
    print(f"Test 3 (n=2): {result3}")
