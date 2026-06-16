# Dynamic Programming - Complete Pattern Guide

## 📚 Overview
This folder contains **40 comprehensive DP problems** covering ALL major patterns needed for FAANG interviews. Each file includes multiple approaches, detailed explanations, time/space complexity analysis, and interview tips.

---

## 🎯 Problem Categories

### **1. Basic/Linear DP (Problems 1-5)**
Foundation problems to understand DP fundamentals.

| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 01 | Fibonacci Number | Basic | Easy | Base cases, memoization |
| 02 | Climbing Stairs | Linear | Easy | State transition |
| 03 | House Robber | Linear | Medium | Non-adjacent selection |
| 04 | Maximum Subarray (Kadane's) | Linear | Easy | Running maximum |
| 05 | House Robber II | Circular | Medium | Breaking cycles |

**Interview Tip**: Master these first! They form the foundation.

---

### **2. Subsequence DP (Problems 6-10)**
Problems involving subsequences and common patterns.

| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 06 | Longest Increasing Subsequence | Subsequence | Medium | O(n²) → O(n log n) |
| 07 | Coin Change | Unbounded Knapsack | Medium | Minimum coins |
| 08 | Longest Common Subsequence | 2D DP | Medium | String matching |
| 09 | Edit Distance | 2D DP | Hard | Levenshtein distance |
| 10 | Partition Equal Subset Sum | 0/1 Knapsack | Medium | Subset sum |

---

### **3. Path Problems (Problems 11-14)**
Grid traversal and path counting.

| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 11 | Unique Paths | Grid DP | Medium | Combinatorics |
| 12 | Minimum Path Sum | Grid DP | Medium | Cost optimization |
| 13 | Unique Paths II | Grid DP | Medium | Obstacles |
| 14 | Triangle | Grid DP | Medium | Top-down path |

---

### **4. String DP (Problems 8, 9, 15, 17)**
Advanced string manipulation problems.

| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 15 | Decode Ways | Linear DP | Medium | State compression |
| 17 | Word Break | DP + Backtracking | Medium | Dictionary matching |
| 31 | Min Insertion Palindrome | Palindrome | Hard | LPS application |
| 32 | Distinct Subsequences | String DP | Hard | Counting paths |
| 33 | Interleaving String | 2D DP | Medium | Path finding |
| 34 | Scramble String | Partition DP | Hard | Recursive split |

---

### **5. Knapsack Family (Problems 21-25, 37-38)**
Most important pattern for interviews!

| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 21 | **0/1 Knapsack** | 0/1 Knapsack | Medium | **MUST KNOW** |
| 22 | **Unbounded Knapsack** | Unbounded | Medium | **MUST KNOW** |
| 23 | Rod Cutting | Unbounded | Medium | Price optimization |
| 24 | Coin Change II | Unbounded | Medium | Count combinations |
| 25 | Target Sum | 0/1 Knapsack | Medium | +/- assignment |
| 37 | Min Subset Sum Difference | 0/1 Knapsack | Medium | Partition optimization |
| 38 | Count Subset Sum | 0/1 Knapsack | Medium | Counting variant |

**Pattern Recognition**:
- **0/1 Knapsack**: Can use each item once → Traverse right to left
- **Unbounded**: Can use items multiple times → Traverse left to right

---

### **6. Interval/Partition DP (Problems 26-30, 40)**
Divide and conquer with DP.

| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 26 | Palindrome Partitioning II | Partition DP | Hard | Min cuts |
| 27 | **Matrix Chain Multiplication** | Partition DP | Hard | **CLASSIC** |
| 28 | Egg Drop | Min-Max DP | Hard | Binary search opt |
| 29 | Burst Balloons | Partition DP | Hard | Think backwards! |
| 30 | Longest Palindromic Subsequence | Interval DP | Medium | LCS variant |
| 40 | Min Score Triangulation | Partition DP | Medium | Similar to MCM |

**Key Pattern**: Try all split points, combine results.

---

### **7. Advanced Patterns (Problems 35-39)**

#### **Game Theory DP**
| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 36 | Stone Game | Game Theory | Medium | Min-Max, optimal play |

#### **Combinatorial DP**
| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 35 | Catalan Numbers | Combinatorial | Medium | Recursive structures |

#### **Bitmasking DP**
| # | Problem | Pattern | Difficulty | Key Concept |
|---|---------|---------|------------|-------------|
| 39 | TSP (Traveling Salesman) | Bitmasking | Hard | State compression |

---

## 🔥 FAANG Interview Priorities

### **Must Know (Practice First)**
1. ✅ 0/1 Knapsack (21)
2. ✅ Unbounded Knapsack (22)
3. ✅ LIS (06)
4. ✅ LCS (08)
5. ✅ Coin Change (07)
6. ✅ Matrix Chain Multiplication (27)
7. ✅ Edit Distance (09)
8. ✅ Word Break (17)
9. ✅ Palindrome Problems (26, 30, 31)
10. ✅ Target Sum (25)

### **Frequently Asked**
- **Google**: LIS, Edit Distance, Burst Balloons, Unique Paths
- **Amazon**: Coin Change, Knapsack variants, LCS, Partition problems
- **Facebook**: Matrix Chain, Word Break, Palindrome Partitioning
- **Microsoft**: Maximum Subarray, Longest Palindrome, Egg Drop
- **Apple**: House Robber, Climbing Stairs, Unique Paths

---

## 📖 Pattern Templates

### **1. Linear DP**
```cpp
vector<int> dp(n);
dp[0] = base_case;

for (int i = 1; i < n; i++) {
    dp[i] = function(dp[i-1], dp[i-2], ...);
}
```

### **2. 0/1 Knapsack**
```cpp
vector<int> dp(capacity + 1, 0);

for (int item : items) {
    for (int w = capacity; w >= item.weight; w--) {  // Right to left!
        dp[w] = max(dp[w], dp[w - item.weight] + item.value);
    }
}
```

### **3. Unbounded Knapsack**
```cpp
vector<int> dp(capacity + 1, 0);

for (int item : items) {
    for (int w = item.weight; w <= capacity; w++) {  // Left to right!
        dp[w] = max(dp[w], dp[w - item.weight] + item.value);
    }
}
```

### **4. LCS (2D DP)**
```cpp
vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (s1[i-1] == s2[j-1]) {
            dp[i][j] = 1 + dp[i-1][j-1];
        } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
```

### **5. Interval DP**
```cpp
for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        for (int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
        }
    }
}
```

---

## 🎓 Study Plan (5 Days Before Interview)

### **Day 1: Foundation (6 hours)**
- Morning: Problems 1-5 (Linear DP)
- Afternoon: Problems 6-10 (Subsequence DP)
- Evening: Practice variations

### **Day 2: Knapsack Master (6 hours)**
- Morning: 0/1 Knapsack (21) - ALL approaches
- Afternoon: Unbounded (22), Rod Cutting (23), Coin Change II (24)
- Evening: Target Sum (25), Subset problems (37, 38)

### **Day 3: String DP (6 hours)**
- Morning: LCS (08), Edit Distance (09)
- Afternoon: Palindrome problems (26, 30, 31)
- Evening: Word Break (17), Interleaving (33)

### **Day 4: Advanced Patterns (6 hours)**
- Morning: Matrix Chain (27), Burst Balloons (29)
- Afternoon: Egg Drop (28), Partition DP
- Evening: Game Theory (36), Catalan (35)

### **Day 5: Review & Hard Problems (6 hours)**
- Morning: Revise templates, solve random problems
- Afternoon: Scramble String (34), TSP (39)
- Evening: Mock interview practice

---

## ⚡ Quick Recognition Guide

**How to identify DP pattern:**

| Problem Type | Keywords | Pattern |
|--------------|----------|---------|
| Count ways | "How many ways", "number of" | Counting DP |
| Optimize | "Maximum", "minimum", "longest" | Optimization DP |
| Subset/Partition | "Subset", "partition", "knapsack" | 0/1 or Unbounded |
| String matching | Two strings, "common", "edit" | 2D String DP |
| Interval | "Split", "partition", "range" | Interval DP |
| Grid paths | "Paths", "grid", "obstacles" | Grid DP |
| Game | "Optimal play", "two players" | Game Theory DP |

---

## 💡 Interview Tips

1. **Always ask about constraints**:
   - n ≤ 20 → Bitmask DP possible
   - n ≤ 1000 → O(n²) or O(n³) acceptable
   - n ≤ 10⁶ → Need O(n) or O(n log n)

2. **Start with brute force**:
   - Explain recursive solution first
   - Identify overlapping subproblems
   - Add memoization
   - Convert to bottom-up

3. **Space optimization**:
   - Often can reduce from 2D to 1D
   - Mention even if not implementing

4. **Common mistakes**:
   - Wrong loop direction (knapsack!)
   - Off-by-one errors
   - Integer overflow
   - Not handling edge cases

5. **Time management**:
   - 5 min: Understand problem
   - 5 min: Discuss approach
   - 15 min: Code
   - 5 min: Test & optimize

---

## 📊 Complexity Cheat Sheet

| Pattern | Time | Space | Example |
|---------|------|-------|---------|
| Linear DP | O(n) | O(n) → O(1) | Fibonacci, Climbing Stairs |
| 2D DP | O(n²) or O(m*n) | O(n²) → O(n) | LCS, Edit Distance |
| Knapsack | O(n*W) | O(W) | 0/1, Unbounded |
| Interval DP | O(n³) | O(n²) | MCM, Burst Balloons |
| Grid DP | O(m*n) | O(n) | Unique Paths |
| Bitmasking | O(n²*2ⁿ) | O(n*2ⁿ) | TSP |

---

## 🚀 Advanced Optimizations

1. **Space Optimization**: 2D → 1D using rolling array
2. **Binary Search**: Egg Drop, LIS
3. **Segment Tree**: Range query DP
4. **Divide & Conquer**: Some partition DP
5. **Memoization vs Tabulation**: Choose based on problem

---

## 📝 Notes

- All problems have **multiple approaches** (recursive, memo, bottom-up, optimized)
- **Detailed explanations** with example traces
- **Pattern connections** highlighted
- **Interview tips** in every file
- **Common mistakes** section
- **Related problems** listed

---

## 🏆 Final Checklist Before Interview

- [ ] Can recognize all 8 DP patterns instantly
- [ ] Know knapsack template by heart
- [ ] Can explain state transitions clearly
- [ ] Understand time/space complexity
- [ ] Practiced at least 3 problems from each category
- [ ] Can optimize space in common patterns
- [ ] Know when to use top-down vs bottom-up
- [ ] Comfortable with edge cases

---

## 🎯 Success Mantra

> **"Identify the pattern, define the state, write the recurrence, optimize the space!"**

**Good luck with your FAANG interview! 🚀**

---

*Last Updated: December 17, 2024*
*Total Problems: 40*
*Coverage: ALL DP patterns for FAANG interviews*
