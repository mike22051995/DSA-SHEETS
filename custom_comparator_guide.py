"""
CUSTOM COMPARATORS IN PYTHON - COMPLETE GUIDE
==============================================

Custom comparators allow you to define how elements should be compared and sorted.
This is essential for sorting complex objects, implementing custom priority queues,
and solving many algorithm problems.
"""

from functools import cmp_to_key
import heapq
from typing import List, Tuple

# =============================================================================
# 1. BASIC SORTING WITH KEY FUNCTIONS
# =============================================================================

def basic_sorting_examples():
    """
    Key function: Takes an element and returns a value used for sorting
    Elements are sorted based on the returned value in ascending order
    """

    # Sort by absolute value
    nums = [-5, -2, 3, 1, -4]
    sorted_nums = sorted(nums, key=abs)
    print(f"Sort by absolute value: {sorted_nums}")  # [1, -2, 3, -4, -5]

    # Sort strings by length
    words = ["apple", "pie", "banana", "kiwi"]
    sorted_words = sorted(words, key=len)
    print(f"Sort by length: {sorted_words}")  # ['pie', 'kiwi', 'apple', 'banana']

    # Sort in descending order
    nums = [3, 1, 4, 1, 5]
    sorted_desc = sorted(nums, reverse=True)
    print(f"Descending order: {sorted_desc}")  # [5, 4, 3, 1, 1]


# =============================================================================
# 2. SORTING WITH LAMBDA FUNCTIONS
# =============================================================================

def lambda_comparator_examples():
    """
    Lambda functions provide inline custom comparison logic
    """

    # Sort tuples by second element
    pairs = [(1, 3), (2, 1), (3, 2)]
    sorted_pairs = sorted(pairs, key=lambda x: x[1])
    print(f"Sort by second element: {sorted_pairs}")  # [(2, 1), (3, 2), (1, 3)]

    # Sort by multiple criteria: first by length, then alphabetically
    words = ["apple", "pie", "kiwi", "banana", "ant"]
    sorted_words = sorted(words, key=lambda x: (len(x), x))
    print(f"Sort by length then alphabetically: {sorted_words}")
    # ['ant', 'pie', 'kiwi', 'apple', 'banana']

    # Sort 2D points by distance from origin
    points = [[1, 3], [3, 4], [2, 1]]
    sorted_points = sorted(points, key=lambda p: p[0]**2 + p[1]**2)
    print(f"Sort by distance from origin: {sorted_points}")
    # [[2, 1], [1, 3], [3, 4]]


# =============================================================================
# 3. COMPLEX COMPARISONS USING CMP_TO_KEY
# =============================================================================

def cmp_to_key_examples():
    """
    For complex comparison logic, use functools.cmp_to_key
    Comparison function should return:
    - Negative value if a < b
    - Zero if a == b
    - Positive value if a > b
    """

    # Example 1: Sort strings by custom rule
    # Longer strings come first, if equal length, sort alphabetically
    def custom_compare(a, b):
        if len(a) != len(b):
            return len(b) - len(a)  # Longer first (descending)
        if a < b:
            return -1
        elif a > b:
            return 1
        return 0

    words = ["apple", "pie", "banana", "kiwi"]
    sorted_words = sorted(words, key=cmp_to_key(custom_compare))
    print(f"Custom comparison: {sorted_words}")  # ['banana', 'apple', 'kiwi', 'pie']

    # Example 2: Largest Number problem (LeetCode 179)
    # Sort numbers so their concatenation gives largest number
    def compare_for_largest(a, b):
        if a + b > b + a:
            return -1  # a should come before b
        elif a + b < b + a:
            return 1   # b should come before a
        return 0

    nums = [3, 30, 34, 5, 9]
    str_nums = [str(n) for n in nums]
    sorted_nums = sorted(str_nums, key=cmp_to_key(compare_for_largest))
    print(f"Largest number arrangement: {''.join(sorted_nums)}")  # 9534330


# =============================================================================
# 4. SORTING OBJECTS/CLASSES
# =============================================================================

class Student:
    def __init__(self, name: str, grade: int, age: int):
        self.name = name
        self.grade = grade
        self.age = age

    def __repr__(self):
        return f"Student({self.name}, grade={self.grade}, age={self.age})"

    # Method 1: Implementing comparison methods
    def __lt__(self, other):
        """Less than comparison - used by sort() by default"""
        return self.grade < other.grade

    def __eq__(self, other):
        """Equal comparison"""
        return self.grade == other.grade


