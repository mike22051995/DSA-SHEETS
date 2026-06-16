"""
PROBLEM: Word Ladder (LeetCode 127)
Difficulty: Hard
Pattern: BFS on Implicit Graph

DESCRIPTION:
Given two words (beginWord and endWord) and a dictionary's word list,
find the length of shortest transformation sequence from beginWord to endWord.
Rules:
1. Only one letter can be changed at a time
2. Each transformed word must exist in the word list

APPROACH:
1. Build implicit graph where each word is a node
2. Two words are connected if they differ by exactly one character
3. Use BFS to find shortest path from beginWord to endWord
4. Return the length of the path (number of words in sequence)

TIME COMPLEXITY: O(M² * N) where M = word length, N = number of words
SPACE COMPLEXITY: O(M * N)
"""

from typing import List
from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)
        # If endWord not in dictionary
        if endWord not in word_set:
            return 0
        q = deque()
        q.append((beginWord, 1))
        while q:
            word, level = q.popleft()
            # If we reached endWord
            if word == endWord:
                return level
            # Try changing each character
            for i in range(len(word)):
                # Try all 26 letters
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    new_word = word[:i] + c + word[i+1:]
                    # If this word is in dictionary
                    if new_word in word_set:
                        q.append((new_word, level + 1))
                        word_set.remove(new_word)  # mark as visited
        return 0  # No transformation sequence found


if __name__ == "__main__":
    sol = Solution()
    print(f"Shortest transformation length: {sol.ladderLength('hit', 'cog', ['hot','dot','dog','lot','log','cog'])}")
    print(f"Shortest transformation length: {sol.ladderLength('hit', 'cog', ['hot','dot','dog','lot','log'])}")
