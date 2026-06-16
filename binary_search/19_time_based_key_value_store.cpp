/*
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
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
    
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }
        
        auto& pairs = store[key];
        int left = 0, right = pairs.size() - 1;
        string result = "";
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (pairs[mid].first <= timestamp) {
                result = pairs[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

int main() {
    // Test Case 1
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << "Test 1a: " << timeMap.get("foo", 1) << endl;
    cout << "Test 1b: " << timeMap.get("foo", 3) << endl;
    timeMap.set("foo", "bar2", 4);
    cout << "Test 1c: " << timeMap.get("foo", 4) << endl;
    cout << "Test 1d: " << timeMap.get("foo", 5) << endl;
    
    return 0;
}
