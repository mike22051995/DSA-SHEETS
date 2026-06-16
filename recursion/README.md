# Recursion - FAANG Interview Preparation
## 30 Essential Problems with Complete Solutions

Master ALL recursion patterns from basics to expert level - ready to crack any FAANG interview!

---

## 📚 Pattern Classification

### Level 1: Basic Recursion - EASY (Problems 1-8)
**Foundation concepts - Start here!**
- ✅ 01_factorial.cpp - Linear recursion, tail recursion
- ✅ 02_fibonacci.cpp - Tree recursion, memoization
- ✅ 03_power.cpp - Divide and conquer, O(log n)
- ✅ 04_sum_of_digits.cpp - Breaking down numbers
- ✅ 05_reverse_string.cpp - Two approaches
- ✅ 06_palindrome_check.cpp - Two-pointer recursion
- ✅ 07_count_digits.cpp - Simple linear recursion
- ✅ 08_gcd.cpp - Euclidean algorithm

### Level 2: Array & String Recursion - EASY-MEDIUM (Problems 9-15)
**Build problem-solving intuition**
- ✅ 09_binary_search.cpp - Divide and conquer classic
- ✅ 10_print_array.cpp - Forward and reverse printing
- ✅ 11_check_sorted.cpp - Array validation
- ✅ 12_sum_array.cpp - Aggregation pattern
- ✅ 13_remove_occurrences.cpp - String building
- ✅ 14_string_subsequences.cpp - Include/exclude pattern
- ✅ 15_tower_of_hanoi.cpp - Classic recursion puzzle

### Level 3: Backtracking Fundamentals - MEDIUM (Problems 16-22)
**Master the backtracking template**
- ✅ 16_subsets.cpp - Power set generation
- ✅ 17_permutations.cpp - All arrangements
- ✅ 18_combinations.cpp - Choose K from N
- ✅ 19_letter_combinations.cpp - Phone keypad
- ✅ 20_generate_parentheses.cpp - Constraint-based
- ✅ 21_word_search.cpp - 2D grid DFS
- ✅ 22_palindrome_partitioning.cpp - String partitioning

### Level 4: Advanced Backtracking - MEDIUM-HARD (Problems 23-27)
**Interview favorites - Practice these!**
- ✅ 23_n_queens.cpp - Constraint satisfaction
- ✅ 24_sudoku_solver.cpp - Complex validation
- ✅ 25_combination_sum.cpp - Unbounded choices
- ✅ 26_restore_ip_addresses.cpp - String partitioning with rules
- ✅ 27_beautiful_arrangement.cpp - Constrained permutations

### Level 5: Expert Level - HARD (Problems 28-30)
**Top 1% candidates solve these**
- ✅ 28_regex_matching.cpp - Dynamic programming + recursion
- ✅ 29_wildcard_matching.cpp - Pattern matching
- ✅ 30_expression_add_operators.cpp - Expression evaluation

---

## 🎯 14-Day Study Plan

### **Week 1: Foundations & Arrays**

**Day 1: Basic Recursion (1-4)**
- Master base case identification
- Understand recursion tree
- Practice: Factorial, Fibonacci, Power, Sum of Digits

**Day 2: String Recursion (5-8)**
- String manipulation patterns
- Palindrome checks
- Practice: Reverse, Palindrome, Count Digits, GCD

**Day 3: Arrays & Search (9-12)**
- Divide and conquer
- Array traversal recursively
- Practice: Binary Search, Print Array, Check Sorted, Sum Array

**Day 4: String Building (13-15)**
- Include/exclude pattern
- Classic problems
- Practice: Remove Occurrences, Subsequences, Tower of Hanoi

**Day 5-6: Backtracking Basics (16-18)**
- Understand backtracking template
- Choose/Explore/Unchoose pattern
- Practice: Subsets, Permutations, Combinations

**Day 7: Review Week 1**
- Solve all problems again without looking
- Time yourself: 20 min per problem

### **Week 2: Advanced Patterns**

**Day 8: Backtracking with Constraints (19-20)**
- Multi-branch recursion
- Constraint validation
- Practice: Letter Combinations, Generate Parentheses

