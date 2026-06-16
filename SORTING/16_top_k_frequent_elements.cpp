/*
PROBLEM: Top K Frequent Elements (LeetCode 347)
===============================================
DESCRIPTION:
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

PATTERN: Heap / QuickSelect / Bucket Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log k) using heap, O(n) using bucket sort
SPACE COMPLEXITY: O(n)

INPUT:
nums = [1,1,1,2,2,3], k = 2

OUTPUT:
[1,2]

EXAMPLE:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Min Heap (Most intuitive)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Min heap: pair<frequency, number>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove least frequent
            }
        }
        
        // Extract elements from heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
    
    // Approach 2: Bucket Sort (O(n) solution)
    vector<int> topKFrequentBucket(vector<int>& nums, int k) {
        // Count frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Create buckets: index = frequency
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }
        
        // Collect top k frequent elements
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
    
    // Approach 3: Using sorting
    vector<int> topKFrequentSort(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        
        // Sort by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    cout << "Array: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nK = " << k1 << endl;
    
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Top " << k1 << " frequent (Heap): ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    
    vector<int> result2 = sol.topKFrequentBucket(nums1, k1);
    cout << "Top " << k1 << " frequent (Bucket): ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: MIN HEAP
1. Count frequency of each element
2. Use min heap of size k
3. Keep k most frequent elements in heap
4. If heap size > k, remove minimum
5. Final heap contains k most frequent

Time: O(n log k), Space: O(n)

APPROACH 2: BUCKET SORT (OPTIMAL)
1. Count frequency of each element
2. Create buckets where index = frequency
3. Iterate buckets from high to low frequency
4. Collect k elements

Time: O(n), Space: O(n)

APPROACH 3: SORTING
1. Count frequency
2. Sort by frequency
3. Take first k elements

Time: O(n log n), Space: O(n)

WHY BUCKET SORT IS OPTIMAL:
- Frequency is bounded by n
- Can use counting sort principle
- Linear time complexity

COMPARISON:
Min Heap:
- Good when k << n
- O(n log k) time
- More memory efficient

Bucket Sort:
- Best overall time O(n)
- Uses frequency as index
- Optimal when need O(n) solution

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates heap usage for top-k problems
- Shows optimization from O(n log n) to O(n)
- Common pattern in frequency-based problems
- Used in: Top k frequent words, k closest points, etc.
- Shows trade-off between different data structures
*/
