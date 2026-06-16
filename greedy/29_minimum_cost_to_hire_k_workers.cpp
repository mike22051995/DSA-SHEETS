/*
PROBLEM: Minimum Cost to Hire K Workers (LeetCode 857)
DIFFICULTY: Hard
PATTERN: Greedy with Ratio Sorting + Max Heap

DESCRIPTION:
There are n workers. You are given two integer arrays quality and wage where quality[i] is 
the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
We want to hire exactly k workers to form a paid group. When hiring k workers, we must pay 
them according to these rules:
1. Every worker in the paid group should be paid in ratio to their quality
2. Every worker must be paid at least their minimum wage expectation
Return the least amount of money needed to form a paid group satisfying the above conditions.

INPUT:
- quality: array of worker qualities
- wage: array of minimum wage expectations
- k: number of workers to hire

OUTPUT:
- Minimum cost to hire k workers

APPROACH:
1. Calculate wage/quality ratio for each worker
2. Sort workers by this ratio
3. Use max heap to track k workers with smallest qualities
4. For each ratio, calculate cost if this worker sets the ratio
5. Keep track of minimum cost

WHY GREEDY WORKS:
The worker with highest ratio in selected group determines payment for all.
By processing in sorted order and maintaining minimum quality sum, we find optimal group.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;  // (ratio, quality)
        
        // Calculate ratio for each worker
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        // Sort by ratio
        sort(workers.begin(), workers.end());
        
        double minCost = 1e9;
        int qualitySum = 0;
        priority_queue<int> maxHeap;  // Max heap to remove highest quality
        
        for (auto& worker : workers) {
            double ratio = worker.first;
            int qual = worker.second;
            
            qualitySum += qual;
            maxHeap.push(qual);
            
            // If we have more than k workers, remove highest quality
            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            
            // If we have exactly k workers, calculate cost
            if (maxHeap.size() == k) {
                minCost = min(minCost, qualitySum * ratio);
            }
        }
        
        return minCost;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> quality1 = {10, 20, 5};
    vector<int> wage1 = {70, 50, 30};
    cout << "Test 1 - quality=[10,20,5], wage=[70,50,30], k=2" << endl;
    cout << "Output: " << fixed << setprecision(5) << sol.mincostToHireWorkers(quality1, wage1, 2) << endl;
    cout << "Expected: 105.00000" << endl << endl;
    
    // Test Case 2
    vector<int> quality2 = {3, 1, 10, 10, 1};
    vector<int> wage2 = {4, 8, 2, 2, 7};
    cout << "Test 2 - quality=[3,1,10,10,1], wage=[4,8,2,2,7], k=3" << endl;
    cout << "Output: " << fixed << setprecision(5) << sol.mincostToHireWorkers(quality2, wage2, 3) << endl;
    cout << "Expected: 30.66667" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log n) for sorting + O(n log k) for heap operations = O(n log n)
SPACE COMPLEXITY: O(n + k)

KEY LEARNING:
- Greedy with ratio: sort by ratio, process in order
- Max heap to maintain k smallest qualities
- Key insight: highest ratio in group determines all payments
- Sliding window with heap optimization
- Very challenging problem combining multiple techniques
- Tests understanding of greedy + heap + math
- Common in harder technical interviews (Google, Meta)
*/
