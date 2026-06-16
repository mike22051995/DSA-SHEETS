# FAANG Interview Preparation - Top 30 Array Problems

## Overview
This collection contains 30 carefully selected array problems that cover all essential patterns for FAANG interviews. Each problem includes:
- Problem description
- Complete C++ solution
- Detailed explanation
- Time and space complexity analysis
- 2-3 test cases with input/output examples

## Difficulty Levels

### Easy (Problems 1-10)
Focus on fundamental techniques and basic patterns:
1. **Two Sum** - Hash Map pattern
2. **Best Time to Buy and Sell Stock** - Greedy, Sliding Window
3. **Contains Duplicate** - Hash Set
4. **Maximum Subarray** - Kadane's Algorithm (DP)
5. **Move Zeroes** - Two Pointers
6. **Plus One** - Array Manipulation
7. **Remove Duplicates from Sorted Array** - Two Pointers
8. **Merge Sorted Array** - Two Pointers
9. **Intersection of Two Arrays II** - Hash Map, Two Pointers
10. **Majority Element** - Boyer-Moore Voting Algorithm

### Medium (Problems 11-20)
Build on fundamentals with more complex patterns:
11. **3Sum** - Two Pointers, Sorting
12. **Product of Array Except Self** - Prefix/Suffix Product
13. **Container With Most Water** - Two Pointers
14. **Rotate Array** - Array Reversal
15. **Find First and Last Position** - Binary Search
16. **Jump Game** - Greedy
17. **Subarray Sum Equals K** - Prefix Sum, Hash Map
18. **Next Permutation** - Array Manipulation
19. **Sort Colors** - Dutch National Flag (Three Pointers)
20. **Spiral Matrix** - Matrix Traversal

### Hard (Problems 21-30)
Advanced problems requiring deep understanding:
21. **Trapping Rain Water** - Two Pointers, DP
22. **First Missing Positive** - Cyclic Sort
23. **Median of Two Sorted Arrays** - Binary Search
24. **Sliding Window Maximum** - Deque (Monotonic Queue)
25. **Longest Consecutive Sequence** - Hash Set
26. **Maximum Product Subarray** - Dynamic Programming
27. **4Sum** - Two Pointers, Sorting
28. **Minimum Window Substring** - Sliding Window, Hash Map
29. **Largest Rectangle in Histogram** - Monotonic Stack
30. **Find Peak Element** - Binary Search

## Key Patterns Covered

1. **Hash Map/Set** - Problems 1, 3, 9, 17, 25
2. **Two Pointers** - Problems 5, 7, 8, 11, 13, 14, 19, 21
3. **Sliding Window** - Problems 2, 24, 28
4. **Binary Search** - Problems 15, 23, 30
5. **Dynamic Programming** - Problems 4, 26
6. **Greedy** - Problems 2, 16
7. **Stack/Deque** - Problems 24, 29
8. **Sorting** - Problems 11, 19, 27
9. **Prefix/Suffix** - Problems 12, 17
10. **Array Manipulation** - Problems 6, 18, 22

## How to Use This Collection

### For Beginners:
1. Start with Easy problems (1-10)
2. Understand the pattern used in each solution
3. Try to solve without looking at the code first
4. Study the explanation if stuck

### For Intermediate:
1. Focus on Medium problems (11-20)
2. Try to identify the pattern before coding
3. Optimize your solution after getting it to work
4. Compare your approach with the provided solution

### For Advanced:
1. Tackle Hard problems (21-30)
2. Time yourself (aim for 30-45 minutes per problem)
3. Focus on optimal solutions from the start
4. Practice explaining your approach out loud

## Compilation Instructions

To compile any problem:
```bash
g++ -std=c++17 <filename>.cpp -o <output_name>
```

Example:
```bash
g++ -std=c++17 01_two_sum.cpp -o two_sum
./two_sum
```

## Interview Tips

1. **Always clarify requirements** before coding
2. **Discuss your approach** before implementing
3. **Start with brute force**, then optimize
4. **Test with edge cases**: empty array, single element, duplicates
5. **Analyze time/space complexity** of your solution
6. **Practice explaining** your thought process

## Pattern Recognition Guide

- **Need to find pairs/triplets?** → Consider Two Pointers or Hash Map
- **Subarray problems?** → Consider Sliding Window or Prefix Sum
- **Sorted array search?** → Consider Binary Search
- **Need optimal value from choices?** → Consider DP or Greedy
- **Need to track maximums/minimums?** → Consider Stack/Deque
- **Array modifications in-place?** → Consider Two Pointers

## Good Luck with Your Interview! 🚀

Practice these problems thoroughly, understand the patterns, and you'll be well-prepared for any array-related question in your FAANG interview!
