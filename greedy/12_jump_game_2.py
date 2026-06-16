"""
PROBLEM: Jump Game II (LeetCode 45)
DIFFICULTY: Medium
PATTERN: Greedy BFS / Range-based Jumping

DESCRIPTION:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i.
Return the minimum number of jumps to reach nums[n - 1]. Test cases are generated such that 
you can reach nums[n - 1].

INPUT:
- nums: array where nums[i] is max jump length from position i

OUTPUT:
- Minimum number of jumps to reach last index

APPROACH (Greedy BFS):
1. Think of each jump as a "level" in BFS
2. Track current jump's reach and next jump's reach
3. When we exhaust current range, increment jumps
4. Always explore farthest reachable in current jump

WHY GREEDY WORKS:
We always want to maximize reach with each jump. Within current jump range,
we find the position that allows us to reach farthest in next jump.
"""

from typing import List, Optional

class Solution:
    def jump(self, nums):
        public:
        int jump(vector<int>& nums):
        if (len(nums) <= 1) return 0
        jumps = 0
        currentEnd = 0;      # End of current jump range
        farthest = 0;        # Farthest we can reach
        # We don't need to jump from last position
        for i in range(len(nums) - 1):
        # Update farthest position reachable
        farthest = max(farthest, i + nums[i])
        # If we've reached end of current jump
        if i == currentEnd:
        jumps += 1
        currentEnd = farthest;  # Next jump can reach up to farthest
        # Early exit if we can reach the end
        if (currentEnd >= len(nums) - 1):
        break
        return jumps


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 3, 1, 1, 4]
    print(f"Test 1 - Array: [2,3,1,1,4]")
    print(f"Output: {sol.jump(nums1)}")
    print(f"Expected: 2 (jump to index 1, then to last index)")
    nums2 = [2, 3, 0, 1, 4]
    print(f"Test 2 - Array: [2,3,0,1,4]")
    print(f"Output: {sol.jump(nums2)}")
    print(f"Expected: 2")
    nums3 = [1, 2, 3]
    print(f"Test 3 - Array: [1,2,3]")
    print(f"Output: {sol.jump(nums3)}")
    print(f"Expected: 2")
    nums4 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0]
    print(f"Test 4 - Array: [10,9,8,7,6,5,4,3,2,1,1,0]")
    print(f"Output: {sol.jump(nums4)}")
    print(f"Expected: 2 (jump to index 1, then to last)")
