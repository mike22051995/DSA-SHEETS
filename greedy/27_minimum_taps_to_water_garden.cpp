/*
PROBLEM: Minimum Number of Taps to Open to Water a Garden (LeetCode 1326)
DIFFICULTY: Hard
PATTERN: Greedy Interval Coverage / Jump Game Variant

DESCRIPTION:
There is a one-dimensional garden on the x-axis. The garden starts at point 0 and ends at point n.
There are n + 1 taps located at points [0, 1, ..., n] in the garden.
Given an integer n and an integer array ranges of length n + 1 where ranges[i] means the 
i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.
Return the minimum number of taps that should be open to water the whole garden, or -1 if impossible.

INPUT:
- n: garden length
- ranges: array where ranges[i] is reach of tap i

OUTPUT:
- Minimum taps needed, or -1 if impossible

APPROACH:
1. Convert taps to intervals [left, right]
2. Similar to Jump Game II: track current end and farthest reach
3. For each position, find tap that extends farthest
4. When we reach current end, must open a tap

WHY GREEDY WORKS:
Within current covered range, always choose tap that extends farthest.
This minimizes number of taps needed.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Convert to intervals and create jump array
        vector<int> maxReach(n + 1, 0);
        
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxReach[left] = max(maxReach[left], right);
        }
        
        int taps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i <= n; i++) {
            // If current position is beyond our reach, impossible
            if (i > farthest) {
                return -1;
            }
            
            // Update farthest reachable from current range
            farthest = max(farthest, maxReach[i]);
            
            // If we've reached end of current tap's coverage
            if (i == currentEnd) {
                taps++;
                currentEnd = farthest;
                
                // If we've covered the garden
                if (currentEnd >= n) {
                    return taps;
                }
            }
        }
        
        return currentEnd >= n ? taps : -1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> ranges1 = {3, 4, 1, 1, 0, 0};
    cout << "Test 1 - n=5, ranges=[3,4,1,1,0,0]" << endl;
    cout << "Output: " << sol.minTaps(5, ranges1) << endl;
    cout << "Expected: 1 (tap at index 1)" << endl << endl;
    
    // Test Case 2
    vector<int> ranges2 = {0, 0, 0, 0};
    cout << "Test 2 - n=3, ranges=[0,0,0,0]" << endl;
    cout << "Output: " << sol.minTaps(3, ranges2) << endl;
    cout << "Expected: -1 (impossible)" << endl << endl;
    
    // Test Case 3
    vector<int> ranges3 = {1, 2, 1, 0, 2, 1, 0, 1};
    cout << "Test 3 - n=7, ranges=[1,2,1,0,2,1,0,1]" << endl;
    cout << "Output: " << sol.minTaps(7, ranges3) << endl;
    cout << "Expected: 3" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is garden length
SPACE COMPLEXITY: O(n) for maxReach array

KEY LEARNING:
- Interval coverage problem: similar to Jump Game
- Convert problem representation to simpler form
- Greedy BFS approach without actual BFS
- Track current coverage and maximum reach
- Pattern: minimum intervals to cover range
- Appears in: video stitching, jump game variants
*/
