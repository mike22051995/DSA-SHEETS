"""
PROBLEM: Assign Cookies (LeetCode 455)
DIFFICULTY: Easy
PATTERN: Two Pointer + Greedy Matching

DESCRIPTION:
You have g children and s cookies. Each child has a greed factor g[i], which is the minimum size 
of a cookie that the child will be content with. Each cookie has a size s[j]. If s[j] >= g[i], 
we can assign the cookie j to the child i, and the child becomes content. 
Your goal is to maximize the number of content children.

INPUT:
- greed: array of integers representing children's greed factors
- cookies: array of integers representing cookie sizes

OUTPUT:
- Maximum number of content children

APPROACH:
1. Sort both arrays in ascending order
2. Use two pointers to match smallest available cookie to least greedy child
3. If current cookie satisfies current child, move to next child
4. Always move to next cookie

WHY GREEDY WORKS:
Giving the smallest sufficient cookie to the least greedy child leaves larger cookies 
for greedier children, maximizing total satisfied children.
"""

from typing import List, Optional

class Solution:
    def findContentChildren(self, greed, cookies):
        # Sort both arrays
        sort(greed.begin(), greed.end())
        sort(cookies.begin(), cookies.end())
        child = 0;  # Pointer for children
        cookie = 0; # Pointer for cookies
        # Try to satisfy each child with available cookies
        while (child < len(greed) and cookie < len(cookies)):
        if cookies[cookie] >= greed[child]:
        child++; # Child satisfied, move to next child
        cookie++; # Move to next cookie regardless
        return child; # Number of satisfied children


if __name__ == "__main__":
    sol = Solution()
    greed1 = [1, 2, 3]
    cookies1 = [1, 1]
    print(f"Test 1 - Greed: [1,2,3], Cookies: [1,1]")
    print(f"Output: {sol.findContentChildren(greed1,}")
    print(f"Expected: 1")
    greed2 = [1, 2]
    cookies2 = [1, 2, 3]
    print(f"Test 2 - Greed: [1,2], Cookies: [1,2,3]")
    print(f"Output: {sol.findContentChildren(greed2,}")
    print(f"Expected: 2")
    greed3 = [10, 9, 8, 7]
    cookies3 = [5, 6, 7, 8]
    print(f"Test 3 - Greed: [10,9,8,7], Cookies: [5,6,7,8]")
    print(f"Output: {sol.findContentChildren(greed3,}")
    print(f"Expected: 2")
