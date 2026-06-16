"""
PROBLEM: Reorganize String (LeetCode 767)
DIFFICULTY: Medium
PATTERN: Greedy Scheduling with Max Heap

DESCRIPTION:
Given a string s, rearrange the characters of s so that any two adjacent characters are 
not the same. Return any possible rearrangement of s or return "" if not possible.

INPUT:
- s: string to reorganize

OUTPUT:
- Reorganized string or empty string if impossible

APPROACH:
1. Count frequency of each character
2. Use max heap to always pick most frequent character
3. Pick top 2 characters, append them, decrease count
4. Put them back if count > 0
5. Handle last remaining character specially

WHY GREEDY WORKS:
Always using most frequent character (that's different from previous) 
ensures we don't run out of alternatives too early.
"""

from typing import List, Optional

class Solution:
    def reorganizeString(self, s):
        # Count frequency
        freq
        for c in s:
        freq[c]++
        # Check if reorganization is possible
        # If any character appears more than (n+1)/2 times, impossible
        for (auto& p : freq):
        if (p.second > (len(s) + 1) / 2):
        return ""
        # Max heap based on frequency
        priority_queue<pair<int, char>> maxHeap
        for (auto& p : freq):
        maxHeap.push({p.second, p.first})
        result = ""
        # Process pairs of characters
        while (len(maxHeap) >= 2):
        auto first = maxHeap.top(); maxHeap.pop()
        auto second = maxHeap.top(); maxHeap.pop()
        result += first.second
        result += second.second
        # Put back if still have remaining
        if --first.first > 0:
        maxHeap.push(first)
        if --second.first > 0:
        maxHeap.push(second)
        # Handle last character if any
        if !not maxHeap:
        result += maxHeap.top().second
        return result


if __name__ == "__main__":
    sol = Solution()
    s1 = "aab"
    print(f"Test 1 - Input: {s1}")
    print(f"Output: {sol.reorganizeString(s1)}")
    print(f"Expected: aba or similar")
    s2 = "aaab"
    print(f"Test 2 - Input: {s2}")
    print(f"Output: {sol.reorganizeString(s2)}")
    print(f"Expected: (empty - impossible)")
    s3 = "vvvlo"
    print(f"Test 3 - Input: {s3}")
    print(f"Output: {sol.reorganizeString(s3)}")
    print(f"Expected: vlvov or similar")
    s4 = "aaabbcc"
    print(f"Test 4 - Input: {s4}")
    print(f"Output: {sol.reorganizeString(s4)}")
    print(f"Expected: ababcac or similar")
