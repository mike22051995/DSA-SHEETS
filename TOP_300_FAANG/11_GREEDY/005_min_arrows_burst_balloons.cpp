/*
================================================================================
PROBLEM: Minimum Number of Arrows to Burst Balloons (LeetCode #452)
DIFFICULTY: Medium
PATTERN: Greedy / Intervals
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int end = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }
        
        return arrows;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    
    cout << "Minimum arrows: " << sol.findMinArrowShots(points) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Non-overlapping Intervals (LeetCode #435)
2. Merge Intervals (LeetCode #56)
3. Insert Interval (LeetCode #57)
4. Meeting Rooms (LeetCode #252)
5. Meeting Rooms II (LeetCode #253)
6. Interval List Intersections (LeetCode #986)
7. Remove Covered Intervals (LeetCode #1288)
8. Maximum Number of Events Attended (LeetCode #1353)
9. Maximum Profit in Job Scheduling (LeetCode #1235)
10. Video Stitching (LeetCode #1024)
*/
