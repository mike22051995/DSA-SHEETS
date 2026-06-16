"""
    Letter Combinations of a Phone Number - LeetCode #17
    
    Given a string containing digits from 2-9 inclusive, return all possible letter
    combinations that the number could represent. Return the answer in any order.
    
    A mapping of digits to letters (just like on the telephone buttons):
    2: abc, 3: def, 4: ghi, 5: jkl, 6: mno, 7: pqrs, 8: tuv, 9: wxyz
    
    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    Example 2:
    Input: digits = ""
    Output: []
    
    Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]
    
    Constraints:
    - 0 <= digits.length <= 4
    - digits[i] is a digit in the range ['2', '9']
    
    Time Complexity: O(4^n) where n is length of digits
    Space Complexity: O(n) for recursion stack
"""

from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        phone = {
            '2': 'abc', '3': 'def', '4': 'ghi',
            '5': 'jkl', '6': 'mno', '7': 'pqrs',
            '8': 'tuv', '9': 'wxyz'
        }
        
        result = []
        
        def backtrack(index: int, current: str):
            if index == len(digits):
                result.append(current)
                return
            
            letters = phone[digits[index]]
            for letter in letters:
                backtrack(index + 1, current + letter)
        
        backtrack(0, "")
        return result
    
    # Iterative approach
    def letterCombinationsIterative(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        phone = {
            '2': 'abc', '3': 'def', '4': 'ghi',
            '5': 'jkl', '6': 'mno', '7': 'pqrs',
            '8': 'tuv', '9': 'wxyz'
        }
        
        result = ['']
        for digit in digits:
            temp = []
            for combo in result:
                for letter in phone[digit]:
                    temp.append(combo + letter)
            result = temp
        
        return result

if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    result1 = sol.letterCombinations("23")
    print(f"Test 1: {result1}")
    
    # Test 2
    result2 = sol.letterCombinations("")
    print(f"Test 2: {result2}")
    
    # Test 3
    result3 = sol.letterCombinations("2")
    print(f"Test 3: {result3}")
