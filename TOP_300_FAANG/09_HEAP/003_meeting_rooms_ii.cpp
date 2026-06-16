/*
================================================================================
PROBLEM: Meeting Rooms II (LeetCode #253)
DIFFICULTY: Medium
PATTERN: Heap (Priority Queue) / Sweep Line
COMPANIES: Amazon, Facebook, Google, Microsoft, Bloomberg
================================================================================
DESCRIPTION:
Given meeting time intervals, return the minimum number of rooms required.

INPUT FORMAT:
- intervals: list of [start, end] pairs

OUTPUT FORMAT:
- single integer = minimum rooms needed

APPROACH (HEAP):
- Sort intervals by start time.
- Use a min-heap of end times; reuse a room if the earliest end <= next start.
- Heap size is the number of rooms in use.

CODE EXPLANATION:
- minMeetingRooms sorts intervals, then tracks active meetings by end time.
- If the next meeting starts after the earliest ending, reuse that room.
- Heap size after processing all intervals is the answer.

COMPLEXITY:
- Time: O(n log n)
- Space: O(n)

SAMPLE INPUT/OUTPUT:
1) intervals = [[0,30],[5,10],[15,20]] -> 2
2) intervals = [[7,10],[2,4]] -> 1
3) intervals = [[1,5],[8,9],[8,9]] -> 2
4) intervals = [[1,4],[2,3],[3,5]] -> 2
5) intervals = [[1,2],[2,3],[3,4],[4,5]] -> 1
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    // Priority Queue Approach
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(intervals[i][1]);
        }
        
        return minHeap.size();
    }
    
    // Sweep Line Approach
    int minMeetingRoomsSweep(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        
        for (auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;
        
        while (i < starts.size()) {
            if (starts[i] < ends[j]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;
                j++;
            }
        }
        
        return maxRooms;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout << "Min meeting rooms: " << sol.minMeetingRooms(intervals) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Meeting Rooms (LeetCode #252)
2. Merge Intervals (LeetCode #56)
3. Insert Interval (LeetCode #57)
4. My Calendar I (LeetCode #729)
5. My Calendar II (LeetCode #731)
6. My Calendar III (LeetCode #732)
7. Employee Free Time (LeetCode #759)
8. Interval List Intersections (LeetCode #986)
9. Car Pooling (LeetCode #1094)
10. Corporate Flight Bookings (LeetCode #1109)
*/
