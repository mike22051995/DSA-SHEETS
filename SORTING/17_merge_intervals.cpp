/*
PROBLEM: Merge Intervals (LeetCode 56)
===============================================
DESCRIPTION:
Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals.

PATTERN: Sorting + Merge
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of intervals

OUTPUT:
Array of merged intervals

EXAMPLE:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Input: [[1,4],[4,5]]
Output: [[1,5]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // Get last interval in merged list
            vector<int>& last = merged.back();
            vector<int>& current = intervals[i];
            
            // Check if current overlaps with last
            if (current[0] <= last[1]) {
                // Merge: extend end time to maximum
                last[1] = max(last[1], current[1]);
            } else {
                // No overlap: add as new interval
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> intervals1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    cout << "Intervals 1: ";
    for (auto& interval : intervals1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    vector<vector<int>> result1 = sol.merge(intervals1);
    cout << "Merged: ";
    for (auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    vector<vector<int>> intervals2 = {{1,4}, {4,5}};
    cout << "\nIntervals 2: ";
    for (auto& interval : intervals2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    vector<vector<int>> result2 = sol.merge(intervals2);
    cout << "Merged: ";
    for (auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
ALGORITHM:
1. Sort intervals by start time
2. Initialize result with first interval
3. For each interval:
   - If overlaps with last merged interval: extend end time
   - Otherwise: add as new interval

OVERLAP CONDITION:
- current.start <= last.end
- Example: [1,3] and [2,6] overlap because 2 <= 3

MERGING:
- Keep minimum start (already sorted)
- Take maximum end: max(last.end, current.end)

EDGE CASES:
1. Empty intervals: return []
2. Single interval: return as is
3. Adjacent intervals [1,4] and [4,5]: merged to [1,5]
4. No overlaps: return all intervals

VISUALIZATION:
Input: [[1,3],[2,6],[8,10],[15,18]]

After sorting (already sorted):
1----3
  2------6
         8--10
                15---18

Merging:
Step 1: Add [1,3]
Step 2: [1,3] + [2,6] = [1,6] (overlap)
Step 3: Add [8,10] (no overlap)
Step 4: Add [15,18] (no overlap)

Result: [[1,6],[8,10],[15,18]]

WHY SORTING IS KEY:
- After sorting by start, only need to check with last merged interval
- Don't need to check all previous intervals
- Linear scan after sorting

WHY THIS PATTERN IS IMPORTANT:
- Fundamental interval problem pattern
- Used in: Meeting rooms, insert interval, employee free time
- Demonstrates sorting + greedy approach
- Very common in FAANG interviews
- Foundation for interval scheduling problems
*/
