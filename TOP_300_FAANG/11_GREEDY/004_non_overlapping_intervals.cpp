/*
================================================================================
PROBLEM: Non-overlapping Intervals (LeetCode #435)
DIFFICULTY: Medium
PATTERN: Greedy / Sorting
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
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
        
        int count = 0;
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                count++; // Overlap, remove current interval
            } else {
                lastEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Min removals: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Merge Intervals (LeetCode #56)
2. Insert Interval (LeetCode #57)
3. Meeting Rooms (LeetCode #252)
4. Meeting Rooms II (LeetCode #253)
5. Minimum Number of Arrows (LeetCode #452)
6. My Calendar I (LeetCode #729)
7. My Calendar II (LeetCode #731)
8. Interval List Intersections (LeetCode #986)
9. Remove Covered Intervals (LeetCode #1288)
10. Maximum Profit in Job Scheduling (LeetCode #1235)
*/
