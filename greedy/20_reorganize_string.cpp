/*
PROBLEM: Reorganize String (LeetCode 767)
DIFFICULTY: Medium
PATTERN: Greedy Scheduling with Max Heap

DESCRIPTION:
Given a string s, rearrange the characters of s so that any two adjacent characters are 
not the same. Return any possible rearrangement of s or return "" if not possible.

INPUT:
- s: string to reorganize

OUTPUT:
- Reorganized string or empty string if impossible

APPROACH:
1. Count frequency of each character
2. Use max heap to always pick most frequent character
3. Pick top 2 characters, append them, decrease count
4. Put them back if count > 0
5. Handle last remaining character specially

WHY GREEDY WORKS:
Always using most frequent character (that's different from previous) 
ensures we don't run out of alternatives too early.
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // Count frequency
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Check if reorganization is possible
        // If any character appears more than (n+1)/2 times, impossible
        for (auto& p : freq) {
            if (p.second > (s.length() + 1) / 2) {
                return "";
            }
        }
        
        // Max heap based on frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& p : freq) {
            maxHeap.push({p.second, p.first});
        }
        
        string result = "";
        
        // Process pairs of characters
        while (maxHeap.size() >= 2) {
            auto first = maxHeap.top(); maxHeap.pop();
            auto second = maxHeap.top(); maxHeap.pop();
            
            result += first.second;
            result += second.second;
            
            // Put back if still have remaining
            if (--first.first > 0) {
                maxHeap.push(first);
            }
            if (--second.first > 0) {
                maxHeap.push(second);
            }
        }
        
        // Handle last character if any
        if (!maxHeap.empty()) {
            result += maxHeap.top().second;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "aab";
    cout << "Test 1 - Input: " << s1 << endl;
    cout << "Output: " << sol.reorganizeString(s1) << endl;
    cout << "Expected: aba or similar" << endl << endl;
    
    // Test Case 2
    string s2 = "aaab";
    cout << "Test 2 - Input: " << s2 << endl;
    cout << "Output: " << sol.reorganizeString(s2) << endl;
    cout << "Expected: (empty - impossible)" << endl << endl;
    
    // Test Case 3
    string s3 = "vvvlo";
    cout << "Test 3 - Input: " << s3 << endl;
    cout << "Output: " << sol.reorganizeString(s3) << endl;
    cout << "Expected: vlvov or similar" << endl << endl;
    
    // Test Case 4
    string s4 = "aaabbcc";
    cout << "Test 4 - Input: " << s4 << endl;
    cout << "Output: " << sol.reorganizeString(s4) << endl;
    cout << "Expected: ababcac or similar" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n log k) where k is unique characters (at most 26)
SPACE COMPLEXITY: O(k) for heap

KEY LEARNING:
- Greedy with max heap: always pick most frequent available option
- Similar to task scheduler problem
- Check feasibility first: maxFreq <= (n+1)/2
- Process in pairs to ensure no adjacency
- Pattern: rearrangement with constraints
- Common in string manipulation interviews
*/
