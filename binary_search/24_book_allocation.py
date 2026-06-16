"""
PROBLEM: Book Allocation Problem
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Given an array of N books where ith book has pages[i] pages. M students need to be allocated 
contiguous books, with each student getting at least one book. Allocate books such that the 
maximum number of pages allocated to a student is minimized.

EXPLANATION:
Binary search on maximum pages:
- Min pages = max(pages) (student must read largest book)
- Max pages = sum(pages) (one student reads all)
- For each mid, check if M students can be allocated
- Find minimum maximum pages

Time Complexity: O(n * log(sum))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: pages = [12,34,67,90], students = 2
Output: 113
Explanation: Student 1: [12,34,67], Student 2: [90]

Example 2:
Input: pages = [10,20,30,40], students = 2
Output: 60
Explanation: Student 1: [10,20,30], Student 2: [40]

Example 3:
Input: pages = [5,17,100,11], students = 4
Output: 100
"""

from typing import List, Optional


def can_allocate(pages, students, max_pages):
    count = 1
    current = 0
    for p in pages:
        if current + p > max_pages:
            count += 1
            current = 0
        current += p
    return count <= students


class Solution:
    def allocateBooks(self, pages, students):
        if students > len(pages):
            return -1
        left = max(pages)
        right = sum(pages)
        while left < right:
            mid = left + (right - left) // 2
            if can_allocate(pages, students, mid):
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    solution = Solution()
    pages1 = [12, 34, 67, 90]
    print(f"Test 1: {solution.allocateBooks(pages1, 2)}")
    pages2 = [10, 20, 30, 40]
    print(f"Test 2: {solution.allocateBooks(pages2, 2)}")
    pages3 = [5, 17, 100, 11]
    print(f"Test 3: {solution.allocateBooks(pages3, 4)}")
