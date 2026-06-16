/*
================================================================================
PROBLEM: Find K Pairs with Smallest Sums (LeetCode #373)
DIFFICULTY: Medium
PATTERN: Heap
COMPANIES: Amazon, Google, Microsoft
================================================================================
DESCRIPTION:
Return the k pairs (u,v) with the smallest sums from two sorted arrays.

INPUT FORMAT:
- nums1: sorted list of integers
- nums2: sorted list of integers
- k: number of pairs to return

OUTPUT FORMAT:
- list of pairs, ordered by non-decreasing sum

APPROACH (MIN-HEAP):
- Push (i,0) for the first min(k, n1) rows.
- Pop smallest sum and push (i, j+1) to advance in nums2.

CODE EXPLANATION:
- Heap nodes store indices (i,j) and compare by nums1[i] + nums2[j].
- Start with pairs (i,0) and expand along nums2 as pairs are popped.

COMPLEXITY:
- Time: O(k log min(n1, k))
- Space: O(min(n1, k))

SAMPLE INPUT/OUTPUT:
1) nums1 = [1,7,11], nums2 = [2,4,6], k = 3 -> [[1,2],[1,4],[1,6]]
2) nums1 = [1,1,2], nums2 = [1,2,3], k = 2 -> [[1,1],[1,1]]
3) nums1 = [1,2], nums2 = [3], k = 3 -> [[1,3],[2,3]]
4) nums1 = [-1,0,1], nums2 = [-2,3], k = 4 -> [[-1,-2],[0,-2],[1,-2],[-1,3]]
5) nums1 = [1], nums2 = [1], k = 1 -> [[1,1]]
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        
        if (nums1.empty() || nums2.empty() || k == 0) {
            return result;
        }
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
        
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            minHeap.push({i, 0});
        }
        
        while (k-- > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            
            result.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size()) {
                minHeap.push({i, j + 1});
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    
    vector<vector<int>> result = sol.kSmallestPairs(nums1, nums2, 3);
    
    cout << "K smallest pairs:" << endl;
    for (auto& pair : result) {
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Kth Smallest Element in Sorted Matrix (LeetCode #378)
2. Find K-th Smallest Pair Distance (LeetCode #719)
3. Kth Smallest Prime Fraction (LeetCode #786)
4. Merge k Sorted Lists (LeetCode #23)
5. Ugly Number II (LeetCode #264)
6. Super Ugly Number (LeetCode #313)
7. Kth Largest Element (LeetCode #215)
8. Top K Frequent Elements (LeetCode #347)
9. K Closest Points to Origin (LeetCode #973)
10. Minimum Cost to Hire K Workers (LeetCode #857)
*/
