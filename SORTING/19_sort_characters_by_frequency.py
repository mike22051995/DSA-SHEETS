"""
PROBLEM: Sort Characters by Frequency (LeetCode 451)
===============================================
DESCRIPTION:
Given a string s, sort it in decreasing order based on the frequency of the 
characters. The frequency of a character is the number of times it appears in 
the string.

PATTERN: Frequency Count + Sorting / Bucket Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n) for sorting, O(n) for bucket sort
SPACE COMPLEXITY: O(n)

INPUT:
String

OUTPUT:
String sorted by character frequency

EXAMPLE:
Input: "tree"
Output: "eert" or "eetr" (e appears twice, r and t once)

Input: "cccaaa"
Output: "aaaccc" or "cccaaa"
"""

from typing import List

class Solution:
    def frequencySort(self, s: str) -> str:
        # Count frequency
        freq = {}
        for c in s:
            freq[c] = freq.get(c, 0) + 1
        
        # Sort by frequency in descending order
        sorted_chars = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        
        # Build result string
        result = ""
        for ch, count in sorted_chars:
            result += ch * count
        
        return result
    
    def frequencySortBucket(self, s: str) -> str:
        # Count frequency
        freq = {}
        for c in s:
            freq[c] = freq.get(c, 0) + 1
        
        # Bucket sort by frequency
        buckets = [[] for _ in range(len(s) + 1)]
        for ch, count in freq.items():
            buckets[count].append(ch)
        
        # Build result from highest frequency
        result = ""
        for i in range(len(buckets) - 1, -1, -1):
            for ch in buckets[i]:
                result += ch * i
        
        return result


if __name__ == "__main__":
    sol = Solution()
    
    s1 = "tree"
    print(f"Input: {s1}")
    print(f"Output (Sort): {sol.frequencySort(s1)}")
    
    s2 = "cccaaa"
    print(f"\nInput: {s2}")
    print(f"Output (Bucket): {sol.frequencySortBucket(s2)}")
    
    s3 = "Aabb"
    print(f"\nInput: {s3}")
    print(f"Output (Sort): {sol.frequencySort(s3)}")