def sorting_objects_examples():
    """Different ways to sort custom objects"""

    students = [
        Student("Alice", 85, 20),
        Student("Bob", 92, 19),
        Student("Charlie", 85, 21),
        Student("David", 78, 20)
    ]

    # Method 1: Using __lt__ method defined in class
    sorted_by_grade = sorted(students)
    print("Sorted by grade (using __lt__):")
    print(sorted_by_grade)

    # Method 2: Using lambda with attribute
    sorted_by_name = sorted(students, key=lambda s: s.name)
    print("\nSorted by name:")
    print(sorted_by_name)

    # Method 3: Multiple criteria - grade descending, then age ascending
    sorted_multi = sorted(students, key=lambda s: (-s.grade, s.age))
    print("\nSorted by grade (desc) then age (asc):")
    print(sorted_multi)

    # Method 4: Using operator.attrgetter (more efficient)
    from operator import attrgetter
    sorted_by_age = sorted(students, key=attrgetter('age', 'name'))
    print("\nSorted by age then name:")
    print(sorted_by_age)


# =============================================================================
# 5. PRIORITY QUEUE (HEAPQ) WITH CUSTOM COMPARATORS
# =============================================================================

def priority_queue_examples():
    """
    heapq in Python is a min-heap by default
    For custom ordering, we need to modify the comparison
    """

    # Min heap (default)
    min_heap = [5, 2, 8, 1, 9]
    heapq.heapify(min_heap)
    print(f"Min heap top element: {min_heap[0]}")  # 1

    # Max heap: negate values to simulate max heap
    max_heap = [-x for x in [5, 2, 8, 1, 9]]
    heapq.heapify(max_heap)
    print(f"Max heap top element: {-max_heap[0]}")  # 9

    # Priority queue with tuples: (priority, value)
    # Lower priority number = higher priority
    pq = []
    heapq.heappush(pq, (3, "Low priority"))
    heapq.heappush(pq, (1, "High priority"))
    heapq.heappush(pq, (2, "Medium priority"))

    print("\nPriority Queue (tuples):")
    while pq:
        priority, task = heapq.heappop(pq)
        print(f"Priority {priority}: {task}")

    # Custom object in heap using wrapper class
    class Task:
        def __init__(self, priority: int, name: str):
            self.priority = priority
            self.name = name

        def __lt__(self, other):
            # Higher priority value = higher priority (max heap behavior)
            return self.priority > other.priority

        def __repr__(self):
            return f"Task({self.name}, priority={self.priority})"

    task_heap = []
    heapq.heappush(task_heap, Task(3, "Low"))
    heapq.heappush(task_heap, Task(1, "Medium"))
    heapq.heappush(task_heap, Task(5, "High"))

    print("\nCustom Task Heap:")
    while task_heap:
        print(heapq.heappop(task_heap))


# =============================================================================
# 6. COMMON DSA PROBLEM PATTERNS
# =============================================================================

