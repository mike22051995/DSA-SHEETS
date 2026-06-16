"""
PROBLEM: Candy (LeetCode 135)
DIFFICULTY: Hard
PATTERN: Two-Pass Greedy with Neighbor Constraints

DESCRIPTION:
There are n children standing in a line. Each child is assigned a rating value given in array ratings.
You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy
- Children with a higher rating get more candies than their neighbors
Return the minimum number of candies you need to have to distribute.

INPUT:
- ratings: array of ratings for each child

OUTPUT:
- Minimum candies needed

APPROACH:
1. Initialize all children with 1 candy
2. Left to right pass: if rating[i] > rating[i-1], candies[i] = candies[i-1] + 1
3. Right to left pass: if rating[i] > rating[i+1], candies[i] = max(candies[i], candies[i+1] + 1)
4. Sum all candies

WHY GREEDY WORKS:
Two-pass ensures both left and right neighbor constraints are satisfied.
Taking max in second pass preserves first pass results.
"""

from typing import List, Optional

class Solution:
    def candy(self, ratings):
        public:
        int candy(vector<int>& ratings):
        n = len(ratings)
        if (n == 0) return 0
        candies(n, 1);  # Everyone gets at least 1 candy
        # Left to right: ensure right neighbor constraint
        for i in range(1, n):
        if ratings[i] > ratings[i-1]:
        candies[i] = candies[i-1] + 1
        # Right to left: ensure left neighbor constraint
        for i in range(n-2, 0 - 1, -1):
        if ratings[i] > ratings[i+1]:
        candies[i] = max(candies[i], candies[i+1] + 1)
        # Sum all candies
        return accumulate(candies.begin(), candies.end(), 0)


if __name__ == "__main__":
    sol = Solution()
    ratings1 = [1, 0, 2]
    print(f"Test 1 - Ratings: [1,0,2]")
    print(f"Output: {sol.candy(ratings1)}")
    print(f"Expected: 5 (candies: [2,1,2])")
    ratings2 = [1, 2, 2]
    print(f"Test 2 - Ratings: [1,2,2]")
    print(f"Output: {sol.candy(ratings2)}")
    print(f"Expected: 4 (candies: [1,2,1])")
    ratings3 = [1, 3, 2, 2, 1]
    print(f"Test 3 - Ratings: [1,3,2,2,1]")
    print(f"Output: {sol.candy(ratings3)}")
    print(f"Expected: 7 (candies: [1,3,2,1,1] or [1,3,1,2,1])")
    ratings4 = [1, 2, 3, 4, 5]
    print(f"Test 4 - Ratings: [1,2,3,4,5]")
    print(f"Output: {sol.candy(ratings4)}")
    print(f"Expected: 15 (candies: [1,2,3,4,5])")
