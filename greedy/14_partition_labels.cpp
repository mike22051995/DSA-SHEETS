/*
PROBLEM: Partition Labels (LeetCode 763)
DIFFICULTY: Medium
PATTERN: Greedy Interval Merging / Last Occurrence Tracking

DESCRIPTION:
You are given a string s. We want to partition the string into as many parts as possible 
so that each letter appears in at most one part. Return a list of integers representing 
the size of these parts.

INPUT:
- s: string to partition

OUTPUT:
- List of partition sizes

APPROACH:
1. Record last occurrence of each character
2. Use two pointers: start and end of current partition
3. Expand end to include last occurrence of all chars seen so far
4. When current index reaches end, partition is complete

WHY GREEDY WORKS:
Once we see a character, we must extend partition to include its last occurrence.
This greedy extension gives us minimal partitions.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Store last occurrence of each character
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i]] = i;
        }
        
        vector<int> result;
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Extend partition end to include last occurrence of current char
            end = max(end, lastOccurrence[s[i]]);
            
            // If we've reached the end of current partition
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;  // Start new partition
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "ababcbacadefegdehijhklij";
    cout << "Test 1 - String: " << s1 << endl;
    cout << "Output: ";
    vector<int> result1 = sol.partitionLabels(s1);
    for (int size : result1) cout << size << " ";
    cout << "\nExpected: 9 7 8" << endl << endl;
    
    // Test Case 2
    string s2 = "eccbbbbdec";
    cout << "Test 2 - String: " << s2 << endl;
    cout << "Output: ";
    vector<int> result2 = sol.partitionLabels(s2);
    for (int size : result2) cout << size << " ";
    cout << "\nExpected: 10" << endl << endl;
    
    // Test Case 3
    string s3 = "abcdef";
    cout << "Test 3 - String: " << s3 << endl;
    cout << "Output: ";
    vector<int> result3 = sol.partitionLabels(s3);
    for (int size : result3) cout << size << " ";
    cout << "\nExpected: 1 1 1 1 1 1" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is string length (two passes)
SPACE COMPLEXITY: O(1) - at most 26 characters in map

KEY LEARNING:
- Last occurrence tracking is key for partitioning problems
- Greedy interval expansion: extend to cover all dependencies
- Similar to merge intervals but with different merging logic
- Pattern appears in string segmentation problems
- Common in Facebook/Amazon interviews
*/
