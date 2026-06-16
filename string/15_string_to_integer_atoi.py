"""
    String to Integer (atoi) - LeetCode #8
    
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
    
    Algorithm:
    1. Read in and ignore any leading whitespace
    2. Check if the next character is '-' or '+'. Read this character if it is either.
    3. Read in next the characters until the next non-digit character or end of the input is reached.
    4. Convert these digits into an integer. If no digits were read, then the integer is 0.
    5. If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], 
       then clamp the integer so that it remains in the range.
    6. Return the integer as the final result.
    
    Example 1:
    Input: s = "42"
    Output: 42
    
    Example 2:
    Input: s = "   -42"
    Output: -42
    
    Example 3:
    Input: s = "4193 with words"
    Output: 4193
    
    Time Complexity: O(n)
    Space Complexity: O(1)
"""

class Solution:
    def myAtoi(self, s: str) -> int:
        i = 0
        n = len(s)
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        # Step 1: Skip leading whitespace
        while i < n and s[i] == ' ':
            i += 1
        
        # Step 2: Check for sign
        sign = 1
        if i < n and s[i] in ['+', '-']:
            sign = -1 if s[i] == '-' else 1
            i += 1
        
        # Step 3: Convert digits
        result = 0
        while i < n and s[i].isdigit():
            result = result * 10 + int(s[i])
            
            # Step 4: Check for overflow
            if result * sign >= INT_MAX:
                return INT_MAX
            if result * sign <= INT_MIN:
                return INT_MIN
            
            i += 1
        
        return result * sign

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.myAtoi('42')}")                    # 42
    print(f"Test 2: {sol.myAtoi('   -42')}")                # -42
    print(f"Test 3: {sol.myAtoi('4193 with words')}")       # 4193
    print(f"Test 4: {sol.myAtoi('words and 987')}")         # 0
    print(f"Test 5: {sol.myAtoi('-91283472332')}")          # -2147483648
