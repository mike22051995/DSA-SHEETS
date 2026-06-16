/*
================================================================================
PROBLEM: IPO (LeetCode #502)
DIFFICULTY: Hard
PATTERN: Heap / Greedy
COMPANIES: Amazon, Google, Microsoft
================================================================================
DESCRIPTION:
Choose at most k projects to maximize capital. Each project i requires capital[i]
and yields profit[i]. Start with capital w.

INPUT FORMAT:
- k: maximum number of projects
- w: initial capital
- profits: list of project profits
- capital: list of required capital

OUTPUT FORMAT:
- maximum capital after completing up to k projects

APPROACH:
- Sort projects by required capital.
- Use a max-heap of profits for all projects affordable at current capital.
- Repeatedly pick the most profitable available project.

CODE EXPLANATION:
- Projects are sorted by capital so we can add all affordable ones in order.
- maxHeap always holds profits of projects we can currently start.
- Each of k rounds picks the best profit and increases capital.

COMPLEXITY:
- Time: O(n log n)
- Space: O(n)

SAMPLE INPUT/OUTPUT:
1) k = 2, w = 0, profits = [1,2,3], capital = [0,1,1] -> 4
2) k = 1, w = 2, profits = [1,2,3], capital = [1,1,2] -> 5
3) k = 3, w = 0, profits = [1,2], capital = [1,1] -> 0
4) k = 2, w = 1, profits = [2,4,6], capital = [0,1,1] -> 11
5) k = 2, w = 3, profits = [1,2,3], capital = [0,4,5] -> 6
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Sort by capital requirement
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxHeap;
        int i = 0;
        
        for (int j = 0; j < k; j++) {
            // Add all projects we can afford to maxHeap
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            
            if (maxHeap.empty()) {
                break;
            }
            
            // Pick the most profitable project
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};

int main() {
    Solution sol;
    int k = 2, w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    
    cout << "Maximum capital: " << sol.findMaximizedCapital(k, w, profits, capital) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximum Profit in Job Scheduling (LeetCode #1235)
2. Meeting Rooms II (LeetCode #253)
3. Task Scheduler (LeetCode #621)
4. Single-Threaded CPU (LeetCode #1834)
5. Furthest Building You Can Reach (LeetCode #1642)
6. Minimum Cost to Hire K Workers (LeetCode #857)
7. Find Servers That Handled Most Requests (LeetCode #1606)
8. Maximum Performance of Team (LeetCode #1383)
9. Most Profit Assigning Work (LeetCode #826)
10. Merge k Sorted Lists (LeetCode #23)
*/
