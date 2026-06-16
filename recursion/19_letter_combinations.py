"""
PROBLEM: Letter Combinations of a Phone Number
---------------------------------------------------------------------------
Given a string containing digits from 2-9, return all possible letter 
combinations that the number could represent (like on a phone keypad).

DIFFICULTY: Medium
PATTERN: Backtracking (Multi-branch recursion)
TIME COMPLEXITY: O(4^n) where n is length of digits
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Explanation: 2 maps to "abc", 3 maps to "def"

Example 2:
Input: digits = "2"
Output: ["a","b","c"]
"""

from typing import List, Optional

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        """Generate all letter combinations for given phone digits"""
        if not digits:
            return []
        
        # Phone keypad mapping
        phone_map = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }
        
        result = []
        current = []
        self.backtrack(digits, 0, current, result, phone_map)
        return result
    
    def backtrack(self, digits: str, index: int, current: List[str], 
                  result: List[List[str]], phone_map: dict) -> None:
        """Helper function for backtracking"""
        # Base case: processed all digits
        if index == len(digits):
            result.append(''.join(current))
            return
        
        # Get letters for current digit
        letters = phone_map[digits[index]]
        
        # Try each letter
        for letter in letters:
            current.append(letter)  # Choose
            self.backtrack(digits, index + 1, current, result, phone_map)  # Explore
            current.pop()  # Unchoose (backtrack)


if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    digits1 = "23"
    result1 = sol.letterCombinations(digits1)
    print(f"Test 1: digits='{digits1}'")
    print(f"Result: {result1}")
    
    # Test 2
    digits2 = "2"
    result2 = sol.letterCombinations(digits2)
    print(f"Test 2: digits='{digits2}'")
    print(f"Result: {result2}")