def dsa_problem_patterns():
    """Common patterns where custom comparators are used"""

    # Pattern 1: K Closest Points to Origin
    def k_closest(points: List[List[int]], k: int) -> List[List[int]]:
        # Sort by distance from origin
        points.sort(key=lambda p: p[0]**2 + p[1]**2)
        return points[:k]

    points = [[3, 3], [5, -1], [-2, 4]]
    print(f"2 closest points: {k_closest(points, 2)}")

    # Pattern 2: Meeting Rooms II - Sort intervals by start time
    def min_meeting_rooms(intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        # Sort by start time
        intervals.sort(key=lambda x: x[0])

        # Use min heap to track end times
        heap = []
        heapq.heappush(heap, intervals[0][1])

        for i in range(1, len(intervals)):
            # If room is free, remove it
            if intervals[i][0] >= heap[0]:
                heapq.heappop(heap)

            # Add current meeting's end time
            heapq.heappush(heap, intervals[i][1])

        return len(heap)

    meetings = [[0, 30], [5, 10], [15, 20]]
    print(f"Min meeting rooms needed: {min_meeting_rooms(meetings)}")

    # Pattern 3: Merge Intervals
    def merge_intervals(intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        # Sort by start time
        intervals.sort(key=lambda x: x[0])
        merged = [intervals[0]]

        for current in intervals[1:]:
            if current[0] <= merged[-1][1]:
                # Overlapping, merge
                merged[-1][1] = max(merged[-1][1], current[1])
            else:
                merged.append(current)

        return merged

    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    print(f"Merged intervals: {merge_intervals(intervals)}")

    # Pattern 4: Top K Frequent Elements
    def top_k_frequent(nums: List[int], k: int) -> List[int]:
        from collections import Counter
        count = Counter(nums)

        # Sort by frequency (descending)
        return [num for num, freq in
                sorted(count.items(), key=lambda x: -x[1])[:k]]

    nums = [1, 1, 1, 2, 2, 3]
    print(f"Top 2 frequent elements: {top_k_frequent(nums, 2)}")


# =============================================================================
# 7. STABLE VS UNSTABLE SORTING
# =============================================================================

def stability_examples():
    """
    Stable sort: maintains relative order of equal elements
    Python's sorted() and list.sort() are stable
    """

    students = [
        ("Alice", 85),
        ("Bob", 92),
        ("Charlie", 85),
        ("David", 92)
    ]

    # Stable sort by grade - students with same grade maintain order
    sorted_students = sorted(students, key=lambda x: x[1])
    print("Stable sort (by grade):")
    for student in sorted_students:
        print(student)
    # Alice and Charlie maintain their relative order
    # Bob and David maintain their relative order


# =============================================================================
# 8. ADVANCED: MULTI-LEVEL SORTING
# =============================================================================

def multi_level_sorting():
    """Complex sorting with multiple criteria"""

    # Sort by: 1) Length (desc), 2) Alphabetically (asc), 3) Vowel count (desc)
    def count_vowels(s):
        return sum(1 for c in s.lower() if c in 'aeiou')

    words = ["apple", "pie", "banana", "kiwi", "pear", "ant"]

    sorted_words = sorted(words,
                         key=lambda w: (-len(w), w, -count_vowels(w)))

    print("Multi-level sort:")
    for word in sorted_words:
        print(f"{word}: len={len(word)}, vowels={count_vowels(word)}")


# =============================================================================
# 9. PERFORMANCE COMPARISONS
# =============================================================================

def performance_notes():
    """
    Performance considerations for custom comparators
    """

    print("""
    PERFORMANCE TIPS:

    1. Key functions are generally faster than comparison functions
       - key function is called once per element
       - comparison function is called multiple times

    2. Use operator.attrgetter/itemgetter for better performance
       from operator import itemgetter
       sorted(data, key=itemgetter(1))  # Faster than lambda x: x[1]

    3. For very large datasets, consider:
       - Using heapq.nlargest/nsmallest instead of sorting
       - Partial sorting if you don't need full sort

    4. Time Complexities:
       - sorted(): O(n log n)
       - list.sort(): O(n log n) in-place
       - heapq operations: O(log n) per operation
       - heapq.heapify(): O(n)
    """)


# =============================================================================
# 10. COMMON PITFALLS AND BEST PRACTICES
# =============================================================================

def common_pitfalls():
    """Common mistakes and how to avoid them"""

    print("""
    COMMON PITFALLS:

    1. PITFALL: Modifying list during iteration
       BAD:  for i in range(len(lst)): lst.sort()
       GOOD: Sort once before loop

    2. PITFALL: Using mutable default arguments
       BAD:  def func(lst=[]):
       GOOD: def func(lst=None): lst = lst or []

    3. PITFALL: Sorting with None values
       BAD:  sorted([1, None, 3], key=lambda x: x)  # Error!
       GOOD: sorted([1, None, 3], key=lambda x: (x is None, x))

    4. PITFALL: Not handling edge cases in comparator
       - Check for None, empty strings, zero values
       - Handle equal values correctly

    5. BEST PRACTICE: Use tuple comparison for multiple criteria
       GOOD: key=lambda x: (x.priority, -x.value, x.name)
       - Each element in tuple is compared in order
       - Negate for descending order in that field
    """)


# =============================================================================
# MAIN EXECUTION
# =============================================================================

if __name__ == "__main__":
    print("=" * 70)
    print("CUSTOM COMPARATORS - COMPREHENSIVE GUIDE")
    print("=" * 70)

    print("\n1. BASIC SORTING")
    print("-" * 70)
    basic_sorting_examples()

    print("\n\n2. LAMBDA COMPARATORS")
    print("-" * 70)
    lambda_comparator_examples()

    print("\n\n3. CMP_TO_KEY EXAMPLES")
    print("-" * 70)
    cmp_to_key_examples()

    print("\n\n4. SORTING OBJECTS")
    print("-" * 70)
    sorting_objects_examples()

    print("\n\n5. PRIORITY QUEUE (HEAPQ)")
    print("-" * 70)
    priority_queue_examples()

    print("\n\n6. DSA PROBLEM PATTERNS")
    print("-" * 70)
    dsa_problem_patterns()

    print("\n\n7. STABLE SORTING")
    print("-" * 70)
    stability_examples()

    print("\n\n8. MULTI-LEVEL SORTING")
    print("-" * 70)
    multi_level_sorting()

    print("\n\n9. PERFORMANCE NOTES")
    print("-" * 70)
    performance_notes()

    print("\n\n10. COMMON PITFALLS")
    print("-" * 70)
    common_pitfalls()

    print("\n" + "=" * 70)
    print("END OF GUIDE")
    print("=" * 70)
