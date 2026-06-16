# SORTING PROBLEMS - Complete Collection for FAANG Interview Preparation

## Overview
This folder contains 30 carefully curated sorting problems covering all important patterns and techniques needed to ace FAANG interviews. Each problem includes complete implementation, detailed explanation, time/space complexity analysis, and comprehensive examples.

## 📚 Problem Categories

### **EASY PROBLEMS (1-10)** ⭐
Foundation building and basic sorting techniques

1. **01_bubble_sort.cpp** - Classic bubble sort algorithm
2. **02_selection_sort.cpp** - Selection sort implementation
3. **03_insertion_sort.cpp** - Insertion sort algorithm
4. **04_merge_two_sorted_arrays.cpp** - Two pointer merge technique
5. **05_sort_array_by_parity.cpp** - Partition technique
6. **06_sort_colors.cpp** - Dutch National Flag problem (3-way partition)
7. **07_squares_of_sorted_array.cpp** - Two pointer on sorted array
8. **08_kth_largest_element_basic.cpp** - Simple sorting approach
9. **09_valid_anagram.cpp** - Sorting for comparison
10. **10_intersection_of_two_arrays.cpp** - Sorting + two pointer

### **MEDIUM PROBLEMS (11-25)** ⭐⭐
Advanced techniques and real interview questions

11. **11_merge_sort.cpp** - Divide and conquer sorting
12. **12_quick_sort.cpp** - Partition-based sorting
13. **13_heap_sort.cpp** - Heap-based sorting
14. **14_sort_linked_list.cpp** - Merge sort on linked list
15. **15_kth_largest_quickselect.cpp** - QuickSelect algorithm
16. **16_top_k_frequent_elements.cpp** - Heap/bucket sort
17. **17_merge_intervals.cpp** - Interval sorting pattern
18. **18_meeting_rooms_ii.cpp** - Sweep line algorithm
19. **19_sort_characters_by_frequency.cpp** - Frequency-based sorting
20. **20_largest_number.cpp** - Custom comparator
21. **21_custom_sort_string.cpp** - Custom ordering/counting sort
22. **22_sort_by_increasing_frequency.cpp** - Multi-level sorting
23. **23_3sum.cpp** - Sorting + two pointer
24. **24_4sum.cpp** - Extended two pointer technique
25. **25_group_anagrams.cpp** - Sorting for grouping

### **HARD PROBLEMS (26-30)** ⭐⭐⭐
Advanced patterns for senior positions

26. **26_count_smaller_after_self.cpp** - Modified merge sort
27. **27_reverse_pairs.cpp** - Merge sort with counting
28. **28_maximum_gap.cpp** - Bucket sort/radix sort
29. **29_count_of_range_sum.cpp** - Prefix sum + merge sort
30. **30_median_two_sorted_arrays.cpp** - Binary search on sorted arrays

## 🎯 Key Patterns Covered

### 1. **Basic Sorting Algorithms**
- Bubble Sort, Selection Sort, Insertion Sort
- Understanding time/space complexity trade-offs

### 2. **Advanced Sorting Algorithms**
- Merge Sort (Divide & Conquer)
- Quick Sort (Partition technique)
- Heap Sort (Heap data structure)

### 3. **Two Pointer Technique**
- After sorting for O(n) operations
- Used in: 3Sum, 4Sum, merge operations

### 4. **Custom Comparators**
- Sorting with special rules
- Multi-level sorting criteria

### 5. **Partition Techniques**
- Dutch National Flag
- QuickSelect for kth element

### 6. **Frequency-Based Sorting**
- Bucket Sort
- Counting Sort
- Character/element frequency

### 7. **Interval Problems**
- Merge Intervals
- Meeting Rooms
- Sweep Line Algorithm

### 8. **Modified Merge Sort**
- Counting inversions
- Range sum queries
- Order statistics

### 9. **Linear Time Sorting**
- Bucket Sort
- Radix Sort
- Counting Sort

### 10. **Binary Search on Sorted Arrays**
- Finding median
- kth element
- Range queries

## 💡 Study Strategy

### Week 1: Foundation (Problems 1-10)
- Master basic sorting algorithms
- Understand time complexity analysis
- Practice two-pointer technique

