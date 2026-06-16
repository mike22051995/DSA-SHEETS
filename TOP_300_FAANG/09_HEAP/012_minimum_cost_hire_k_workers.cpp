/*
================================================================================
PROBLEM: Minimum Cost to Hire K Workers (LeetCode #857)
DIFFICULTY: Hard
PATTERN: Heap / Greedy
COMPANIES: Amazon, Google, Facebook
================================================================================
DESCRIPTION:
Hire exactly k workers with minimum total cost. Each worker must be paid at least
their wage, and pay is proportional to quality for all chosen workers.

INPUT FORMAT:
- quality: list of worker quality
- wage: list of minimum wage
- k: number of workers to hire

OUTPUT FORMAT:
- minimum possible total cost (double)

APPROACH:
- Sort workers by wage/quality ratio.
- Maintain a max-heap of qualities to keep the smallest total quality for k.
- For each ratio, compute cost = ratio * sum(qualities).

CODE EXPLANATION:
- workers stores (ratio, quality) and is sorted by ratio.
- maxHeap tracks the largest qualities to drop when size exceeds k.
- When heap size is k, current ratio * qualitySum is a valid cost.

COMPLEXITY:
- Time: O(n log n)
- Space: O(n)

SAMPLE INPUT/OUTPUT:
1) quality = [10,20,5], wage = [70,50,30], k = 2 -> 105.0
2) quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3 -> 30.6667
3) quality = [5,5,5], wage = [10,10,10], k = 2 -> 20.0
4) quality = [4,8,2,6], wage = [8,16,6,12], k = 2 -> 18.0
5) quality = [1,2,3], wage = [5,6,9], k = 2 -> 15.0
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        // Sort by wage-to-quality ratio
        sort(workers.begin(), workers.end());
        
        priority_queue<int> maxHeap;
        double minCost = DBL_MAX;
        int qualitySum = 0;
        
        for (auto& [ratio, q] : workers) {
            maxHeap.push(q);
            qualitySum += q;
            
            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (maxHeap.size() == k) {
                minCost = min(minCost, qualitySum * ratio);
            }
        }
        
        return minCost;
    }
};

int main() {
    Solution sol;
    vector<int> quality = {10,20,5};
    vector<int> wage = {70,50,30};
    int k = 2;
    
    cout << "Minimum cost: " << sol.mincostToHireWorkers(quality, wage, k) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. IPO (LeetCode #502)
2. Meeting Rooms II (LeetCode #253)
3. Task Scheduler (LeetCode #621)
4. Maximum Performance of Team (LeetCode #1383)
5. Most Profit Assigning Work (LeetCode #826)
6. Single-Threaded CPU (LeetCode #1834)
7. Furthest Building You Can Reach (LeetCode #1642)
8. Find Servers That Handled Most Requests (LeetCode #1606)
9. Maximum Profit in Job Scheduling (LeetCode #1235)
10. Kth Largest Element (LeetCode #215)
*/
