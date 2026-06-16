"""
PROBLEM: Search Suggestions System
Difficulty: Medium
Pattern: Binary Search + Trie

DESCRIPTION:
You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character 
of searchWord is typed. Suggested products should have common prefix with searchWord. If there 
are more than three products with a common prefix return the three lexicographically minimums.
Return a list of lists of the suggested products after each character of searchWord is typed.

EXPLANATION:
Binary search approach:
1. Sort products array
2. For each prefix of searchWord, use binary search to find start position
3. Collect up to 3 matching products
4. Use lower_bound to find first match efficiently

Time Complexity: O(n log n + m * n) where m = searchWord length
Space Complexity: O(1) excluding output

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],
         ["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

Example 3:
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],
         ["baggage","bags"],["bags"]]
"""

from typing import List, Optional
import bisect


class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()
        result = []
        prefix = ""
        for c in searchWord:
            prefix += c
            suggestions = []
            idx = bisect.bisect_left(products, prefix)
            for i in range(idx, min(idx + 3, len(products))):
                if products[i].startswith(prefix):
                    suggestions.append(products[i])
                else:
                    break
            result.append(suggestions)
        return result


if __name__ == "__main__":
    solution = Solution()
    products1 = ["mobile", "mouse", "moneypot", "monitor", "mousepad"]
    result1 = solution.suggestedProducts(products1, "mouse")
    print(f"Test 1: {result1}")
    products2 = ["havana"]
    result2 = solution.suggestedProducts(products2, "havana")
    print(f"Test 2: {result2}")
    products3 = ["bags", "baggage", "banner", "box", "cloths"]
    result3 = solution.suggestedProducts(products3, "bags")
    print(f"Test 3: {result3}")