### Week 2: Core Patterns (Problems 11-18)
- Learn divide & conquer (Merge/Quick sort)
- Master QuickSelect
- Practice interval problems

### Week 3: Advanced Techniques (Problems 19-25)
- Custom comparators
- Multi-level sorting
- Complex two-pointer problems

### Week 4: Hard Problems (Problems 26-30)
- Modified merge sort patterns
- Linear time sorting
- Binary search variations

## 🔑 Time Complexity Reference

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | Yes |
| Radix Sort | O(d*n) | O(d*n) | O(d*n) | O(n+k) | Yes |
| Bucket Sort | O(n+k) | O(n+k) | O(n²) | O(n) | Yes |

## 📝 Interview Tips

### Before Your Interview:
1. ✅ Solve all 30 problems at least once
2. ✅ Understand time/space complexity of each approach
3. ✅ Practice explaining your solution clearly
4. ✅ Know when to use which sorting technique

### During Interview:
1. **Clarify Requirements**: Ask about input size, constraints
2. **Start Simple**: Mention naive approach first
3. **Optimize**: Discuss better solutions
4. **Code Clean**: Write readable, bug-free code
5. **Test**: Walk through test cases

### Common Interview Questions:
- "Why this sorting algorithm over others?"
- "Can you optimize space/time complexity?"
- "What if input is nearly sorted?"
- "Handle edge cases: empty array, duplicates, large numbers"

## 🎓 Key Takeaways

### When to Use Each Sort:
- **Quick Sort**: General purpose, in-place needed
- **Merge Sort**: Stable sort needed, linked lists
- **Heap Sort**: Memory constrained, guaranteed O(n log n)
- **Insertion Sort**: Small arrays, nearly sorted data
- **Counting/Radix**: Limited range integers
- **Bucket Sort**: Uniformly distributed data

### Stability Matters When:
- Maintaining relative order of equal elements
- Sorting complex objects by multiple keys
- Database operations

### Space Complexity Matters When:
- Embedded systems
- Large datasets
- Memory-constrained environments

## 🚀 Next Steps

After completing these 30 problems:
1. Solve variations of each problem
2. Practice explaining solutions out loud
3. Time yourself (aim for 20-30 minutes per problem)
4. Review weekly to maintain proficiency
5. Move to system design if targeting senior roles

## 🏢 FAANG Interview Questions (Sorted by Company)

### **Google** 🔴
These problems are frequently asked in Google interviews:

