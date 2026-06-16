/*
PROBLEM: Task Scheduler (LeetCode 621)
DIFFICULTY: Medium
PATTERN: Greedy Scheduling with Cooling Period

DESCRIPTION:
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter 
represents a different task. Tasks could be done in any order. Each task is done in one unit 
of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two 
same tasks (the same letter), meaning there must be at least n units of time between any two 
same tasks. Return the least number of units of time that the CPU will take to finish all tasks.

INPUT:
- tasks: array of characters representing tasks
- n: cooling period between same tasks

OUTPUT:
- Minimum time units to complete all tasks

APPROACH:
1. Count frequency of each task
2. Most frequent task determines minimum time
3. Formula: (maxFreq - 1) * (n + 1) + numberOfTasksWithMaxFreq
4. But answer can't be less than total tasks

WHY GREEDY WORKS:
Schedule most frequent task first with maximum spacing. Other tasks fill the gaps.
If gaps aren't enough, we can append tasks at the end.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task
        unordered_map<char, int> freq;
        int maxFreq = 0;
        
        for (char task : tasks) {
            freq[task]++;
            maxFreq = max(maxFreq, freq[task]);
        }
        
        // Count how many tasks have maximum frequency
        int maxFreqCount = 0;
        for (auto& p : freq) {
            if (p.second == maxFreq) {
                maxFreqCount++;
            }
        }
        
        // Calculate minimum time
        // (maxFreq - 1) chunks, each of size (n + 1), plus final tasks
        int minTime = (maxFreq - 1) * (n + 1) + maxFreqCount;
        
        // If we have enough variety of tasks, we don't need idle time
        return max(minTime, (int)tasks.size());
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Test 1 - Tasks: ['A','A','A','B','B','B'], n=2" << endl;
    cout << "Output: " << sol.leastInterval(tasks1, 2) << endl;
    cout << "Expected: 8 (A->B->idle->A->B->idle->A->B)" << endl << endl;
    
    // Test Case 2
    vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Test 2 - Tasks: ['A','A','A','B','B','B'], n=0" << endl;
    cout << "Output: " << sol.leastInterval(tasks2, 0) << endl;
    cout << "Expected: 6 (no cooling needed)" << endl << endl;
    
    // Test Case 3
    vector<char> tasks3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << "Test 3 - Tasks: ['A'*6,'B','C','D','E','F','G'], n=2" << endl;
    cout << "Output: " << sol.leastInterval(tasks3, 2) << endl;
    cout << "Expected: 16" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is number of tasks
SPACE COMPLEXITY: O(1) - at most 26 different tasks

KEY LEARNING:
- Greedy scheduling: place most frequent items first with spacing
- Mathematical formula derived from greedy strategy
- Fill gaps with other tasks
- If not enough gaps, extend timeline
- Very common in system design and scheduling interviews
- Similar to "Reorganize String" problem
*/