**Day 9: 2D Grid & Partitioning (21-22)**
- DFS in grids
- String partitioning
- Practice: Word Search, Palindrome Partitioning

**Day 10: Constraint Satisfaction (23-24)**
- Complex validation
- Multiple constraints
- Practice: N-Queens, Sudoku Solver

**Day 11: Advanced Combinations (25-27)**
- Unbounded choices
- Complex partitioning
- Practice: Combination Sum, IP Addresses, Beautiful Arrangement

**Day 12: Expert Problems (28-30)**
- Memoization techniques
- Complex state management
- Practice: Regex, Wildcard, Expression Operators

**Day 13: Mock Interview**
- 3 random problems (1 easy, 1 medium, 1 hard)
- Explain approach out loud
- 45 minutes per problem

**Day 14: Final Review**
- Quick review of all 30 problems
- Focus on patterns, not memorization
- Write down key insights

---

## 💡 Core Recursion Patterns

### 1. **Linear Recursion**
```cpp
int linearRecursion(int n) {
    // Base case
    if (n == 0) return baseValue;
    
    // Recursive case
    return operation(n, linearRecursion(n - 1));
}
```
**Used in:** Factorial, Sum of Digits, Count Digits

### 2. **Tree Recursion (Multiple Calls)**
```cpp
int treeRecursion(int n) {
    if (n <= 1) return n;
    
    return treeRecursion(n - 1) + treeRecursion(n - 2);
}
```
**Used in:** Fibonacci, Subsequences

### 3. **Divide and Conquer**
```cpp
int divideConquer(arr, left, right) {
    if (left >= right) return baseCase;
    
    int mid = left + (right - left) / 2;
    
    return combine(
        divideConquer(arr, left, mid),
        divideConquer(arr, mid + 1, right)
    );
}
```
**Used in:** Binary Search, Merge Sort, Power

### 4. **Backtracking Template**
```cpp
void backtrack(state, choices, result) {
    // Base case
    if (isComplete(state)) {
        result.add(state);
        return;
    }
    
    // Try each choice
    for (choice : choices) {
        if (isValid(choice)) {
            makeChoice(choice);      // Choose
            backtrack(newState);     // Explore
            undoChoice(choice);      // Unchoose (Backtrack)
        }
    }
}
```
**Used in:** Subsets, Permutations, N-Queens, Sudoku

### 5. **Memoization Pattern**
```cpp
int solve(params, memo) {
    // Check memo
    if (memo[key] != -1) return memo[key];
    
    // Base case
    if (baseCondition) return baseValue;
    
    // Recursive case
    int result = recursiveCalls();
    
    // Store in memo
    memo[key] = result;
    return result;
}
```
**Used in:** Fibonacci (optimized), Regex Matching, Wildcard

---

## 🔥 Interview Success Tips

### **Before the Interview:**
1. ✅ Understand recursion tree visualization
2. ✅ Master base case identification
3. ✅ Practice explaining recursive calls
4. ✅ Know time/space complexity analysis

### **During the Interview:**
1. **Always start with base case**
   - What's the simplest input?
   - What should it return?

2. **Draw the recursion tree**
   - Helps visualize the problem
   - Shows interviewer your thinking

3. **Identify the pattern**
   - Is it linear, tree, or backtracking?
   - What are the choices at each step?

4. **Think about optimization**
   - Can you add memoization?
   - Is there repeated work?

5. **Trace a small example**
   - Walk through n=2 or n=3
   - Verify base case works

### **Common Mistakes to Avoid:**
- ❌ Forgetting base case → Stack overflow
- ❌ Wrong recursive call parameters
- ❌ Not considering edge cases (empty input, n=0)
- ❌ Forgetting to backtrack (in backtracking problems)
- ❌ Not handling memoization correctly

---

## 📊 Complexity Cheat Sheet

| Pattern | Time | Space | Example |
|---------|------|-------|---------|
| Linear Recursion | O(n) | O(n) | Factorial, Sum |
| Tree Recursion (naive) | O(2^n) | O(n) | Fibonacci |
| Tree Recursion (memo) | O(n) | O(n) | Fibonacci optimized |
| Divide & Conquer | O(log n) | O(log n) | Binary Search, Power |
| Backtracking (all subsets) | O(2^n) | O(n) | Subsets |
| Backtracking (permutations) | O(n!) | O(n) | Permutations |
| N-Queens | O(n!) | O(n²) | N-Queens |

