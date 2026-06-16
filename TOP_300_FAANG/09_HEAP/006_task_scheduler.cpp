/*
================================================================================
PROBLEM: Task Scheduler (LeetCode #621)
DIFFICULTY: Medium
PATTERN: Greedy / Heap
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
DESCRIPTION:
Given a list of CPU tasks and a cooldown n, return the minimum time units to
finish all tasks. The same task must be separated by at least n units.

INPUT FORMAT:
- tasks: list of uppercase letters
- n: non-negative integer cooldown

OUTPUT FORMAT:
- minimum total time units

APPROACH:
- Greedy math: arrange the most frequent tasks first and count idle slots.
- Heap simulation: process cycles of size n+1 using a max-heap of frequencies.

CODE EXPLANATION:
- leastInterval computes idle slots based on the most frequent tasks.
- leastIntervalHeap simulates cycles with a max-heap of remaining counts.
- Each cycle picks up to n+1 tasks, reduces counts, and accumulates time.

COMPLEXITY:
- Time: O(N)
- Space: O(1) to O(26)

SAMPLE INPUT/OUTPUT:
1) tasks = [A,A,A,B,B,B], n = 2 -> 8
2) tasks = [A,A,A,B,B,B], n = 0 -> 6
3) tasks = [A,A,A,A,B,B,B,C,C], n = 2 -> 10
4) tasks = [A,A,A,A,A,A,B,C,D,E,F,G], n = 2 -> 16
5) tasks = [A,B,C,D], n = 3 -> 4
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        
        for (char task : tasks) {
            freq[task]++;
            maxFreq = max(maxFreq, freq[task]);
        }
        
        int maxCount = 0;
        for (auto& p : freq) {
            if (p.second == maxFreq) {
                maxCount++;
            }
        }
        
        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxFreq * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
    
    // Heap approach
    int leastIntervalHeap(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }
        
        priority_queue<int> pq;
        for (auto& p : freq) {
            pq.push(p.second);
        }
        
        int time = 0;
        
        while (!pq.empty()) {
            vector<int> temp;
            
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int f = pq.top();
                    pq.pop();
                    
                    if (f > 1) {
                        temp.push_back(f - 1);
                    }
                }
            }
            
            for (int f : temp) {
                pq.push(f);
            }
            
            time += pq.empty() ? temp.size() + (n - temp.size() + 1) : n + 1;
        }
        
        return time;
    }
};

int main() {
    Solution sol;
    vector<char> tasks1 = {'A','A','A','B','B','B'};
    vector<char> tasks2 = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    
    cout << "Minimum intervals: " << sol.leastInterval(tasks1, 2) << endl;
    cout << "Minimum intervals: " << sol.leastInterval(tasks2, 2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Rearrange String k Distance Apart (LeetCode #358)
2. Reorganize String (LeetCode #767)
3. CPU Scheduling
4. Meeting Rooms II (LeetCode #253)
5. Top K Frequent Elements (LeetCode #347)
6. Furthest Building You Can Reach (LeetCode #1642)
7. Maximum Performance of a Team (LeetCode #1383)
8. Minimum Cost to Hire K Workers (LeetCode #857)
9. Single-Threaded CPU (LeetCode #1834)
10. Process Tasks Using Servers (LeetCode #1882)
*/
