# String Problems - FAANG Interview Preparation

This folder contains 30 of the most important string-related problems frequently asked in FAANG interviews. Each problem includes both C++ and Python implementations with detailed explanations, multiple approaches, time/space complexity analysis, and test cases.

## 📚 Problem Categories

### Easy (1-10)
1. **Valid Anagram** - Hash map and array-based character frequency counting
2. **Valid Palindrome** - Two-pointer technique with character filtering
3. **Longest Substring Without Repeating Characters** - Sliding window with hash map
4. **Longest Palindromic Substring** - Expand around center and DP approaches
5. **Group Anagrams** - Hash map with sorted strings or character count as keys
6. **Valid Parentheses** - Stack-based bracket matching
7. **Longest Repeating Character Replacement** - Sliding window with character frequency
8. **Longest Common Prefix** - Vertical/horizontal scanning and sorting approaches
9. **Palindromic Substrings** - Expand around center technique
10. **Encode and Decode Strings** - Length prefix encoding scheme

### Medium (11-20)
11. **Generate Parentheses** - Backtracking to generate valid combinations
12. **Letter Combinations of a Phone Number** - Backtracking and iterative approaches
13. **Decode Ways** - Dynamic programming for counting decode possibilities
14. **Word Break** - DP to check if string can be segmented
15. **String to Integer (atoi)** - String parsing with edge case handling
16. **Implement strStr()** - Naive search and KMP algorithm
17. **Longest Common Subsequence** - Classic DP problem
18. **Edit Distance** - Levenshtein distance using DP
19. **Group Shifted Strings** - Pattern-based grouping with shift differences
20. **Minimum Window Substring** - Sliding window with character frequency tracking

### Hard (21-30)
21. **Regular Expression Matching** - DP for pattern matching with '.' and '*'
22. **Wildcard Matching** - DP and two-pointer approaches for '?' and '*'
23. **Word Break II** - Backtracking with memoization to return all solutions
24. **Palindrome Pairs** - Trie or hash map with palindrome checking
25. **Distinct Subsequences** - DP to count distinct subsequences
26. **Interleaving String** - DP to check if string is interleaving of two strings
27. **Substring with Concatenation of All Words** - Sliding window with word matching
28. **Shortest Palindrome** - KMP algorithm to find shortest palindrome
29. **Scramble String** - Recursive DP with memoization
30. **Minimum Window Subsequence** - DP or two-pointer to find minimum window

## 🎯 Key Patterns & Techniques

### 1. Sliding Window
- Problems: 3, 7, 20, 27
- Use when finding optimal substrings/subarrays
- Time: O(n), Space: O(k) where k is window size

### 2. Two Pointers
- Problems: 2, 3, 22, 30
- Use for palindrome checking, searching from both ends
- Time: O(n), Space: O(1)

### 3. Dynamic Programming
- Problems: 4, 13, 14, 17, 18, 21, 22, 23, 25, 26, 30
- Use for optimization problems with overlapping subproblems
- Time: O(n²) or O(n³), Space: O(n²)

### 4. Hash Map / Set
- Problems: 1, 3, 5, 19, 24
- Use for frequency counting, grouping, fast lookups
- Time: O(n), Space: O(n)

### 5. Backtracking
- Problems: 11, 12, 23
- Use for generating all valid combinations
- Time: Exponential, Space: O(n) for recursion stack

### 6. KMP Algorithm
- Problems: 16, 28
- Use for efficient pattern matching
- Time: O(n+m), Space: O(m)

## 📊 Complexity Summary

| Difficulty | Average Time | Average Space | Key Techniques |
|------------|--------------|---------------|----------------|
| Easy       | O(n) - O(n²) | O(1) - O(n)   | Two Pointers, Hash Map, Sliding Window |
| Medium     | O(n²)        | O(n) - O(n²)  | DP, Backtracking, Advanced Sliding Window |
| Hard       | O(n²) - O(n³)| O(n²) - O(n³) | Advanced DP, KMP, Complex Backtracking |

## 💡 Interview Tips

1. **Always clarify constraints**: Ask about string length, character set (ASCII, Unicode), null/empty cases
2. **Consider multiple approaches**: Brute force → Optimized → Space-optimized
3. **Watch for edge cases**: Empty strings, single character, all same characters
4. **Common optimizations**:
   - Use arrays instead of hash maps for fixed character sets (26 lowercase letters)
   - Space-optimize DP from O(n²) to O(n) when possible
   - Consider in-place modifications when allowed

5. **Time management**: 
   - Easy problems: 10-15 minutes
   - Medium problems: 20-30 minutes
   - Hard problems: 35-45 minutes

## 🚀 Study Plan

### Week 1: Foundations (Problems 1-10)
- Master basic string manipulation
- Practice two-pointer and sliding window techniques
- Build intuition for palindrome problems

### Week 2: Intermediate Techniques (Problems 11-20)
- Deep dive into backtracking and DP
- Learn pattern matching algorithms
- Practice word segmentation problems

### Week 3: Advanced Topics (Problems 21-30)
- Master complex DP patterns
- Study advanced pattern matching (KMP)
- Tackle multi-dimensional DP problems

## 📝 How to Use

1. **Understand the problem**: Read description and examples carefully
2. **Identify the pattern**: Match with similar problems you've solved
3. **Discuss approach**: Start with brute force, then optimize
4. **Code the solution**: Write clean, well-documented code
5. **Test thoroughly**: Run through test cases and edge cases
6. **Analyze complexity**: Discuss time and space trade-offs

## 🔗 Related Topics
- Arrays (for character manipulation)
- Hash Tables (for frequency counting)
- Stacks (for parentheses/bracket problems)
- Dynamic Programming (for optimization problems)
- Recursion/Backtracking (for generating combinations)
- Trees (Trie for advanced string problems)

## 📈 Progress Tracking

Create a personal checklist:
- [ ] Problems 1-10 (Easy)
- [ ] Problems 11-20 (Medium)
- [ ] Problems 21-30 (Hard)

Mark each problem as you complete it, and revisit challenging ones regularly!

---

**Good luck with your interview preparation! 🎯**

*Remember: Consistency is key. Practice daily, understand patterns, and you'll master these problems!*
