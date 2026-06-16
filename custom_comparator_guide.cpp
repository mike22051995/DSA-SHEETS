/*
================================================================================
CUSTOM COMPARATORS IN C++ - COMPLETE GUIDE
================================================================================

Custom comparators allow you to define how elements should be compared and sorted.
This is essential for sorting complex objects, implementing custom priority queues,
and solving many algorithm problems.

Compilation: g++ -std=c++17 custom_comparator_guide.cpp -o comparator_guide
Run: ./comparator_guide
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

// =============================================================================
// 1. BASIC SORTING WITH DEFAULT COMPARATOR
// =============================================================================

void basicSortingExamples() {
    cout << "1. BASIC SORTING\n";
    cout << string(70, '-') << "\n";

    // Default sort (ascending)
    vector<int> nums = {5, 2, 8, 1, 9};
    sort(nums.begin(), nums.end());
    cout << "Ascending sort: ";
    for (int n : nums) cout << n << " ";
    cout << "\n";

    // Descending sort using greater<int>()
    vector<int> nums2 = {5, 2, 8, 1, 9};
    sort(nums2.begin(), nums2.end(), greater<int>());
    cout << "Descending sort: ";
    for (int n : nums2) cout << n << " ";
    cout << "\n";

    // Partial sort - sort first k elements
    vector<int> nums3 = {5, 2, 8, 1, 9, 3, 7};
    partial_sort(nums3.begin(), nums3.begin() + 3, nums3.end());
    cout << "Partial sort (first 3): ";
    for (int n : nums3) cout << n << " ";
    cout << "\n\n";
}

// =============================================================================
// 2. LAMBDA FUNCTIONS AS COMPARATORS
// =============================================================================

void lambdaComparatorExamples() {
    cout << "2. LAMBDA COMPARATORS\n";
    cout << string(70, '-') << "\n";

    // Sort by absolute value
    vector<int> nums = {-5, -2, 3, 1, -4};
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    cout << "Sort by absolute value: ";
    for (int n : nums) cout << n << " ";
    cout << "\n";

    // Sort strings by length
    vector<string> words = {"apple", "pie", "banana", "kiwi"};
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    cout << "Sort by length: ";
    for (const auto& w : words) cout << w << " ";
    cout << "\n";

    // Sort pairs by second element
    vector<pair<int, int>> pairs = {{1, 3}, {2, 1}, {3, 2}};
    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    cout << "Sort pairs by second element: ";
    for (const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // Multi-criteria: first by length, then alphabetically
    vector<string> words2 = {"apple", "pie", "kiwi", "banana", "ant"};
    sort(words2.begin(), words2.end(), [](const string& a, const string& b) {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    });
    cout << "Sort by length then alphabetically: ";
    for (const auto& w : words2) cout << w << " ";
    cout << "\n\n";
}

// =============================================================================
// 3. FUNCTION OBJECTS (FUNCTORS)
// =============================================================================

// Functor for sorting by absolute value
struct CompareByAbsValue {
    bool operator()(int a, int b) const {
        return abs(a) < abs(b);
    }
};

// Functor for sorting pairs by sum
struct ComparePairBySum {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return (a.first + a.second) < (b.first + b.second);
    }
};

void functorExamples() {
    cout << "3. FUNCTION OBJECTS (FUNCTORS)\n";
    cout << string(70, '-') << "\n";

    vector<int> nums = {-5, -2, 3, 1, -4};
    sort(nums.begin(), nums.end(), CompareByAbsValue());
    cout << "Sort by absolute value (functor): ";
    for (int n : nums) cout << n << " ";
    cout << "\n";

    vector<pair<int, int>> pairs = {{1, 3}, {2, 1}, {3, 2}};
    sort(pairs.begin(), pairs.end(), ComparePairBySum());
    cout << "Sort pairs by sum: ";
    for (const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n\n";
}

// =============================================================================
// 4. SORTING CUSTOM CLASSES/STRUCTS
// =============================================================================

class Student {
public:
    string name;
    int grade;
    int age;

    Student(string n, int g, int a) : name(n), grade(g), age(a) {}

    // Method 1: Overload < operator (used by default sort)
    bool operator<(const Student& other) const {
        return grade < other.grade;
    }

    // For printing
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "Student(" << s.name << ", grade=" << s.grade << ", age=" << s.age << ")";
        return os;
    }
};

// Comparator function for sorting by name
bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// Functor for multi-criteria sorting
struct CompareStudentMulti {
    bool operator()(const Student& a, const Student& b) const {
        // Grade descending, then age ascending
        if (a.grade != b.grade)
            return a.grade > b.grade;
        return a.age < b.age;
    }
};

void sortingObjectsExamples() {
    cout << "4. SORTING CUSTOM OBJECTS\n";
    cout << string(70, '-') << "\n";

    vector<Student> students = {
        Student("Alice", 85, 20),
        Student("Bob", 92, 19),
        Student("Charlie", 85, 21),
        Student("David", 78, 20)
    };

    // Method 1: Using overloaded < operator
    vector<Student> s1 = students;
    sort(s1.begin(), s1.end());
    cout << "Sorted by grade (using operator<):\n";
    for (const auto& s : s1) cout << "  " << s << "\n";

    // Method 2: Using comparison function
    vector<Student> s2 = students;
    sort(s2.begin(), s2.end(), compareByName);
    cout << "\nSorted by name (using function):\n";
    for (const auto& s : s2) cout << "  " << s << "\n";

    // Method 3: Using lambda
    vector<Student> s3 = students;
    sort(s3.begin(), s3.end(), [](const Student& a, const Student& b) {
        return a.age < b.age;
    });
    cout << "\nSorted by age (using lambda):\n";
    for (const auto& s : s3) cout << "  " << s << "\n";

    // Method 4: Multi-criteria using functor
    vector<Student> s4 = students;
    sort(s4.begin(), s4.end(), CompareStudentMulti());
    cout << "\nSorted by grade (desc) then age (asc):\n";
    for (const auto& s : s4) cout << "  " << s << "\n";

    cout << "\n";
}

// =============================================================================
// 5. PRIORITY QUEUE WITH CUSTOM COMPARATORS
// =============================================================================

void priorityQueueExamples() {
    cout << "5. PRIORITY QUEUE (CUSTOM COMPARATORS)\n";
    cout << string(70, '-') << "\n";

    // Default priority_queue (max heap)
    priority_queue<int> maxHeap;
    maxHeap.push(5); maxHeap.push(2); maxHeap.push(8);
    cout << "Max heap top: " << maxHeap.top() << "\n";

    // Min heap using greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5); minHeap.push(2); minHeap.push(8);
    cout << "Min heap top: " << minHeap.top() << "\n";

    // Custom comparator for pairs - min heap by second element
    auto pairComp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Note: reversed for min heap
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pairComp)> pairHeap(pairComp);

    pairHeap.push({1, 5});
    pairHeap.push({2, 3});
    pairHeap.push({3, 7});

    cout << "Pair heap (min by second): ";
    while (!pairHeap.empty()) {
        auto [a, b] = pairHeap.top();
        pairHeap.pop();
        cout << "(" << a << "," << b << ") ";
    }
    cout << "\n";

    // Priority queue with custom class
    struct Task {
        int priority;
        string name;

        // For max heap behavior (higher priority value = higher priority)
        bool operator<(const Task& other) const {
            return priority < other.priority; // Lower priority goes deeper
        }
    };

    priority_queue<Task> taskHeap;
    taskHeap.push({3, "Low"});
    taskHeap.push({1, "Medium"});
    taskHeap.push({5, "High"});

    cout << "Task heap (by priority): ";
    while (!taskHeap.empty()) {
        cout << taskHeap.top().name << "(" << taskHeap.top().priority << ") ";
        taskHeap.pop();
    }
    cout << "\n\n";
}

// =============================================================================
// 6. SET AND MAP WITH CUSTOM COMPARATORS
// =============================================================================

// Custom comparator for set - sort by string length
struct CompareStringLength {
    bool operator()(const string& a, const string& b) const {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b; // Tie-breaker
    }
};

void setMapExamples() {
    cout << "6. SET AND MAP WITH CUSTOM COMPARATORS\n";
    cout << string(70, '-') << "\n";

    // Set with custom comparator
    set<string, CompareStringLength> customSet;
    customSet.insert("apple");
    customSet.insert("pie");
    customSet.insert("banana");
    customSet.insert("kiwi");

    cout << "Set sorted by length: ";
    for (const auto& s : customSet) cout << s << " ";
    cout << "\n";

    // Set with lambda (C++11 onwards)
    auto comp = [](int a, int b) { return abs(a) < abs(b); };
    set<int, decltype(comp)> absSet(comp);
    absSet.insert(-5); absSet.insert(3); absSet.insert(-2);

    cout << "Set sorted by absolute value: ";
    for (int n : absSet) cout << n << " ";
    cout << "\n";

    // Map with custom key comparator
    map<string, int, CompareStringLength> customMap;
    customMap["apple"] = 1;
    customMap["pie"] = 2;
    customMap["banana"] = 3;

    cout << "Map sorted by key length: ";
    for (const auto& [key, val] : customMap) {
        cout << key << ":" << val << " ";
    }
    cout << "\n\n";
}

// =============================================================================
// 7. COMMON DSA PROBLEM PATTERNS
// =============================================================================

void dsaProblemPatterns() {
    cout << "7. DSA PROBLEM PATTERNS\n";
    cout << string(70, '-') << "\n";

    // Pattern 1: K Closest Points to Origin
    auto kClosest = [](vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    };

    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    auto result = kClosest(points, 2);
    cout << "2 closest points to origin: ";
    for (const auto& p : result) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << "\n";

    // Pattern 2: Merge Intervals
    auto mergeIntervals = [](vector<vector<int>>& intervals) {
        if (intervals.empty()) return vector<vector<int>>();

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    };

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto merged = mergeIntervals(intervals);
    cout << "Merged intervals: ";
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n";

    // Pattern 3: Top K Frequent Elements
    auto topKFrequent = [](vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Sort by frequency descending
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }
        return result;
    };

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto topK = topKFrequent(nums, 2);
    cout << "Top 2 frequent elements: ";
    for (int n : topK) cout << n << " ";
    cout << "\n";

    // Pattern 4: Largest Number (LeetCode 179)
    auto largestNumber = [](vector<int>& nums) {
        vector<string> strNums;
        for (int n : nums) strNums.push_back(to_string(n));

        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return a + b > b + a; // Custom comparison
        });

        if (strNums[0] == "0") return string("0");

        string result;
        for (const auto& s : strNums) result += s;
        return result;
    };

    vector<int> nums2 = {3, 30, 34, 5, 9};
    cout << "Largest number: " << largestNumber(nums2) << "\n\n";
}

// =============================================================================
// 8. STABLE SORT VS SORT
// =============================================================================

void stableSortExamples() {
    cout << "8. STABLE SORT VS SORT\n";
    cout << string(70, '-') << "\n";

    struct Person {
        string name;
        int age;
    };

    vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 25},
        {"David", 30}
    };

    // stable_sort maintains relative order of equal elements
    stable_sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    cout << "Stable sort by age (maintains name order for same age):\n";
    for (const auto& p : people) {
        cout << "  " << p.name << ": " << p.age << "\n";
    }
    cout << "Note: Alice comes before Charlie, Bob comes before David\n\n";
}

// =============================================================================
// 9. NTH_ELEMENT AND PARTIAL_SORT
// =============================================================================

void nthElementExamples() {
    cout << "9. NTH_ELEMENT AND PARTIAL_SORT\n";
    cout << string(70, '-') << "\n";

    // nth_element - O(n) average, faster than full sort
    vector<int> nums1 = {5, 2, 8, 1, 9, 3, 7};
    nth_element(nums1.begin(), nums1.begin() + 3, nums1.end());
    cout << "After nth_element(3): ";
    for (int n : nums1) cout << n << " ";
    cout << "\n  Element at index 3: " << nums1[3] << "\n";
    cout << "  Elements before index 3 are smaller, after are larger\n";

    // partial_sort - sorts first k elements
    vector<int> nums2 = {5, 2, 8, 1, 9, 3, 7};
    partial_sort(nums2.begin(), nums2.begin() + 3, nums2.end());
    cout << "\nAfter partial_sort(first 3): ";
    for (int n : nums2) cout << n << " ";
    cout << "\n  First 3 elements are sorted: " << nums2[0] << " " << nums2[1] << " " << nums2[2] << "\n\n";
}

// =============================================================================
// 10. BINARY SEARCH WITH CUSTOM COMPARATORS
// =============================================================================

void binarySearchExamples() {
    cout << "10. BINARY SEARCH WITH CUSTOM COMPARATORS\n";
    cout << string(70, '-') << "\n";

    vector<int> nums = {-5, -3, -1, 2, 4, 6};

    // lower_bound - first element >= value
    auto it1 = lower_bound(nums.begin(), nums.end(), 0);
    if (it1 != nums.end()) {
        cout << "lower_bound(0): " << *it1 << " at index " << (it1 - nums.begin()) << "\n";
    }

    // upper_bound - first element > value
    auto it2 = upper_bound(nums.begin(), nums.end(), 2);
    if (it2 != nums.end()) {
        cout << "upper_bound(2): " << *it2 << " at index " << (it2 - nums.begin()) << "\n";
    }

    // binary_search - checks if element exists
    bool found = binary_search(nums.begin(), nums.end(), 2);
    cout << "binary_search(2): " << (found ? "found" : "not found") << "\n";

    // Custom comparator for absolute value search
    vector<int> absNums = {-5, -3, -1, 2, 4, 6};
    sort(absNums.begin(), absNums.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    cout << "\nSorted by absolute value: ";
    for (int n : absNums) cout << n << " ";
    cout << "\n";

    auto comp = [](int a, int b) { return abs(a) < abs(b); };
    auto it3 = lower_bound(absNums.begin(), absNums.end(), 3, comp);
    if (it3 != absNums.end()) {
        cout << "lower_bound with abs comparator for 3: " << *it3 << "\n";
    }

    cout << "\n";
}

// =============================================================================
// 11. PERFORMANCE AND COMPLEXITY
// =============================================================================

void performanceNotes() {
    cout << "11. PERFORMANCE AND COMPLEXITY\n";
    cout << string(70, '-') << "\n";
    cout << R"(
TIME COMPLEXITIES:
- sort()              : O(n log n) - IntroSort (quicksort + heapsort + insertion)
- stable_sort()       : O(n log n) - Merge sort (stable)
- partial_sort()      : O(n log k) - where k is number of elements to sort
- nth_element()       : O(n) average - QuickSelect algorithm
- heap operations     : O(log n) per push/pop
- make_heap()         : O(n)
- lower_bound()       : O(log n) - requires sorted range
- upper_bound()       : O(log n) - requires sorted range

SPACE COMPLEXITIES:
- sort()              : O(log n) - in-place with recursion stack
- stable_sort()       : O(n) - may need extra space
- priority_queue      : O(n) for storing elements
- set/map            : O(n) for storing elements

BEST PRACTICES:
1. Use lambda for simple, one-time comparators
2. Use functors for reusable comparators or when storing state
3. Use operator< overloading for natural ordering of custom types
4. Prefer stable_sort when order of equal elements matters
5. Use nth_element for finding kth element (faster than full sort)
6. Remember: priority_queue comparator is REVERSED (> for min heap)

COMMON COMPARATOR RULES:
- Must define strict weak ordering
- Irreflexive: comp(a, a) must be false
- Asymmetric: if comp(a, b) is true, comp(b, a) must be false
- Transitive: if comp(a, b) and comp(b, c), then comp(a, c)
- Equivalence transitive: if a~b and b~c, then a~c

)" << "\n";
}

// =============================================================================
// 12. COMMON PITFALLS AND SOLUTIONS
// =============================================================================

void commonPitfalls() {
    cout << "12. COMMON PITFALLS AND SOLUTIONS\n";
    cout << string(70, '-') << "\n";
    cout << R"(
COMMON MISTAKES:

1. PITFALL: Wrong comparator for priority_queue
   BAD:  Use < for min heap (actually creates max heap!)
   GOOD: Use > for min heap, or use greater<int>

2. PITFALL: Not handling equal elements
   BAD:  bool operator<(const T& a, const T& b) { return a.val <= b.val; }
   GOOD: bool operator<(const T& a, const T& b) { return a.val < b.val; }

3. PITFALL: Comparing floats with ==
   BAD:  return a.val == b.val;
   GOOD: return abs(a.val - b.val) < EPSILON;

4. PITFALL: Violating strict weak ordering
   BAD:  Inconsistent comparison logic
   GOOD: Ensure transitivity and asymmetry

5. PITFALL: Sorting with undefined comparator
   BAD:  Comparing objects without operator< or custom comparator
   GOOD: Always define comparison method

6. PITFALL: Using unstable sort when order matters
   BAD:  sort() when relative order of equal elements matters
   GOOD: stable_sort() to maintain relative order

7. PITFALL: Inefficient comparisons
   BAD:  Expensive operations in comparator called O(n log n) times
   GOOD: Precompute values or use simpler comparisons

DEBUGGING TIPS:
- Test comparator with edge cases: equal values, negative numbers
- Verify strict weak ordering properties
- Use assertions to check comparator behavior
- For priority_queue, remember comparator is reversed!

)" << "\n";
}

// =============================================================================
// 13. ADVANCED TECHNIQUES
// =============================================================================

void advancedTechniques() {
    cout << "13. ADVANCED TECHNIQUES\n";
    cout << string(70, '-') << "\n";

    // Technique 1: Schwartzian Transform (decorate-sort-undecorate)
    vector<string> words = {"apple", "pie", "banana", "kiwi"};
    vector<pair<int, string>> decorated;
    for (const auto& w : words) {
        decorated.push_back({w.length(), w});
    }
    sort(decorated.begin(), decorated.end());
    cout << "Schwartzian transform (sort by length): ";
    for (const auto& [len, word] : decorated) {
        cout << word << " ";
    }
    cout << "\n";

    // Technique 2: Counting sort (when range is small)
    vector<int> nums = {3, 1, 2, 1, 3, 2, 3};
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> count(maxVal + 1, 0);
    for (int n : nums) count[n]++;

    vector<int> sorted;
    for (int i = 0; i <= maxVal; i++) {
        for (int j = 0; j < count[i]; j++) {
            sorted.push_back(i);
        }
    }
    cout << "Counting sort: ";
    for (int n : sorted) cout << n << " ";
    cout << "\n";

    // Technique 3: Using multiset for automatic sorting with duplicates
    multiset<int, greater<int>> autoSorted; // Descending order
    autoSorted.insert(5);
    autoSorted.insert(2);
    autoSorted.insert(8);
    autoSorted.insert(2);
    cout << "Multiset (auto-sorted desc): ";
    for (int n : autoSorted) cout << n << " ";
    cout << "\n\n";
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================

int main() {
    cout << string(70, '=') << "\n";
    cout << "CUSTOM COMPARATORS IN C++ - COMPREHENSIVE GUIDE\n";
    cout << string(70, '=') << "\n\n";

    basicSortingExamples();
    lambdaComparatorExamples();
    functorExamples();
    sortingObjectsExamples();
    priorityQueueExamples();
    setMapExamples();
    dsaProblemPatterns();
    stableSortExamples();
    nthElementExamples();
    binarySearchExamples();
    performanceNotes();
    commonPitfalls();
    advancedTechniques();

    cout << string(70, '=') << "\n";
    cout << "END OF GUIDE\n";
    cout << string(70, '=') << "\n";

    return 0;
}

/*
================================================================================
QUICK REFERENCE CHEAT SHEET
================================================================================

1. BASIC SORT:
   sort(v.begin(), v.end());                    // Ascending
   sort(v.begin(), v.end(), greater<int>());    // Descending

2. LAMBDA:
   sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

3. PRIORITY QUEUE:
   priority_queue<int> pq;                                      // Max heap
   priority_queue<int, vector<int>, greater<int>> pq;          // Min heap

4. CUSTOM CLASS:
   struct Node {
       int val;
       bool operator<(const Node& other) const { return val < other.val; }
   };

5. SET/MAP:
   set<int, greater<int>> s;                    // Descending set
   map<string, int, CompareFunc> m;             // Custom map

6. COMMON PATTERNS:
   - Sort by abs value:  [](int a, int b) { return abs(a) < abs(b); }
   - Sort pairs by 2nd:  [](auto& a, auto& b) { return a.second < b.second; }
   - Multi-criteria:     if (a.x != b.x) return a.x < b.x; return a.y < b.y;

================================================================================
*/
