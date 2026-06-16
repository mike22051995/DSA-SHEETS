/*
================================================================================
PROBLEM: Meeting Rooms (LeetCode #252)
DIFFICULTY: Easy
PATTERN: Sorting / Greedy
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        
        sort(intervals.begin(), intervals.end());
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false; // Overlap found
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals1 = {{0,30},{5,10},{15,20}};
    vector<vector<int>> intervals2 = {{7,10},{2,4}};
    
    cout << "Can attend (test 1): " << (sol.canAttendMeetings(intervals1) ? "true" : "false") << endl;
    cout << "Can attend (test 2): " << (sol.canAttendMeetings(intervals2) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Meeting Rooms II (LeetCode #253) - Min rooms needed
2. Merge Intervals (LeetCode #56)
3. Insert Interval (LeetCode #57)
4. Non-overlapping Intervals (LeetCode #435)
5. Minimum Number of Arrows (LeetCode #452)
6. My Calendar I (LeetCode #729)
7. My Calendar II (LeetCode #731)
8. My Calendar III (LeetCode #732)
9. Employee Free Time (LeetCode #759)
10. Interval List Intersections (LeetCode #986)
*/
