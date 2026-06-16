# Matrix Problems - FAANG Interview Collection

This folder contains 20 frequently asked matrix-based problems from top tech companies (Microsoft, Google, Meta, Amazon, Netflix).

## 📊 Problem List

### Easy Problems (5)
1. **Transpose Matrix** - Basic matrix manipulation
2. **Reshape Matrix** - Array reshaping with validation
3. **Lucky Numbers** - Row min and column max finding
4. **Toeplitz Matrix** - Diagonal pattern validation
5. **Matrix Diagonal Sum** - Primary and secondary diagonal sum

### Medium Problems (12)
6. **Spiral Matrix** - Spiral order traversal
7. **Rotate Image** - 90-degree rotation in-place
8. **Set Matrix Zeroes** - In-place zero marking
9. **Search 2D Matrix** - Binary search on sorted matrix
10. **Search 2D Matrix II** - Elimination-based search
11. **Valid Sudoku** - Hash set validation
12. **Word Search** - Backtracking on grid
13. **Diagonal Traverse** - Diagonal order with direction changes
14. **Maximal Square** - DP for largest square
15. **Kth Smallest in Sorted Matrix** - Binary search or heap
16. **Range Sum Query 2D** - Prefix sum optimization
17. **Count Square Submatrices** - DP counting
18. **Image Overlap** - Translation and convolution

### Hard Problems (3)
19. **Longest Increasing Path** - DFS with memoization
20. **Maximal Rectangle** - Histogram-based DP

## 🏢 Company-wise Distribution

### Microsoft (15 problems)
- Spiral Matrix, Rotate Image, Set Matrix Zeroes
- Search 2D Matrix, Valid Sudoku, Word Search
- Maximal Square, Longest Increasing Path, Maximal Rectangle
- Range Sum Query 2D, Kth Smallest, Reshape Matrix

### Google (18 problems)
- All medium and hard problems
- Diagonal Traverse, Toeplitz Matrix, Lucky Numbers
- Image Overlap, Count Square Submatrices

### Meta (16 problems)
- Most medium and hard problems
- Focus on DP and backtracking problems

### Amazon (14 problems)
- Search problems, Valid Sudoku
- Word Search, Maximal problems
- Lucky Numbers, Matrix manipulation

### Netflix (5 problems)
- Set Matrix Zeroes, Valid Sudoku
- Word Search, Range Sum Query 2D

## 📚 Pattern Categories

### 1. Matrix Traversal
- Spiral Matrix
- Diagonal Traverse
- Matrix Diagonal Sum

### 2. In-Place Manipulation
- Rotate Image (90° rotation)
- Set Matrix Zeroes (O(1) space)
- Transpose Matrix

### 3. Search & Binary Search
- Search 2D Matrix (sorted rows)
- Search 2D Matrix II (sorted rows + columns)
- Kth Smallest in Sorted Matrix

### 4. Dynamic Programming
- Longest Increasing Path (DFS + DP)
- Maximal Rectangle (histogram DP)
- Maximal Square (2D DP)
- Count Square Submatrices (DP counting)

### 5. Backtracking
- Word Search (DFS backtracking)
- Valid Sudoku (constraint validation)

### 6. Prefix Sum / Range Query
- Range Sum Query 2D (2D prefix sum)

### 7. Matrix Properties
- Toeplitz Matrix (diagonal check)
- Valid Sudoku (row/column/box validation)
- Lucky Numbers (row min & col max)

### 8. Matrix Transformation
- Reshape Matrix (dimension validation)
- Transpose Matrix (flip diagonal)
- Image Overlap (translation vectors)

## 🎯 Difficulty Progression

**Start with:**
1. Transpose Matrix
2. Reshape Matrix
3. Matrix Diagonal Sum
4. Toeplitz Matrix

**Then move to:**
1. Spiral Matrix
2. Rotate Image
3. Set Matrix Zeroes
4. Search 2D Matrix

**Advanced:**
1. Word Search
2. Maximal Square
3. Longest Increasing Path
4. Maximal Rectangle

## 💡 Key Concepts

### 1. Index Mapping
- Convert 2D to 1D: `index = i * n + j`
- Convert 1D to 2D: `i = index / n`, `j = index % n`

### 2. Matrix Boundaries
- Top, Bottom, Left, Right pointers for spiral traversal
- Shrinking boundaries technique

### 3. DP on Matrix
- `dp[i][j]` typically represents optimal solution ending at `(i,j)`
- Use previous cells: `dp[i-1][j]`, `dp[i][j-1]`, `dp[i-1][j-1]`

### 4. Space Optimization
- Use first row/column as markers (Set Matrix Zeroes)
- In-place modifications (Rotate Image)
- Rolling array for DP (O(n) instead of O(m*n))

### 5. Search Strategies
- Binary search on value range (Kth Smallest)
- Elimination from corner (Search 2D Matrix II)
- Multi-source BFS for distance problems

## 📈 Time Complexity Summary

| Problem | Time | Space |
|---------|------|-------|
| Spiral Matrix | O(M×N) | O(1) |
| Rotate Image | O(N²) | O(1) |
| Set Matrix Zeroes | O(M×N) | O(1) |
| Search 2D Matrix | O(log(M×N)) | O(1) |
| Search 2D Matrix II | O(M+N) | O(1) |
| Valid Sudoku | O(1) | O(1) |
| Word Search | O(M×N×4^L) | O(L) |
| Longest Increasing Path | O(M×N) | O(M×N) |
| Maximal Rectangle | O(M×N) | O(N) |
| Maximal Square | O(M×N) | O(M×N) |
| Kth Smallest | O(N²×M²) | O(M²) |
| Range Sum Query 2D | O(1) query | O(M×N) |

## 🔥 Interview Tips

1. **Clarify Constraints:**
   - Matrix dimensions (square vs rectangular)
   - In-place vs extra space allowed
   - Edge cases (empty matrix, single element)

2. **Common Edge Cases:**
   - Empty matrix `[]`
   - Single row/column `[[1,2,3]]`
   - Single element `[[5]]`
   - All zeros or all ones

3. **Optimization Techniques:**
   - First row/column as markers
   - Two pointers for boundaries
   - Memoization for recursive solutions
   - Prefix sums for range queries

4. **Drawing Helps:**
   - Visualize the transformation
   - Mark visited cells
   - Track boundary changes

## 🚀 Practice Strategy

1. **Week 1:** Easy problems (1-5)
2. **Week 2:** Search & Traversal (6-10)
3. **Week 3:** DP problems (11-14)
4. **Week 4:** Advanced problems (15-20)

Practice each problem at least twice. Try to solve without looking at the solution first!

## 📝 Notes

- All solutions include detailed diagrams
- Multiple approaches provided where applicable
- Time and space complexity analyzed
- Follow-up questions addressed
- Company tags included

Good luck with your interviews! 🎯
