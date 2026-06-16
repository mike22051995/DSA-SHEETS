/*
PROBLEM: IPO (LeetCode 502)
DIFFICULTY: Hard
PATTERN: Greedy with Two Heaps

DESCRIPTION:
You are given n projects where the ith project has a pure profit profits[i] and a minimum 
capital of capital[i] is needed to start it. Initially, you have w capital. When you finish 
a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital.

INPUT:
- k: maximum projects to complete
- w: initial capital
- profits: profit for each project
- capital: capital needed for each project

OUTPUT:
- Maximum capital after completing at most k projects

APPROACH:
1. Store all projects sorted by capital (min heap)
2. Use max heap for available projects (by profit)
3. At each step, add all affordable projects to max heap
4. Pick highest profit project
5. Repeat k times

WHY GREEDY WORKS:
Always picking the most profitable affordable project maximizes capital growth,
which enables more projects in future iterations.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Min heap of projects by capital requirement
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;
        
        for (int i = 0; i < n; i++) {
            minCapital.push({capital[i], profits[i]});
        }
        
        // Max heap of profits for affordable projects
        priority_queue<int> maxProfit;
        
        for (int i = 0; i < k; i++) {
            // Add all projects we can now afford to max heap
            while (!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }
            
            // If no affordable projects, break
            if (maxProfit.empty()) {
                break;
            }
            
            // Pick most profitable project
            w += maxProfit.top();
            maxProfit.pop();
        }
        
        return w;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> profits1 = {1, 2, 3};
    vector<int> capital1 = {0, 1, 1};
    cout << "Test 1 - k=2, w=0, profits=[1,2,3], capital=[0,1,1]" << endl;
    cout << "Output: " << sol.findMaximizedCapital(2, 0, profits1, capital1) << endl;
    cout << "Expected: 4 (do project 0: w=1, then project 2: w=4)" << endl << endl;
    
    // Test Case 2
    vector<int> profits2 = {1, 2, 3};
    vector<int> capital2 = {0, 1, 2};
    cout << "Test 2 - k=3, w=0, profits=[1,2,3], capital=[0,1,2]" << endl;
    cout << "Output: " << sol.findMaximizedCapital(3, 0, profits2, capital2) << endl;
    cout << "Expected: 6" << endl << endl;
    
    // Test Case 3
    vector<int> profits3 = {1, 2, 3};
    vector<int> capital3 = {1, 1, 2};
    cout << "Test 3 - k=1, w=0, profits=[1,2,3], capital=[1,1,2]" << endl;
    cout << "Output: " << sol.findMaximizedCapital(1, 0, profits3, capital3) << endl;
    cout << "Expected: 0 (can't afford any project)" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n + k log n) where n is number of projects
SPACE COMPLEXITY: O(n) for heaps

KEY LEARNING:
- Two heaps pattern: one for availability, one for selection
- Greedy: always pick best available option
- Update availability as resources increase
- Pattern appears in: scheduling with dependencies, resource allocation
- Common in Google/Amazon interviews
*/
