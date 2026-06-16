/*
PROBLEM: Minimum Number of Arrows to Burst Balloons (LeetCode 452)
DIFFICULTY: Medium
PATTERN: Interval Overlap Detection / Greedy Shooting

DESCRIPTION:
There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] 
denotes a balloon whose horizontal diameter stretches between xstart and xend.
An arrow can be shot up exactly vertically from any point along the x-axis. A balloon with 
xstart and xend is burst by an arrow shot at x if xstart ≤ x ≤ xend. Return the minimum 
number of arrows that must be shot to burst all balloons.

INPUT:
- points: array of [xstart, xend] representing balloons

OUTPUT:
- Minimum number of arrows needed

APPROACH:
1. Sort balloons by end position
2. Shoot arrow at first balloon's end
3. This arrow bursts all overlapping balloons
4. When we find non-overlapping balloon, shoot new arrow

WHY GREEDY WORKS:
Shooting at the end of earliest-ending balloon maximizes the number of balloons 
burst by that arrow.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort by end position
        sort(points.begin(), points.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int arrows = 1;
        int arrowPos = points[0][1];  // Shoot at first balloon's end
        
        for (int i = 1; i < points.size(); i++) {
            // If current balloon starts after arrow position, need new arrow
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];  // Shoot at new balloon's end
            }
            // Otherwise, current arrow bursts this balloon too
        }
        
        return arrows;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Test 1 - Balloons: [[10,16],[2,8],[1,6],[7,12]]" << endl;
    cout << "Output: " << sol.findMinArrowShots(points1) << endl;
    cout << "Expected: 2 (arrows at x=6 and x=11)" << endl << endl;
    
    // Test Case 2
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Test 2 - Balloons: [[1,2],[3,4],[5,6],[7,8]]" << endl;
    cout << "Output: " << sol.findMinArrowShots(points2) << endl;
    cout << "Expected: 4 (no overlaps)" << endl << endl;
    
    // Test Case 3
    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Test 3 - Balloons: [[1,2],[2,3],[3,4],[4,5]]" << endl;
    cout << "Output: " << sol.findMinArrowShots(points3) << endl;
    cout << "Expected: 2" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) due to sorting
SPACE COMPLEXITY: O(1) ignoring sort space

KEY LEARNING:
- Similar to non-overlapping intervals but inverted logic
- Sort by end time and shoot at earliest end
- Count number of "groups" of overlapping intervals
- Pattern: convert problem to interval scheduling
- Common in Google/Microsoft interviews
*/
