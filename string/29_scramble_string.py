"""
    Scramble String - LeetCode #87
    
    We can scramble a string s to get a string t using the following algorithm:
    1. If the length of the string is 1, stop.
    2. If the length of the string is > 1, do the following:
       - Split the string into two non-empty substrings at a random index
       - Randomly decide to swap the two substrings or keep them in order
       - Apply step 1 recursively on each substring
    
    Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1.
    
    Example 1:
    Input: s1 = "great", s2 = "rgeat"
    Output: true
    Explanation: One possible scenario is:
    "great" --> "gr/eat" --> "gr/e/at" --> swap("gr", "e") --> "e/gr/at" --> "rg/e/at"
    --> swap("rg", "e") --> "e/rg/at" --> "gr/e/at" --> "rg/eat" --> "rgeat"
    
    Example 2:
    Input: s1 = "abcde", s2 = "caebd"
    Output: false
    
    Example 3:
    Input: s1 = "a", s2 = "a"
    Output: true
    
    Constraints:
    - s1.length == s2.length
    - 1 <= s1.length <= 30
    - s1 and s2 consist of lowercase English letters
    
    Time Complexity: O(n^4) with memoization
    Space Complexity: O(n^3) for memoization
"""

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        
        memo = {}
        return self.helper(s1, s2, memo)
    
    def helper(self, s1: str, s2: str, memo: dict) -> bool:
        if s1 == s2:
            return True
        if len(s1) != len(s2):
            return False
        
        key = s1 + "#" + s2
        if key in memo:
            return memo[key]
        
        # Check if both strings have same character frequency
        if sorted(s1) != sorted(s2):
            memo[key] = False
            return False
        
        n = len(s1)
        
        # Try all possible split points
        for i in range(1, n):
            # Case 1: No swap
            if (self.helper(s1[:i], s2[:i], memo) and 
                self.helper(s1[i:], s2[i:], memo)):
                memo[key] = True
                return True
            
            # Case 2: With swap
            if (self.helper(s1[:i], s2[n-i:], memo) and 
                self.helper(s1[i:], s2[:n-i], memo)):
                memo[key] = True
                return True
        
        memo[key] = False
        return False

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isScramble('great', 'rgeat')}")        # True
    print(f"Test 2: {sol.isScramble('abcde', 'caebd')}")        # False
    print(f"Test 3: {sol.isScramble('a', 'a')}")                # True
    print(f"Test 4: {sol.isScramble('abcdbdacbdac', 'bdacabcdbdac')}")  # True