#### Easy-Medium
- ✅ **Sort Colors** (Problem #6) - Array partition, very common
- ✅ **Valid Anagram** (Problem #9) - String manipulation
- ✅ **Merge Intervals** (Problem #17) - Calendar/scheduling problems
- ✅ **Meeting Rooms II** (Problem #18) - Resource allocation
- ✅ **3Sum** (Problem #23) - Variation of 2Sum
- ✅ **Group Anagrams** (Problem #25) - String grouping

#### Hard
- ✅ **Median of Two Sorted Arrays** (Problem #30) - Binary search mastery
- ✅ **Count of Smaller Numbers After Self** (Problem #26) - Modified merge sort
- ✅ **Maximum Gap** (Problem #28) - Linear time sorting
- **Skyline Problem** - Sweep line + heap (similar to #18)
- **Count of Range Sum** (Problem #29) - Advanced technique

### **Meta (Facebook)** 🔵
Meta focuses on practical problems and optimization:

#### Easy-Medium
- ✅ **Merge Two Sorted Arrays** (Problem #4) - Array manipulation
- ✅ **Kth Largest Element** (Problem #15) - QuickSelect technique
- ✅ **Top K Frequent Elements** (Problem #16) - Frequency analysis
- ✅ **Sort Array by Parity** (Problem #5) - Partition logic
- ✅ **Merge Intervals** (Problem #17) - Very frequent!
- ✅ **Valid Anagram** (Problem #9) - Follow-ups included

#### Hard
- ✅ **Largest Number** (Problem #20) - Custom comparator
- ✅ **4Sum** (Problem #24) - Extension problems
- ✅ **Reverse Pairs** (Problem #27) - Inversion counting
- **Interval List Intersections** - Similar to #17
- **Task Scheduler** - Greedy + sorting

### **Amazon** 🟠
Amazon loves array manipulation and practical scenarios:

#### Easy-Medium
- ✅ **Merge Two Sorted Arrays** (Problem #4) - Classic merge
- ✅ **Sort Colors** (Problem #6) - Partition technique
- ✅ **Top K Frequent Elements** (Problem #16) - E-commerce analytics
- ✅ **Meeting Rooms II** (Problem #18) - Resource scheduling
- ✅ **3Sum** (Problem #23) - Array problems
- ✅ **Merge Intervals** (Problem #17) - Delivery time windows

#### Medium-Hard
- ✅ **Kth Largest Element** (Problem #15) - Order statistics
- ✅ **Sort Linked List** (Problem #14) - Linked list operations
- ✅ **Group Anagrams** (Problem #25) - Product categorization
- ✅ **Largest Number** (Problem #20) - Custom ordering
- **Reorder Data in Log Files** - Custom comparator
- **K Closest Points to Origin** - Similar to #16

### **Apple** 🍎
Apple emphasizes clean code and efficient solutions:

#### Easy-Medium
- ✅ **Squares of Sorted Array** (Problem #7) - Two pointer
- ✅ **Merge Two Sorted Arrays** (Problem #4) - Array operations
- ✅ **Valid Anagram** (Problem #9) - String processing
- ✅ **Intersection of Two Arrays** (Problem #10) - Set operations
- ✅ **Sort Characters by Frequency** (Problem #19) - String manipulation
- ✅ **Sort Array by Increasing Frequency** (Problem #22) - Custom sorting

#### Medium
- ✅ **Merge Intervals** (Problem #17) - Calendar app logic
- ✅ **Sort Linked List** (Problem #14) - Data structure mastery
- ✅ **Custom Sort String** (Problem #21) - String ordering
- **Relative Sort Array** - Similar to #21
- **Sort Array by Parity II** - Extension of #5

### **Microsoft** 💚
Microsoft tests algorithmic depth and optimization:

#### Easy-Medium
- ✅ **Sort Colors** (Problem #6) - Classic problem
- ✅ **Merge Intervals** (Problem #17) - Very common
- ✅ **Kth Largest Element** (Problem #15) - QuickSelect
- ✅ **Top K Frequent Elements** (Problem #16) - Heap usage
- ✅ **3Sum** (Problem #23) - Array algorithms
- ✅ **Meeting Rooms II** (Problem #18) - Scheduling

#### Hard
- ✅ **Median of Two Sorted Arrays** (Problem #30) - Binary search
- ✅ **Count Smaller After Self** (Problem #26) - Advanced merge sort
- ✅ **Largest Number** (Problem #20) - Comparator logic
- **K Closest Points** - Heap/QuickSelect
- **Minimum Number of Arrows** - Interval problems

### **Netflix** 🔴
Netflix focuses on streaming and recommendation problems:

#### Medium
- ✅ **Top K Frequent Elements** (Problem #16) - Recommendation systems
- ✅ **Sort Characters by Frequency** (Problem #19) - Content analysis
- ✅ **Merge Intervals** (Problem #17) - Video streaming segments
- ✅ **Kth Largest Element** (Problem #15) - Rating analysis
- **Top K Frequent Words** - Similar to #16
- **Sort Features by Popularity** - Custom sorting

### **Other Top Tech Companies**

#### LinkedIn 💼
- ✅ **Merge Intervals** (Problem #17)
- ✅ **Meeting Rooms II** (Problem #18)
- ✅ **Group Anagrams** (Problem #25)
- ✅ **3Sum** (Problem #23)

#### Uber 🚗
- ✅ **Meeting Rooms II** (Problem #18) - Driver scheduling
- ✅ **Merge Intervals** (Problem #17) - Trip scheduling
- ✅ **Kth Largest Element** (Problem #15)
- ✅ **Top K Frequent Elements** (Problem #16)

#### Airbnb 🏠
- ✅ **Merge Intervals** (Problem #17) - Booking conflicts
- ✅ **Meeting Rooms II** (Problem #18) - Property availability
- ✅ **Group Anagrams** (Problem #25)
- ✅ **3Sum** (Problem #23)

#### Salesforce ☁️
- ✅ **Merge Two Sorted Arrays** (Problem #4)
- ✅ **Sort Colors** (Problem #6)
- ✅ **Kth Largest Element** (Problem #15)
- ✅ **Merge Intervals** (Problem #17)

## 📊 Most Frequently Asked Across All FAANG

### Top 10 Must-Know Problems:
1. **Merge Intervals** (#17) - Asked at ALL FAANG companies
2. **Kth Largest Element** (#15) - QuickSelect is crucial
3. **Top K Frequent Elements** (#16) - Heap/bucket sort
4. **3Sum** (#23) - Foundation for many variations
5. **Sort Colors** (#6) - Dutch National Flag
6. **Meeting Rooms II** (#18) - Scheduling problems
7. **Merge Two Sorted Arrays** (#4) - Basic merge technique
8. **Group Anagrams** (#25) - HashMap + sorting
9. **Valid Anagram** (#9) - String fundamentals
10. **Median of Two Sorted Arrays** (#30) - Hard but frequent at Google

### Problems by Interview Round:

#### Phone Screen (30-45 min)
- Easy to Medium problems
- Focus: #4, #5, #6, #7, #9, #10
- Need to solve in 15-20 minutes

#### Onsite - Algorithm Round (45-60 min)
- Medium to Hard problems
- Focus: #15, #16, #17, #18, #23, #25
- Need to solve in 30-40 minutes

#### Onsite - Advanced Round
- Hard problems for senior positions
- Focus: #26, #27, #28, #29, #30
- Discuss multiple approaches

## 🎯 Interview Patterns by Company

### Google's Focus:
- Optimization and multiple approaches
- Time complexity analysis
- Edge cases handling
- Clean, production-ready code

### Meta's Focus:
- Practical applications
- Scalability discussions
- Follow-up variations
- System design integration

### Amazon's Focus:
- Leadership principles in code
- Handling large datasets
- Real-world scenarios
- Trade-off discussions

### Apple's Focus:
- Code quality and readability
- Elegant solutions
- Memory efficiency
- User experience considerations

### Microsoft's Focus:
- Algorithmic depth
- Problem-solving process
- Communication skills
- Multiple solution approaches

## 💼 Interview Success Strategy

### Pre-Interview (1 Week Before):
1. **Day 1-2**: Solve all Easy problems (1-10)
2. **Day 3-4**: Focus on most frequent (15, 16, 17, 18, 23)
3. **Day 5**: Practice explaining solutions aloud
4. **Day 6**: Solve timed mock interviews
5. **Day 7**: Review hard problems (26-30)

### Day Before Interview:
- Review: #6, #15, #17, #18, #23, #25
- Practice explaining without looking at code
- Review time complexity cheat sheet
- Get good sleep!

### During Interview:
1. **Clarify** (2 min): Understand the problem fully
2. **Examples** (3 min): Work through examples
3. **Approach** (5 min): Discuss naive + optimal solutions
4. **Code** (20 min): Implement clean solution
5. **Test** (5 min): Walk through test cases
6. **Optimize** (5 min): Discuss improvements

### Common Follow-up Questions:
- "What if input is very large and doesn't fit in memory?"
- "Can you optimize space complexity?"
- "How would you handle duplicate elements?"
- "What if input is a stream of data?"
- "How would you parallelize this?"

## 📖 Additional Resources

- LeetCode sorting tag
- GeeksforGeeks sorting articles
- "Introduction to Algorithms" (CLRS) - Chapters 2, 6-9
- Visualizations: visualgo.net
- Company-specific interview guides on Glassdoor
- LeetCode company tags (premium)

## ✨ Good Luck!

Remember: **Consistency is key**. Solve 2-3 problems daily, and you'll be ready for your FAANG interview on Friday!

**Pro Tip**: Before the interview, solve problems 6, 15, 17, 23, and 30 again - these are most frequently asked!

---
*Last Updated: December 16, 2025*
*Total Problems: 30 | Easy: 10 | Medium: 15 | Hard: 5*