---

## 🎓 Key Concepts to Master

### **1. Base Case**
- Smallest input that can be solved directly
- Prevents infinite recursion
- Usually: n == 0, n == 1, empty array, etc.

### **2. Recursive Case**
- How to break problem into smaller subproblems
- Trust that recursion solves smaller problem
- Combine results appropriately

### **3. Recursion Tree**
- Visual representation of recursive calls
- Helps understand time complexity
- Shows overlapping subproblems

### **4. Backtracking**
- Choose → Explore → Unchoose
- Used when exploring all possibilities
- Must undo changes after exploration

### **5. Memoization**
- Cache results to avoid recomputation
- Converts exponential to polynomial
- Essential for interview optimization

---

## 🚀 How to Compile and Run

For any problem:
```powershell
# Compile
g++ -std=c++17 01_factorial.cpp -o 01_factorial

# Run
.\01_factorial
```

Compile all:
```powershell
Get-ChildItem *.cpp | ForEach-Object { g++ -std=c++17 $_.Name -o $_.BaseName }
```

---

## 🎯 Pattern Recognition Guide

**When you see:**
- "Find all combinations" → Backtracking
- "Generate all permutations" → Backtracking (swap method)
- "Check if possible" → Recursion with pruning
- "Count number of ways" → Recursion with memoization
- "Divide into halves" → Divide and conquer
- "Grid/matrix search" → DFS backtracking
- "String matching/pattern" → Recursion with memo

---

## ✅ Progress Tracker

- [ ] **Week 1 - Basics (1-15)**
  - [ ] Day 1: Basic Recursion (1-4)
  - [ ] Day 2: String Recursion (5-8)
  - [ ] Day 3: Arrays & Search (9-12)
  - [ ] Day 4: String Building (13-15)
  - [ ] Day 5-6: Backtracking Basics (16-18)
  - [ ] Day 7: Review

- [ ] **Week 2 - Advanced (16-30)**
  - [ ] Day 8: Constraints (19-20)
  - [ ] Day 9: 2D & Partitioning (21-22)
  - [ ] Day 10: Satisfaction (23-24)
  - [ ] Day 11: Advanced (25-27)
  - [ ] Day 12: Expert (28-30)
  - [ ] Day 13: Mock Interview
  - [ ] Day 14: Final Review

---

## 🌟 Expected Outcomes

After completing all 30 problems:
- ✅ Recognize recursion patterns instantly
- ✅ Write base cases without thinking
- ✅ Implement backtracking fluently
- ✅ Optimize with memoization
- ✅ Analyze time/space complexity accurately
- ✅ Solve 90% of recursion problems in interviews
- ✅ Explain recursive thinking clearly

---

## 💪 Final Tips

1. **Don't just code - understand WHY**
   - Why this base case?
   - Why these recursive calls?
   - Why backtrack here?

2. **Practice explaining out loud**
   - Pretend you're teaching someone
   - Use proper terminology
   - Draw diagrams

3. **Start simple, then optimize**
   - Get brute force working first
   - Then add memoization
   - Then optimize space

4. **Pattern over memorization**
   - Understand the template
   - Apply to different problems
   - Don't memorize solutions

---

## 🔑 Quick Reference

**Most Important Problems:**
- 🌟 Fibonacci (memoization)
- 🌟 Subsets (backtracking template)
- 🌟 Permutations (swap technique)
- 🌟 Generate Parentheses (constraints)
- 🌟 N-Queens (constraint satisfaction)
- 🌟 Word Search (2D DFS)

**Practice These Daily:**
- Days 1-7: At least 4 problems/day
- Days 8-12: At least 3 problems/day
- Days 13-14: Review and mock

---

## 🎉 You've Got This!

Recursion seems magical at first, but with practice it becomes intuitive. 

**Remember:** Every expert was once a beginner who didn't give up!

Good luck with your FAANG interview! 🚀
