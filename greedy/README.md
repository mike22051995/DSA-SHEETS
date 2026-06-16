# 🎯 Greedy Algorithms - Complete FAANG Interview Preparation

> **Interview Date:** Friday, December 13, 2025  
> **Total Problems:** 30 (10 Easy + 10 Medium + 10 Hard)  
> **Language:** C++

---

## 📋 Table of Contents
- [Overview](#overview)
- [Why Greedy Algorithms?](#why-greedy-algorithms)
- [Problem List](#problem-list)
- [Key Patterns](#key-patterns)
- [How to Use This Collection](#how-to-use-this-collection)
- [Compilation Instructions](#compilation-instructions)
- [Study Plan](#study-plan)

---

## 🎓 Overview

This collection contains **30 most famous greedy algorithm problems** that are frequently asked in FAANG interviews (Facebook/Meta, Amazon, Apple, Netflix, Google). Each problem is carefully selected to cover a specific greedy pattern that will help you solve any greedy problem in interviews.

### What's Included:
- ✅ Problem description with constraints
- ✅ Complete working C++ code
- ✅ Multiple test cases with expected outputs
- ✅ Time and space complexity analysis
- ✅ Detailed explanation of why greedy approach works
- ✅ Key learning points and patterns
- ✅ Interview tips

---

## 🤔 Why Greedy Algorithms?

Greedy algorithms are **crucial** for FAANG interviews because:
1. **High frequency** - Appears in 25-30% of coding interviews
2. **Thinking process** - Tests your ability to prove correctness
3. **Optimization** - Shows you can find efficient solutions
4. **Real-world applications** - Resource allocation, scheduling, routing
5. **Foundation** - Understanding greedy helps with DP and other paradigms

### When to Use Greedy:
- ✅ Problem asks for optimization (min/max)
- ✅ Local optimal choice leads to global optimal
- ✅ Problem has greedy choice property
- ✅ Problem has optimal substructure
- ✅ No need to reconsider past decisions

---

## 📚 Problem List

### 🟢 EASY Problems (1-10)

| # | Problem | Pattern | Difficulty | Company | Time | File |
|---|---------|---------|------------|---------|------|------|
| 1 | **Assign Cookies** | Two Pointer Matching | Easy | Google, Amazon | O(n log n) | `01_assign_cookies.cpp` |
| 2 | **Lemonade Change** | Greedy Simulation | Easy | Amazon, Facebook | O(n) | `02_lemonade_change.cpp` |
| 3 | **Best Time to Buy/Sell Stock II** | Peak Valley | Easy | Facebook, Amazon, Microsoft | O(n) | `03_best_time_to_buy_sell_stock_2.cpp` |
| 4 | **Maximum Subarray (Kadane's)** | Running Sum | Easy | Amazon, Microsoft, Google | O(n) | `04_maximum_subarray.cpp` |
| 5 | **Can Place Flowers** | Local Constraints | Easy | LinkedIn, Google | O(n) | `05_can_place_flowers.cpp` |
| 6 | **Majority Element** | Boyer-Moore Voting | Easy | Google, Facebook, Adobe | O(n) | `06_majority_element.cpp` |
| 7 | **Minimum Cost to Move Chips** | Parity-Based | Easy | Amazon | O(n) | `07_minimum_cost_to_move_chips.cpp` |
| 8 | **Maximum Units on Truck** | Fractional Knapsack | Easy | Amazon | O(n log n) | `08_maximum_units_on_truck.cpp` |
| 9 | **Maximum 69 Number** | Single Change | Easy | Facebook | O(d) | `09_maximum_69_number.cpp` |
| 10 | **Min Operations Array Equal** | Mathematical | Easy | Microsoft | O(1) | `10_minimum_operations_to_make_array_equal.cpp` |

### 🟡 MEDIUM Problems (11-20)

| # | Problem | Pattern | Difficulty | Company | Time | File |
|---|---------|---------|------------|---------|------|------|
| 11 | **Jump Game** | Reachability Tracking | Medium | Google, Amazon, Facebook | O(n) | `11_jump_game.cpp` |
| 12 | **Jump Game II** | Greedy BFS | Medium | Google, Facebook, Amazon | O(n) | `12_jump_game_2.cpp` |
| 13 | **Gas Station** | Circular Array | Medium | Amazon, Google, Microsoft | O(n) | `13_gas_station.cpp` |
| 14 | **Partition Labels** | Interval Merging | Medium | Facebook, Amazon | O(n) | `14_partition_labels.cpp` |
| 15 | **Non-overlapping Intervals** | Activity Selection | Medium | Amazon, Google, Facebook | O(n log n) | `15_non_overlapping_intervals.cpp` |
| 16 | **Min Arrows Burst Balloons** | Interval Coverage | Medium | Google, Microsoft | O(n log n) | `16_minimum_arrows_to_burst_balloons.cpp` |
| 17 | **Task Scheduler** | Scheduling with Cooling | Medium | Facebook, Amazon, Google | O(n) | `17_task_scheduler.cpp` |
| 18 | **Connect Sticks** | Huffman Coding | Medium | Amazon, Google | O(n log n) | `18_minimum_cost_to_connect_sticks.cpp` |
| 19 | **Boats to Save People** | Two Pointer Pairing | Medium | Google, Amazon | O(n log n) | `19_boats_to_save_people.cpp` |
| 20 | **Reorganize String** | Max Heap Scheduling | Medium | Google, Facebook, Amazon | O(n log k) | `20_reorganize_string.cpp` |

### 🔴 HARD Problems (21-30)

| # | Problem | Pattern | Difficulty | Company | Time | File |
|---|---------|---------|------------|---------|------|------|
| 21 | **Candy** | Two-Pass Bidirectional | Hard | Google, Facebook | O(n) | `21_candy.cpp` |
| 22 | **Remove K Digits** | Monotonic Stack | Hard | Google, Amazon, TikTok | O(n) | `22_remove_k_digits.cpp` |
| 23 | **Create Maximum Number** | Complex Merge | Hard | Google | O(k(m+n)²) | `23_create_maximum_number.cpp` |
| 24 | **Patching Array** | Range Coverage | Hard | Google | O(m + log n) | `24_patching_array.cpp` |
| 25 | **Split Array Largest Sum** | Binary Search + Greedy | Hard | Google, Facebook, ByteDance | O(n log sum) | `25_split_array_largest_sum.cpp` |
| 26 | **IPO** | Two Heaps | Hard | Google, Amazon | O(n log n) | `26_ipo.cpp` |
| 27 | **Min Taps Water Garden** | Jump Game Variant | Hard | Google, Amazon | O(n) | `27_minimum_taps_to_water_garden.cpp` |
| 28 | **Wildcard Matching** | Greedy Backtracking | Hard | Google, Facebook | O(min(s,p)) | `28_wildcard_matching.cpp` |
| 29 | **Min Cost Hire K Workers** | Ratio Sorting + Heap | Hard | Google, Facebook | O(n log n) | `29_minimum_cost_to_hire_k_workers.cpp` |
| 30 | **Trapping Rain Water** | Two Pointer | Hard | Google, Amazon, Facebook, Microsoft | O(n) | `30_trapping_rain_water.cpp` |

---

## 🎯 Key Patterns

### 1. **Sorting-Based Greedy**
Problems where sorting enables greedy choice:
- Assign Cookies (#1)
- Maximum Units on Truck (#8)
- Non-overlapping Intervals (#15)
- Min Arrows Burst Balloons (#16)
- Boats to Save People (#19)

**Key Insight:** Sort by the property that enables greedy selection (end time, value density, etc.)

---

### 2. **Two Pointer Techniques**
Problems using two pointers for greedy decisions:
- Assign Cookies (#1)
- Boats to Save People (#19)
- Trapping Rain Water (#30)
- Wildcard Matching (#28)

**Key Insight:** Process from both ends or maintain window with optimal properties.

---

### 3. **Heap-Based Greedy**
Problems requiring priority-based selection:
- Connect Sticks (#18)
- Reorganize String (#20)
- IPO (#26)
- Min Cost Hire K Workers (#29)

**Key Insight:** Always pick the best available option using min/max heap.

---

### 4. **Interval Scheduling**
Classic interval problems:
- Non-overlapping Intervals (#15)
- Min Arrows Burst Balloons (#16)
- Partition Labels (#14)
- Min Taps Water Garden (#27)

**Key Insight:** Sort by end time, greedily select non-overlapping intervals.

---

### 5. **Monotonic Stack/Deque**
Maintaining increasing/decreasing order:
- Remove K Digits (#22)
- Create Maximum Number (#23)

**Key Insight:** Remove elements that violate monotonic property while constraints allow.

---

### 6. **Greedy BFS (Without Queue)**
Range-based exploration:
- Jump Game (#11)
- Jump Game II (#12)
- Min Taps Water Garden (#27)

**Key Insight:** Track current range end and maximum reachable, increment level when needed.

---

### 7. **Two-Pass Greedy**
Bidirectional constraint satisfaction:
- Candy (#21)

**Key Insight:** One pass for each direction, use max to combine results.

---

### 8. **Mathematical/Counting Greedy**
Problems with closed-form solutions:
- Maximum Subarray (Kadane's) (#4)
- Majority Element (Boyer-Moore) (#6)
- Min Cost Move Chips (#7)
- Min Operations Array Equal (#10)

**Key Insight:** Look for mathematical properties that simplify the problem.

---

### 9. **Simulation with State Tracking**
Sequential processing with state:
- Lemonade Change (#2)
- Best Time to Buy/Sell Stock II (#3)
- Can Place Flowers (#5)

**Key Insight:** Process events in order, maintain minimal necessary state.

---

### 10. **Binary Search + Greedy Validation**
Optimization with feasibility check:
- Split Array Largest Sum (#25)

**Key Insight:** Binary search on answer space, use greedy to validate feasibility.

---

### 11. **Circular Array Greedy**
Problems on circular structures:
- Gas Station (#13)

**Key Insight:** If solution exists, it's unique; use running sum with reset strategy.

---

### 12. **Greedy with Ratio/Density**
Sort by value per unit:
- Maximum Units on Truck (#8)
- Min Cost Hire K Workers (#29)

**Key Insight:** Calculate ratio, sort by it, process in order.

---

## 🚀 How to Use This Collection

### For Interview Preparation:

#### **Week 1: Foundation (Easy)**
- Days 1-2: Problems 1-5
- Days 3-4: Problems 6-10
- Day 5: Review and practice variations

#### **Week 2: Intermediate (Medium)**
- Days 1-2: Problems 11-14
- Days 3-4: Problems 15-18
- Days 5-6: Problems 19-20
- Day 7: Review patterns

#### **Week 3: Advanced (Hard)**
- Days 1-2: Problems 21-23
- Days 3-4: Problems 24-26
- Days 5-6: Problems 27-30
- Day 7: Mock interviews

#### **Last 2 Days Before Interview:**
- Review all patterns
- Practice explaining "why greedy works"
- Focus on problems you found difficult
- Do timed mock interviews

---

## 💻 Compilation Instructions

### Compile Single File:
```bash
g++ -std=c++17 01_assign_cookies.cpp -o 01_assign_cookies
./01_assign_cookies
```

### Compile All Files (PowerShell):
```powershell
Get-ChildItem -Filter *.cpp | ForEach-Object {
    $name = $_.BaseName
    g++ -std=c++17 $_.Name -o "$name.exe"
}
```

### Run All Tests:
```powershell
Get-ChildItem -Filter *.exe | ForEach-Object {
    Write-Host "`n=== Running $($_.Name) ===" -ForegroundColor Green
    & $_.FullName
}
```

### Compile with Optimizations:
```bash
g++ -std=c++17 -O2 -Wall -Wextra problem.cpp -o problem
```

---

## 📖 Study Plan

### **2 Days Before Interview (Today: Dec 11)**

#### Morning Session (3 hours):
1. **Review Easy Problems (1-10)** - 90 mins
   - Focus on patterns: sorting, two pointer, simulation
   - Practice explaining why greedy works
   
2. **Practice Medium Problems (11-15)** - 90 mins
   - Jump game patterns
   - Interval scheduling
   - Gas station logic

#### Afternoon Session (3 hours):
1. **Medium Problems (16-20)** - 90 mins
   - Task scheduler
   - Heap-based greedy
   - String reorganization

2. **Hard Problems Introduction (21-23)** - 90 mins
   - Candy distribution
   - Monotonic stack pattern
   - Two-pass greedy

#### Evening Session (2 hours):
- Review all patterns learned today
- Practice proving greedy correctness
- Write down key insights

---

### **1 Day Before Interview (Dec 12)**

#### Morning Session (3 hours):
1. **Hard Problems (24-27)** - 120 mins
   - Binary search + greedy
   - Two heaps pattern
   - Range coverage

2. **Review Session** - 60 mins
   - Go through all patterns
   - Practice time/space complexity analysis

#### Afternoon Session (3 hours):
1. **Hard Problems (28-30)** - 90 mins
   - Wildcard matching
   - Ratio-based greedy
   - Trapping rain water

2. **Mock Interview** - 90 mins
   - Pick 2 medium + 1 hard randomly
   - Practice under time pressure
   - Explain your thought process out loud

#### Evening Session (2 hours):
- **Light Review Only**
  - Go through pattern summary
  - Review problems you struggled with
  - Get good sleep! 😴

---

### **Interview Day (Dec 13)**

#### Before Interview:
- Quick 30-min review of key patterns
- Don't try to learn new problems
- Stay confident and calm

#### During Interview:
1. **Listen carefully** to the problem
2. **Ask clarifying questions**
3. **Identify the pattern** (use this collection as mental reference)
4. **Explain your approach** before coding
5. **Prove why greedy works**
6. **Write clean code** with comments
7. **Test with examples**
8. **Analyze complexity**

---

## 🎯 Interview Tips

### How to Identify Greedy Problems:
1. Problem asks for **optimal value** (min/max)
2. Making **locally optimal choice** seems reasonable
3. Problem has **no dependencies** on future decisions
4. **Sorting** might help organize choices
5. Problem involves **intervals, scheduling, or selection**

### How to Prove Greedy Works:
1. **Greedy Choice Property**: Show local optimal leads to global optimal
2. **Optimal Substructure**: After greedy choice, remaining problem is similar
3. **Exchange Argument**: Show swapping greedy choice with optimal doesn't improve
4. **Induction**: Prove for base case and inductive step

### Common Mistakes to Avoid:
❌ Not proving why greedy works  
❌ Confusing greedy with dynamic programming  
❌ Forgetting edge cases (empty array, single element)  
❌ Not optimizing time complexity  
❌ Poor variable naming  

### What Interviewers Look For:
✅ Clear thinking process  
✅ Ability to identify pattern  
✅ Proof of correctness  
✅ Clean, bug-free code  
✅ Complexity analysis  
✅ Test case coverage  

---

## 🏆 FAANG-Specific Insights

### **Google:**
- Loves: Jump Game variations, Interval problems, Hard greedy
- Focus: Proving correctness, handling edge cases
- Common: Problems 11, 12, 15, 21, 22, 25, 26, 29, 30

### **Amazon:**
- Loves: Practical greedy, Sorting-based, Medium difficulty
- Focus: Working code quickly, optimization
- Common: Problems 1, 2, 3, 8, 11, 13, 14, 15, 18, 27

### **Facebook/Meta:**
- Loves: String problems, Scheduling, Heap-based
- Focus: Multiple solutions, trade-offs
- Common: Problems 3, 6, 11, 14, 17, 20, 21, 28, 29, 30

### **Microsoft:**
- Loves: Classic problems, Two-pointer, Array manipulation
- Focus: Clear explanation, complexity analysis
- Common: Problems 3, 4, 10, 13, 16, 22, 30

### **Apple:**
- Loves: Clean code, Optimal solutions
- Focus: Code quality, readability
- Common: Standard greedy patterns

---

## 📊 Complexity Cheat Sheet

| Pattern | Typical Time | Typical Space | Example |
|---------|--------------|---------------|---------|
| Sorting + Greedy | O(n log n) | O(1) | Assign Cookies |
| Two Pointer | O(n) | O(1) | Boats to Save People |
| Heap-based | O(n log n) | O(n) | Connect Sticks |
| Monotonic Stack | O(n) | O(n) | Remove K Digits |
| Two-Pass | O(n) | O(n) | Candy |
| Kadane's | O(n) | O(1) | Maximum Subarray |
| Binary Search + Greedy | O(n log sum) | O(1) | Split Array |

---

## 🎓 Additional Resources

### Related Patterns:
- **Dynamic Programming**: When greedy doesn't work (overlapping subproblems)
- **Divide and Conquer**: Break problem into independent subproblems
- **Backtracking**: When need to explore multiple paths

### Practice Platforms:
- LeetCode: Filter by "Greedy" tag
- HackerRank: Greedy algorithms section
- Codeforces: Greedy problems

### Books:
- "Introduction to Algorithms" (CLRS) - Chapter on Greedy Algorithms
- "Algorithm Design Manual" - Greedy approach section

---

## ✅ Final Checklist

### Before Your Interview:
- [ ] Completed all 30 problems
- [ ] Can explain each pattern
- [ ] Can prove why greedy works for each
- [ ] Practiced time/space complexity analysis
- [ ] Done mock interviews with timer
- [ ] Reviewed edge cases and corner cases
- [ ] Confident in implementing from scratch

### During Interview:
- [ ] Listen to entire problem
- [ ] Ask clarifying questions
- [ ] Identify the greedy pattern
- [ ] Explain approach before coding
- [ ] Prove correctness
- [ ] Write clean code
- [ ] Test with examples
- [ ] Analyze complexity

---

## 💪 Motivation

> "Greedy algorithms work when local optimal choices lead to global optimal solutions. Your preparation is the same - each problem you solve is a local optimal choice leading to your global optimal outcome: landing your dream FAANG job!"

**You've got this! 🚀**

All 30 problems cover every major greedy pattern. After completing this collection, you'll be able to:
- ✅ Identify greedy problems instantly
- ✅ Choose the right pattern
- ✅ Prove correctness confidently
- ✅ Write optimal solutions quickly
- ✅ Handle follow-up questions
- ✅ Ace your FAANG interview!

---

## 📞 Quick Reference

### Pattern Recognition Flowchart:
```
Is it optimization problem (min/max)?
  └─ YES → Can you make local optimal choice?
      └─ YES → Does it need future information?
          └─ NO → GREEDY ✓
          └─ YES → Maybe DP
      └─ NO → Try other approaches
  └─ NO → Not greedy
```

### Common Greedy Proof Techniques:
1. **Exchange Argument**: Swap greedy solution with optimal, show no improvement
2. **Stays Ahead**: Greedy always at least as good as optimal at each step
3. **Induction**: Prove base case and inductive step

---

## 🎯 Good Luck!

**Remember:** The greedy approach is about making the best local choice. You've prepared by solving the best problems. Now make the best interview choices!

**Interview Date:** Friday, December 13, 2025  
**You're Ready:** 30/30 Problems ✓

---

*Last Updated: December 11, 2025*  
*Created for: FAANG Interview Preparation*  
*Author: Prepared with 💯 dedication for success*
