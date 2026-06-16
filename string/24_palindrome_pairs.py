"""
    Palindrome Pairs - LeetCode #336
    
    Given a list of unique words, return all the pairs of distinct indices (i, j) in the
    given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.
    
    Example 1:
    Input: words = ["abcd","dcba","lls","s","sssll"]
    Output: [[0,1],[1,0],[3,2],[2,4]]
    Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
    
    Example 2:
    Input: words = ["bat","tab","cat"]
    Output: [[0,1],[1,0]]
    Explanation: The palindromes are ["battab","tabbat"]
    
    Example 3:
    Input: words = ["a",""]
    Output: [[0,1],[1,0]]
    
    Constraints:
    - 1 <= words.length <= 5000
    - 0 <= words[i].length <= 300
    - words[i] consists of lowercase English letters
    
    Time Complexity: O(n * k^2) where k is average word length
    Space Complexity: O(n)
"""

from typing import List

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        result = []
        word_map = {word: i for i, word in enumerate(words)}
        
        for i, word in enumerate(words):
            length = len(word)
            
            # Check all possible splits
            for j in range(length + 1):
                left = word[:j]
                right = word[j:]
                
                # If left is palindrome, check if reverse of right exists
                if self.is_palindrome(left):
                    reverse_right = right[::-1]
                    if reverse_right in word_map and word_map[reverse_right] != i:
                        result.append([word_map[reverse_right], i])
                
                # If right is palindrome, check if reverse of left exists
                # j != length to avoid duplicates
                if j != length and self.is_palindrome(right):
                    reverse_left = left[::-1]
                    if reverse_left in word_map and word_map[reverse_left] != i:
                        result.append([i, word_map[reverse_left]])
        
        return result
    
    def is_palindrome(self, s: str) -> bool:
        return s == s[::-1]

if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    words1 = ["abcd", "dcba", "lls", "s", "sssll"]
    result1 = sol.palindromePairs(words1)
    print(f"Test 1: {result1}")
    
    # Test 2
    words2 = ["bat", "tab", "cat"]
    result2 = sol.palindromePairs(words2)
    print(f"Test 2: {result2}")
