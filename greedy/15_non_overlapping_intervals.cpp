/*
PROBLEM: Non-overlapping Intervals (LeetCode 435)
DIFFICULTY: Medium
PATTERN: Interval Scheduling / Activity Selection

DESCRIPTION:
Given an array of intervals where intervals[i] = [start_i, end_i], return the minimum 
number of intervals you need to remove to make the rest of the intervals non-overlapping.

INPUT:
- intervals: array of [start, end] pairs

OUTPUT:
- Minimum number of intervals to remove

APPROACH:
1. Sort intervals by end time (earliest ending first)
2. Keep track of end time of last kept interval
3. If current interval starts before last end, it overlaps → remove it
4. Otherwise, update last end time

WHY GREEDY WORKS:
Keeping intervals that end earliest leaves more room for future intervals.
This is the classic activity selection problem.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int removals = 0;
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval starts before last end, overlaps
            if (intervals[i][0] < lastEnd) {
                removals++;  // Remove current interval
            } else {
                lastEnd = intervals[i][1];  // Update last end
            }
        }
        
        return removals;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Test 1 - Intervals: [[1,2],[2,3],[3,4],[1,3]]" << endl;
    cout << "Output: " << sol.eraseOverlapIntervals(intervals1) << endl;
    cout << "Expected: 1 (remove [1,3])" << endl << endl;
    
    // Test Case 2
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Test 2 - Intervals: [[1,2],[1,2],[1,2]]" << endl;
    cout << "Output: " << sol.eraseOverlapIntervals(intervals2) << endl;
    cout << "Expected: 2 (keep only one)" << endl << endl;
    
    // Test Case 3
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};
    cout << "Test 3 - Intervals: [[1,2],[2,3]]" << endl;
    cout << "Output: " << sol.eraseOverlapIntervals(intervals3) << endl;
    cout << "Expected: 0 (touching but not overlapping)" << endl << endl;
    
    // Test Case 4
    vector<vector<int>> intervals4 = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    cout << "Test 4 - Intervals: [[1,100],[11,22],[1,11],[2,12]]" << endl;
    cout << "Output: " << sol.eraseOverlapIntervals(intervals4) << endl;
    cout << "Expected: 2" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) due to sorting
SPACE COMPLEXITY: O(1) ignoring sort space

KEY LEARNING:
- Classic activity selection problem
- Sort by end time (not start time!)
- Greedy: always choose interval ending earliest
- Similar problems: meeting rooms, scheduling
- Very common pattern in FAANG interviews
- Can be modified to find maximum non-overlapping intervals
*/
