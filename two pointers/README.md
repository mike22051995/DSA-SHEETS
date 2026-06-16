# Two Pointers - FAANG Interview Preparation
## 30 Essential Problems with Complete Solutions

This collection covers ALL major two-pointer patterns you need to crack any FAANG interview!

---

## 📚 Pattern Classification

### Pattern 1: Opposite Direction Two Pointers (Problems 1-8)
**When to use:** Sorted arrays, finding pairs, optimization problems
- ✅ 01_two_sum_II.cpp - Classic two-pointer on sorted array
- ✅ 02_valid_palindrome.cpp - String validation from both ends
- ✅ 03_container_with_most_water.cpp - Greedy optimization
- ✅ 04_3sum.cpp - Extended two-pointer with fixed element
- ✅ 05_4sum.cpp - Nested two-pointer approach
- ✅ 06_trapping_rain_water.cpp - Advanced water trapping
- ✅ 07_two_sum_less_than_k.cpp - Constraint-based pairing
- ✅ 08_remove_duplicates_sorted_array.cpp - In-place modification

### Pattern 2: Same Direction (Fast-Slow) Two Pointers (Problems 9-15)
**When to use:** In-place array modification, partitioning
- ✅ 09_remove_element.cpp - Remove specific values
- ✅ 10_move_zeroes.cpp - Reorder elements
- ✅ 11_sort_colors.cpp - Dutch National Flag (3 pointers!)
- ✅ 12_remove_duplicates_II.cpp - Allow limited duplicates
- ✅ 13_partition_array.cpp - Partition around pivot
- ✅ 14_squares_sorted_array.cpp - Merge from both ends
- ✅ 15_merge_sorted_array.cpp - Backward merging technique

### Pattern 3: Sliding Window (Problems 16-22)
**When to use:** Substring/subarray problems, optimization with constraints
- ✅ 16_longest_substring_no_repeat.cpp - Variable window with set
- ✅ 17_min_size_subarray_sum.cpp - Minimum window size
- ✅ 18_max_consecutive_ones_III.cpp - Window with k flips
- ✅ 19_fruit_into_baskets.cpp - At most K distinct elements
- ✅ 20_longest_repeating_char_replacement.cpp - Character frequency
- ✅ 21_permutation_in_string.cpp - Fixed window matching
- ✅ 22_find_all_anagrams.cpp - Multiple window matches

### Pattern 4: Partition & Dutch National Flag (Problems 23-25)
**When to use:** Categorizing elements, quick select
- ✅ 23_sort_array_by_parity.cpp - Binary partitioning
- ✅ 24_segregate_even_odd.cpp - QuickSort-style partition
- ✅ 25_kth_largest_quickselect.cpp - Selection algorithm

### Pattern 5: Advanced Two Pointers (Problems 26-30)
**When to use:** Complex constraints, multiple conditions
- ✅ 26_subarray_product_less_than_k.cpp - Counting subarrays
- ✅ 27_3sum_closest.cpp - Optimization with target
- ✅ 28_minimum_window_substring.cpp - Most complex sliding window
- ✅ 29_longest_mountain.cpp - Expand from center
- ✅ 30_boats_to_save_people.cpp - Greedy pairing

---

## 🎯 Study Plan (14 Days to Interview)

### Week 1: Master the Basics
**Day 1-2:** Opposite Direction (Problems 1-8)
- Focus on: Two Sum variants, palindrome checks
- Key insight: When to move left vs right pointer

**Day 3-4:** Same Direction (Problems 9-15)
- Focus on: In-place modifications, partitioning
- Key insight: Fast pointer explores, slow pointer writes

**Day 5-6:** Sliding Window Basics (Problems 16-19)
- Focus on: Variable window expansion/contraction
- Key insight: When to expand vs when to shrink

**Day 7:** Review & Practice
- Solve all Week 1 problems again without looking at solutions

### Week 2: Advanced Patterns
**Day 8-9:** Sliding Window Advanced (Problems 20-22)
- Focus on: Fixed windows, frequency maps
- Key insight: HashMap/array for character counting

