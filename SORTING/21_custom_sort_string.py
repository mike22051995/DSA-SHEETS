"""
PROBLEM: Custom Sort String (LeetCode 791)
===============================================
DESCRIPTION:
You are given two strings order and s. All the characters of order are unique 
and were sorted in some custom order previously. Permute the characters of s 
so that they match the order that order was sorted. Return any permutation of 
s that satisfies this property.

PATTERN: Custom Comparator / Counting Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n + m) where n = s.length, m = order.length
SPACE COMPLEXITY: O(1) - constant 26 letters

INPUT:
order = "cba", s = "abcd"

OUTPUT:
"cbad"

EXAMPLE:
Input: order = "cba", s = "abcd"
Output: "cbad" (c, b, a appear in order, d at end)
"""

from typing import List

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        # Create map for ordering
        orderMap = {ch: i for i, ch in enumerate(order)}
        
        # Sort s based on custom order
        def sort_key(ch):
            return orderMap.get(ch, len(order))
        
        return "".join(sorted(s, key=sort_key))
    
    def customSortStringCount(self, order: str, s: str) -> str:
        # Count frequency of each character in s
        freq = {}
        for ch in s:
            freq[ch] = freq.get(ch, 0) + 1
        
        # Build result following order
        result = ""
        for ch in order:
            if ch in freq:
                result += ch * freq[ch]
        
        # Add remaining characters not in order
        for ch, count in freq.items():
            if ch not in order:
                result += ch * count
        
        return result


if __name__ == "__main__":
    sol = Solution()
    
    order1 = "cba"
    s1 = "abcd"
    print(f"Order: {order1}")
    print(f"Result (Comparator): {sol.customSortString(order1, s1)}")
    print(f"Result (Counting): {sol.customSortStringCount(order1, s1)}")
    
    order2 = "cbafg"
    s2 = "abcd"
    print(f"\nOrder: {order2}")
    print(f"Result (Comparator): {sol.customSortString(order2, s2)}")
    print(f"Result (Counting): {sol.customSortStringCount(order2, s2)}")
