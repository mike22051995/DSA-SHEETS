"""
PROBLEM: Maximum Product of Word Lengths
==========================================
Given a string array, find the maximum product of lengths of two words 
that do not share common letters.

APPROACH:
- Use bitmask to represent which letters each word contains
- For each word, create a 26-bit mask (for a-z)
- Check if two words have no common letters: mask1 & mask2 == 0
- Find maximum product among valid pairs

PATTERN: Bitmask for Character Set Representation

INPUT/OUTPUT:
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: "abcw" and "xtfn" have no common letters, 4*4 = 16

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: "ab" and "cd" have no common letters, 2*2 = 4

TIME COMPLEXITY: O(n^2 + L) where L is total length of all words
SPACE COMPLEXITY: O(n) for storing masks
"""

from typing import List, Optional

class Solution:
    def maxProduct(self, words):
        n = len(words)
        masks(n, 0)
        # Create bitmask for each word
        for i in range(n):
        for (char c : words[i]):
        masks[i] |= (1 << (c - 'a'))
        maxProd = 0
        # Check all pairs
        for i in range(n):
        for j in range(i + 1, n):
        # If no common letters (AND is 0)
        if ((masks[i] & masks[j]) == 0):
        product = words[i].length() * words[j].length()
        maxProd = max(maxProd, product)
        return maxProd


if __name__ == "__main__":
    sol = Solution()
    words1 = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
    print(f"Input: [\")
    print(f"Output: {sol.maxProduct(words1)}")
    print(f"Explanation: \")
    words2 = ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
    print(f"Input: [\")
    print(f"Output: {sol.maxProduct(words2)}")
    print(f"Explanation: \")
    words3 = ["a", "aa", "aaa", "aaaa"]
    print(f"Input: [\")
    print(f"Output: {sol.maxProduct(words3)}")
    print(f"Explanation: All words share 'a', no valid pair")
