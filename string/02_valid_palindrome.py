"""
    Valid Palindrome - LeetCode #125
    
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
    and removing all non-alphanumeric characters, it reads the same forward and backward.
    
    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    
    Example 2:
    Input: s = "race a car"
    Output: false
    
    Constraints:
    - 1 <= s.length <= 2 * 10^5
    - s consists only of printable ASCII characters
    
    Time Complexity: O(n)
    Space Complexity: O(1)
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        
        while left < right:
            # Skip non-alphanumeric characters from left
            while left < right and not s[left].isalnum():
                left += 1
            
            # Skip non-alphanumeric characters from right
            while left < right and not s[right].isalnum():
                right -= 1
            
            # Compare characters (case-insensitive)
            if s[left].lower() != s[right].lower():
                return False
            
            left += 1
            right -= 1
        
        return True
    
    # Pythonic approach
    def isPalindromePythonic(self, s: str) -> bool:
        cleaned = ''.join(c.lower() for c in s if c.isalnum())
        return cleaned == cleaned[::-1]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isPalindrome('A man, a plan, a canal: Panama')}")  # True
    print(f"Test 2: {sol.isPalindrome('race a car')}")  # False
    print(f"Test 3: {sol.isPalindrome(' ')}")  # True
