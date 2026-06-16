"""
    Valid Parentheses - LeetCode #20
    
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.
    
    An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.
    
    Example 1:
    Input: s = "()"
    Output: true
    
    Example 2:
    Input: s = "()[]{}"
    Output: true
    
    Example 3:
    Input: s = "(]"
    Output: false
    
    Constraints:
    - 1 <= s.length <= 10^4
    - s consists of parentheses only '()[]{}'
    
    Time Complexity: O(n)
    Space Complexity: O(n)
"""

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {
            ')': '(',
            '}': '{',
            ']': '['
        }
        
        for char in s:
            if char in pairs:
                # Closing bracket
                if not stack or stack[-1] != pairs[char]:
                    return False
                stack.pop()
            else:
                # Opening bracket
                stack.append(char)
        
        return len(stack) == 0
    
    # Alternative approach
    def isValidSimple(self, s: str) -> bool:
        stack = []
        
        for char in s:
            if char == '(':
                stack.append(')')
            elif char == '{':
                stack.append('}')
            elif char == '[':
                stack.append(']')
            elif not stack or stack[-1] != char:
                return False
            else:
                stack.pop()
        
        return len(stack) == 0

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isValid('()')}")           # True
    print(f"Test 2: {sol.isValid('()[]{}')} ")      # True
    print(f"Test 3: {sol.isValid('(]')}")           # False
    print(f"Test 4: {sol.isValid('([)]')}")         # False
    print(f"Test 5: {sol.isValid('{[]}')} ")        # True
