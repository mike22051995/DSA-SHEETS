"""
PROBLEM: Time Based Key-Value Store
Difficulty: Medium
Pattern: Binary Search on Timestamps

DESCRIPTION:
Design a time-based key-value data structure that can store multiple values for the same key 
at different time stamps and retrieve the key's value at a certain timestamp.
Implement the TimeMap class:
- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key with the value at the given timestamp.
- String get(String key, int timestamp) Returns a value such that set was called previously, 
  with timestamp_prev <= timestamp. If there are multiple such values, return the one with 
  the largest timestamp_prev. If there are no values, return "".

EXPLANATION:
Use hash map with vector for each key:
- Store (timestamp, value) pairs sorted by timestamp
- For get operation, use binary search to find largest timestamp <= given timestamp

Time Complexity: set O(1), get O(log n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: ["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output: [null, null, "bar", "bar", null, "bar2", "bar2"]

Example 2:
Input: ["TimeMap", "set", "set", "get", "get"]
[[], ["a", "val1", 1], ["a", "val2", 2], ["a", 1], ["a", 3]]
Output: [null, null, null, "val1", "val2"]

Example 3:
Input: ["TimeMap", "set", "get"]
[[], ["key", "value", 10], ["key", 5]]
Output: [null, null, ""]
"""

import bisect
from collections import defaultdict


class TimeMap:
    def __init__(self):
        self.store = defaultdict(list)  # key -> [(timestamp, value)]

    def set(self, key, value, timestamp):
        self.store[key].append((timestamp, value))

    def get(self, key, timestamp):
        if key not in self.store:
            return ""
        pairs = self.store[key]
        timestamps = [t for t, v in pairs]
        idx = bisect.bisect_right(timestamps, timestamp) - 1
        if idx >= 0:
            return pairs[idx][1]
        return ""


if __name__ == "__main__":
    time_map = TimeMap()
    time_map.set("foo", "bar", 1)
    print(f"Test 1a: {time_map.get('foo', 1)}")   # bar
    print(f"Test 1b: {time_map.get('foo', 3)}")   # bar
    time_map.set("foo", "bar2", 4)
    print(f"Test 1c: {time_map.get('foo', 4)}")   # bar2
    print(f"Test 1d: {time_map.get('foo', 5)}")   # bar2
