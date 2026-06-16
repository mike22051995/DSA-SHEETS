"""
    Substring with Concatenation of All Words - LeetCode #30
    
    You are given a string s and an array of strings words. All the strings of words are of
    the same length. A concatenated substring in s is a substring that contains all the strings
    of any permutation of words concatenated.
    
    Return the starting indices of all the concatenated substrings in s.
    
    Example 1:
    Input: s = "barfoothefoobarman", words = ["foo","bar"]
    Output: [0,9]
    Explanation: The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"].
    The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"].
    
    Example 2:
    Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
    Output: []
    Explanation: There is no concatenated substring.
    
    Example 3:
    Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
    Output: [6,9,12]
    
    Constraints:
    - 1 <= s.length <= 10^4
    - 1 <= words.length <= 5000
    - 1 <= words[i].length <= 30
    - s and words[i] consist of lowercase English letters
    
    Time Complexity: O(n * m * len) where n is length of s, m is number of words
    Space Complexity: O(m)
"""

from collections import Counter
from typing import List

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        result = []
        if not s or not words:
            return result
        
        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        
        if len(s) < total_len:
            return result
        
        # Count frequency of each word
        word_freq = Counter(words)
        
        # Check each possible starting position
        for i in range(word_len):
            left = i
            count = 0
            window_freq = {}
            
            right = i
            while right <= len(s) - word_len:
                word = s[right:right + word_len]
                
                if word in word_freq:
                    window_freq[word] = window_freq.get(word, 0) + 1
                    count += 1
                    
                    # If word appears more than needed, shrink window
                    while window_freq[word] > word_freq[word]:
                        left_word = s[left:left + word_len]
                        window_freq[left_word] -= 1
                        left += word_len
                        count -= 1
                    
                    # If all words matched
                    if count == word_count:
                        result.append(left)
                        
                        # Move left pointer
                        left_word = s[left:left + word_len]
                        window_freq[left_word] -= 1
                        left += word_len
                        count -= 1
                else:
                    # Reset window
                    window_freq.clear()
                    count = 0
                    left = right + word_len
                
                right += word_len
        
        return result

if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    words1 = ["foo", "bar"]
    result1 = sol.findSubstring("barfoothefoobarman", words1)
    print(f"Test 1: {result1}")
    
    # Test 2
    words2 = ["word", "good", "best", "word"]
    result2 = sol.findSubstring("wordgoodgoodgoodbestword", words2)
    print(f"Test 2: {result2}")
    
    # Test 3
    words3 = ["bar", "foo", "the"]
    result3 = sol.findSubstring("barfoofoobarthefoobarman", words3)
    print(f"Test 3: {result3}")
