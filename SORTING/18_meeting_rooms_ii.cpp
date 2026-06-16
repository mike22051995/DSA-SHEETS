/*
PROBLEM: Meeting Rooms II (LeetCode 253)
===============================================
DESCRIPTION:
Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...], find the minimum number of conference rooms required.

PATTERN: Sorting + Sweep Line / Min Heap
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of meeting intervals

OUTPUT:
Minimum number of rooms required

EXAMPLE:
Input: [[0,30],[5,10],[15,20]]
Output: 2 (meetings [0,30] and [5,10] overlap)

Input: [[7,10],[2,4]]
Output: 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    // Approach 1: Min Heap (Track ending times)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by start time
        sort(intervals.begin(), intervals.end());
        
        // Min heap to track end times of meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0][1]); // Add first meeting's end time
        
        for (int i = 1; i < intervals.size(); i++) {
            // If earliest ending meeting finishes before current starts
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop(); // Room becomes free
            }
            
            // Add current meeting's end time
            minHeap.push(intervals[i][1]);
        }
        
        // Heap size = number of rooms needed
        return minHeap.size();
    }
    
    // Approach 2: Sweep Line Algorithm (Two Pointers)
    int minMeetingRoomsSweep(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        vector<int> starts, ends;
        for (auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        
        // Sort start and end times separately
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int rooms = 0, maxRooms = 0;
        int startPtr = 0, endPtr = 0;
        
        while (startPtr < starts.size()) {
            if (starts[startPtr] < ends[endPtr]) {
                // Meeting starts, need a room
                rooms++;
                maxRooms = max(maxRooms, rooms);
                startPtr++;
            } else {
                // Meeting ends, free a room
                rooms--;
                endPtr++;
            }
        }
        
        return maxRooms;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> meetings1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Meetings 1: ";
    for (auto& m : meetings1) {
        cout << "[" << m[0] << "," << m[1] << "] ";
    }
    cout << endl;
    cout << "Min rooms (Heap): " << sol.minMeetingRooms(meetings1) << endl;
    cout << "Min rooms (Sweep): " << sol.minMeetingRoomsSweep(meetings1) << endl;
    
    vector<vector<int>> meetings2 = {{7, 10}, {2, 4}};
    cout << "\nMeetings 2: ";
    for (auto& m : meetings2) {
        cout << "[" << m[0] << "," << m[1] << "] ";
    }
    cout << endl;
    cout << "Min rooms (Heap): " << sol.minMeetingRooms(meetings2) << endl;
    cout << "Min rooms (Sweep): " << sol.minMeetingRoomsSweep(meetings2) << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: MIN HEAP
1. Sort meetings by start time
2. Use min heap to track end times of ongoing meetings
3. For each meeting:
   - If earliest ending meeting finishes first, reuse room
   - Add current meeting's end time to heap
4. Heap size = concurrent meetings = rooms needed

VISUALIZATION:
Meetings: [[0,30],[5,10],[15,20]]

Time:  0----5----10---15---20---30
Meeting1: [----------30]
Meeting2:      [--10]
Meeting3:            [---20]

At time 5: Need 2 rooms (Meeting1 and Meeting2)
At time 15: Need 2 rooms (Meeting1 and Meeting3)

APPROACH 2: SWEEP LINE
1. Separate and sort start and end times
2. Use two pointers
3. When start < end: meeting starts, increment rooms
4. When start >= end: meeting ends, decrement rooms
5. Track maximum rooms needed

EXAMPLE:
Starts: [0, 5, 15]
Ends:   [10, 20, 30]

Process:
- 0 < 10: rooms = 1
- 5 < 10: rooms = 2 (max)
- 10 < 15: rooms = 1
- 15 < 20: rooms = 2
- 20 < 30: rooms = 1
- 30 done: rooms = 0

Max rooms = 2

COMPARISON:
Min Heap:
- Intuitive
- O(n log n) time
- O(n) space

Sweep Line:
- More efficient
- O(n log n) time
- O(n) space
- Better constants

WHY THIS PATTERN IS IMPORTANT:
- Classic interval scheduling problem
- Demonstrates sweep line algorithm
- Common in calendar/scheduling problems
- Used in: CPU scheduling, resource allocation
- Shows optimization using different data structures
- Very frequent in FAANG interviews
*/
