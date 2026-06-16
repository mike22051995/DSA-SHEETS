/*
================================================================================
PROBLEM: Top K Frequent Elements (LeetCode #347)
DIFFICULTY: Medium
PATTERN: Heap / Bucket Sort / Quick Select
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
DESCRIPTION:
Return the k most frequent elements from the input array. Order can be any.

INPUT FORMAT:
- nums: list of integers
- k: number of elements to return

OUTPUT FORMAT:
- list of k integers with highest frequency (any order)

APPROACH (HEAP):
- Count frequencies with a hash map.
- Maintain a min-heap of size k by frequency.
- Pop the smallest frequency when size exceeds k.

CODE EXPLANATION:
- freq stores counts for each number.
- The custom comparator makes a min-heap by frequency.
- Heap size is capped at k, so the heap ends with the top-k frequent elements.

COMPLEXITY:
- Time: O(n log k)
- Space: O(n)

SAMPLE INPUT/OUTPUT:
1) nums = [1,1,1,2,2,3], k = 2 -> [1,2]
2) nums = [1], k = 1 -> [1]
3) nums = [4,4,4,6,6,5,5,5,5], k = 2 -> [5,4]
4) nums = [-1,-1,-2,-2,-2,3], k = 2 -> [-2,-1]
5) nums = [7,7,7,7,8,8,9], k = 3 -> [7,8,9]
================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    // Heap Approach
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        auto comp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        for (auto& [num, count] : freq) {
            pq.push({num, count});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
    
    // Bucket Sort - O(n)
    vector<int> topKFrequentBucket(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }
        
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    auto result = sol.topKFrequent(nums, 2);
    
    cout << "Top 2 frequent: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Kth Largest Element in Array (LeetCode #215)
2. Top K Frequent Words (LeetCode #692)
3. Sort Characters By Frequency (LeetCode #451)
4. Find K Closest Elements (LeetCode #658)
5. K Closest Points to Origin (LeetCode #973)
6. Reorganize String (LeetCode #767)
7. Task Scheduler (LeetCode #621)
8. Kth Smallest Element in BST (LeetCode #230)
9. Sort Array By Increasing Frequency (LeetCode #1636)
10. Maximum Frequency Stack (LeetCode #895)
*/
