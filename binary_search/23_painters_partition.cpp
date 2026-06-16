/*
PROBLEM: Painter's Partition Problem
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Given an array of N boards, where the ith board has length boards[i]. Some K painters are 
available to paint these boards. Each painter takes 1 unit time to paint 1 unit of the board.
The task is to find the minimum time to paint all boards under the constraints that any painter 
will only paint contiguous sections of boards, and all painters work simultaneously.

EXPLANATION:
Binary search on maximum time:
- Min time = max(boards) (one painter must paint longest board)
- Max time = sum(boards) (one painter paints all)
- For each time, check if K painters can finish
- Find minimum time that works

Time Complexity: O(n * log(sum))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: boards = [10,20,30,40], painters = 2
Output: 60
Explanation: Painter 1: [10,20,30], Painter 2: [40]

Example 2:
Input: boards = [10,10,10,10], painters = 2
Output: 20
Explanation: Each painter paints 2 boards

Example 3:
Input: boards = [5,10,30,20,15], painters = 3
Output: 35
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int paintersPartition(vector<int>& boards, int painters) {
        int left = *max_element(boards.begin(), boards.end());
        int right = accumulate(boards.begin(), boards.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canPaint(boards, painters, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canPaint(vector<int>& boards, int painters, int maxTime) {
        int paintersNeeded = 1;
        int currentTime = 0;
        
        for (int board : boards) {
            if (currentTime + board > maxTime) {
                paintersNeeded++;
                currentTime = board;
                
                if (paintersNeeded > painters) {
                    return false;
                }
            } else {
                currentTime += board;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> boards1 = {10,20,30,40};
    cout << "Test 1: " << solution.paintersPartition(boards1, 2) << endl;
    
    // Test Case 2
    vector<int> boards2 = {10,10,10,10};
    cout << "Test 2: " << solution.paintersPartition(boards2, 2) << endl;
    
    // Test Case 3
    vector<int> boards3 = {5,10,30,20,15};
    cout << "Test 3: " << solution.paintersPartition(boards3, 3) << endl;
    
    return 0;
}