**Day 10:** Partition Techniques (Problems 23-25)
- Focus on: Dutch National Flag, QuickSelect
- Key insight: Multiple categories, pivot selection

**Day 11-12:** Advanced Problems (Problems 26-30)
- Focus on: Complex constraints, multiple techniques
- Key insight: Combining patterns

**Day 13:** Mock Interview Practice
- Pick 3 random problems, solve under time pressure (45 min each)

**Day 14:** Final Review
- Go through all 30 problems, focus on tricky ones
- Review time/space complexities

---

## 💡 Key Patterns to Remember

### 1. **Opposite Direction Pattern**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // process
        left++; right--;
    } else if (needMore) {
        left++;
    } else {
        right--;
    }
}
```

### 2. **Fast-Slow Pattern**
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (shouldKeep(arr[fast])) {
        arr[slow] = arr[fast];
        slow++;
    }
}
```

### 3. **Sliding Window Pattern**
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Expand window
    addToWindow(arr[right]);
    
    // Shrink if needed
    while (!isValid()) {
        removeFromWindow(arr[left]);
        left++;
    }
    
    // Update result
    updateResult(right - left + 1);
}
```

---

## 🔥 Interview Tips

1. **Always clarify constraints:**
   - Can array be empty?
   - Are there negative numbers?
   - Is array sorted?

2. **Think out loud:**
   - Explain why you choose a pattern
   - Mention time/space complexity

3. **Start with brute force:**
   - Then optimize to two pointers
   - Shows problem-solving process

4. **Watch for edge cases:**
   - Empty arrays
   - Single element
   - All same elements
   - Already sorted/reverse sorted

5. **Common mistakes to avoid:**
   - Off-by-one errors (left <= right vs left < right)
   - Not handling duplicates in sorted arrays
   - Forgetting to update pointers in while loops

---

## 📊 Complexity Cheat Sheet

| Pattern | Time | Space | Use Case |
|---------|------|-------|----------|
| Opposite Direction | O(n) | O(1) | Sorted arrays, pair finding |
| Fast-Slow | O(n) | O(1) | In-place modification |
| Sliding Window | O(n) | O(k) | Substring/subarray problems |
| Partition | O(n) | O(1) | Categorizing elements |
| QuickSelect | O(n) avg | O(1) | Finding kth element |

---

## 🚀 How to Compile and Run

For any problem:
```powershell
# Compile
g++ -std=c++17 01_two_sum_II.cpp -o 01_two_sum_II

# Run
.\01_two_sum_II
```

Or compile all at once:
```powershell
# Compile all files
Get-ChildItem *.cpp | ForEach-Object { g++ -std=c++17 $_.Name -o $_.BaseName }
```

---

## ✅ Practice Strategy

1. **First Pass:** Understand the problem and pattern
2. **Second Pass:** Implement without looking at solution
3. **Third Pass:** Optimize and handle edge cases
4. **Fourth Pass:** Explain to yourself as if in an interview

---

## 🎓 Expected Outcomes

After completing all 30 problems, you will:
- ✅ Recognize two-pointer patterns instantly
- ✅ Know when to use which pattern
- ✅ Handle edge cases confidently
- ✅ Optimize brute force to O(n) solutions
- ✅ Ace any two-pointer question in FAANG interviews

---

## 📝 Progress Tracker

Track your progress:
- [ ] Pattern 1: Opposite Direction (1-8)
- [ ] Pattern 2: Fast-Slow (9-15)
- [ ] Pattern 3: Sliding Window (16-22)
- [ ] Pattern 4: Partition (23-25)
- [ ] Pattern 5: Advanced (26-30)
- [ ] Mock Interview Practice
- [ ] Full Review Complete

---

## 🌟 Good Luck!

Remember: **Consistency > Perfection**

Do at least 3-4 problems daily, and you'll be ready for your interview in 2 weeks!

**You got this! 💪**
