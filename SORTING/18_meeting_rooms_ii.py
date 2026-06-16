"""
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
"""

import heapq
from typing import List

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        
        # Sort by start time
        intervals.sort(key=lambda x: x[0])
        
        # Min heap to track end times of meetings
        minHeap = []
        heapq.heappush(minHeap, intervals[0][1])
        
        for i in range(1, len(intervals)):
            # If earliest ending meeting finishes before current starts
            if intervals[i][0] >= minHeap[0]:
                heapq.heappop(minHeap)
            # Add current meeting's end time
            heapq.heappush(minHeap, intervals[i][1])
        
        # Heap size = number of rooms needed
        return len(minHeap)
    
    def minMeetingRoomsSweep(self, intervals: List[List[int]]) -> int:
        # Sweep line approach
        events = []
        for start, end in intervals:
            events.append((start, 1))      # Start of meeting
            events.append((end, -1))        # End of meeting
        
        # Sort by time, then by event type (end before start at same time)
        events.sort(key=lambda x: (x[0], x[1]))
        
        rooms = max_rooms = 0
        for _, event in events:
            rooms += event
            max_rooms = max(max_rooms, rooms)
        
        return max_rooms


if __name__ == "__main__":
    sol = Solution()
    
    meetings1 = [[0, 30], [5, 10], [15, 20]]
    print("Meetings 1: ")
    for m in meetings1:
        print(f"[{m[0]}, {m[1]}]", end=" ")
    print()
    print(f"Min rooms (Heap): {sol.minMeetingRooms(meetings1)}")
    print(f"Min rooms (Sweep): {sol.minMeetingRoomsSweep(meetings1)}")
    
    meetings2 = [[7, 10], [2, 4]]
    print("\nMeetings 2: ")
    for m in meetings2:
        print(f"[{m[0]}, {m[1]}]", end=" ")
    print()
    print(f"Min rooms (Heap): {sol.minMeetingRooms(meetings2)}")
    print(f"Min rooms (Sweep): {sol.minMeetingRoomsSweep(meetings2)}")
