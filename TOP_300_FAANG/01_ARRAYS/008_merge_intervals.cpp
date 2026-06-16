/*
================================================================================
PROBLEM: Merge Intervals (LeetCode #56)
DIFFICULTY: Medium
PATTERN: Intervals / Sorting
COMPANIES: Amazon, Facebook, Google, Microsoft, Bloomberg, Apple
================================================================================

PROBLEM DESCRIPTION:
Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Working with intervals/ranges
2. Need to merge overlapping ranges
3. Sorting by start/end times helps
4. Problems involve scheduling, meetings, time ranges

Key Indicators:
- "Merge intervals" or "overlapping ranges"
- Start and end times/positions
- Need to consolidate ranges
- Sorting simplifies the problem

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Intervals [1,3] and [2,6] overlap, merged to [1,6]

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping

Example 3:
Input: intervals = [[1,4],[0,4]]
Output: [[0,4]]
Explanation: [0,4] contains [1,4]

================================================================================
EXPLANATION:

Approach: Sort + Merge
1. Sort intervals by start time
2. Iterate through sorted intervals
3. If current overlaps with last merged:
   - Extend the last interval's end
4. Else:
   - Add current as new interval

Overlap Condition:
- current.start <= last.end

Time Complexity: O(n log n) - sorting dominates
Space Complexity: O(n) - result array

================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // Sort by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = merged.back();
            vector<int>& current = intervals[i];
            
            // Check if intervals overlap
            if (current[0] <= last[1]) {
                // Merge: extend end time
                last[1] = max(last[1], current[1]);
            } else {
                // No overlap: add as new interval
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};

void runTest(vector<vector<int>> intervals, string testName) {
    Solution sol;
    vector<vector<int>> result = sol.merge(intervals);
    
    cout << testName << ": " << endl;
    cout << "Input:  [[";
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i][0] << "," << intervals[i][1];
        if (i < intervals.size() - 1) cout << "],[";
    }
    cout << "]]" << endl;
    
    cout << "Output: [[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "," << result[i][1];
        if (i < result.size() - 1) cout << "],[";
    }
    cout << "]]" << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    runTest(intervals1, "Test 1");
    
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    runTest(intervals2, "Test 2");
    
    vector<vector<int>> intervals3 = {{1,4},{0,4}};
    runTest(intervals3, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Insert Interval (LeetCode #57) - Medium
   - Insert and merge new interval

2. Non-overlapping Intervals (LeetCode #435) - Medium
   - Minimum removals to make non-overlapping

3. Meeting Rooms (LeetCode #252) - Easy
   - Can attend all meetings?

4. Meeting Rooms II (LeetCode #253) - Medium
   - Minimum conference rooms needed

5. Interval List Intersections (LeetCode #986) - Medium
   - Find intersection of two interval lists

6. Employee Free Time (LeetCode #759) - Hard
   - Find common free time

7. My Calendar I/II/III (LeetCode #729, #731, #732) - Medium/Hard
   - Book events without conflicts

8. Data Stream as Disjoint Intervals (LeetCode #352) - Hard
   - Build intervals from stream

9. Remove Covered Intervals (LeetCode #1288) - Medium
   - Remove intervals covered by others

10. Divide Intervals Into Minimum Groups (LeetCode #2406) - Medium
    - Partition into non-overlapping groups

================================================================================
*/
