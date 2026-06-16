/*
PROBLEM: Sort Array by Increasing Frequency (LeetCode 1636)
===============================================
DESCRIPTION:
Given an array of integers nums, sort the array in increasing order based on 
the frequency of the values. If multiple values have the same frequency, sort 
them in decreasing order. Return the sorted array.

PATTERN: Frequency Count + Custom Comparator
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Array sorted by frequency (ascending), then by value (descending)

EXAMPLE:
Input: [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: 3 appears 1 time, 1 appears 2 times, 2 appears 3 times

Input: [2,3,1,3,2]
Output: [1,3,3,2,2]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Custom comparator:
        // 1. Sort by frequency (ascending)
        // 2. If frequencies are same, sort by value (descending)
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b]; // Increasing frequency
            }
            return a > b; // Decreasing value
        });
        
        return nums;
    }
    
    // Alternative: Using pairs for clarity
    vector<int> frequencySortV2(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Create vector of (value, frequency) pairs
        vector<pair<int, int>> pairs;
        for (int num : nums) {
            pairs.push_back({num, freq[num]});
        }
        
        // Sort with custom comparator
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second; // By frequency ascending
            }
            return a.first > b.first; // By value descending
        });
        
        // Extract values
        vector<int> result;
        for (auto& [val, freq] : pairs) {
            result.push_back(val);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    cout << "Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    
    vector<int> result1 = sol.frequencySort(nums1);
    cout << "Output: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    
    vector<int> nums2 = {2, 3, 1, 3, 2};
    cout << "\nInput: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    
    vector<int> result2 = sol.frequencySort(nums2);
    cout << "Output: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    
    vector<int> nums3 = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    cout << "\nInput: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;
    
    vector<int> result3 = sol.frequencySort(nums3);
    cout << "Output: ";
    for (int num : result3) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
PROBLEM REQUIREMENTS:
1. Primary sort: By frequency (ascending)
2. Secondary sort: By value (descending) - if frequencies equal

CUSTOM COMPARATOR LOGIC:
if (freq[a] != freq[b])
    return freq[a] < freq[b];  // Less frequent comes first
else
    return a > b;              // Larger value comes first

EXAMPLE WALKTHROUGH:
Input: [1,1,2,2,2,3]

Frequency count:
1 → 2 times
2 → 3 times
3 → 1 time

Sorting:
- 3 appears 1 time (least frequent) → comes first
- 1 appears 2 times → comes second
- 2 appears 3 times (most frequent) → comes last

Result: [3, 1, 1, 2, 2, 2]

EXAMPLE WITH TIE:
Input: [2,3,1,3,2]

Frequency:
1 → 1 time
2 → 2 times
3 → 2 times

Sorting:
- 1 appears 1 time → comes first
- 2 and 3 both appear 2 times → sort by value descending
  - 3 > 2, so 3 comes before 2

Result: [1, 3, 3, 2, 2]

COMPARATOR BREAKDOWN:
Primary criterion: freq[a] < freq[b]
- Lower frequency → comes first
- Ascending order of frequency

Secondary criterion: a > b (when frequencies equal)
- Larger value → comes first
- Descending order of value

APPROACH 1 vs APPROACH 2:
Approach 1 (In-place):
- Sorts original array directly
- Uses lambda with captured freq map
- More memory efficient

Approach 2 (Pairs):
- Creates explicit pairs
- More readable
- Slightly more memory

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates multi-level sorting criteria
- Shows how to combine multiple comparisons
- Common in real-world sorting scenarios
- Tests understanding of comparator logic
- Used in: Ranking systems, priority queues with multiple criteria
*/
