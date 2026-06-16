/*
PROBLEM: Sort Characters by Frequency (LeetCode 451)
===============================================
DESCRIPTION:
Given a string s, sort it in decreasing order based on the frequency of the 
characters. The frequency of a character is the number of times it appears in 
the string.

PATTERN: Frequency Count + Sorting / Bucket Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n) for sorting, O(n) for bucket sort
SPACE COMPLEXITY: O(n)

INPUT:
String

OUTPUT:
String sorted by character frequency

EXAMPLE:
Input: "tree"
Output: "eert" or "eetr" (e appears twice, r and t once)

Input: "cccaaa"
Output: "aaaccc" or "cccaaa"
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: HashMap + Sorting
    string frequencySort(string s) {
        // Count frequency
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Create vector of pairs for sorting
        vector<pair<int, char>> freqVec;
        for (auto& [ch, count] : freq) {
            freqVec.push_back({count, ch});
        }
        
        // Sort by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());
        
        // Build result string
        string result;
        for (auto& [count, ch] : freqVec) {
            result.append(count, ch); // Append character 'count' times
        }
        
        return result;
    }
    
    // Approach 2: Bucket Sort (O(n) solution)
    string frequencySortBucket(string s) {
        // Count frequency
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Create buckets: index = frequency
        vector<string> buckets(s.length() + 1);
        for (auto& [ch, count] : freq) {
            buckets[count].push_back(ch);
        }
        
        // Build result from high frequency to low
        string result;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (char ch : buckets[i]) {
                result.append(i, ch); // Append character i times
            }
        }
        
        return result;
    }
    
    // Approach 3: Using max heap
    string frequencySortHeap(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Max heap based on frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push({count, ch});
        }
        
        string result;
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result.append(count, ch);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    string s1 = "tree";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output (Sort): \"" << sol.frequencySort(s1) << "\"" << endl;
    
    string s2 = "cccaaa";
    cout << "\nInput: \"" << s2 << "\"" << endl;
    cout << "Output (Bucket): \"" << sol.frequencySortBucket(s2) << "\"" << endl;
    
    string s3 = "Aabb";
    cout << "\nInput: \"" << s3 << "\"" << endl;
    cout << "Output (Heap): \"" << sol.frequencySortHeap(s3) << "\"" << endl;
    
    return 0;
}

/*
EXPLANATION:
============
APPROACH 1: HASHMAP + SORTING
1. Count frequency of each character
2. Store as vector of (frequency, character) pairs
3. Sort by frequency in descending order
4. Build result by appending each character freq times

Time: O(n + k log k) where k is unique characters
Space: O(k)

APPROACH 2: BUCKET SORT (OPTIMAL)
1. Count frequency of each character
2. Create buckets where index = frequency
3. Add characters to their frequency bucket
4. Build result from highest to lowest frequency

Time: O(n)
Space: O(n)

APPROACH 3: MAX HEAP
1. Count frequency
2. Add to max heap (frequency as key)
3. Extract from heap and build result

Time: O(n + k log k)
Space: O(k)

WHY BUCKET SORT IS OPTIMAL:
- Frequency is bounded by string length n
- Can use index as frequency
- No need for comparison-based sorting
- Linear time complexity

KEY INSIGHTS:
- Multiple valid outputs (any order with same frequency)
- String.append(count, char) efficiently adds character multiple times
- Bucket sort is optimal when values are bounded

EDGE CASES:
1. Empty string: ""
2. Single character: "a"
3. All same: "aaaa"
4. All different: "abcd"

WHY THIS PATTERN IS IMPORTANT:
- Demonstrates frequency-based sorting
- Shows optimization from O(n log n) to O(n)
- Similar to: Top K frequent elements
- Common in string manipulation problems
- Used in compression algorithms
*/
